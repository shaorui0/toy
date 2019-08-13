读取学生成绩并处理
	重载多个grade(Stude_info)
	grade(midterm, final, (double/vector<double>)homework);

midterm		20%
final		40%
homework	40% (sum/count)
	获取分数(s):
		istream& read_homework(instream&, vector<int>& hw);
	计算平均分
	计算中位分

组织数据
	Student_info{
		double midterm, final;
		string name;
		vector<double> homework;
	};
管理学生信息
	ist& read(ist&, Student_info& );

对学生的最终成绩进行排名
	compare(St_info, St_info)

>>> 需求: 输入多个学生的信息，做出排序
>>> 做习题


---

改成class
能使用构造函数
	Student_info::Student_info(istream& in){read(in);}//这就很舒服的设计方式
>>> 习题


---

使用OOP，此时有了“研究生”
