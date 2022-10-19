const express = require("express");
const userController = require("../controllers/userController");
const authController = require("../controllers/authContoller");

const router = express.Router();

//in routes ko upar hi rakha jata hai hamesa
router.route("/me").get(authController.protect,userController.getMe,userController.getUser);
router.route("/forgot-password").post(authController.forgotPassword);
router.route("/reset-password/:token").patch(authController.resetPassword);
router.route('/update-me').patch(authController.protect,userController.updateMe);
router.route('/update-password').patch(authController.protect,authController.updatePassword);
router.route('/delete-me').delete(authController.protect,userController.deleteMe);
router.route('/singleuser').get(authController.protect,userController.getSingleUser);


router.route("/signup").post(authController.signup);
router.route("/login").post(authController.login);
router.route("/logout").get(authController.logout);



//in routes ko jinme / ya /:id type ke ho inko neche rakha jata hai
router.route("/").get(userController.getAllUsers);
router.route("/:id")
    .get(userController.getUser)
    .patch(authController.protect,userController.updateUser)
    .delete(authController.protect,userController.deleteUser);








module.exports = router;
