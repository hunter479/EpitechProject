var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var cors = require('cors');

var userRouter = require('./routes/user');
var serviceRouter = require('./routes/service');
var registerRouter = require('./routes/register');
var connection = require('./routes/connection');
var about = require('./routes/about/about');

const automation = require('./services/automation');
const CronJob = require('cron').CronJob;
const mongoose = require('mongoose');
const body = require('body-parser');

var app = express();

const job = new CronJob('*/20 * * * * *', function() {
	const d = new Date();
  automation();
});
job.start();

// mongoose.connect('mongodb://127.0.0.1:27017/area', {useNewUrlParser: true});
mongoose.connect('mongodb://db.area:27017/area', {useNewUrlParser: true});

app.use(body.urlencoded({extended: true}));
app.use(body.json());
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');

app.use(body());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/user', userRouter);
app.use('/register', registerRouter);
app.use('/service', serviceRouter);
app.use('/connection', connection);
app.use('/about.json', about);
// catch 404 and forward to error handler

app.listen(8080);

app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;