#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

int main()
{
	// map在c++中翻译为映射,是STL（中文标准模板库）的一个关联容器（字典）。
	// 是有序键（key）值（value）对容器。map的键（key）是索引，不能重复，一个键对应着一个值
	// value为关键字的值，可以重复。map中的元素会自动排序，并且增删改查整体上都很快

	// 1.map的定义
	// 格式为map<typename1，typename2> universities，其中typename1为键的类型，typename2为值的类型
	// 定义一个key和value的类型都是整数的map，存放学生的学号和成绩
	map<int, int> student_score{
		// 学号不可以有重复
		// 学号可以不按顺序创建
		// 学号在创建完成之后会在内部自动排好顺序
		// 学号排序按照大小顺序，int类型的数据就按数值大小排序
		{003, 90},
		{004, 88},
		{001, 88}, // 分数可以有相同的分数
		{002, 78},
	}; // 上述代码创建的map，数据会自动按照key排好顺序

	// item变量来迭代student_score 的每一个元素
	for (auto item : student_score)
	{
		// item是一个pair<int, int>类型
		cout << "id=" << item.first << " "
			<< " score=" << item.second << endl;
	}

	// 实现一个大学的简称和全称对应关系的map
	map<string, string> universities;
	universities["MIT"] = "麻省理工学院 Massachussets  Institute of Technology";
	// 上面的代码看起来是给元素赋值，实际上如果这个元素不存在，则会创建这个元素，所以非常方便
	cout << "size=" << universities.size() << endl; // 可见元素数量是1了
	cout << universities["MIT"] << endl;            // 可以取出这个key为“MIT”的元素的value并输出
	// 使用insert成员函数插入元素：
	universities.insert({ "Harvard", "哈佛大学" });
	cout << "size=" << universities.size() << endl;
	cout << universities["Harvard"] << endl;


	{
		// 初始化map
		// map会自动对插入的元素按照key大小进行排序
		// 这里key是string类型，所以使用string的小于号来排序
		// string的小于号比较大小按照ASCII码的字母表排序
		map<string, string> universities1{
			{"MIT", "麻省理工学院 Massachussets  Institute of Technology"},
			{"UCB", "加州大学伯克利分校 University of  California - Berkeley"},
			{"CMU", "卡内基梅隆大学 Carnegie Mellon  University"},
			{"CC", "哥伦比亚大学 Columbia University  /Community College"},
			{"CU", "康奈尔大学 Cornell University"},
			{"UNC", "北卡罗来纳大学 University of North  Carolina - Chapel Hill"},
			{"UWM", "威斯康辛大学麦迪逊分校 University of  Wisconsin - Madison"},
			{"GWU", "乔治华盛顿大学 George Washington  University"},
			{"JHU", "约翰霍普金斯大学 Johns Hopkins  University"},
			{"MSU", "密歇根州立大学 Michigan State  University"},
		};

		// 运行时根据业务需要，插入一条记录
		universities1["Penn"] = "宾夕法尼亚大学 University of  Pennsylvania";

		// 按照字母表顺序输出所有大学
		cout << "All " << universities1.size() << " universities:" << endl;
		for (auto& item : universities1)
		{
			cout << "key=" << item.first << " , value= " << item.second << endl;
		}
	}
	//map的每一个元素包括两部分key和value；
	//key在插入后就不再可以改变，可以被删除（同时对应的value一起被删除）；
	//key对应的value可以被访问和读写；
	//map使用中括号[]操作符来获取key对应的value；
	//map的元素在插入的过程中会自动排序（使用小于号 < 对元素按照key排序）。

	system("pause");
	return 0;
}