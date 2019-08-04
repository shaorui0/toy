 ///
 /// @file    Picture.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 18:18:27
 ///
 
#ifndef __PICTURE_H__
#define __PICTURE_H__
#include "Ptr.h"
#include <iostream>
#include <vector>
#include <string>
using std::ostream;
using std::endl;
using std::vector;
using std::string;


//TODO: 这里的前置声明使用是否正确
class Basic_pic;

class Picture{
	friend Picture frame(const Picture& pic);//用到私有成员
	friend Picture hcat(const Picture&, const Picture&);
	friend Picture vcat(const Picture&, const Picture&);
	friend ostream& operator<<(ostream&, const Picture&);
public:
	//这个构造函数看出它将数据传入到哪里
	Picture(const vector<string>& = vector<string>{});

private:
	Picture(Basic_pic *ptr)
	:pPicture_(ptr){}

	Ptr<Basic_pic> pPicture_;
};
//全局
Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);

ostream& operator<<(ostream&, const Picture&);



#endif

