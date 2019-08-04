 ///
 /// @file    String_pic.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-04 00:56:18
 ///
 
#include "String_pic.h"

std::ostream& String_pic::display(std::ostream &os, size_t lineNum, bool toFillSpace)
{
	//display i-th line
	size_t start = 0;

	if (lineNum < getHeight()) {
		os << data_[lineNum];
		start = data_[lineNum].size();
	}
	if (toFillSpace)
		pad(os, start, getWidth());//对每一行进行补，通过os里面的？

	return os;
}
size_t String_pic::getWidth()
{
	//Get max width by iterating strings
	size_t maxsize = 0;	
	//for i in strings
	for (int i = 0; i!= data_.size(); ++i){
		//if strings[i]'s size > maxsize
		//update maxsize
		std::max(maxsize, data_[i].size());//利用algorithm减少行数
	}
	return maxsize;
}
