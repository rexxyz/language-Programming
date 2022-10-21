const Academics = require("../models/academicsModel");


exports.getAll = async(req,res) =>{
	try{
		const academics = await Academics.find();

		res.status(200).json({
			status:"success",
			results:academics.length,
			academics
		})

	}catch(err){
		res.status(500).send("SERVER ERROR")
	}
}

exports.singleBranch = async(req,res) =>{
	try{
		
		const branch = await Academics.find({
			branch:req.params.branch,
			semester:req.params.semester
		});
		if(!branch){
			res.status(404).json({
				msg:"There is no Branch related to this"
			})
		}
		res.status(200).json({
		status:"success",
		results:branch.length,
		branch
	});
	}catch(error){
		console.log(error)
	}
	
}

exports.updateSingleBranch = async(req,res) =>{
	try{
		if(req.user.role == "developer" || req.user.role =="admin"){
			const branch = await Academics.findOneAndUpdate({
			branch:req.params.branch,
			year:req.params.year,
			semester:req.params.semester},
			// console.log(branch);
			{syllabus:req.body.syllabus},  //bs syllabus input lenge so that only syllabus change ka 
			{new:true}					   // option hi rahe baki year waigrah koi change nahi kar paye
			);
		
		res.status(201).json({
			status:"success",
			branch
		});
		}else{
			res.status(400).json({
				status:"fail",
				message:"You are not assigned as developer to Update this"
			});
		}
		
	}catch(error){
		console.log(error);
		re.status(400).json({

			status:"Fail",
			message:error
		});
	}
}


exports.createOne = async(req,res) =>{
	try{
		const academics = await Academics.create(req.body);
		res.status(200).json({
			status:"success",
			academics
		});

	}catch(err){
		res.status(500).send("SERVER ERROR");
	}
}









