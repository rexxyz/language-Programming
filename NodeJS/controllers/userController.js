const User = require("../models/userModel");


exports.getAllUsers = async (req, res) => {
  try {
    const users = await User.find()
    res.status(200).json({
      status: "Success",
      TotalUsers:users.length,
      users
    });
  } catch (err) {
    res.status(400).json({
      status: "Fail",
      message: err,
    });
  }
};

exports.getSingleUser = async(req,res) =>{
  try{
    const user = await User.findById(req.user.id).select('-password');  //req.user protect middleware se aa rha hai
    res.json(user);
  }catch(error){
    res.status(400).json({
      status:"fail",
      message:error
    })
  }
}



exports.getUser = async (req, res) => {
  try {
    const user = await User.findById(req.params.id);
    if(!user){
      return res.status(404).json({
        status:"fail",
        message:"There is no User with this id"
      });
    }
    res.status(200).json({
      status: "Success",
      user
    });
  } catch (err) {
    res.status(400).json({
      status: "Fail",
      message: err,
    });
  }
};


exports.updateUser = async (req, res) => {
  try {

    const user = await User.findByIdAndUpdate(req.params.id,req.body,{new:true});
    if(!user){
      return res.status(404).json({
        status:"fail",
        message:"There is no User with this id"
      });
    }
    res.status(200).json({
      status: "Success",
      user
    });
  } catch (err) {
    res.status(400).json({
      status: "Fail",
      message: err,
    });
  }
};

exports.deleteUser = async (req, res) => {
  try {
    const user = await User.findByIdAndDelete(re.params.id);
    if(!user){
      return res.status(404).json({
        status:"fail",
        message:"There is no User with this id"
      });
    }
    res.status(200).json({
      status: "Success",
      message: "User has been successfully deleted",
    });
  } catch (err) {
    res.status(400).json({
      status: "Fail",
      message: err,
    });
  }
};

//authcontroller.protect ke through hmare pass req.user aa gya hai then hum req.user.id ka use karke user
//find karenge and delete ka method lagayenge
exports.getMe = (req,res,next) =>{
  req.params.id = req.user.id
  console.log(req.params.id);
  next();
}


exports.deleteMe = async (req,res,next) =>{
  try{
    await User.findByIdAndDelete(req.user.id);
    res.status(200).json({
      message:"User has been deleted succcessfully",
      data:null
    });
  }catch(err){
    res.status(400).json({
      status:"fail",
      message:err
    })
  }
}

exports.updateMe = async(req,res,next) =>{
  try{
    if(req.body.password || req.body.passwordConfirm){
      return  res.status(500).json({
        status:"Fail",
        message:"this route is not for password update please use /update-password"
      });
    }

    await User.findByIdAndUpdate(req.user.id,req.body,{new:true})
    res.status(200).json({
      status:"success",
      msg:"Updated successfully"
    });

  }catch(err){
    res.status(400).json({
      status:"fail",
      "message":err
    })
  }
}




