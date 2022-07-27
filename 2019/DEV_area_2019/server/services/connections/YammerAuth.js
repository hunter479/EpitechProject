var fetch = require('node-fetch');
var Form = require('form-data');

module.exports = async function (code) {
    let username = String;
    let access_token = String;
    let urlAccess = 'https://www.yammer.com/oauth2/access_token?client_id=cl7coSDecOhvh08AkWKg&client_secret=NYiRPmCga3jdSvTQaX71fhGLH82op6JGwExGzfmH8k&code=' + code + '&grant_type=authorization_code';
    console.log('RESQUEST ACCESS TOKEN IN YAMMER', urlAccess);
    await fetch(urlAccess, {method: 'POST'}).then(response => response.text()).then(async res => {
        console.log('RES', res);
        let parsed = JSON.parse(res);
        access_token = parsed.access_token.token;
        username = parsed.user.full_name;
    });
    return ({username: username, access_token: access_token, refresh_token: "no need :-)"});
}