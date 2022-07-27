var express = require('express');
var router = express.Router();
var User = require('../schema/schema_user');
var fetch = require('node-fetch');
var findService = require('../services/infoServices');
var crypto = require('crypto');
var OAuth = require('oauth-1.0a');


router.post('/add_service', async (req, res) => {
    let id = req.body.id;
    var info;
    var hasfound = false;
    var already_exist = false;
    let updatedUser = await User.findOne({id: id});
    if (!id || !updatedUser || !req.body.name || !req.body.code) {
        return res.status(400).send("ERROR 400 Missing argument in body need [id, name, code]");
    }
    if (req.body.code !== -42) {
        console.log('FIND SERVICE');
        info = await findService(req.body.name, req.body.code);
    } else {
        info = {
            access_token: req.body.access_token,
            refresh_token: req.body.refresh_token,
            username: req.body.username
        };
    }
    if (!info)
        return res.status(404).send("Auth file not found. Service probably does not exist.");
    if (!info.access_token || !info.refresh_token || !info.username)
        return res.status(400).send('Either access_token, refresh_token or username is missing.');
    updatedUser.connections.map(elem => {
        if (elem.name === req.body.name) {
            elem.info.map(map_info => {
                if (map_info.username === info.username) {
                    map_info = info;
                    already_exist = true;
                    return map_info;
                }
            })
            if (already_exist === false)
                elem.info.push(info);
            hasfound = true;
        } else {}
        return elem;
    });
    if (already_exist === true)
        return res.status(409).send('User already exist in database.');
    if (hasfound === true) {
        await updatedUser.save();
        return res.status(201).send('User correctly added to the database.');
    }
    connection = {
        name: req.body.name,
        info: []
    };
    connection.info.push(info);
    updatedUser.connections.push(connection);
    await updatedUser.save();
    res.status(201).send('Service and user correctly added to the database.');
});

router.delete('/:id', async(req, res) => {
    let id = req.params.id;
    let serviceName = req.body.serviceName;
    let username = req.body.username;
    if (!id || !serviceName || !username)
        return res.status(400).send("Error 400, either user, serviceName or username has not been defined.");
    let user = await User.findOne({id: id});
    if (!user)
        return res.status(404).send("The requested user was not found.");
    var i = 0;
    for(; i !== user.connections.length && user.connections[i].name !== serviceName; i += 1);
    if (i === user.connections.length)
        return res.status(404).send("serviceName does not exist.");
    else {
        var info = user.connections[i].info;
        for (i = 0; i !== info.length && info[i].username !== username; i += 1);
        if (i !== info.length) {
            info.splice(i, 1);
            await user.save();
            return res.status(200).send("Ressource has been deleted successfully.");
        } else
            return res.status(404).send("Username does not exist.");
    }
})

router.get('/twitter', async (req, res) => {
    console.log('IN connection/twitter/1');
    const oauth = OAuth({
    consumer: { key: 'gW37rGIJEmIkHzpBCBxJLcOYC', secret: 'kcbXOJxNeWlCXvcHS0NwcyXu23LdToO3cosWawWCPtZgoPyHBy' },
    signature_method: 'HMAC-SHA1',
    hash_function(base_string, key) {
        return crypto
            .createHmac('sha1', key)
            .update(base_string)
            .digest('base64')
    }});
    const request_data = {
        url: 'https://api.twitter.com/oauth/request_token',
        method: 'POST',
        data: { oauth_callback: 'https://www.area.com:8081/twitter' },
    }
    console.log('OUI', oauth.toHeader(oauth.authorize(request_data)));
    let options = {
        method: 'POST',
        redirect: 'follow',
        headers: oauth.toHeader(oauth.authorize(request_data))
    }
    await fetch('https://api.twitter.com/oauth/request_token', options).then(response => response.text()).then(async res => {
        console.log(res);
        ret = res;
    }).catch(err => console.error(err));
    return res.status(200).send(ret);
});

router.get('/:id/:service', async (req, res) => {
    let id = req.params.id;
    let serviceName = req.params.service;
    console.log("ID :", req.params.id, 'SERVICE : ' + req.params.service);
    let user = await User.findOne({id: id});
    console.log("USER = " + user);
    if (!user)
        return res.status(404).send("User not found.");
    for (let i = 0; i < user.connections.length; i++) {
        const elem = user.connections[i];
        if (elem.name === serviceName)
            return res.status(200).json(elem);
    }
    return res.status(200).send({info: []});
});

module.exports = router