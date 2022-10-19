const nodemailer = require('nodemailer');
const nodemailerSendgrid = require('nodemailer-sendgrid');


const sendEMail = async options =>{
	//create a transporter

	// const transporter = nodemailer.createTransport({
	// 	 host: 'smtp.mail.yahoo.com',
 //            port: 465,
 //            service:'yahoo',
 //            secure: false,
 //   			//Gmail and yahoo jaise kuchh operators ka host waigrah define rehta hai pehle se
	// 	auth:{				//lekin third party ka use krenge to host and port define krna prta hai
	// 		user:process.env.EMAIL_USERNAME,
	// 		pass:process.env.EMAIL_PASSWORD
	// 	},
	// 	 debug: false,
 //            logger: true
		//IN GMAIL  activate less secure options
	// });

	//creating transporter using api key
	const transporter = nodemailer.createTransport(
    nodemailerSendgrid({
        apiKey: process.env.SENDGRID_API_KEY
    })
);

	//define the email options
	const mailOptions = {
		from:'hosteZON <hostezon@yahoo.com>',
		to:options.email,
		subject:options.subject,
		text:options.message
		//html if we want then html code bhi bhej skte hain
	}

	//Actually send the mail

	await transporter.sendMail(mailOptions);

};

module.exports = sendEMail;
