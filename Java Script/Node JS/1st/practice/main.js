/*
** Author : Md. Asif Shahjalal
            Avijit Nandi
            Mohammad Mohiuddin
*/
var fs = require("fs");

var i =0,j = 0,k = 0;
var tempData;
var humidityData;
var accelerometerData;

var databaseFile = fs.createWriteStream('database.txt');

fs.readFile('temp_sensor.txt', (err, data)=> {
    if(err) throw err;
    tempData = data.toString().split("\n");
});

fs.readFile('humidity_sensor.txt', (err, data)=> {
    if(err) throw err;
    humidityData = data.toString().split("\n");
});

fs.readFile('accelerometer_sensor.txt', (err, data)=> {
    if(err) throw err;
    accelerometerData = data.toString().split("\n");
});

function temperature(){
    if(i < 100){
        var date = new Date();
        var utcDate = date.toUTCString();
        databaseFile.write(utcDate+" "+tempData[i]+"\n")
        console.log(utcDate+" "+tempData[i]);
        i++;
    }
}

function humidity(){
    if(j < 100){
        var date = new Date();
        var utcDate = date.toUTCString();
        databaseFile.write(utcDate+" "+humidityData[j]+"\n")
        console.log(utcDate+" "+humidityData[j]);
        j++;
    } 
}


function accelerometer(){
    if(k < 100){
        var date = new Date();
        var utcDate = date.toUTCString();
        databaseFile.write(utcDate+" "+accelerometerData[k]+"\n")
        console.log(utcDate+" "+accelerometerData[k]);
        k++;
    }
}

setInterval(temperature, 2000);
setInterval(humidity, 5000);
setInterval(accelerometer, 10000);