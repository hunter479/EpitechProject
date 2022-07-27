var express = require('express');
var router = express.Router();
var ipaddr = require('ipaddr.js');
var date = new Date()

router.get('/', async (req, res) => {
    var ip = req.headers['x-forwarded-for'] || req.connection.remoteAddress;
    var to_ret = require('./sample.json')

    to_ret.client.host = ipaddr.process(ip).toString();
    to_ret.server.current_time = date.getTime();
    // console.log("ip = ", ipaddr.process(ip).toString());
    // console.log(date.getTime());
    res.send(to_ret)
});

module.exports = router