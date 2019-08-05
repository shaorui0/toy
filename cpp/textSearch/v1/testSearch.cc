 ///
 /// @file    testSearch.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-05 00:31:26
 ///
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace	 std; 
void test()
{
	//map<string, vector<int>> word_lines;
	map<string, set<int>> word_lines;//可能重行（一行多个）
	map<string, int> word_frequency;
	map<int, string> line_text;

	string filename = "../English.txt";

	ifstream ifs(filename);
	if (!ifs) {
		cerr << "cannot open file" << filename <<endl;
	}
	string line;
	int lineNum = 0;
	/* 处理文件信息 */
	while(getline(ifs, line)){
		//update line_text
		line_text[lineNum] = line;
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
			//update word_lines
			word_lines[word].insert(lineNum);
			//word_frequency
			++word_frequency[word];
		
		}
		++lineNum;
	}
	
	/* 查询word*/
	string theWord;
	cin >> theWord;
	/* 打印信息 */

	cout << theWord << " occurs " << word_frequency[theWord] << " time(s)"<<endl;
	set<int> &lineSet = word_lines[theWord];
	for (auto i = lineSet.begin(); i != lineSet.end(); ++i) {
		cout << "(line "<< *i <<") " << line_text[*i]<<endl;
	}

}
int main(void)
{
	test();
	return 0;
 
}
