const express = require("express");
const authController = require('../controllers/authContoller');
const blogController = require("../controllers/blogController");

const commentRouter = require('../routes/commentRoute');     //yaha pe router.use as a middleware use krenge 															//jaisa app.js me kiya tha baki routes me
const router = express.Router();


router.use('/:blogId/comments',commentRouter); //comment router me request chala jayega
	


router.route('/top-5-blogs').get(blogController.topBlogs,blogController.getAllBlogs)

router.route('/').get(blogController.getAllBlogs)
router.route('/create-blog').post(authController.protect,blogController.createBlog);

// router.route('/:slug')
// 	.get(blogController.getBlog)   //isme findOneAndUpdate({slug:req.params.slug}) use krenge jisme object ki tarah 
// 	.patch(blogController.updateBlog)  //parameter pass krte hai eb.
	
	//in routes ko jinme / ya /:id type ke ho inko neche rakha jata hai
router.route('/single/:id')    //agar id se search karna chahte hain then ise use kr skte haint
 	.get(blogController.getSingleBlog)     //isme Blog.findByIdAndUpdate() use krenge
	.patch(blogController.updateSingleBlog)  
 	.delete(blogController.deleteSingleBlog);


 	
    
    



module.exports = router;
