var fetch = require('node-fetch');
var FormData = require('form-data');
var mongoose = require('mongoose');
var User = require('../../../schema/schema_user');
const EventEmitter = require("events").EventEmitter;

class updateCommit extends EventEmitter {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        var myHeaders = new fetch.Headers();
        myHeaders.append("Content-Type", "application/json")
        myHeaders.append("access_token", co_info.access_token);
        var requestOptions = {
            method: 'GET',
            headers: myHeaders,
            redirect: 'follow'
        };
        gitlab_data = JSON.parse(user.automation[auto_index].action.data);
        fetch("https://gitlab.com/api/v4/projects/" + encodeURIComponent(gitlab_data.path) + "/repository/commits", requestOptions)
        .then(response => response.text())
        .then(async(result) => {
            var parsed = JSON.parse(result);
            var key = Date.parse(parsed[0].committed_date);
            console.log(parsed);
            console.log("Date Received from last commit: " + key);
            console.log("Date in db: " + user.automation[auto_index].action.id);
            if (user.automation[auto_index].action.id === undefined || user.automation[auto_index].action.id === "" || parseInt(user.automation[auto_index].action.id) < key) {
                console.log("NEW COMMITS HAS BEEN RECEIVE");
                user.automation[auto_index].action.id = key;
                await user.save();
                this.emit("reaction", user, auto_index, co_info, co_index);
            }
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = updateCommit;