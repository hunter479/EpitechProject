const request = require('supertest');
const app = require('../app');
const mongoose = require('mongoose');
const {MongoClient} = require('mongodb');
const registerTestRequire = require('./registerTest');
const connectionTestRequire = require('./connectionTest');
const userTestRequire = require('./userTest');

describe('Register route test', () => {
    let connection;
    let db;
    let saveUser;
    
    beforeAll(async () => {
        connection = await MongoClient.connect('mongodb://127.0.0.1:27017/area', {
            useNewUrlParser: true,
            useUnifiedTopology: true
        });
        db = await connection.db();
        await db.collection('users').findOne({id: 'usr_test'}, async(err, res) => {
            if (err);
            else saveUser = res;
            if (!saveUser) {
                saveUser = {
                    id: 'usr_test',
                    username: 'Test',
                    connections: [],
                    automation: []
                };
            }
            console.log('users', saveUser);
        });
        await db.collection('users').deleteOne({id: 'usr_test'});
    });
    
    afterAll(async () => {
        // await db.collection('users').deleteOne({id: 'usr_test'});
        // await db.collection('users').insertOne(saveUser);
        connection.close();
    });

    const registerTest = new registerTestRequire();
    registerTest.launchTest();

    const connectionTest = new connectionTestRequire();
    connectionTest.launchTest();

    const userTest = new userTestRequire();
    userTest.launchTest();

});

describe('Error 404 test', () => {
    // Testing when we need to have a 404 response code
    it('Testing if 404 working', async () => {
        const res = await (request(app).get('/lol'));
        expect(res.statusCode).toBe(404);
    });
    // Testing when we don't want a 404 response code
    it('Testing not 404', async () => {
        const res = await (request(app).get('/'));
        expect(res.statusCode).toBe(404);
    });
});

afterAll(() => mongoose.disconnect());
