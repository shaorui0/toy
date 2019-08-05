# Demand
《AC++》chapter 15

# Question
- 设计是为了在类中进行消息传递，保存对象状态，少复制几次。

# Design 
```
Picture s;
Picture s2;

cout << s;

Picture s3 = frame(s);//express syntax clearl)y
cout << hcat(s, s2);
cout << vcat(s, s2);

```
使用面向对象的方法
需要使用handle实现一个shared_ptr的用法。

- 类的设计
----------------------------------------------
### version 1
基类：
	- Basic_pic:仅作接口存在，本身不能产生对象
		Basic_pic(vector<string>);//底层为vec<str>
		display(Basic_pic);//输出底层内容
		vector<string>
派生类：
	- Frame_pic:	
		- Frame_pic(vector<string>);
		- frame(Picture &p);
		- display();
		- vector<string> picture;

	- Hcat_pic
		- Hcat_pic(vec...)
		- Picture hcat(Picture &lhs, Picture &rhs);//仍然产生了复制
		- display();
		- vector<str>;
	- Vcat_pic
		...
```
vector<string> v1;
vector<string> v2;
Basic_pic *p1 = new Hcat_pic(v1, v2);
p1->display();
```
----------------------------------------------
###version 2
设计过version1之后才发现，这种设计比较粗糙，作为用户，我并不关心有哪些基类、派生类，我只想调用方法，且隐藏细节。
	- 根据调用方法：
	```
	hcat(frame(picture), picture2);
	picture2.hcat(picture1.frame())
	```
	所以这是抽象处**接口**的目的？

	问题一：如何减少深拷贝的使用
	问题二：如何记录structure info//由对象持有
		- 所谓struct info, 组要分为 user input/ handled(frame/vcat/hcat) info
		- 增加一个派生类 String_pic为user input，那其他类和这个类就有些许**不同**了。
		- user无需知道是否处理过（只用写main()），所以抽象出一个基类。而且因为也不需要知道传统的**基类指针指向派生类对象**实现OO，于是还要向上抽象出一层**接口类**（Picture）【接口类 - 派生关系对用户不可见】
			- 还想使用**引用计数**（减少copy），这样就更不必对用户可见了。
			```
			//1. 
			Ptr<Basic_pic> = new Frame_pic(vector<string>)
			
			//2. 
			Picture p1(vector<string>);
			Picture p3 = frame(p1);//非成员函数 

			//哪个舒服？
			```
		- 如果说增加一个【接口类】使得用户可无差别直接访问各个对象，那么【接口类】是怎么做到的，应该怎么设计？
			中间层！
			- 因为接口和基类本质上是等价关系（使用同一底层资源），所以此处应该使用【指针】，明确一点是【智能指针】
			```
			class Ptr;//前向声明与c++链接模型
			class Picture{
			public: 
				Picture(const vector<string>& = vector<string>{});
			private:
				Ptr<Basic_pic> pPic;
			};
			```

		TODO:  接口类Picture实现了设计上的一半，剩下的就是handle方法，及显示ostream了。

		- 思考一下display()
		```
		p.display();//底层是frame(p)
		p.display();//hcat(p)
		//...

		```
			Print user_input and framed_picture is easy, one by one;
			But, hcat? cannot first print a picture and then print others;
			So , **for(i) + display(, i, ...);**

		- 思考一下getWidth():
			派生类中，frame-width = string_pic-width + fill spaces
					  vcat-width遍历获取

			以上这些派生类方法，通过全局的几个函数（frame/vcat/hcat(p1, p2)），Picture获取到的。(多态)
			通过Picture获取到派生类的宽度（反正最终还是要回归底层 ----- vector<string>）
