#include <iostream>
#include <string>
#include <vector>	//vector叫动态数组，是一种存放变量的容器(向量)
#include <list>		//list双向链表容器
#include <array>	//array 容器是 C++ 11 标准中新增的序列容器
#include <forward_list>		//C++ 11 标准中新增容器，与list相似
#include <iterator>			//头文件 <iterator> 中的 distance() 函数

using namespace std;

bool demo(double first, double second)
{
	return (int(first) == int(second));
}

int main()
{
	//2.3容器
	//list双向链表容器，即该容器的底层是以双向链表的形式实现的。
	//list 容器中的元素可以分散存储在内存空间里，而不是必须存储在一整块连续的内存空间中。
	//实际场景中，如何需要对序列进行大量添加或删除元素的操作，而直接访问元素的需求却很少，这种情况建议使用 list 容器存储序列。
	//优势，即它可以在序列已知的任何位置快速插入或删除元素,并且在 list 容器中移动元素
	//缺点是，它不能像 array 和 vector 那样，通过位置直接访问元素。
	list<int> values;			//创建一个没有任何元素的空 list 容器
	list<int> values1(10);		//创建一个包含 n 个元素的 list 容器
	list<int> values2(10, 5);	//创建了一个包含 10 个元素并且值都为 5 个 values 容器
	list<int> values3(values1);	//已有 list 容器的情况下，通过拷贝该容器可以创建新的 list 容器
	//采用此方式，必须保证新旧容器存储的元素类型一致。

	//通过拷贝其他类型容器（或者普通数组）中指定区域内的元素，可以创建新的 list 容器
	//拷贝普通数组，创建list容器
	int a[] = { 1,2,3,4,5 };
	std::list<int> values4(a, a + 5);
	//拷贝其它类型的容器，创建 list 容器
	std::array<int, 5>arr{ 11,12,13,14,15 };
	std::list<int>values5(arr.begin() + 2, arr.end());//拷贝arr容器中的{13,14,15}
	//向容器中添加元素
	values.push_back(3);
	values.push_back(2);
	values.push_back(9);
	values.push_back(7);
	cout << "values size：" << values.size() << endl;
	//对容器中的元素进行排序
	values.sort();
	//使用迭代器输出list容器中的元素
	for (std::list<int>::iterator it = values.begin(); it != values.end(); ++it)
	{
		std::cout << *it << " ";
	}
	cout << endl;


	/*C++ STL list迭代器及用法详解*/
	//list 容器迭代器最大的不同在于，其配备的迭代器类型为双向迭代器，而不再是随机访问迭代器。
	//它们支持使用 ++p1、 p1++、 p1--、 p1++、 *p1、 p1==p2 以及 p1!=p2 运算符，但不支持以下操作（其中 i 为整数）
	//p1[i]：不能通过下标访问 list 容器中指定位置处的元素。
	//p1 -= i、 p1 += i、 p1 + i 、p1 - i：双向迭代器 p1 不支持使用 -= 、 += 、 + 、 - 运算符。
	//p1<p2、 p1>p2、 p1 <= p2、 p1 >= p2：双向迭代器 p1、p2 不支持使用 <、 >、 <= 、 >= 比较运算符。

	//下面这个程序演示了如何使用表 1 中的迭代器遍历 list 容器中的各个元素。
	//创建 list 容器
	std::list<char> values6{ 'h','t','t','p',':','/','/','c','.','b','i','a','n','c','h','e','n','g','.','n','e','t' };
	//使用begin()/end()迭代器函数对输出list容器中的元素,正向
	for (std::list<char>::iterator it = values6.begin(); it != values6.end(); ++it) {
		std::cout << *it;
	}
	cout << endl;
	//使用 rbegin()/rend()迭代器函数输出 lsit 容器中的元素，反向
	for (std::list<char>::reverse_iterator it = values6.rbegin(); it != values6.rend(); ++it) {
		std::cout << *it;
	}
	cout << endl;
	//程序中比较迭代器之间的关系，用的是 != 运算符，因为它不支持 < 等运算符。
	//另外在实际场景中，所有迭代器函数的返回值都可以传给使用 auto 关键字定义的变量，
	//因为编译器可以自行判断出该迭代器的类型。


	//list 容器在进行插入（insert()）、接合（splice()）等操作时，都不会造成原有的 list 迭代器失效，
	//甚至进行删除操作，而只有指向被删除元素的迭代器失效，其他迭代器不受任何影响。如下例
	//创建 begin 和 end 迭代器
	std::list<char>::iterator begin = values6.begin();
	std::list<char>::iterator end = values6.end();
	//头部和尾部插入字符 '1'
	values6.insert(begin, '1');
	values6.insert(end, '1');
	while (begin != end)
	{
		std::cout << *begin;
		++begin;
	}
	//在进行插入操作之后，仍使用先前创建的迭代器遍历容器，
	//虽然程序不会出错，但由于插入位置的不同，可能会遗漏新插入的元素。
	cout << endl;


	/*C++ list（STL list）访问元素的几种方法*/
	//list 容器不支持随机访问，未提供下标操作符 [] 和 at() 成员函数，也没有提供 data() 成员函数
	//通过 front() 和 back() 成员函数，可以分别获得 list 容器中第一个元素和最后一个元素的引用形式
	std::list<int> mylist{ 1,2,3,4 };
	int& first = mylist.front();
	int& last = mylist.back();
	cout << first << " " << last << endl;
	first = 10;
	last = 20;
	cout << mylist.front() << " " << mylist.back() << endl;
	//通过 front() 和 back() 的返回值，我们不仅能分别获取当前 list 容器中的首尾元素，必要时还能修改它们的值

	//如果想访问 list 容存储的其他元素，就只能使用 list 容器的迭代器。例如
	const std::list<int> mylist1{ 1,2,3,4,5 };
	auto it = mylist1.begin();
	cout << *it << " ";
	++it;
	while (it != mylist1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//对于非 const 类型的 list 容器，迭代器不仅可以访问容器中的元素，也可以对指定元素的值进行修改。
	//对于修改容器指定元素的值，list 模板类提供有专门的成员函数 assign()


	/*C++ STL list添加（插入）元素方法详解*/
	/*push_front()：向 list 容器首个元素前添加新元素；
	push_back()：向 list 容器最后一个元素后添加新元素；
	emplace_front()：在容器首个元素前直接生成新的元素；
	emplace_back()：在容器最后一个元素后直接生成新的元素；
	emplace()：在容器的指定位置直接生成新的元素；
	insert()：在指定位置插入新元素；
	splice()：将其他 list 容器存储的多个元素添加到当前 list 容器的指定位置处。*/
	//除了 insert() 和 splice() 方法有多种语法格式外，其它成员方法都仅有 1 种语法格式
	std::list<int> values7{ 1,2,3 };
	values7.push_front(0);//{0,1,2,3}
	values7.push_back(4); //{0,1,2,3,4}
	values7.emplace_front(-1);//{-1,0,1,2,3,4}
	values7.emplace_back(5);  //{-1,0,1,2,3,4,5}
	//更重要的是，实现同样的功能，emplace 系列方法的执行效率更高。
	//emplace(pos,value),其中 pos 表示指明位置的迭代器，value为要插入的元素值
	values7.emplace(values7.end(), 6);//{-1,0,1,2,3,4,5,6}
	for (auto p = values7.begin(); p != values7.end(); ++p) {
		cout << *p << " ";
	}
	cout << endl;

	//下面的程序演示了如何使用 insert() 方法向 list 容器中插入元素
	std::list<int> values8{ 1,2 };
	//第一种格式用法
	values8.insert(values8.begin(), 3);//{3,1,2}
	//第二种格式用法
	values8.insert(values8.end(), 2, 5);//{3,1,2,5,5}
	//第三种格式用法
	//iterator insert(pos,first,last) 
	//在迭代器 pos 指定的位置之前，插入其他容器（例如 array、vector、deque 等） 
	//中位于[first,last) 区域的所有元素，并返回表示第一个新插入元素位置的迭代器。
	std::array<int, 3>test{ 7,8,9 };
	values8.insert(values8.end(), test.begin(), test.end());//{3,1,2,5,5,7,8,9}
	//第四种格式用法
	values8.insert(values8.end(), { 10,11 });//{3,1,2,5,5,7,8,9,10,11}
	for (auto p = values8.begin(); p != values8.end(); ++p)
	{
		cout << *p << " ";
	}
	cout << endl;

	{
		//和 insert() 成员方法相比，splice() 成员方法的作用对象是其它 list 容器，
		// 其功能是将其它 list 容器中的元素添加到当前 list 容器中指定位置处。
		//创建并初始化 2 个 list 容器
		list<int> mylist1{ 1,2,3,4 }, mylist2{ 10,20,30 };
		list<int>::iterator it = ++mylist1.begin(); //指向 mylist1 容器中的元素 2

		//调用第一种语法格式
		mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
		// mylist2:
		// it 迭代器仍然指向元素 2，只不过容器变为了 mylist1
		//调用第二种语法格式，将 it 指向的元素 2 移动到 mylist2.begin() 位置处
		mylist2.splice(mylist2.begin(), mylist1, it);   // mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// it 仍然指向元素 2

		//调用第三种语法格式，将 [mylist1.begin(),mylist1.end())范围内的元素移动到 mylist2.begin() 位置处                  
		mylist2.splice(mylist2.begin(), mylist1, mylist1.begin(), mylist1.end());//mylist1:
		//mylist2:1 10 20 30 3 4 2

		cout << "mylist1 包含 " << mylist1.size() << "个元素" << endl;
		cout << "mylist2 包含 " << mylist2.size() << "个元素" << endl;
		//输出 mylist2 容器中存储的数据
		cout << "mylist2:";
		for (auto iter = mylist2.begin(); iter != mylist2.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
	}


	/*C++ STL list删除元素详解*/
	//pop_front()、pop_back() 和 clear() 的用法非常简单
	{
		list<int>values9{ 1,2,3,4 };
		//删除当前容器中首个元素
		values9.pop_front();//{2,3,4}
		//删除当前容器最后一个元素
		values9.pop_back();//{2,3}
		//清空容器，删除容器中所有的元素
		values9.clear(); //{}
		cout << "values9 包含 " << values9.size() << "个元素" << endl;
	}

	//iterator erase (iterator position);
	//可实现删除 list 容器中 position 迭代器所指位置处的元素
	{
		list<int>values{ 1,2,3,4,5 };
		//指向元素 1 的迭代器
		auto del = values.begin();
		//迭代器右移，改为指向元素 2
		++del;
		values.erase(del); //{1,3,4,5}
		for (auto begin = values.begin(); begin != values.end(); ++begin)
		{
			cout << *begin << " ";
		}
		cout << endl;
	}

	//iterator erase (iterator first, iterator last);
	//可实现删除 list 容器中 first 迭代器和 last 迭代器限定区域内的所有元素
	//（包括 first 指向的元素，但不包括 last 指向的元素）
	{
		list<int>values{ 1,2,3,4,5 };
		//指定删除区域的左边界
		auto first = values.begin();
		++first;//指向元素 2
		//指向删除区域的右边界
		auto last = values.end();
		--last;//指向元素 5
		//删除 2、3 和 4
		values.erase(first, last);
		for (auto begin = values.begin(); begin != values.end(); ++begin)
		{
			cout << *begin << " ";
		}
		cout << endl;
	}

	//erase() 成员函数是按照被删除元素所在的位置来执行删除操作，
	//如果想根据元素的值来执行删除操作，可以使用 remove() 成员函数
	{
		list<char>values{ 'a','b','c','d','c','w' };
		values.remove('c');		//删除容器中所有等于 val 的元素。
		for (auto begin = values.begin(); begin != values.end(); ++begin)
		{
			cout << *begin << " ";
		}
		cout << endl;
	}

	//unique()	删除容器中相邻的重复元素，只保留一份,共有两种语法
	//void unique()
	//void unique（BinaryPredicate）//传入一个二元谓词函数
	//第 2 种格式的优势在于，我们能自定义去重的规则，例如
	{
		list<double> mylist{ 1,1.2,1.2,3,4,4.5,4.6 };
		//删除相邻重复的元素，仅保留一份
		mylist.unique();//{1, 1.2, 3, 4, 4.5, 4.6}
		for (auto it = mylist.begin(); it != mylist.end(); ++it)
			cout << *it << ' ';
		cout << endl;
		//demo 为二元谓词函数，是我们自定义的去重规则
		mylist.unique(demo);
		for (auto it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << *it << ' ';
		cout << endl;
	}

	//remove_if()	删除容器中满足条件的元素
	//通过将自定义的谓词函数（不限定参数个数）传给 remove_if() 成员函数，
	//list 容器中能使谓词函数成立的元素都会被删除
	{
		std::list<int> mylist{ 15, 36, 7, 17, 20, 39, 4, 1 };
		//删除 mylist 容器中能够使 lamba 表达式成立的所有元素。
		mylist.remove_if([](int value) {return (value < 10); }); //{15 36 17 20 39}
		for (auto it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << *it << ' ';
		cout << endl;
	}


	/*C++ STL forward_list容器完全攻略*/
	//forward_list 是 C++ 11 新添加的一类容器，其底层实现和 list 容器一样，
	//采用的也是链表结构，只不过 forward_list 使用的是单链表，而 list 使用的是双向链表
	/*存储相同个数的同类型元素，单链表耗用的内存空间更少，空间利用率更高，
	s并且对于实现某些操作单链表的执行效率也更高。效率高是选用
	forward_list 而弃用 list 容器最主要的原因，换句话说，
	只要是 list 容器和 forward_list 容器都能实现的操作，应优先选择 forward_list 容器。*/
	//---创建forward_list容器和创建list容器基本相同
	//表中部分成员函数的用法
	{
		std::forward_list<int> values{ 1,2,3 };
		values.emplace_front(4);//{4,1,2,3}
		values.emplace_after(values.before_begin(), 5); //{5,4,1,2,3}
		values.reverse();//{3,2,1,4,5}
		for (auto it = values.begin(); it != values.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}
	//forward_list 容器中是不提供 size() 函数的，但如果想要获取 forward_list 
	//容器中存储元素的个数，可以使用头文件 <iterator> 中的 distance() 函数
	{
		std::forward_list<int> my_words{ 1,2,3,4 };
		long long count = std::distance(std::begin(my_words), std::end(my_words));
		cout << count;
		cout << endl;
	}

	//forward_list 容器迭代器的移动除了使用 ++ 运算符单步移动，还能使用 advance() 函数
	{
		std::forward_list<int> values{ 1,2,3,4 };
		auto it = values.begin();
		advance(it, 2);//将 it 迭代器前进或后退 n 个位置。
		while (it != values.end())
		{
			cout << *it << " ";
			++it;
		}
	}


	return 0;
}