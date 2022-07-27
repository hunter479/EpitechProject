var fetch = require('node-fetch');
var Form = require('form-data');
var queryString = require('querystring');

module.exports = async function (oauth) {
    let username = String;
    console.log(oauth);
    let oauth_token = oauth.split(':')[0];
    let oauth_verifier = oauth.split(':')[1];
    let oauth_token_secret;
    let urlAccess = 'https://api.twitter.com/oauth/access_token?oauth_consumer_key=gbDOUAAAAAABCobZAAABcHc174M&oauth_token=' + oauth_token + '&oauth_verifier=' + oauth_verifier;
    console.log('RESQUEST ACCESS TOKEN IN TWITTER', urlAccess);
    await fetch(urlAccess, {method: 'POST'}).then(response => response.text()).then(async res => {
        console.log('[Twitter]', res);
        let parsed = queryString.parse(res);
        access_token = parsed.oauth_token;
        oauth_token_secret = parsed.oauth_token_secret;
        console.log('[Twitter]', oauth_token_secret);
        username = parsed.screen_name;
    });
    return ({username: username, access_token: access_token, refresh_token: oauth_token_secret});
}