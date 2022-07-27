var fetch = require('node-fetch');
var FormData = require('form-data');
var mongoose = require('mongoose');
var User = require('../../../schema/schema_user');
const EventEmitter = require("events").EventEmitter;
const Spotify = require("../spotify");

class nextTrack extends Spotify(EventEmitter) {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        var myHeaders = new fetch.Headers();
        myHeaders.append("Accept", "application/json");
        myHeaders.append("Content-Type", "application/json")
        myHeaders.append("Authorization", "Bearer " + co_info.access_token);

        var requestOptions = {
            method: 'POST',
            headers: myHeaders,
            redirect: 'follow'
        };
        fetch("https://api.spotify.com/v1/me/player/next", requestOptions)
        .then(response => response.text())
        .then(async(result) => {
            if (result) {
                var parsed = JSON.parse(result);
                if (parsed.error.status === 401) {
                    this.get_new_ref_token(user, auto_index, co_info, co_index);
                }
            } else
                console.log("NEXT TRACK");
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = nextTrack;