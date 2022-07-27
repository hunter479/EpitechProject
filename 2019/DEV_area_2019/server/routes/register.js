var express = require('express');
var router = express.Router();
var User = require('../schema/schema_user');

/* GET users listing. */
router.post('/', async(req, res, next) => {
  const user = {
    id: req.body.id,
    username: req.body.username,
    connections: req.body.connections,
    automation: req.body.automation
  };
  if (!user.id || !user.username)
      return res.status(400).send('Bad request: missing an argument in body');
  try {
    const newUser = new User(user);
    await newUser.save();
    res.status(201).json(newUser);
  } catch (err) {
    console.log(err);
    res.status(409).send("E11000 duplicate key error collection: area.users index: id_1 dup key: { id:" + user.id + "}");
  }
  return;
})

module.exports = router;
