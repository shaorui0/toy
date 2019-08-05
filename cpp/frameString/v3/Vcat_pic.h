 ///
 /// @file    Vcat_pic.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 19:34:08
 ///
 
#ifndef __VCAT_PIC__
#define __VCAT_PIC__
#include "Basic_pic.h"
#include "Ptr.h"
class Vcat_pic
: public Basic_pic{
	friend Picture vcat(const Picture&, const Picture&);
	friend class Picture;
private:
	Vcat_pic(const Ptr<Basic_pic>& top, const Ptr<Basic_pic>& bottom)
	: top_(top)
	, bottom_(bottom)
	{}
	size_t getWidth()
	{	return std::max(top_->getWidth(), bottom_->getWidth());	}
	size_t getHeight()
	{	return top_->getHeight()+ bottom_->getHeight();	}
	void display(std::ostream &, size_t, bool );
	void reframe(char topAndBottom, char leftAndRight, char corner);

	Ptr<Basic_pic> top_, bottom_;
};

#endif
void Vcat_pic::display(std::ostream &os, size_t lineNum, bool toFillSpace)
{
	size_t w = 0;
	if (lineNum < top_->getHeight()){
		top_->display(os, lineNum, toFillSpace);
		w = top_->getWidth();
	} else if (lineNum < getHeight()) {
		bottom_->display(os, lineNum-top_->getHeight(), toFillSpace);
		w = bottom_->getWidth();
	}

	if (toFillSpace)
		pad(os, w, getWidth());
}
void Vcat_pic::reframe(char topAndBottom, char leftAndRight, char corner)
{
	top_->reframe(topAndBottom, leftAndRight, corner);
	bottom_->reframe(topAndBottom, leftAndRight, corner);
	
}
