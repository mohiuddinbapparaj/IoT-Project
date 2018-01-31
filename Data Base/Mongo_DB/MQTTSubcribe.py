var mqtt = require('mqtt'), url = require('url');

var client = mqtt.connect('mqtt://iot.eclipse.org', {
    will: {
        topic: 'Datasoft_65',
        },
        clientID: '0995a123-1a3f-4220-85e6-1d1a251d0fff'
});

client.on('connect', function () { // When connected

    // subscribe to a topic

    client.subscribe('Datasoft_65', function () {

        // when a message arrives, do something with it

        client.on('message', function (topic, message, packet) {

            console.log("Received '" + message + "' on '" + topic + "'");

           // set the temperature. 

        });

    });

});