const User = require("../models/userModel");
const jwt = require('jsonwebtoken');
const {promisify} = require('util');
const crypto = require('crypto');
const sendEmail = require('../utils/email');


exports.signup = async (req, res) => {
  try {
    const newUser = await User.create({
      name:req.body.name,
      email:req.body.email,
      password:req.body.password,
      passwordConfirm:req.body.passwordConfirm,
      gender:req.body.gender,
      role:req.body.role,
      avatar:req.body.avatar
    });
    const token = jwt.sign({id:newUser._id},process.env.JWT_SECRET,{
      expiresIn:process.env.EXPIRES_IN
    });
    res.status(201).json({
      status:"success",
      token,
      data:{newUser}
    });
  } catch (err) {
    res.status(400).json({
      status: "fail",
      message: err,
    });
  }
};



exports.login = async (req, res, next) => {
  try {
    const {email, password} = req.body;
    if(!email || !password){
      return res.status(404).json({
        status:"fail",
        message:"No User or Password"
      });
         }
    const user = await User.findOne({email:email}).select('+password');

    if(!user || !(await user.correctPassword(password,user.password))){
      return res.status(403).json({
        status:"fail",
        message:"email or password is incorrect"
      });
    }
    const token = jwt.sign({id:user._id},process.env.JWT_SECRET,{
      expiresIn:process.env.EXPIRES_IN
    });
    res.status(200).json({
      status:"success",
      token,
      
    });

    next();

  } catch (err) {
    res.status(400).json({
      status: "fail",
      message: err,
    });
  }
};

exports.logout = (req, res) => {
  res.cookie('jwt', 'loggedout', {
    expires: new Date(Date.now() + 10 * 1000),
    httpOnly: true
  });
  res.status(200).json({ status: 'logged out successfully' });
};



exports.protect = async (req, res, next) => {
  try {
    let token;
    // if(req.headers.authorization && req.headers.authorization.startsWith('Bearer')){
    //   token = req.headers.authorization.split(' ')[1];  
    //}   //ye method use krenge jab Authorization Bearer token wala method use krenge

    token = req.header('x-auth-token');  //is wale method me x-auth-token header ke through token le rhe hai
    //token lene ka tarika change hua hai baki sb same hai

    if(!token){
      return res.status(404).json({
        status:"fail",
        message:"Token not found"
      });
    }
    // console.log("token found");

    //verifying token and extracting info about user
    const decoded = await promisify(jwt.verify)(token,process.env.JWT_SECRET)

    //now getting info about user who is logging through this token
    const currentUser = await User.findById(decoded.id)
    // console.log(currentUser);
    if(!currentUser){
      return res.status(404).json({
        status:"fail",
        message:"User not found"
      });
    };

    //watching if password changed after token was issued
    if(currentUser.changedPasswordAfter(decoded.iat)){
      return res.status(401).json({
        status:"fail",
        message:"passsword changed please login again"
      })
    }
   
  req.user = currentUser;
  // console.log("req finished of protect");
  next();

  } catch (err) {
    res.status(400).json({
      status: "fail",
      message: err,
    });
  }
};



//in dono middlewares controllers ke jagah protect middleware hi kaam aayega usi se req.user.role extract kar
//lenge jahan jaroorat hogi

// exports.isAdmin = async(req,res,next) =>{
//   try{
//     if(req.user.role === 'admin'){
//       console.log("user is admin")
//       next();
//     }else{
//       res.status(400).json({
//         status:"fail",
//         message:"You are not the admin of this website"
//       })
//     }
//   }catch(err){
//     res.status(400).json({
//       status:"Fail",
//       message:err
//     })
//   }

// }

// exports.isDeveloper = async(req,res,next) =>{
//   try{
//     if(req.user.role === 'developer'){
//       console.log("user is developer")
//       next();
//     }else{
//       res.status(400).json({
//         status:"fail",
//         message:"You are not a developer of this website"
//       });
//     }
//   }catch(err){
//     res.status(400).json({
//       status:"Fail",
//       message:err
//     })
//   }

// }


exports.updatePassword = async(req,res,next) =>{
  try{
    const user = await User.findById(req.user).select('+password');

    //matching the password with old saved password
    if(!(await user.correctPassword(req.body.passwordCurrent,user.password))){
      return res.status(400).json({
        status:"fail",
        message:"password did not match"
      })
    }
    user.password = req.body.password;
    user.passwordConfirm = req.body.passwordConfirm;
    await user.save();

    const token = jwt.sign({id:user._id},process.env.JWT_SECRET,{
      expiresIn:process.env.EXPIRES_IN
    });
    res.status(200).json({
      status:"success",
      token,
    });



  }catch(err){
    res.status(400).json({
      status:"fail",
      message:err
    });
  }
}



exports.forgotPassword = async (req,res,next) =>{
//getting user
const user = await User.findOne({email:req.body.email});
if(!user){
  return res.status(404).json({
    status:"fail",
    message:"No user found with this email"
  });
}

//generating reset resetToken
const resetToken = user.createPasswordResetToken();
await user.save({validateBeforeSave:false})

//creating email content
const resetUrl = `${req.protocol}://${req.get('host')}/hostezon/v1/users/reset-password/${resetToken}`;
const message = `Forgot your password Click here to Reset ${resetUrl}.\n if You dont  then ignore`;


try{

  //sending email to user
  await sendEmail({
    email:user.email,
    subject:"Your Password reset token",
    message
  });

  res.status(200).json({
    status:"success",
    message:"Reset Token sent to your email"
  })
}catch(err){
  console.log(err);
  user.passwordResetToken = undefined;
  user.passwordResetExpires = undefined;
  res.status(400).json({
    status:"fail",
    message:err
  });
}


};

//reset password controller
exports.resetPassword = async (req,res,next) =>{
  try{

    //encrypting our token to match with database stored passwordresetToken
    const hashedToken = crypto.createHash('sha256').update(req.params.token).digest('hex');
   
    //getting user by hashed token
    const user = await User.findOne({
      passwordResetToken:hashedToken,passwordResetExpires:{$gte:Date.now()}
    });

    if(!user){
      return res.status(404).json({
        status:"fail",
        message:"User not found"
      });
    }


    //setting the new password
    user.password = req.body.password;
    user.passwordConfirm = req.body.passwordConfirm;
    user.passwordResetToken = undefined;
    user.passwordResetExpires = undefined;

    await user.save();


    const token = jwt.sign({id:user._id},process.env.JWT_SECRET,{
    expiresIn:process.env.EXPIRES_IN
    });


    res.status(200).json({
    status:"success",
    token,
    message:"password successfully changed"
    });



  }catch(err){
    console.log(err);
    res.status(400).json({
      status:"fail",
      message:err
    });
  }

}

