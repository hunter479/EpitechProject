/*
*
* Module specially created for unit testing, please do not touch
*
*/

module.exports = async function (code, serviceName) {
    let username = String;
    let access_token = String;
    let refresh_token = String;

    if (code === 42)
        return ({username: 'test_username_2', access_token: 'test_access_token_2', refresh_token: 'test_refresh_token_2'});
    else
        return ({username: 'test_username_3', access_token: 'test_access_token_3', refresh_token: 'test_refresh_token_3'});
}