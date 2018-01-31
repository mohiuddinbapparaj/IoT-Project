import json
import ijson
import pycurl
import time

import numpy as np

import os

from pyeemd import ceemdan
from pyeemd.utils import plot_imfs


try:
    from io import BytesIO
except ImportError:
    from StringIO import StringIO as BytesIO

MASTER_URL ='http://Node-LB-618209181.us-east-1.elb.amazonaws.com/'
DEVLIST_URL = '1/Devices'


SRC_PATH = './JSON_DIR/'
DES_PATH = './DATA_DIR/'

TODAY_ONLY = 0

TAR_PTS = 1000


if not os.path.exists(DES_PATH):
	try:
    		os.makedirs(DES_PATH)
	except:
		pass


def getBody(url):
        buffer = BytesIO()

        c = pycurl.Curl()

        c.setopt(c.URL, MASTER_URL+url)
        c.setopt(c.WRITEDATA, buffer)
        c.perform()
        x = buffer.getvalue()
        c.close()

        #return buffer.getvalue()
        return x

def parse_file(filename):
    with open(filename, 'r') as f:
        z=f.readlines()

        arr = np.array([elem[:-1].split(',') for elem in z])
        d = {}
        d["tem"] = arr[:,0].astype(float)
        d["hum"] = arr[:,1].astype(float)
        d["co2"] = arr[:,2].astype(float)
        d["dewpt"] = arr[:,3].astype(float)
        d["pm"] = arr[:,4].astype(float)
        ts = arr[:,5]
        ts_mod = [time.strptime(tt, "%Y-%m-%dT%H:%M:%S.000Z") for tt in ts]
        d["upd_ts"] = [np.uint32(time.mktime(x)) for x in ts_mod]
        d["tod"] = np.array([x.tm_hour*60 + x.tm_min for x in ts_mod])#tod= time_of_day
        d["dow"] = np.array([x.tm_wday for x in ts_mod])               #day_of_week
        d["voc"] = arr[:,6].astype(float)

        #return tem, hum, co2, dewpt, pm, upd_ts, tod, dow, voc
        return d    


all_devs = json.loads(getBody(DEVLIST_URL))
dev_list = [dev[u'device'] for dev in all_devs]
name_list = [dev[u'name'] for dev in all_devs]

json_list =  os.listdir(SRC_PATH)


d_list = []	#device list, with details.

#jf--> json file
for idx, jf in enumerate(json_list):
	temp_list = []
	hum_list =[]
	co2_list = []
	dewpt_list = []
	pm_list = []
	ts_list = [] #timestamp
	voc_list = []
	print jf
	print "Processing %d/%d..." %(idx+1, len(json_list))
	dev = jf.split('_')[0]
	name = jf.split('_')[1][:-5]
	print name
	start = time.time()
	try:
	    with open(SRC_PATH+jf, 'r') as f:
		parser = ijson.parse(f)
		for prefix, event, value in parser:
			if prefix.endswith('temperature'):
				temp_list.append(value*1.8/1000.0 + 32)
                        elif prefix.endswith('humidity'):
                                hum_list.append(value/1000.0)
                        elif prefix.endswith('co2'):
                                co2_list.append(value)
                        elif prefix.endswith('dewpoint'):
                                dewpt_list.append(value)
                        elif prefix.endswith('pm'):
                                pm_list.append(value)
                        elif prefix.endswith('timestamp'):
                                ts_list.append(value)
                        elif prefix.endswith('voc'):
                                voc_list.append(value)
		## Saved as Temp | Hum | Co2 | Dewpt | pm | ts | VOC
		arr = np.vstack((temp_list, hum_list)) 
		arr = np.vstack((arr, co2_list))
        	arr = np.vstack((arr, dewpt_list))
        	arr = np.vstack((arr, pm_list))
        	arr = np.vstack((arr, ts_list))
        	arr = np.vstack((arr, voc_list))
		arr = arr.T
		np.savetxt(DES_PATH + dev + '_' + name + '.txt', arr[::100,:], fmt = '%s', delimiter=',')

	except Exception, e:
		print "Error: "+str(e)
		pass

	print "Processed & Saved in %d seconds\n" %(time.time()-start)



print "Parse process Completed."



