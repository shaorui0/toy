- 此版本重构version 1，使得代码扩展性、可读性、子程序正交性更强。
	
可扩展性：
- 你可能希望从命令行直接输入查询单词
- 查询多个词同时在一行的情况
- 文件名通过配置文件读入
。。。


书上（《c++ primer》12.3）构建了两个类：TextQuery/QueryResult

```
class TextQuery{
public:
	//查询过程

private:
	string filename_;
	string queryWord_;

	map<string, vector<int>> wordLines_;
	map<string, int> wordFrequency_;
	map<int, string> lineText_;
};

class QueryResult{
public:
	//打印结果

private:
	map<string, vector<int>> wordLines_;
	map<string, int> wordFrequency_;
	map<int, string> lineText_;

};
```
很明显，两个类中都保存了处理后的文件内容，效率可以改进。
如何结合？
利用智能指针？

---
注意：
因为line-text，之前选用的是map<int, string>，其实vector<string>就好，为了防止复制过多，我们使用shared_ptr<vector<string>> line_text
map<string, set<int>> word_line
