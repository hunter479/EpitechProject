var express = require('express');
var router = express.Router();
var User = require('../schema/schema_user');

router.delete('/delete/:id', async(req, res, next) => {
    let id = req.params.id;
    var userToDelete = await User.findOne({id: id})
    if (!userToDelete)
        res.status(404).send("User not found.");
    else {
        await User.deleteOne({id: id});
        res.status(200).send("User " + id + " deleted successfully.");
    }
})

router.delete('/automation/delete/:id', async(req, res, next) => {
    let user = req.params.id;
    let auto_index = req.query.auto_id;
    if (!auto_index)
        return res.status(400).send("Auto_id is missing.");
    updatedUser = await User.findOne({id: user});
    if (!updatedUser)
        return res.status(404).send("User not found.");
    else {
        updatedUser.automation.splice(auto_index, 1);
        await updatedUser.save();
        res.status(200).send("Automation " + auto_index + " has been successfully deleted.");
    }
    return;
})

// router.patch('/automation/update/:id', async(req, res, next) => {
//     let id = req.params.id;
//     let index = req.body.index;
//     let automation = req.body.auto;
//     let updatedUser = await User.findOne({id: id});

//     if (!updatedUser)
//         return res.send("USER NOT FOUND");
//     parsed_auto = JSON.parse(automation);
//     if (!parsed_auto)
//         return res.status(400).send("Error in query");
//     updatedUser.automation[index] = parsed_auto.automation;
//     await updatedUser.save();
//     res.status(200).json(updatedUser);
// })

router.post('/automation/:id', async(req, res, next) => {
    let id = req.params.id;
    let automation = req.body.auto;
    let updatedUser = await User.findOne({id: id});

    if (!updatedUser)
        return res.status(404).send("User not found.");
    if (!automation)
        return res.status(400).send("Auto value is missing in body.")
    try {
        parsed_auto = JSON.parse(automation);
        // if (parsed_auto.automation.action)
        //     parsed_auto.automation.action.data = JSON.stringify(parsed_auto.automation.action.data);
        // // if (parsed_auto.automation.reaction)
        //     parsed_auto.automation.reaction.data = JSON.stringify(parsed_auto.automation.reaction.data);
        if (!parsed_auto.automation.action && !parsed_auto.automation.reaction)
            return res.status(400).send('Automation object is not valid or complete.');
    } catch (err) {
        console.log("ERR:", err);
        return res.status(415).send("Either the media is not supported or the stringify is wrong.");
    }
    updatedUser.automation.push(parsed_auto.automation);
    await updatedUser.save();
    res.status(201).json(updatedUser);
})

router.get('/:id', async(req, res, next) => {
    var id = req.params.id;
    const user = await User.findOne({id: id});
    if (!user)
        res.status(404).send("User not found.");
    else
        res.status(200).json(user);
})

module.exports = router;