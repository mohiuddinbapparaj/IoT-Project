fs=require('fs');
//module.exports.createNewData=createNewData;

tem='';
hum='';
acc='';
for( var i=1; i<100; i++)
{

  tem += "Line "+i+", "+'temperature reading '+randomNum(30.0,45.0) + " C\n";
  hum += "Line "+i+", "+'humidity reading '+randomNum(40.0,100.0) + " %\n";
  acc += "Line "+i+", "+'accelerometer reading '+randomNum(1.0,100.0) + " \n";

 }

 fs.writeFileSync('temperature_sensor.txt',tem);
 fs.writeFileSync('humidity_sensor.txt',hum);
 fs.writeFileSync('accelerometer_sensor.txt',acc);

 function randomNum(min, max) {
    var value= (Math.random() * (max - min)) + min;
    return value.toFixed(2); 
}
