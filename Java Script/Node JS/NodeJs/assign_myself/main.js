var fs=require('fs');
var events=require('events');
var file_creator= require('./file_creater.js');
var rl=require('readline-specific');

eventEmitter=new events.EventEmitter();

eventEmitter.on('sendToDt', function(data)
{
    fs.appendFile('database.txt',data,(err)=>
   {
    if(err) throw err;
   });

});

tem_file_line=1;
hum_file_line=1;
acc_file_line=1;

file_creator.createNewData();

temTimeInterval=setInterval(function()
{ 
    var timeStamp=new Date();
    data='';
    rl.oneline('./temperature_sensor.txt', tem_file_line, function(err,res)
   {
      if(err) console.error(err);
      eventEmitter.emit('sendToDt', timeStamp+", "+res+'\n');
	  console.log(timeStamp+", "+res);

   });

   tem_file_line++;
   if(tem_file_line>100)
   {
       clearInterval(temTimeInterval);
       //showData();
   }

},1000);



humTimeInterval = setInterval(function(){
    var timeStamp = new Date();
    data='';
    rl.oneline('./humidity_sensor.txt', hum_file_line, function(err, res) {
        if (err) console.error(err);	//handling error
        eventEmitter.emit('sendToDt',timeStamp+", "+ res+'\n');
		console.log(timeStamp+", "+res);
    });
    hum_file_line++;
    if(hum_file_line>100){
        clearInterval(humTimeInterval);
        //showData();
    }
},3000);


accTimeInterval = setInterval(function(){
    var timeStamp = new Date();
    data='';
    rl.oneline('./accelerometer_sensor.txt', acc_file_line, function(err, res) {
        if (err) console.error(err);	//handling error
        eventEmitter.emit('sendToDt',timeStamp+", "+ res+'\n');
		console.log(timeStamp+", "+res);
      });
      
      acc_file_line++;
      if(acc_file_line>100){
          clearInterval(accTimeInterval);
          //showData();

      }
    },2000);


    function showData(){
        if(acc_file_line>10 && tem_file_line>10 && hum_file_line>10){
            setTimeout(function(){
                fs.readFile('./database.txt',function(err,data){
                    console.log(data.toString('ascii'));
                });
            },1000);
            
        }
    }