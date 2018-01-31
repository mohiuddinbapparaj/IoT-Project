/*
** Author : Md. Asif Shahjalal
            Avijit Nandi
            Mohammad Mohiuddin
*/

var fs = require("fs");

var tempData = '';
var humidityData = '';
var accelarationData = '';

var maxTemp = 45.0;
var minTemp = 30.0;

for(var i = 0; i <=99; i++){
    var num = Math.random();
    tempData += "Line" + (i+1) +", ";
    tempData += num * (maxTemp - minTemp) + minTemp;
    tempData += " C";
    tempData += '\n';
}
// Create a writable stream
var writerStream = fs.createWriteStream('temp_sensor.txt');

// Write the data to stream with encoding to be utf8
writerStream.write(tempData,'UTF8');

// Mark the end of file
writerStream.end();

// Handle stream events --> finish, and error
writerStream.on('finish', function() {
    console.log("Temp Data Write completed.");
});

writerStream.on('error', function(err){
   console.log(err.stack);
});


var maxHum = 100.0;
var minHum = 40.0;

for(var i = 0; i <=99; i++){
    var num = Math.random();
    humidityData += "Line" + (i+1) +", ";
    humidityData += num * (maxHum - minHum) + minHum;
    humidityData += " %";
    humidityData += '\n';
}

// Create a writable stream
var writerStream = fs.createWriteStream('humidity_sensor.txt');

// Write the data to stream with encoding to be utf8
writerStream.write(humidityData,'UTF8');

// Mark the end of file
writerStream.end();

// Handle stream events --> finish, and error
writerStream.on('finish', function() {
    console.log("Humidity Data Write completed.");
});

writerStream.on('error', function(err){
   console.log(err.stack);
});


var maxAcc = 100.0;
var minAcc = 1.0;

for(var i = 0; i <=99; i++){
    var num = Math.random();
    accelarationData += "Line" + (i+1) +", ";
    accelarationData += num * (maxAcc - minAcc) + minAcc;
    accelarationData +=  " m/(s^2)";
    accelarationData += '\n';
}

// Create a writable stream
var writerStream = fs.createWriteStream('accelerometer_sensor.txt');

// Write the data to stream with encoding to be utf8
writerStream.write(accelarationData,'UTF8');

// Mark the end of file
writerStream.end();

// Handle stream events --> finish, and error
writerStream.on('finish', function() {
    console.log("Accelerometer Data Write completed.");
});

writerStream.on('error', function(err){
   console.log(err.stack);
});

