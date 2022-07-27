var express = require('express');
var fetch = require('node-fetch');
var form = require('form-data');
var router = express.Router();
var crypto = require('crypto')
var OAuth = require('oauth-1.0a')

router.get('/', (req, res, next) => {

    const oauth = OAuth({
        consumer: { key: 'ltkhitU6dKP9aoidCe7asbXKn', secret: 'H6vwNDH7E8dbv8O9zmXdy54K9wmf14y50uUq5H7mb8jvgpwbcD' },
        signature_method: 'HMAC-SHA1',
        hash_function(base_string, key) {
            return crypto
                .createHmac('sha1', key)
                .update(base_string)
                .digest('base64')
        },
    });
    const request_data = {
        url: 'https://api.twitter.com/oauth/request_token',
        method: 'POST',
        data: { oauth_callback: 'https://www.area.com:8081/twitter' },
    }

    console.log('OUI', oauth.toHeader(oauth.authorize(request_data)));
    // console.log('Encoded string' , encodeURIComponent('http://localhost:3000/token'));
    // console.log('TimeStamp' , date);
    // let nounce = 'encoredequoirigoler';
    // let version = '1.0';
    // let realm = 'http://localhost:3000/token';
    let myHeaders = new fetch.Headers();
    myHeaders.append('Authorisation', oauth.toHeader(oauth.authorize(request_data)));

    let options = {
        method: 'POST',
        redirect: 'follow',
        headers: oauth.toHeader(oauth.authorize(request_data))
    }


    fetch('https://api.twitter.com/oauth/request_token', options).then(response => response.text()).then(async res => {
        console.log(res);
        // let parsed = JSON.parse(res);
    });

    return res.send('koukou');
});


module.exports = router;