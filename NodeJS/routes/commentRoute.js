const express = require('express');
const commentController = require('../controllers/commentController');
const authController = require('../controllers/authContoller');



const router = express.Router({mergeParams:true});  //mergeParams:true kiye taki
													// /:blogId yaha pe accesible ho ske

router.route('/')
.get(commentController.getAllComment)
.post(authController.protect,commentController.createComment);



module.exports = router;














