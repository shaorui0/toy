 ///
 /// @file    String_pic.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 19:01:03
 ///
 
#ifndef __STRING_H__
#define __STRING_H__
#include "Basic_pic.h"
#include <vector>
#include <string>
using std::vector;
using std::string;
class Picture;
class String_pic
: public Basic_pic
{
	friend class Picture;
//TODO: 必须定义所有的抽象基类的纯虚函数，否则也为抽象类
private:
	String_pic(const vector<string> &v)
	: data_(v)
	{}

	size_t getWidth();
	size_t getHeight()
	{	return data_.size();		}
	std::ostream& display(std::ostream &, size_t, bool );
	
	vector<string> data_;

};

#endif
