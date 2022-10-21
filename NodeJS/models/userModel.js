const mongoose = require("mongoose");
const validator = require("validator");
const bcrypt = require('bcrypt');
const crypto = require("crypto");  //This is built in in node_module


const userSchema = new mongoose.Schema({
  name: {
    type: String,
    required: [true, "A Name Is Required"],
  },
  email: {
    type: String,
    unique:true,
    required: [true, "An E-mail is Required"],
  },
  password: {
    type: String,
    required: [true, "A Password is Required"],
    minLength: 8,
    select: false,
  },
  passwordConfirm: {
    type: String,
    required: [true, "Please Enter the Confirm Password"],
    select: false,
    validate: {
      validator: function (el) {
        return el === this.password;
      },
      message: "Password Do Not Match",
    },
  },
  // gender: {
  //   type: String,
  //   required: [true, "Please Select Your gender"],
  // },
  role:{
    type:String,
    enum:['user','developer','admin'],
    default:'user'
  },
  avatar: {
    type: String,
  },
  active:{
    type:Boolean,
    default: true,
    select:false
  },
  passwordChangedAt:String,
  passwordResetToken:String,
  passwordResetExpires:Date

});

//hashing the password before saving it to database
userSchema.pre('save',async function(next){
  if(!this.isModified('password')) return next();

  this.password = await bcrypt.hash(this.password,12);
  this.passwordConfirm = undefined;  //undefined kr dene se ye database me save nahi hoga
  next();

});


//checking the password it matches or not to inputted password
userSchema.methods.correctPassword = async function(candidatePassword,userPassword){
  return await bcrypt.compare(candidatePassword,userPassword)
};


//password changed after token issued checking method
userSchema.methods.changedPasswordAfter = function(JWTTimestamp){
  if(this.passwordChangedAt){
    const changedTimeStamp = parseInt(this.passwordChangedAt.getTime() / 1000,10);
    return JWTTimestamp < changedTimeStamp;
  }
  return false;
}


//creating token for forget password
userSchema.methods.createPasswordResetToken = function(){
  //creating the reset token
  const resetToken = crypto.randomBytes(32).toString('hex');

  //hashing the token
  this.passwordResetToken = crypto.createHash('sha256').update(resetToken).digest('hex');
  console.log({resetToken},this.passwordResetToken);

  //setting the token expire time
  this.passwordResetExpires = Date.now() + 15 *60*1000;

  return resetToken;

}

const User = mongoose.model("User", userSchema);
module.exports = User;
