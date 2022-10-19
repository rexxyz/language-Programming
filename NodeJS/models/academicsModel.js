const mongoose = require('mongoose');


const academicsSchema = new mongoose.Schema({
	branch:{
		type:String
	},
	year:{
		type:Number
	},
	semester:{
		type:Number
	},
	syllabus:{
		type:String
	},
	papers:{
		type:String
	}
});

const Academics = mongoose.model('Academics',academicsSchema);

module.exports = Academics;
