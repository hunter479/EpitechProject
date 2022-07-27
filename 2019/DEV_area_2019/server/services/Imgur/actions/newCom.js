var fetch = require('node-fetch');
var FormData = require('form-data');
var mongoose = require('mongoose');
var User = require('../../../schema/schema_user');
const EventEmitter = require("events").EventEmitter;
var Imgur = require("../Imgur");

class newCom extends Imgur(EventEmitter) {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        var myHeaders = new fetch.Headers();
        myHeaders.append("Authorization", "Bearer " + co_info.access_token);

        var formdata = new FormData();

        var requestOptions = {
            method: 'GET',
            headers: myHeaders,
            redirect: 'follow'
        };

        fetch("https://api.imgur.com/3/account/" + co_info.username + "/comments", requestOptions)
        .then(response => response.text())
        .then(async(result) => {
            var parsed = JSON.parse(result);
            if (parsed.status == 200) {
                console.log("OK comment");
                if (!parsed || !parsed.data[0])
                    return false;
                    console.log("PARSED INT FOR COM: " + parseInt(parsed.data[0].datetime));
                    console.log("USER AUTOMATION ID: " + user.automation[auto_index].action.id);
                    if (user.automation[auto_index].action.id === undefined || user.automation[auto_index].action.id === "" || parseInt(user.automation[auto_index].action.id) < parseInt(parsed.data[0].datetime)) {
                        console.log("UPDATING IN DB....");
                        user.automation[auto_index].action.id = parsed.data[0].datetime;
                        await user.save();
                        this.emit("reaction", user, auto_index, co_info, co_index);
                        return true;
                    }
                return false;
            } else if (parsed.status == 403) {
                this.gen_new_ref_token(user, auto_index, co_info, co_index);
                return true;
            } else
                return false;
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = newCom;