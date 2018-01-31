from flask import Flask
from flask import request
from pymongo import MongoClient
app = Flask(__name__)

client = MongoClient('localhost:27017')
db=client.sensor

print(client)
print(db)
print("done") 
@app.route('/')
def hello_world():
    return 'Hello, World!'

@app.route('/sensor',methods = ['POST', 'GET'])
def sensor():
   if request.method == 'POST':
      print (request.is_json)
      
      content = request.json
    #   db.value.insert_one(content)
      print (content)
      
      return "done"
   else:
    #   user = request.args.get('nm')
      return "error"
if __name__ =='__main__':
   app.run(host='0.0.0.0')