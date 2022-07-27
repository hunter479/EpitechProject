const request = require('supertest');
const app = require('../app');
const mongoose = require('mongoose');
const {MongoClient} = require('mongodb');

class connectionTest {

    launchTest() {
        this.postTest();
        this.getTest();
        this.deleteTest();
    }

    postTest() {
        it('POST missing argument on [/connection/add_service]', async () => {
            const body = {
                id: 'usr_test',
            };
            const res = await (request(app).post('/connection/add_service').send(body));
            expect(res.text).toBe("ERROR 400 Missing argument in body need [id, name, code]");
            expect(res.statusCode).toBe(400);
        });

        it('POST adding service and user with code equal to -42 on [/connection/add_service]', async () => {
            const body = {
                id: 'usr_test',
                name: 'Weather',
                code: -42,
                access_token: 'test_access_token',
                refresh_token: 'test_refresh_token',
                username: 'test_username'
            };
            const res = await (request(app).post('/connection/add_service').send(body));
            expect(res.text).toBe('Service and user correctly added to the database.');
            expect(res.statusCode).toBe(201);
        });

        it('POST adding service and user with code equal to -42 on [/connection/add_service]', async () => {
            const body = {
                id: 'usr_test',
                name: 'Riot Games',
                code: -42,
                access_token: 'test',
                refresh_token: 'test',
                username: 'test'
            };
            const res = await (request(app).post('/connection/add_service').send(body));
            expect(res.text).toBe('Service and user correctly added to the database.');
            expect(res.statusCode).toBe(201);
        });

        it('POST adding service and user with valid code on [/connection/add_service]', async () => {
            const body = {
                id: 'usr_test',
                name: 'Weather',
                code: 42,
            };
            const res = await (request(app).post('/connection/add_service').send(body));
            expect(res.text).toBe('User correctly added to the database.');
            expect(res.statusCode).toBe(201);
        });

        it('POST service already created, adding user on [/connection/add_service]', async () => {
            const body = {
                id: 'usr_test',
                name: 'Weather',
                code: 84,
            };
            const res = await (request(app).post('/connection/add_service').send(body));
            expect(res.text).toBe('User correctly added to the database.');
            expect(res.statusCode).toBe(201);
        });

        it('POST auth file does not exist on [/connection/add_service]', async () => {
            const body = {
                id: 'usr_test',
                name: 'Weather_not_exist',
                code: 84,
            };
            const res = await (request(app).post('/connection/add_service').send(body));
            expect(res.text).toBe("Auth file not found. Service probably does not exist.");
            expect(res.statusCode).toBe(404);
        });

        it('POST duplicate username on same service on [/connection/add_service]', async () => {
            const body = {
                id: 'usr_test',
                name: 'Weather',
                code: -42,
                access_token: 'test_access_token',
                refresh_token: 'test_refresh_token',
                username: 'test_username'
            };
            const res = await (request(app).post('/connection/add_service').send(body));
            expect(res.text).toBe('User already exist in database.');
            expect(res.statusCode).toBe(409);
        });

        it('POST adding service with no info if code is equal to -42 on [/connection/add_service]', async () => {
            const body = {
                id: 'usr_test',
                name: 'Weather',
                code: -42,
            };
            const res = await (request(app).post('/connection/add_service').send(body));
            expect(res.text).toBe('Either access_token, refresh_token or username is missing.');
            expect(res.statusCode).toBe(400);
        });
    }

    getTest() {
        it('GET info of service in db on [/connection/:id/:service]', async () => {
            var weather = {
                info: [
                    {
                        access_token: 'test_access_token',
                        refresh_token: 'test_refresh_token',
                        username: 'test_username'
                    },
                    {
                        access_token: 'test_access_token_2',
                        refresh_token: 'test_refresh_token_2',
                        username: 'test_username_2'
                    },
                    {
                        access_token: 'test_access_token_3',
                        refresh_token: 'test_refresh_token_3',
                        username: 'test_username_3'
                    },
                ],
                name: 'Weather'
            }
            const res = await (request(app).get('/connection/usr_test/Weather'));
            expect(res.body).toMatchObject(weather);
            expect(res.statusCode).toBe(200);
        });

        it('GET service does not exist on [/connection/:id/:service]', async () => {
            const res = await (request(app).get('/connection/usr_test/Weather_not_exist'));
            expect(res.body).toMatchObject({info: []});
            expect(res.statusCode).toBe(200);
        });

        it('GET user not found on [/connection/:id/:service]', async () => {
            const res = await (request(app).get('/connection/usr_test_not_exist/Weather'));
            expect(res.text).toBe("User not found.");
            expect(res.statusCode).toBe(404);
        });
    }

    deleteTest() {
        it('DELETE missing arguments on [/connection/:id]', async () => {
            const body = {
            }
            const res = await (request(app).delete('/connection/usr_test').send(body));
            expect(res.text).toBe("Error 400, either user, serviceName or username has not been defined.");
            expect(res.statusCode).toBe(400);
        });

        it('DELETE user not found on [/connection/:id]', async () => {
            const body = {
                serviceName: 'Weather',
                username: 'test_username_2'
            }
            const res = await (request(app).delete('/connection/usr_test_not_found').send(body));
            expect(res.text).toBe("The requested user was not found.");
            expect(res.statusCode).toBe(404);
        });

        it('DELETE service does not exist on [/connection/:id]', async () => {
            const body = {
                serviceName: 'Weather_not_exist',
                username: 'test_username_2'
            }
            const res = await (request(app).delete('/connection/usr_test').send(body));
            expect(res.text).toBe("serviceName does not exist.");
            expect(res.statusCode).toBe(404);
        });

        it('DELETE username does not exist on [/connection/:id]', async () => {
            const body = {
                serviceName: 'Weather',
                username: 'test_username_2_not_exist'
            }
            const res = await (request(app).delete('/connection/usr_test').send(body));
            expect(res.text).toBe("Username does not exist.");
            expect(res.statusCode).toBe(404);
        });

        it.each([{serviceName: 'Riot Games', username: 'test'}, {serviceName: 'Weather', username: 'test_username'}, {serviceName: 'Weather', username: 'test_username_2'}, {serviceName: 'Weather', username: 'test_username_3'}])('DELETE username of a service in db on [/connection/:id]', async (body) => {
            const res = await (request(app).delete('/connection/usr_test').send(body));
            expect(res.text).toBe("Ressource has been deleted successfully.");
            expect(res.statusCode).toBe(200);
        });

        it('GET service empty (with no info) in db on [/connection/:id/:service]', async () => {
            const res = await (request(app).get('/connection/usr_test/Weather'));
            expect(res.body).toMatchObject({info: []});
            expect(res.statusCode).toBe(200);
        });
    }
}

module.exports = connectionTest;