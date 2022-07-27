var fetch = require('node-fetch');
var FormData = require('form-data');
var mongoose = require('mongoose');
var User = require('../../../schema/schema_user');
const EventEmitter = require("events").EventEmitter;

class updateNetsoul extends EventEmitter {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        var myHeaders = new fetch.Headers();

        var intra_info = JSON.parse(user.automation[auto_index].action.data)
        fetch("https://intra.epitech.eu/" + intra_info.autologin + "/user/" + intra_info.email + "/netsoul?format=json", {
            method: "GET",
            headers: myHeaders,
            credentials: 'same-origin'
        })
        .then(response => response.text())
        .then(async(result) => {
            if (result) {
                var parsed = JSON.parse(result);
                if (!parsed || !parsed[0])
                    return;
                    console.log(parsed[0]);
                    if (intra_info.time > parseInt(parsed[0][5])) {
                    console.log("TEMPS DE LOG INFERIEUR À L'HEURE ENTRÉE PAR L'UTILISATEUR")
                    this.emit("reaction", user, auto_index, co_info, co_index);
                }
            }
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = updateNetsoul;