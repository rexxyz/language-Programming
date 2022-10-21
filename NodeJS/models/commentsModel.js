const mongoose = require('mongoose');

const commentSchema = new mongoose.Schema({
	comment:{
		type:String,
		minlength:[5,"A comment must have atleast 5 characters "]
	},
	rating:{
		type:Number,
		min: 1,
      	max: 10
	},
	cratedAt:{
		type:Date,
		Default:Date.now()
	},
	blog: {
      type: mongoose.Schema.Types.ObjectId,
      ref: 'Blog',
      required: [true, 'Comment must belong to a tour.']
    },
    user: {
      type: mongoose.Schema.Types.ObjectId,
      ref: 'User',
      required: [true, 'comment must belong to a user']
    }

    
    
   

},
	{
        toJSON:{virtuals:true},
        toObject:{virtuals:true}
    }
);

commentSchema.pre(/^find/,function(next){
	// this.populate({
	// 	path:'blog',
	// 	select:'title'     			//ye basically blogs and user dono ko populate krne ke liye hai
	// }).populate({	   			// lekin jb comment virtual populate kr rhe hain then blog phr se 
	// 	path:'user',	  			// populate ho ja rha hai isiliye sirf user ko populate kiye 
	// 	select:'name email role'   // lekin as a refrence ye code comment kiye jisse dono ek sath 
	// })						  // populte kr skte hain.

	this.populate({
		path:'user',
		select:'name email role'
	})
	next();
})

const Comment = mongoose.model('Comment',commentSchema);

module.exports = Comment;