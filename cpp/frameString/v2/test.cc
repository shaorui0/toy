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
	cout << p<<endl;	
	//test Frame_pic
	Picture p2 = frame(p);
	cout << p2<<endl;	
	Picture p3 = frame(p2);
	cout << p3<<endl;	
	//test Vcat_pic
	//cout << vcat(vcat(p, p), p)<<endl;	
	//
	//test Hcat_pic
	cout << hcat(p, p3)<<endl;	
	//
	//test fixed picture
	cout << frame(hcat(p, frame(p)))<<endl;	

}

int main(void)
{
	test(); 
}
