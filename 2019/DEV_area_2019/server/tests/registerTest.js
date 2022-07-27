const request = require('supertest');
const app = require('../app');
const mongoose = require('mongoose');
const {MongoClient} = require('mongodb');

class registerTest {

    launchTest() {
        it('Testing post /register', async () => {
            const user = {
                id: 'usr_test',
                username: 'Test',
                connections: [],
                automation: []
            };
            const res = await (request(app).post('/register').send(user));
            // expect(res.body).toMatchObject(user);
            expect(res.statusCode).toBe(201);
        });
        
        it('Testing post /register', async() => {
            const user = {
                connections: [],
                automation: []
            }
            const res = await (request(app).post('/register').send(user));
            expect(res.text).toBe('Bad request: missing an argument in body');
            expect(res.statusCode).toBe(400);
        })
    
        it('Testing post /register', async() => {
            const user = {
                id: 'usr_test',
                username: 'Test',
                connections: [],
                automation: []
            }
            const res = await (request(app).post('/register').send(user));
            expect(res.text).toBe("E11000 duplicate key error collection: area.users index: id_1 dup key: { id:" + user.id + "}");
            expect(res.statusCode).toBe(409);
        })
    }
}

module.exports = registerTest;