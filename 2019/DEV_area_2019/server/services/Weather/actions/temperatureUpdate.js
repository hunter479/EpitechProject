var fetch = require('node-fetch');
var FormData = require('form-data');
var User = require('../../../schema/schema_user');
var KelvinToCelsius = require('kelvin-to-celsius');
const EventEmitter = require("events").EventEmitter;

const superior = 1;

class temperatureUpdate extends EventEmitter {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        var myHeaders = new fetch.Headers();
        var requestOptions = {
            method: 'GET',
            headers: myHeaders,
            redirect: 'follow'
        };
        var parsed_data = JSON.parse(user.automation[auto_index].action.data);
        fetch("https://api.openweathermap.org/data/2.5/forecast?q=" + parsed_data.city + "&appid=62d8bb4d613a021c23ae24c562527faf", requestOptions)
        .then(response => response.text())
        .then(async(result) => {
            var parsed = JSON.parse(result);
            if (parsed && parsed.cod && parsed.cod === "200") {
                var temp = parsed.list[2].main.temp;
                console.log("Celsius: " + KelvinToCelsius(temp));
                console.log("USER INPUT TEMP: " + parsed_data.temp);
                if (parsed_data.sign === superior) {
                    if (KelvinToCelsius(temp) >= parsed_data.temp) {
                        this.emit("reaction", user, auto_index, co_info, co_index);
                    }
                } else {
                    console.log("INFERIOR");
                    if (KelvinToCelsius(temp) <= parsed_data.temp) {
                        this.emit("reaction", user, auto_index, co_info, co_index);
                    }
                }
            } else {
                console.log("ERROR IN WEATHER REQUEST");
            }
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = temperatureUpdate;