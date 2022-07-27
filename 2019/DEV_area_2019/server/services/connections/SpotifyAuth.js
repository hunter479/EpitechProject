var fetch = require('node-fetch');
var Form = require('form-data');
const { base64encode, base64decode } = require('nodejs-base64');

module.exports = async function (code, serviceName) {
    let username = String;
    let access_token = String;
    let refresh_token = String;
    let urlAccess = 'https://accounts.spotify.com/api/token?grant_type=authorization_code&code=' + code + '&redirect_uri=https%3A%2F%2Fwww.area.com%3A8081%2Fspotify';

    var myHeaders = new fetch.Headers();
    myHeaders.append("Content-Type", "application/x-www-form-urlencoded");
    myHeaders.append("Authorization", "Basic " + base64encode("4c9db4d390d54c04ab928d78c19ec1af:4f4920e43cda4c1eb97fe32e1c1f5648"));

    var requestOptions = {
        method: 'POST',
        headers: myHeaders,
        redirect: 'follow'
    };
    await fetch(urlAccess, requestOptions).then(response => response.text()).then(async res => {
        let parsed = JSON.parse(res);
        access_token = parsed.access_token;
        refresh_token = parsed.refresh_token;
        var secondHeaders = new fetch.Headers();
        secondHeaders.append("Authorization", "Bearer " + access_token);
        await fetch('https://api.spotify.com/v1/me', {method: 'GET', headers: secondHeaders}).then(response => response.text()).then(res => {
            console.log('RES SPOTIFY ACCOUNT: ', JSON.parse(res));
            let parsed = JSON.parse(res);
            username = parsed.display_name;
        }).catch(err => console.error(err));
    });
    return ({username: username, access_token: access_token, refresh_token: refresh_token});
}