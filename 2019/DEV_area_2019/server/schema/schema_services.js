var mongoose = require('mongoose');

const schema = mongoose.Schema({
    nom : String,
    connection : Boolean,
});

module.exports = mongoose.model('services', schema);