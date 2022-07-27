const request = require('supertest');
const app = require('../app');
const mongoose = require('mongoose');
const {MongoClient} = require('mongodb');

/*
 * Testing some endpoints
 */
// describe('init db', () => {
//   let connection;
//   let db;
//   let saveUser;
  
//   beforeAll(async () => {
//       console.log(process.env.MONGO_URL);
//     connection = await MongoClient.connect('mongodb://127.0.0.1:27017/area', {
//       useNewUrlParser: true,
//       useUnifiedTopology: true
//     });
//     db = await connection.db();
//     await db.createCollection('users', (err, res) => {
//       if (err) throw err;
//       console.log('lol c passé');
  
//       saveUser = res.findOne({id: 13}, (err, res) => {
//           if (err) console.log('user don\'t exist');
//           else console.log('user already exist');
//       });
//       res.deleteOne({id: 13}, (err, res) => {
//           if (err) throw err;
//           console.log('removed succesfully');
//       });
//     });
//   });
  
//   afterAll(async () => {
//     await db.createCollection('users', (err, res) => {
//       res.deleteOne({id: 13});
//       res.insertOne(saveUser);
//     });
//     console.log('lol');
//     await connection.close();
//   });
// })


describe('Endpoint Test', () => {
    // Testing '/users' endpoint
    console.log('this is in test');
    let connection;
    let db;
    let saveUser;
    
    beforeAll(async () => {
        console.log(process.env.MONGO_URL);
      connection = await MongoClient.connect('mongodb://127.0.0.1:27017/area', {
        useNewUrlParser: true,
        useUnifiedTopology: true
      });
      db = await connection.db();
      await db.collection('users').findOne({id: 13}, (err, res) => {
        if (err) console.log(err);
        else saveUser = res;
        console.log('users', saveUser);
      });
      await db.collection('users').deleteOne({id: 13});
    });
    
    afterAll(async () => {
      await db.collection('users').deleteOne({id: 13});
      await db.collection('users').insertOne(saveUser);
      connection.close();

      console.log('lol');
    });
    it('Testing get /register', async () => {
        const user = {
            id: 13,
            firstname: 'Aleks',
            lastname: 'Dems',
            mail: 'aleks@epitech.eu',
            username: 'Onaisuo',
            password: 'fn'
        };
        const res = await (request(app).post('/register').send(user));
        console.log('ouais ouais ouais');
        expect(res.body).toMatchObject(user);
        expect(res.statusCode).toBe(200);
    });
    // Testing '/home' endpoint
    it('Testing get /home', async () => {
        const res = await (request(app).get('/home'));
        expect(res.body).toMatchObject({});
        expect(res.statusCode).toBe(404);
    });

    it('Testing DELETE /user/delete/:id', async () => {
      const res = await (request(app).delete('/user/delete/13'));
      expect(res.text).toBe('User 13 deleted succesfully.');
      expect(res.statusCode).toBe(200);
      db.collection('users').insertOne(saveUser);
    });

    it('Testing GET /user/:id', async () => {
      const res = await request(app).get('/user/13');
      const res2 = await request(app).get('/user/-1');
      const user = {
        id: 13,
        firstname: 'Aleks',
        lastname: 'Dems',
        mail: 'aleks@epitech.eu',
        username: 'Onaisuo',
        password: 'fn'
      };
      expect(res2.statusCode).toBe(400);
      expect(res.body).toMatchObject(user);
      expect(res.statusCode).toBe(200);
    });

    it('Testing PUT /user/automation/:id', async () => {
      const query = {
        isAction: 1,
        index: 13,
        name: 'post',
        connection: 0,
        accessToken: '01010101011010',
        service: 'imgur',
        trigger: 'lol'
      }
      request(app).put('/user/automation/13').query(query).expect(200, (err, res) => {
        // TODO
      });
      query.isAction = 0;
      request(app).put('/user/automation/13').query(query).expect(200, (err, res) => {
        // TODO
      });
      request(app).put('/user/automation/13').query({}).expect(300, (err, res) => {
        expect(res.text).toBe('Missing params or query');
      });
    });

    it('Testing DEL /user/automation/delete/:id', async () => {
      request(app).delete('/user/automation/delete/0').query({id: 13}).expect(200, (err, res) => {
        // TO DO
      });
      request(app).delete('/user/automation/delete/0').query({id: -1}).expect(400, (err, res) => {
        // TO DO
      });
      request(app).delete('/user/automation/delete/0').expect(300, (err, res) => {
        // TO DO
      });
    });
    // Testing get /service on an empty list
    // it('Testing get /service', async () => {
    //     const res = await (request(app).get('/service'));
    //     console.log('GET', res.body);
    //     expect(res.body).toMatchObject([]);
    // });
    // // Testing post /service on an empty list
    // const _id = 0;
    // it('Testing post /service', async () => {
    //     const res = await (await (request(app).post('/service').send({nom: 'Aleks', connection: '0'})));
    //     console.log('POST',res.body);
    //     _id = res.body._id;
    //     expect(res.body).toMatchObject([]);
    // }, _id);
    // // Testing get /service on an empty list
    // it('Testing get /service:id', async () => {
    //     const res = await (request(app).get('/service'));
    //     console.log(res.body);
    //     // expect(res.body).toBe([]);
    // }, _id);
    // // Testing get /service on an empty list
    // it('Testing get /service', async () => {
    //     const res = await (request(app).get('/service'));
    //     console.log(res.body);
    //     // expect(res.body).toBe([]);
    // });
});

/*
 * Testing error 404 response
 */
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

/*
 * Wanted to test the error function in the app.js file
 */

// describe('Initialization errors', () => {
//     it('Try init', () => {
//     });
// });

afterAll(() => mongoose.disconnect());
