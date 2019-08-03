 ///
 /// @file    testHandleStr.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-02 18:20:40
 ///
 
#define CATCH_CONFIG_MAIN

#include "handleString.h"

#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
 

void test()
{
	/* test print */
	auto print = [](const string& s){cout << s << endl;};
	vector<string> v{"hello", "my name is xx", "what's your name"};
	std::for_each(v.begin(), v.end(), print);
#if 0
	/* test getMaxlen */
	size_t maxlen = getMaxlen(v);
	cout << "maxlen : "<< maxlen<<endl;
	cout << endl;

	
	/*test empty string */
	vector<string> in{};
	vector<string> out = frameStrings(in);
	std::for_each(out.begin(), out.end(), print);
	cout << endl;

	/* test normal input*/
	vector<string> in_2{"hello", "my name is xx", "what's your name"};
	vector<string> out_2 = frameStrings(in_2);
	std::for_each(out_2.begin(), out_2.end(), print);
	cout << endl;

	/* test abnormal input, eg: string, vector<int/double..> */

	/* test vcat */
	vector<string> vcated_1 = vcatTwoStrings(v, out);
	std::for_each(vcated_1.begin(), vcated_1.end(), print);
	cout << endl;
	vector<string> empty{};
	vector<string> vcated_2 = vcatTwoStrings(empty, out);
	std::for_each(vcated_2.begin(), vcated_2.end(), print);
	cout <<"finished test vcat "<< endl;
#endif

	/* test hcat */
	vector<string> framedV = frameStrings(v);
	//std::for_each(framedV.begin(), framedV.end(), print);
	vector<string> hcated_1 = hcatTwoStrings(v, framedV);
	std::for_each(hcated_1.begin(), hcated_1.end(), print);
#if 0
	cout << endl;
	vector<string> hcated_2 = hcatTwoStrings(frameStrings(v), v);
	std::for_each(hcated_2.begin(), hcated_2.end(), print);
	cout << endl;
#endif
}
int main()
{
	test();

	return 0;

}
