///
/// @file    test.cc
/// @author  shaorui(sr1054461216@gmail.com)
/// @date    2019-08-06 16:57:04
///

#include <iostream>
#include "TextQuery.h"


int main(void)
{
	//use API
	//open file
	//handle file to memory with vector/map/set
	string filename = "../English.txt";
	TextQuery t(filename);
	//store result in QueryResult
	//query word
	//t.printFileText();
	//t.printWordLine();
	while(true){
		string word;
		std::cin >> word;
		QueryResult ret = t.query(word);
		//print result
		print(cout, ret);	
	}
}
