var fetch = require('node-fetch');

let Facebook = function (superClass) {
    return class Facebook extends superClass {

    gen_new_ref_token(user, auto_index, co_info, co_index) {
        console.log("ACCESS TOKEN EXPIRED.");

        var client_id = "203866147425781";
        var client_secret = "f81a8ac23577767a3c81eb22702d45d8";
        var fb_exchange_token = co_info.access_token;

        fetch("https://graph.facebook.com/v6.0/oauth/access_token?grant_type=fb_exchange_token&client_id="+ client_id + "&client_secret=" + client_secret + "&fb_exchange_token=" + fb_exchange_token)
        .then(response => response.text())
        .then(async(result) => {
            var parsed = JSON.parse(result);
            co_info.refresh_token = parsed.access_token;
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

module.exports = Facebook;