var fetch = require('node-fetch');
var FormData = require('form-data');
var mongoose = require('mongoose');
var User = require('../../schema/schema_user');

let microsoft = function (superClass) {
    return class Microsoft extends superClass {

        gen_new_ref_token(user, auto_index, co_info, co_index) {
            console.log("ACCESS TOKEN EXPIRED.");
            var myHeaders = new fetch.Headers();

            var formdata = new FormData();
            formdata.append('grant_type', 'refresh_token');
            formdata.append('client_id', '971ba623-d09d-40ab-9f46-29ad897dd88d');
            formdata.append('client_secret', 'mQ@aS93r=eESWvOPuR3prsxD.UP@J8Hm');
            formdata.append('refresh_token', co_info.refresh_token);
            var requestOptions = {
                method: 'POST',
                headers: myHeaders,
                body: formdata,
                redirect: 'follow'
            };
            fetch("https://login.microsoftonline.com/901cb4ca-b862-4029-9306-e5cd0f6d9f86/oauth2/v2.0/token", requestOptions)
            .then(response => response.text())
            .then(async(result) => {
                var parsed = JSON.parse(result);
                co_info.access_token = parsed.access_token;
                co_info.refresh_token = parsed.refresh_token;
                co_info.username = parsed.account_username;
                user.connection[co_index] = co_info;
                console.log('[MICROSOFT NEW TOKEN SAVE]', co_info);
                await user.save();
                this.ask(user, auto_index, co_info, co_index);
                return;
            })
            .catch(error => console.log('error', error));
        }

        ask(user, auto_index, co_info, co_index) {
            throw new Error('You need to implements ask method to your class');
        }
    };
}

module.exports = microsoft;