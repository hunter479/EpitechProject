var fetch = require('node-fetch');
var FormData = require('form-data');
var mongoose = require('mongoose');
var User = require('../../../schema/schema_user');
const EventEmitter = require("events").EventEmitter;

class lastLogOff extends EventEmitter {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        var myHeaders = new fetch.Headers();
        myHeaders.append("Authorization", "Client-ID a12e84096da979d");
        var requestOptions = {
            method: 'GET',
            headers: myHeaders,
            redirect: 'follow'
        };
        var steam_info = JSON.parse(user.automation[auto_index].action.data);
        fetch("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=377E26B442771B78C27B4C6DE6BA5EBE&steamids=" + steam_info.usercode, requestOptions)
        .then(response => response.text())
        .then(async(result) => {
            var parsed = JSON.parse(result);
            if (user.automation[auto_index].action.id === undefined || user.automation[auto_index].action.id === "" || parseInt(user.automation[auto_index].action.id) < parseInt(parsed.response.players[0].lastlogoff)) {
                console.log("PLAYER: " + parsed.response.players[0].personaname + " IS NOW OFFLINE");
                user.automation[auto_index].action.id = parsed.response.players[0].lastlogoff;
                await user.save();
                this.emit("reaction", user, auto_index, co_info, co_index);
                return true; 
            }
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = lastLogOff;