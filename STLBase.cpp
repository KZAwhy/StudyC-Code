#include <iostream>
#include <string>
#include <vector>	//vector叫动态数组，是一种存放变量的容器(向量)

using namespace std;

int main()
{
	//2.1向量
	/*变长数组（向量）*/
	vector<int> arr;//创建的数组一开始由于没有任何元素，所以，此时数组的大小是0。
	size_t c = arr.size();//此时变量c的值为0,size是数组vector的成员函数，专门用来告诉使用数组的人现在数组元素有几个。
	cout << c << endl; //c = 0。size_t = unsigned long在64位系统中
	//由于函数调用总是用一对圆括号表示，所以调用size应该写成size()
	//由于是数组arr调用自己的成员函数，所以用成员访问操作符点来调用，所以写成arr.size()
	bool b = arr.empty();
	//判断数组是否为空的成员函数是empty()，此函数返回一个bool值。
	arr.push_back(25);//arr新增了一个元素25
	//调用 push_back成员函数往容器中添加一个无名整型变量，并将这个变量的初始值设置为25
	int i = arr[0];//将下标位置（号）为0的元素（变量）的值（25）赋值给整型变量i
	cout << arr[0] << endl;
	//动态扩容,数组的长度会随着添加元素而变长，所以叫动态数组
	for (int i = 0; i < 10; ++i)
	{
		arr.push_back(i);
	}
	cout << "vector size:" << arr.size() << endl;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	/*变长字符串*/
	//string和vector<char>几乎是一样的。
	//但是string增加了更多对字符串专门的操作，比如加法操作符，查找子串，截取子串等字符串独有的功能。
	//所以，如果是处理字符串，string很方便
	string you_say("I love you");
	cout << "字符串内容:" << you_say << endl;//字符串可以直接输出
	cout << "字符串长度:" << you_say.size() << endl;
	cout << "字符串内容:";
	for (size_t i = 0; i < you_say.size(); ++i)
	{
		cout << you_say[i];//使用下标遍历字符串
	}
	cout << endl;
	//拼接字符串
	string i_say = you_say;//复制构造一个新字符串
	i_say += " too";//字符串拼接
	cout << "字符串内容:" << i_say << endl;//字符串可以直接输出


	//2.2迭代器
	//auto 关键字,auto 是在变量定义的时候，用别人的类型作为自己类型的一种定义变量的方式。
	int  a = 1;
	auto b1 = a;		//b1的类型为a的类型int
	const int a1 = 1;
	int  b2 = a1;		//b2的类型为int
	auto b3 = a1;	//b3的类型为int
	//auto& ,auto& a = b; 表示 a是b的引用，类型与b相同。
	int a2 = 1;
	int& b4 = a2;		//b4是a的别名（也就是引用）
	auto& b5 = a2;	//b5是a的别名（也就是引用）

	//auto最常用的场景是对于复杂类型的简化。
	//例如，在 迭代器 中，我们看到了下面的遍历vector的代码：
	//不使用auto
	vector<int>::iterator i1;  //定义正向迭代器
	for (i1 = arr.begin(); i1 != arr.end(); ++i1) {  //用迭代器遍历容器
		cout << *i1 << " ";  //*i 就是迭代器i指向的元素
		*i1 *= 2;  //每个元素变为原来的2倍
	}
	cout << endl;
	//使用auto
	for (auto itr = arr.begin(); itr != arr.end(); ++itr)
	{
		cout << *itr << " "; // 使用解引用操作符 * 获得迭代器迭代到的元素的引用
	}
	//逆迭代器
	cout << endl;
	for (auto itr = arr.rbegin(); itr != arr.rend(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;

	//由于很多容器都提供迭代器，而且迭代器遍历的代码几乎一模一样
	//所以，C++允许将迭代器遍历容器简化成范围for循环：
	//专门针对容器类型的for循环，使用冒号:语句来迭代容器中的每一个元素。
	for (auto& item : arr)
	{
		cout << item << " ";//item遍历list1的每一个元素
	}
	cout << endl;

	//迭代器除了遍历容器，也可以删除容器的元素。
	//删除第一个指定值的元素（使用迭代器）
	//下面的代码从包含{ 1,2,3,4,5,3,9,3 } 这8个数的数组中删除第一个3：
	vector<int> arr1{ 1,3,8,4,3,5,3,4,9,3,4 };
	//遍历
	for (auto item : arr1)
	{
		cout << item << " ";
	}
	cout << endl;
	//删除
	for (auto itr = arr1.begin(); itr != arr1.end(); ++itr)
	{
		if (*itr == 3)
		{
			arr1.erase(itr);//删除附件条件的值
			break;
		}
	}
	//现在打印向量，发现第一个3没有了
	for (auto item : arr1)
	{
		cout << item << " ";
	}
	cout << endl;
	//删除第一个指定值的元素（使用find算法）
	auto itr1 = find(arr1.begin(), arr1.end(), 3);
	arr1.erase(itr1);// 删除第1个3

	for (auto item : arr1)
	{
		cout << item << " ";
	}
	cout << endl;
	//删除所有指定元素
	for (auto itr = arr1.begin(); itr != arr1.end();)
	{
		if (*itr == 3)
		{
			itr = arr1.erase(itr);//间接实现了++itr：迭代器指向了被删除元素的下一个元素
		}
		else
		{
			++itr;
		}
	}
	//现在打印向量，发现3没有了
	for (auto item : arr1)
	{
		cout << item << " ";
	}
	cout << endl;
	//删除所有指定值的元素（使用remove算法）,需要#include <algorithm>
	/*remove 把需要保留的数据紧凑的保留在数组的前面，
	 并返回第一个不应该再属于数组的元素的迭代器，
	 供后续按照范围删除
	 remove 之后数组元素排列如下：
	 1, 2, 4, 5, 9, #, #, #
	*/
	auto itr = remove(arr1.begin(), arr1.end(), 3);
	arr1.erase(itr, arr1.end());// 删除 { # # # }

	//now print all int in arr : no 3 anymore.
	for (auto item : arr1)
	{
		cout << item << " ";
	}

	return 0;
}