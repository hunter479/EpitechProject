var TwitterClient = require('twitter');

let twitter = function (superClass) {
    return class Twitter extends superClass {
        ask(user, auto_index, co_info, co_index) {
            throw new Error('You need to implements ask method to your class');
        }

        getClient(access_token, secret_token) {
            return (new TwitterClient({
                consumer_key: 'gW37rGIJEmIkHzpBCBxJLcOYC',
                consumer_secret: 'kcbXOJxNeWlCXvcHS0NwcyXu23LdToO3cosWawWCPtZgoPyHBy',
                access_token_key: access_token,
                access_token_secret: secret_token
            }));
        }
    };
}

module.exports = twitter;