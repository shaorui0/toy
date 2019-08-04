 ///
 /// @file    Picture.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 20:04:35
 ///
 
#include "Picture.h"
#include "Frame_pic.h"
#include "Hcat_pic.h"
#include "Vcat_pic.h"
#include "String_pic.h"

/* 这个构造函数，真正的将数据传入底层() */
Picture::Picture(const vector<string>& v )
: pPicture_(new String_pic(v)) //基类指针指向派生类对象
{}

Picture frame(const Picture& pic)
{
	return new Frame_pic(pic.pPicture_);//类型转换	
	//这里有个思想，讲Picture看成一个“数值”，可以直接返回，剩下的靠class内部定义（比如display）进行打印等。
}
Picture hcat(const Picture& left, const Picture& right)
{
	return new Hcat_pic(left.pPicture_, right.pPicture_);
}
Picture vcat(const Picture& top, const Picture& bottom)
{
	return new Vcat_pic(top.pPicture_, bottom.pPicture_);
}
ostream& operator<<(ostream& os, const Picture& pic)
{
	//调用display
	const size_t height = pic.pPicture_->getHeight();
	//get height of strings
	//for i in heights
	for (size_t idx = 0; idx != height; ++idx) {
		// display string
		// output '\n'
		pic.pPicture_->display(os, idx, false);
		os << endl;
	}
	return os;
	//return os;
}
