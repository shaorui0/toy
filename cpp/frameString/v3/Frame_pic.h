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
	friend class Picture;
	friend size_t getFramePictureWidth(Picture&);
private:
	Frame_pic(const Ptr<Basic_pic>& p)//实现多态
	: p_(p)
	, corner('+')
	, topAndBottom('-')
	, leftAndRight('|')
	{}

	size_t getWidth()
	{	return p_->getWidth()+4;	}//String_pic
	size_t getHeight()
	{	return p_->getHeight()+4;	}
	void display(std::ostream &, size_t, bool );
	void reframe(char topAndBottom, char leftAndRight, char corner);

	Ptr<Basic_pic> p_;
	char corner;
	char topAndBottom;
	char leftAndRight;

};
#endif
void Frame_pic::display(std::ostream &os, size_t lineNum, bool toFillSpace)
{
	if(lineNum > getHeight()){
		if (toFillSpace)
			pad(os, 0, getWidth());
	} else {
		if (lineNum == 0 || lineNum == getHeight()-1){
			os << corner;
			os<<std::string(getWidth()-2, topAndBottom);
			os << corner;
		}
		else if (lineNum == 1||lineNum == getHeight()-2) {
			os << leftAndRight; 
			pad(os, 1, getWidth()-1);
			os << leftAndRight; 
		} else {
			os << leftAndRight; 
			os << " ";
			p_->display(os, lineNum-2, true);
			os << " ";
			os << leftAndRight; 
		}
	}
	//sleep(2);
}
void Frame_pic::reframe(char t_b, char l_r, char c)
{
	//可能是嵌套frame
	p_->reframe(t_b, l_r, c);	

	topAndBottom = t_b;
	leftAndRight = l_r;
	corner = c;
}
