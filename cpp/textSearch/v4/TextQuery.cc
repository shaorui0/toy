 ///
 /// @file    TextQuery.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-06 19:03:57
 ///

#include "TextQuery.h"
QueryResult TextQuery::query(string word) const 
{
	if (wordLines_.find(word) == wordLines_.end()) {//cannot find "word"		
		set<line_no>* nodata(new set<line_no>);
		return QueryResult(word, nodata, lineText_);
	} else {
		auto localData = wordLines_.find(word);//map
		return QueryResult(word, localData->second, lineText_);
	}
}

void TextQuery::handleFile(){
	ifstream ifs(filename_);
	if (!ifs) {
		cout << "cannot open file" << filename_ <<endl;
	}
	string line;
	int lineNum = 0;
	/* 处理文件信息 */
	while(getline(ifs, line)){
		//update lineText_
		lineText_->push_back(line);
		//handle line text to words
		for (size_t i = 0; i!= line.size(); ++i) {
			if (!isalpha(line[i]))
				line[i] = ' ';
		}
		istringstream iss(line);
		string word;
		//iterate words 
		while (iss >> word){
			//read a word
			//update wordLines_
			auto &lines = wordLines_[word];
			if (!lines)//cannot find "word"
				lines = new set<line_no>;
			lines->insert(lineNum);
		}
		++lineNum;
	}
	ifs.close();
}
void TextQuery::printFileText()
{
	for (size_t i = 0; i < lineText_->size(); ++i) {
		cout << (*lineText_)[i]<<endl;
	
	}

}
void TextQuery::printWordLine(){
	//iterate 
	//word
	//occurs x times
	// line numbers
	for (auto iter = wordLines_.begin(); iter != wordLines_.end(); ++iter) {
		cout << "word: "<< iter->first<<endl;
		auto &lines = (iter->second);//shared_ptr<set<>>
		for (auto iter2 = lines->begin(); iter2 != lines->end(); ++iter2) {
			cout << *iter2<<endl;	
		}
		cout << endl;
	}

}
ostream& print(ostream& os, const QueryResult& ret)
{
	string word = ret.queryWord_;
	os << word<< " occurs " << ret.lines_->size() << " time(s)"<<endl;
	for (auto i = ret.lines_->begin(); i != ret.lines_->end(); ++i) {
		os << "(line "<< *i <<") " << (*ret.lineText_)[*i]<<endl;
	}
	return os;
}
