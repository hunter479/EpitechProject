var fetch = require('node-fetch');
var FormData = require('form-data');
var mongoose = require('mongoose');
var User = require('../../../schema/schema_user');
const EventEmitter = require("events").EventEmitter;

class updateCredits extends EventEmitter {
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
        var intra_info = JSON.parse(user.automation[auto_index].action.data)
        fetch("https://intra.epitech.eu/" + intra_info.autologin + "/user/" + intra_info.email + "?format=json", requestOptions)
        .then(response => response.text())
        .then(async(result) => {
            console.log("HELLO");
            if (result) {
                var parsed = JSON.parse(result);
                console.log("Parsed:", parsed);
                if (!parsed || !parsed[0])
                    return;
                console.log("GPA: ", parsed.gpa);
                if (user.automation[auto_index].action.id === undefined || user.automation[auto_index].action.id === "" || parseInt(user.automation[auto_index].action.id) !== parseInt(parsed.credits)) {
                    console.log("NEW CREDITS RECEIVED. YOUHOUU");
                    user.automation[auto_index].action.id = parsed.credits;
                    await user.save();
                    this.emit("reaction", user, auto_index, co_info, co_index);
                }
            }
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = updateCredits;