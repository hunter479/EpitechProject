var fetch = require('node-fetch');
var FormData = require('form-data');
var mongoose = require('mongoose');
var User = require('../../../schema/schema_user');
const EventEmitter = require("events").EventEmitter;

class newNotif extends EventEmitter {
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
        let intra_info = JSON.parse(user.automation[auto_index].action.data);
        console.log('INFO INTRA LOGIN', (intra_info));
        console.log('URL INTRA', 'https://intra.epitech.eu/' + intra_info.autologin + '/user/notification/message?format=json');
        fetch("https://intra.epitech.eu/" + intra_info.autologin + "/user/notification/message?format=json", requestOptions)
        .then(response => response.text())
        .then(async(result) => {
            if (result) {
                var parsed = JSON.parse(result);
                if (!parsed || !parsed[0])
                    return;
                if (user.automation[auto_index].action.id === undefined || user.automation[auto_index].action.id === "" || parseInt(user.automation[auto_index].action.id) !== parseInt(parsed[0].id)) {
                    console.log("NEW MESSAGE RECEIVED");
                    user.automation[auto_index].action.id = parsed[0].id;
                    await user.save();
                    this.emit("reaction", user, auto_index, co_info, co_index);
                }
            } else
                console.log("NEXT TRACK");
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = newNotif;