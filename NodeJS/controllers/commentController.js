const Comment = require('../models/commentsModel');

exports.getAllComment = async(req,res) =>{
	try{
		let filter = {};
		 if(req.params.blogId) filter = {blog:req.params.blogId}; //agar blogId hoga then bs 
															     //usi blog ka comment find krega
		const comments = await Comment.find(filter);
		res.status(200).json({
			status:"success",
			results:comments.length,
			data:comments
		});
	}catch(err){
		console.log(err);
		res.status(400).json({
			message:"Error occured code jumped to catch block"
		});
	}
	
}


exports.createComment = async(req,res,next) =>{
    try{
    	if(!req.body.blog) req.body.blog = req.params.blogId;
    	if(!req.body.user) req.body.user = req.user.id;
	const newComment = await Comment.create(req.body);

	res.status(201).json({
		status:"success",
		newComment
	});
	}catch(err){
		console.log(err);
		res.status(400).json({
			message:"Error occured code jumped to catch block"
		});
	}
}