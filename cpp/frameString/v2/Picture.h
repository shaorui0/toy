 ///
 /// @file    Picture.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 18:18:27
 ///
 
#ifndef __PICTURE_H__
#define __PICTURE_H__
#include "Ptr.h"
#include "Basic_pic.h"
#include "String_pic.h"
#include "Frame_pic.h"
#include "Vcat_pic.h"
#include "Hcat_pic.h"
#include <iostream>
#include <vector>
#include <string>
using std::ostream;
using std::endl;
using std::vector;
using std::string;


//TODO: 这里的前置声明使用是否正确

class Picture{
	friend Picture frame(const Picture& pic);//用到私有成员
	friend Picture hcat(const Picture&, const Picture&);
	friend Picture vcat(const Picture&, const Picture&);
	friend ostream& operator<<(ostream&, const Picture&);

	friend size_t getFramePictureWidth(Picture &p);

public:
	//这个构造函数看出它将数据传入到哪里
	Picture(const vector<string>& = vector<string>{});

private:
	Picture(Basic_pic *ptr)
	:pPicture_(ptr){}

	Ptr<Basic_pic> pPicture_;
};
#endif
/*---------------------------------------*/
/* Debug helper */
size_t getFramePictureWidth(Picture &p)
{
	Basic_pic* basic = new Frame_pic(p.pPicture_);
	size_t width = basic->getWidth();
	std::cout << "Picture's width = " << width <<endl;
	return width;
}





/*---------------------------------------*/

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
}
