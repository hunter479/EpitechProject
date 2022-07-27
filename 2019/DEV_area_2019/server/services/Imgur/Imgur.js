var fetch = require('node-fetch');
var mongoose = require('mongoose');
const { base64encode, base64decode } = require('nodejs-base64');

let Imgur = function(superClass) {
    return class Imgur extends superClass {

        gen_new_ref_token(user, auto_index, co_info, co_index) {
            console.log("ACCESS TOKEN EXPIRED.");
            var myHeaders = new fetch.Headers();
    
            var formdata = new FormData();
            formdata.append("refresh_token", co_info.refresh_token);
            formdata.append("client_id", "a12e84096da979d");
            formdata.append("client_secret", "ded8ab15f7e5daac822209ebca03382da24db32e");
            formdata.append("grant_type", "refresh_token");
    
            var requestOptions = {
                method: 'POST',
                headers: myHeaders,
                body: formdata,
                redirect: 'follow'
            };
            fetch("https://api.imgur.com/oauth2/token", requestOptions)
            .then(response => response.text())
            .then(async(result) => {
                var parsed = JSON.parse(result);
                co_info.access_token = parsed.access_token;
                co_info.refresh_token = parsed.refresh_token;
                co_info.username = parsed.account_username;
                for (c in user.connections) {
                    if (user.connections[c].name === user.automation[auto_index].action.service)
                        user.connections[c].info[co_index] = co_info;
                }
                await user.save();
                this.ask(user, auto_index, co_info, co_index);
                return;
            })
            .catch(error => console.log('error', error));
        }    

        ask(user, auto_index, co_info, co_index) {
            throw new Error("You need to implements the ask function");
        }
    }
}

module.exports = Imgur;