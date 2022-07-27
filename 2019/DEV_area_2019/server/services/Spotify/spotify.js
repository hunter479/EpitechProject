var fetch = require('node-fetch');
var mongoose = require('mongoose');
const { base64encode, base64decode } = require('nodejs-base64');

let Spotify = function(superClass) {
    return class Spotify extends superClass {
        get_new_ref_token(user, auto_index, co_info, co_index) {
            console.log("Changing user access token for spotify");
            var myHeaders = new fetch.Headers();
            myHeaders.append("Content-Type", "application/x-www-form-urlencoded");
            myHeaders.append("Authorization", "Basic " + base64encode("4c9db4d390d54c04ab928d78c19ec1af:4f4920e43cda4c1eb97fe32e1c1f5648"));
    
            var requestOptions = {
                method: 'POST',
                headers: myHeaders,
                redirect: 'follow'
            };
            fetch("https://accounts.spotify.com/api/token?grant_type=refresh_token&refresh_token=" + co_info.refresh_token, requestOptions)
            .then(response => response.text())
            .then(async(result) => {
                var parsed = JSON.parse(result);
                co_info.access_token = parsed.access_token;
                user.connections.forEach(c => {
                    if (c.name === user.automation[auto_index].action.service)
                        c.info[co_index] = co_info;
                })
                await user.save();
                this.ask(user, auto_index, co_info, co_index);
            })
            .catch(error => console.log('error', error));    
        }

        ask(user, auto_index, co_info, co_index) {
            throw new Error("You need to implements the ask function");
        }
    };
    
}

module.exports = Spotify;