var fetch = require('node-fetch');
var Form = require('form-data');

module.exports = async function (code) {
    let username = String;
    let access_token = String;
    let refresh_token = String;
    let urlAccess = 'https://api.imgur.com/oauth2/token' + code + '';
    console.log('RESQUEST ACCESS TOKEN IN GITLAB', urlAccess);
    await fetch(urlAccess, {method: 'POST'}).then(response => response.text()).then(async res => {
        console.log('RES', res);
        let parsed = JSON.parse(res);
        access_token = parsed.access_token;
        refresh_token = parsed.refresh_token;
        let urlInfos = 'https://' + access_token;
        await fetch(urlInfos, {method: 'GET'}).then(response => response.text()).then(res => {
            console.log('RES', JSON.parse(res));
            let parsed = JSON.parse(res);
            username = parsed.username;
        }).catch(err => console.error(err));
    });
    return ({username: username, access_token: access_token, refresh_token: refresh_token});
}