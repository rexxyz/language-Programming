const Blog = require('../models/blogModel');
const Comment = require('../models/commentsModel');

const slugify = require('slugify');

exports.topBlogs = async(req,res,next) =>{
    req.query.limit='5';
    req.query.sort='-views'; //jiska views jyada rahega wo upar aur phr waise hi dheere dheere neeche
    next();
}


exports.getAllBlogs = async (req,res) =>{
    try{

        //api features

        //getting query
        const queryObj = {...req.query};

        const excludedFields = ['page', 'sort', 'limit', 'fields'];
        excludedFields.forEach((el) => delete queryObj[el]);

        //filtering query
        let queryStr = JSON.stringify(queryObj);
        queryStr = queryStr.replace(/\b(gte|gt|lte|lt)\b/g, match => `$${match}`);

        //main query executing from here
        //parsing is necessary otherwise query become undefined
        let query = Blog.find(JSON.parse(queryStr));

        //sorting
        if(req.query.sort){
            query = query.sort(req.query.sort);
        }

        //limitting fields
        if(req.query.fields){
            const fields = req.query.fields.split(',').join(' ');
            query = query.select(fields)
        }else{
            query = query.select('-_v');
        }

        //pagination
        const page = req.query.page * 1 || 1;
        const limit = req.query.limit * 1 || 20;
        const skip = (page - 1) * limit;
        query = query.skip(skip).limit(limit);


        const blogs = await query;
        res.status(200).json({
            status:"success",
            results:blogs.length,
            blogs
        })
    }catch (error) {
        res.status(400).json({
            status:"fail",
            message:"Error occured code directly runs in catch block",
            Error:error
        })
    }
}

exports.createBlog = async (req,res) =>{
    try{
        const blog = await Blog.create({
            title:req.body.title,
            slug:slugify(req.body.title,{
                lower:true
            }),
            body:req.body.body,
            category:req.body.category,
            views:req.body.views,
            rating:req.body.rating,
            tags:req.body.tags,
            createdAt:req.body.createdAt,
            createdBy:req.user.id


        });

    res.status(201).json({
        status:"success",
        blog
    });

    }catch (error) {
        res.status(400).json({
            status:"fail",
            message:"Error occured code directly runs in catch block",
            Error:error
        })
    }
}



exports.getSingleBlog = async (req,res) =>{
    try{

        const blog = await Blog.findById(req.params.id).populate('comments');
        //const blog = await Blog.findOne({slug:req.params.slug});
        //second method to find by name, slug or something

        // yaha se bhi populate kar skte hain  .populate('createdBy') laga ke
        //bt createdBy direct blog model se populate ho rha hai



        // console.log(blog);
        // res.json({blog});
        res.status(200).json({
            status:"succc555ess",
            blog
        });

    }catch (error) {
        res.status(400).json({
            status:"fail",
            message:"Error occured code directly runs in catch block",
            Error:error
        });
    }
}

exports.updateSingleBlog = async (req,res) =>{
    try{
         // console.log(req.params.slug);
        const blog = await Blog.findByIdAndUpdate(req.params.id,req.body,{new:true});
        //second method to update by name or something like that
        // const blog = await Blog.findOneAndUpdate(req.params.slug,
        //     {title:req.body.title,
        //     slug:slugify(req.body.title,{
        //         lower:true
        //     }),
        //     body:req.body.body,
        //     category:req.body.category,
        //     tags:req.body.tags
        //     },
        //     {new:true});
        // console.log(blog);
        // res.json({blog});
        res.status(200).json({
            status:"succc555ess",
            blog
        });

    }catch (error) {
        res.status(400).json({
            status:"fail",
            message:"Error occured code directly runs in catch block",
            Error:error
        });
    }
}


exports.deleteSingleBlog = async (req,res) =>{
    try{
         // console.log(req.params.slug);
        const blog = await Blog.findByIdAndDelete(req.params.id);
        //second method to delete by name or something like that
        //const blog = await Blog.findOneAndDelete(req.params.slug);

        // console.log(blog);
        // res.json({blog});
        res.status(200).json({
            status:"succc555ess",

        });

    }catch (error) {
        res.status(400).json({
            status:"fail",
            message:"Error occured code directly runs in catch block",
            Error:error
        });
    }
}
