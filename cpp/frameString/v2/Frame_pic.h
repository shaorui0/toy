 ///
 /// @file    Vcat_pic.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 19:34:08
 ///
 
#ifndef __FRAME_H__
#define __FRAME_H__
#include "Basic_pic.h"
#include "Ptr.h"
#include <unistd.h>
class Frame_pic 
: public Basic_pic{
	friend Picture frame(const Picture&);
	friend size_t getFramePictureWidth(Picture&);
	friend class Picture;
private:
	Frame_pic(const Ptr<Basic_pic>& p)//实现多态
	: p_(p)
	{}

	size_t getWidth()
	{	return p_->getWidth()+4;	}//String_pic
	size_t getHeight()
	{	return p_->getHeight()+4;	}
	void display(std::ostream &, size_t, bool );

	Ptr<Basic_pic> p_;

};
#endif
void Frame_pic::display(std::ostream &os, size_t lineNum, bool toFillSpace)
{
	if(lineNum > getHeight()){
		if (toFillSpace)
			pad(os, 0, getWidth());
	} else {
		if (lineNum == 0 || lineNum == getHeight()-1)
			os<<std::string(getWidth(), '*');
		else if (lineNum == 1||lineNum == getHeight()-2) {
			os << "*";
			pad(os, 1, getWidth()-1);
			os << "*";
		} else {
			os << "* ";
			p_->display(os, lineNum-2, true);
			os << " *";
		}
	}
	//sleep(2);
}
