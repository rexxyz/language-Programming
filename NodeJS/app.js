const express = require("express");
const morgan = require('morgan');

//security
const rateLimit = require('express-rate-limit');
const helmet = require('helmet');
const mongoSanitize = require('express-mongo-sanitize');
const xss = require('xss-clean');

//routes
const userRouter = require("./routes/userRoute");
const blogRouter = require("./routes/blogRoute");
const commentRouter = require('./routes/commentRoute');
const academicsRouter = require("./routes/academicsRoute");




const app = express(); //all functions of express in app
app.use(express.json()); //very necessary

app.use(mongoSanitize()); //data sanitization prevents sql injection

app.use(xss()); //data sanitization against xss;

//MIDDLEWARES
if(process.env.NODE_ENV="development"){
	app.use(morgan('dev'));
}

//Security Middlewares
app.use(helmet());

const limiter = rateLimit({
	max:100, //maximum requests you can keep accordingly size to your app
	windowMs:60*60*1000,
	message:"Too Many Requests from this IP Please try again in an hour"
});

app.use('/app',limiter); //hostezon ke baad se harek url pe ye apply ho gya

//for making request without error with react
//in official language called cors error handling
app.use((req,res,next) =>{
	//res.header("Access-Control-Allow-Credentials","true");
	res.header("Access-Control-Allow-Origin","*");
	res.header("Access-Control-Allow-Headers","Origin, X-Requested-With,x-auth-token, Content-Type, Accept,Authorization");
	res.header("Access-Control-Allow-Methods","GET,OPTIONS,POST,PUT,PATCH,DELETE");
	next();
});


app.get("/", (req, res) => {
  res.send("Hostezon (v1.0) Backend by - Tej Pratap");
});


//all router files
app.use("/app/v1/users", userRouter);      	//common users
app.use("/app/v1/blogs", blogRouter);  		//hosteZON-blogs
app.use("/app/v1/comments",commentRouter);		//comment router
app.use("/app/v1/academics",academicsRouter);  //hosteZON-academics



module.exports = app;
