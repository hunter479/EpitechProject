const request = require('supertest');
const app = require('../app');
const mongoose = require('mongoose');
const {MongoClient} = require('mongodb');

class userTest {
    launchTest() {
        it('GET user informations /user/:id', async() => {
            const user = {
                "id":"usr_test",
                "username":"Test",
                "connections":[
                    { "name":"Weather", "info":[] },
                    { "name":"Riot Games", "info":[]}
                ],
                "automation":[],
            }
            const res = await (request(app).get('/user/usr_test'));
            expect(res.body).toMatchObject(user);
            expect(res.statusCode).toBe(200);
        })

        it('GET user does not exist /user/:id', async() => {
            const res = await (request(app).get('/user/usr_test_not_exist'));
            expect(res.text).toBe("User not found.");
            expect(res.statusCode).toBe(404);
        })

        it('DELETE user in db by id /user/delete/:id', async() => {
            const res = await (request(app).delete('/user/delete/usr_test'));
            expect(res.text).toBe("User usr_test deleted successfully.");
            expect(res.statusCode).toBe(200);
        })

        it('DELETE user does not exist /user/delete/:id', async() => {
            const res = await (request(app).delete('/user/delete/usr_test_not_exist'));
            expect(res.text).toBe("User not found.");
            expect(res.statusCode).toBe(404);
        })

        it('Reuploading user to db', async () => {
            const user = {
                id: 'usr_test',
                username: 'Test',
                connections: [{name: "Imgur", info: [{access_token: "at", refresh_token: "rt", username: "test"}]}],
                automation: []
            };
            const res = await (request(app).post('/register').send(user));
            expect(res.statusCode).toBe(201);
        });

        it ('POST automation value not set /user/automation/:id', async() => {
            const auto = {};
            const res = await (request(app).post('/user/automation/usr_test').send(auto));
            expect(res.text).toBe('Auto value is missing in body.');
            expect(res.statusCode).toBe(400);
        })

        it ('POST User not found /user/automation/:id', async() => {
            const auto = {};
            const res = await (request(app).post('/user/automation/usr_test_not_exist').send(auto));
            expect(res.text).toBe('User not found.');
            expect(res.statusCode).toBe(404);
        })

        it ('POST unvalid or uncomplete automation object /user/automation/:id', async() => {
            const body = { 
                auto: {
                    automation: {
                        test: ""
                    }
                }
            }
            body.auto = JSON.stringify(body.auto);
            const res = await (request(app).post('/user/automation/usr_test').send(body));
            expect(res.text).toBe('Automation object is not valid or complete.');
            expect(res.statusCode).toBe(400);
        })

        it ('POST unvalid stringify /user/automation/:id', async() => {
            const body = { auto: {
                    action: {
                        id: "",
                        data: "",
                        account: "None",
                        service: "Weather", //type of the service
                        trigger: "windSpeed",
                    }
                }
            }
            const res = await (request(app).post('/user/automation/usr_test').send(body));
            expect(res.text).toBe('Either the media is not supported or the stringify is wrong.');
            expect(res.statusCode).toBe(415);
        })

        it ('POST valid automation object /user/automation/:id', async() => {
            const body = { 
                auto: {
                    automation: {
                        action: {
                            id: "",
                            data: "",
                            account: "None",
                            service: "Weather", //type of the service
                            trigger: "windSpeed"
                        },
                        reaction: {
                            id: "",
                            data: "",
                            account: "None",
                            service: "Gmail",
                            trigger: "sendMail"
                        }
                    }
                }
            }
            body.auto = JSON.stringify(body.auto);
            const res = await (request(app).post('/user/automation/usr_test').send(body));
            expect(res.statusCode).toBe(201);
        })

        it ('DELETE query value is missing /user/automation/delete/:id', async() => {
            const query = {
                blob: ""
            }
            const res = await (request(app).delete('/user/automation/delete/usr_test').send(query));
            expect(res.text).toBe('Auto_id is missing.');
            expect(res.statusCode).toBe(400);
        })

        it ('DELETE user not found /user/automation/delete/:id', async() => {
            const body = {
                auto_id: 0
            }
            const res = await (request(app).delete('/user/automation/delete/usr_test_not_found?auto_id=0'));
            expect(res.text).toBe('User not found.');
            expect(res.statusCode).toBe(404);
        })

        it ('DELETE valide automation deletion /user/automation/delete/:id', async() => {
            const body = {
                auto_id: 0
            }
            const res = await (request(app).delete('/user/automation/delete/usr_test?auto_id=0'));
            expect(res.text).toBe('Automation 0 has been successfully deleted.');
            expect(res.statusCode).toBe(200);
        })
    }
}

module.exports = userTest;