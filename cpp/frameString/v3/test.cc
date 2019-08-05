 ///
 /// @file    test.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-04 18:12:55
 ///
 
#include "Picture.h"
#include <iostream>
using std::cout;
using std::endl;
 
void test()
{
	//test String_pic
	vector<string> v;
	v.push_back("aaa");
	v.push_back("aaaaaaaaaa");
	v.push_back("aaaaaa");
	Picture p(v);
#if 0
	cout << p<<endl;	
	//test Frame_pic
	Picture p2 = frame(p);
	cout << p2<<endl;	
	Picture p3 = frame(p2);
	cout << p3<<endl;	
	//test Vcat_pic
	//cout << vcat(vcat(p, p), p)<<endl;	
	//
	//test Hcat_pic(left'height > right's ,contrarily)
	cout << hcat(p, p3)<<endl;	
	cout << hcat(p3, p)<<endl;	
	//
	//test fixed picture
	Picture p4 = frame(hcat(p, frame(p)));
	cout << "before reframe:\n"<< p4;
	p4.reframe('&', '*', '~');
	cout << "after reframe:\n" << p4;

#endif
	vector<string> v1{};
	Picture p1(v1);
	cout << hcat(frame(p1), p)<<endl;;
	cout << hcat(p, p1)<<endl;

}

int main(void)
{
	test(); 
}
