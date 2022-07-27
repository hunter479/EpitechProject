var crypto = require('crypto');
var OAuth = require('oauth-1.0a');
var fetch = require('node-fetch');
var FormData = require('form-data');

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
    url: 'https://api.twitter.com/1.1/statuses/update',
    method: 'POST',
    data: {
        status: 'I fuck Nick'
    }
}

let token = {
    key: '2980921674-Oiov9FB6BfVmdVCdpUORzMEdcUYEnLCg7pOduaG',
    secret: 'iyBlTO4eo25E1LKgisvBr89acz60iDfpDkIWWPTjSAnHG'
}

let options = {
    method: 'POST',
    headers: oauth.toHeader(oauth.authorize(request_data, token))
}

// Dependencies
// const request = require('request')
// const OAuth = require('oauth-1.0a')
// const crypto = require('crypto')
 
// // Initialize
// const oauth = OAuth({
//     consumer: { key: 'gW37rGIJEmIkHzpBCBxJLcOYC', secret: 'kcbXOJxNeWlCXvcHS0NwcyXu23LdToO3cosWawWCPtZgoPyHBy' },
//     signature_method: 'HMAC-SHA1',
//     hash_function(base_string, key) {
//         return crypto
//             .createHmac('sha1', key)
//             .update(base_string)
//             .digest('base64')
//     },
// })
 
// const request_data = {
//     url: 'https://api.twitter.com/1.1/statuses/update.json?include_entities=true',
//     method: 'POST',
//     data: { status: 'Hello Ladies + Gentlemen, a signed OAuth request!' },
// }
 
// // Note: The token is optional for some requests
// // const token = {
// //     key: '370773112-GmHxMAgYyLbNEtIKZeRNFsMKPR9EyMZeS9weJAEb',
// //     secret: 'LswwdoUaIvS8ltyTt5jkRh4J50vUPVVHtR2YPi5kE',
// // }
 
// request(
//     {
//         url: request_data.url,
//         method: request_data.method,
//         form: oauth.authorize(request_data, token),
//     },
//     function(error, response, body) {
//         console.log(response);
//         // Process your data here
//     }
// )
var Twitter = require('twitter');
 
var client = new Twitter({
  consumer_key: 'gW37rGIJEmIkHzpBCBxJLcOYC',
  consumer_secret: 'kcbXOJxNeWlCXvcHS0NwcyXu23LdToO3cosWawWCPtZgoPyHBy',
  access_token_key: '1232609700828590081-dUaihWqqUlV46Aj2U3MYUXwk2vGF1s',
  access_token_secret: '2IiZrrU4RMBBbIXItk5dDHq13o2KRxcMKLOefAmLTNmZj'
});


client.get('statuses/show/1233320327351955456', {q: 'meowri'}, function(err, tweet, response) {
    if (err) console.error(err);
    else console.log(tweet);
});

client.post('statuses/retweet/1233320327351955456', '', function(err, tweet, response) {
    if (err) console.error(err);
    else console.log(tweet);
});

