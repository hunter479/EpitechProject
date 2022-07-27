var fetch = require('node-fetch');
var Form = require('form-data');

module.exports = async function (code) {
    let body = new Form();
    body.append('code', code);
    body.append('grant_type', 'Authorization_code');
    body.append('client_id', '971ba623-d09d-40ab-9f46-29ad897dd88d');
    body.append('client_secret', 'mQ@aS93r=eESWvOPuR3prsxD.UP@J8Hm');
    body.append('redirect_uri', 'https://www.area.com:8081/microsoft');

    var requestOptions = {
        method: 'POST',
        redirect: 'follow',
        body: body
    }

    let username = String;
    let access_token = String;
    let refresh_token = String;
    let urlAccess = 'https://login.microsoftonline.com/901cb4ca-b862-4029-9306-e5cd0f6d9f86/oauth2/v2.0/token';
    console.log('RESQUEST ACCESS TOKEN IN YAMMER', urlAccess);
    await fetch(urlAccess, requestOptions).then(response => response.text()).then(async res => {
        console.log('RES', res);
        let parsed = JSON.parse(res);
        access_token = parsed.access_token;
        refresh_token = parsed.refresh_token;
        let myHeaders = new fetch.Headers();
        myHeaders.append('Authorization', 'Bearer ' + access_token);
        let options = {
            method: 'GET',
            redirect: 'follow',
            headers: myHeaders
        }
        await fetch('https://graph.microsoft.com/v1.0/me', options).then(response => response.text()).then(res => {
            console.log(res);
            let parsed = JSON.parse(res);
            console.log(parsed);
            username = parsed.displayName;
        });
        // username = parsed.user.full_name;
    });
    return ({username: username, access_token: access_token, refresh_token: refresh_token});
}