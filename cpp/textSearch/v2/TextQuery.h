///
/// @file    TextQuery.h
/// @author  shaorui(sr1054461216@gmail.com)
/// @date    2019-08-05 01:41:07
///
#ifndef __TEXT_QUERY__
#define __TEXT_QUERY__
#include "QueryResult.h"
class QueryResult;
class TextQuery{
	public:
		TextQuery(string filename)
		: filename_(filename)
		, lineText_(new vector<string>) 
		{
			handleFile();
		}

		QueryResult query(string word);
		// Debug function(看文件处理是否成功)
		void printFileText();
		void printWordLine();
	private:
		void handleFile();

		string filename_;
		string queryWord_;

		map<string, shared_ptr<set<int>>> wordLines_;
		shared_ptr<vector<string>> lineText_;
};
#endif
