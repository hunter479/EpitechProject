var fetch = require('node-fetch');
var Form = require('form-data');

module.exports = async function (access_token) {
    let username = String;
    let urlAccess = 'https://graph.facebook.com/v6.0/me?access_token=' + access_token;
    console.log('RESQUEST ACCESS TOKEN IN FACEBOOK', urlAccess);
    await fetch(urlAccess, {method: 'GET'}).then(response => response.text()).then(async res => {
        console.log('[FACEBOOK]', res);
        let parsed = JSON.parse(res);
        refresh_token = parsed.refresh_token;
        username = parsed.name;
    });
    return ({username: username, access_token: access_token, refresh_token: 'null'});
}