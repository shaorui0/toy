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

	void reframe(char , char , char ){}
	//抽象基类所继承的成员函数必须显式定义.
	size_t getWidth();
	size_t getHeight()
	{	return data_.size();		}
	void display(std::ostream &, size_t, bool );
	
	vector<string> data_;

};

#endif
void String_pic::display(std::ostream &os, size_t lineNum, bool toFillSpace)
{
	//display i-th line
	size_t start = 0;

	if (lineNum < getHeight()) {
		os << data_[lineNum];
		start = data_[lineNum].size();
	}
	if (toFillSpace)
		pad(os, start, getWidth());//对每一行进行补，通过os里面的？

}
size_t String_pic::getWidth()
{
	//Get max width by iterating strings
	size_t maxsize = 0;	
	//for i in strings
	for (size_t i = 0; i != data_.size(); ++i){
		//if strings[i]'s size > maxsize
		//update maxsize
		maxsize = std::max(maxsize, data_[i].size());//利用algorithm减少行数
	}
	return maxsize;
}
