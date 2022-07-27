var fetch = require('node-fetch');

module.exports = async function (code) {
    let username = String;
    let access_token = String;
    let refresh_token = String;
    let urlAccess = 'https://gitlab.com/oauth/token?client_id=3dea71e60ed478864d409ca1aee82d5ecd4f4234dc3621d46e15d240beaa9faa&client_secret=f3b5b9f7c84f591c8ef9cf65f32007d5cfe2926e8d19b411b92db76bb85dc0e6&code=' + code + '&grant_type=authorization_code&redirect_uri=https://www.area.com:8081/gitlab';
    console.log('RESQUEST ACCESS TOKEN IN GITLAB', urlAccess);
    await fetch(urlAccess, {method: 'POST'}).then(response => response.text()).then(async res => {
        console.log('RES', res);
        let parsed = JSON.parse(res);
        access_token = parsed.access_token;
        refresh_token = parsed.refresh_token;
        let urlInfos = 'https://gitlab.com/api/v4/user?access_token=' + access_token;
        await fetch(urlInfos, {method: 'GET'}).then(response => response.text()).then(res => {
            console.log('RES', JSON.parse(res));
            let parsed = JSON.parse(res);
            username = parsed.username;
        }).catch(err => console.error(err));
    });
    return ({username: username, access_token: access_token, refresh_token: refresh_token});
}