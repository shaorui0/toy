///
/// @file    test.cc
/// @author  shaorui(sr1054461216@gmail.com)
/// @date    2019-08-06 16:57:04
///

#include <iostream>
#include "Query.h"


int main()
{
	/*
	Query("word");
	~Query("word");
	Query("word")&Query("word2");
	Query("word")|Query("word2");
	cout << "~Query(word3)|(Query(word)&Query(word2))"<<endl<<endl;;
	string cmd = "~word1|(word2&word3)";
	//parse(cmd);//生成上面的各种Query对象
	*/

	//Query q = ~Query("word3")|(Query("word")&Query("word2"));
	Query q = Query("fieryadsdasdasdasd")|Query("wind");
		//|(Query("word")&Query("a"));
	TextQuery tq("../english.txt");//提供语料
	//tq里面保存了全部的信息(vector/map)
	QueryResult result = q.eval(tq);
	print(cout, result);



	return 0;
}


