支持逻辑运算、混合逻辑运算：
	(查询语句 ===> 解析命令)
	name & file				===> (name|file)
	name | file				===> (name|file)
	~name					===> ~(name)
	name |file & certain	===> ((name|file)&certain)
	name |(file & certain)	===> (name|(file&certain)


问题
	- 如和解析输入的命令？
		- 如何按照优先级解析命令？
			按照c++内部的优先级，有括号算括号，无括号按内部优先级
			===> 类似一个【计算器】 (15+40)*(99 - (100/4))

			1. 逆波兰式
			2. 逆波兰式 -> 输出命令（easy）
				name |(file & certain)===>  name file certain & |  ===> (name|(file&certain)
				利用栈
					string inputCommand
					stack1 keyWords --- part1
					stack2 operator --- part2
					stack3 逆波兰式
					string outputCommand

	- 如何通过命令生成打印内容，
		- 基于数据结构
			map<string, set<int>> wordLine_
			vector<string> lineText_
		- 如何通过逻辑命令操作DS？
	


需求
	- 解析函数 string parseCommand(string) //查询语句中可能包含多个运算符，直接存储好像不行
	- 数据结构的传递
		对数据结构进行逻辑操作
	- 打印结果还是之前的打印方式，主要是内部的逻辑处理方式。（有无逻辑运算都要经过parseCommand）

	逻辑关系本质上是对【行号】进行操作。
		set<int> set1  &  set2  std::set_intersection
		set<int> set1  |  set2  std::set_union
		~ set1                  std::set_different

		~word_1 | (word_2 & word3)    ---> ((~word_1)|(word_2 & word3))
			===>
				command 1: ~word_1				set_1
				command 2: word_2&word3			set_2
				command 3: set_1 | set_2		set_3

	```
	// main.cc:

		cin >> command;
		ifstream ifs;
		TextQuery textQuery(ifs);
		vector<string> parse(command);//分析第一步判断合法 wordNum = commandNum + 1
		QueryResult ret = texQuery.query(vector<string> commands);
		print(cout, ret);

	```


架构设计
	- 面向对象
	普通查询（one word），基类
		query
	混合查询 derive class
		parse command line
		set handle
	friend print(cout, QueryResult);

	方案一：通过面向设计，基础功能的基础上加入复杂功能。
		疑问一：用户并不想知道是否需要【基类指针指向派生类对象】，在其看来，只要输入命令，调用必要的API即可。
			解答；要到AC++所学的interface方法，抽象出一个对象，利用指针（shared/unique）。
			```
			class Query{
					//friend
				public:
					//API
					
				private:
					shared_ptr<TextQuery> p_;
			};
			```
		疑问二：一个类解决所有问题并不是一个好办法。
			解答：
				普通查询/非查询，都是对一个word进行处理
				与/或查询则是二元操作。  
	方案二：
		抽象出一个抽象基类，且构造一个接口（【隐藏】继承体系）

		Query
		Query_Basic(抽象)
		WordQuery/NotQuery/  BinaryQuery(抽象)
							 Or../And...

		用户接口：Query...
		输入命令 string queryCommand
		解析     ~word | (word2 & word3)
		构建     Query q1 = Query(word2)&Query(word3);   //operator&
				 Query q2 = ~Query(word);
				 Query q3 = q1 | q2;
				 print(cout, q3);
	注意设计时：
		一个类/函数，解决一个问题是比较好的设计方式
							  BinaryQuery
			WordQuery/NotQuery/OrQuery/AndQuery
			```
			class Query{
				//构造函数底层指向真正的底层派生类对象
				Query(string cmd)
				: p_(new WordQuery(cmd)){//基类指针，指向派生类对象
				}


				Query operator|(Query &lhs, Query &rhs)
				{
					return new OrQuery(lhs.p_, rhs.p_);
				}
				//...& ~

				QueryResult eval(string &cmd);
				rep();
			
			
			};
			```
			每个查询操作都返回一个结果QueryResult

	灯：这里的架构与AC++架构相似的非常典型（Picture/Base/String/Hcat/Vcat）
		仅String保存底层数据，其余的是通过基类指针，简介操作String，或者说在String的基础上进行打印即可。
		所谓记录结构信息，本质上是通过基类指针自动判断对象类型，然后调用相应的方法（多态）


编码
