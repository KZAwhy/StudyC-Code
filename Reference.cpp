#include <iostream>

using namespace std;

//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//返回局部变量引用
int& test01() {
	int a = 10; //局部变量
	return a;	//warning C4172: 返回局部变量或临时变量的地址: a
}

//返回静态变量引用，全局区
int& test02() {
	static int a = 20;
	return a;
}

//引用使用的场景，通常用来修饰形参
void showValue(const int& v) {
	//v += 10;  
	//error C3892: “v”: 不能给常量赋值
	cout << v << endl;
}

//发现是引用，转换为 int* const ref = &a;
void func(int& ref) {
	ref = 100; // ref是引用，转换为*ref = 100
	cout << "ref:" << ref << endl;
}

int main()
{
	//作用： 给变量起别名
	//语法：数据类型& 别名 = 原名
	{
		int a = 10;
		int& b = a;//引用必须初始化,一旦初始化后，就不可以更改
		cout << "a = " << a;
		cout << "   b = " << b << endl;

		b = 79;//这是赋值操作,使a=100
		cout << "a = " << a;
		cout << "   b = " << b << endl;

		int c = 56;
		b = c;//这是赋值操作，不是更改引用
		cout << "a = " << a;
		cout << "   b = " << b << endl;
	}
	cout << endl;

	//引用做函数参数
	//函数传参时，可以利用引用的技术让形参修饰实参,可以简化指针修改实参
	{
		int a = 10;
		int b = 20;

		mySwap01(a, b);
		cout << "a:" << a << " b:" << b << endl;//值传递，没有返回，形参改变，实参不变

		mySwap02(&a, &b);
		cout << "a:" << a << " b:" << b << endl;//地址传递，改变实参，形参修饰实参

		mySwap03(a, b);
		cout << "a:" << a << " b:" << b << endl;//引用传递，改变实参，形参修饰实参
		//通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单
	}
	cout << endl;

	//引用做函数返回值，引用是可以作为函数的返回值存在的，
	//1.不要返回局部变量引用，
	//2.函数调用作为左值
	{
		//不能返回局部变量的引用
		int& ref = test01();
		cout << "ref = " << ref << endl;//数值错乱
		cout << "ref = " << ref << endl;

		//如果函数做左值，那么必须返回引用
		int& ref2 = test02();//静态常量
		cout << "ref2 = " << ref2 << endl;//数值正确
		cout << "ref2 = " << ref2 << endl;

		test02() = 1000;//如果函数返回值是引用，这个函式可以做为左值用

		cout << "ref2 = " << ref2 << endl;
		cout << "ref2 = " << ref2 << endl;
	}
	cout << endl;

	//引用的本质：引用的本质在c++内部实现是一个指针常量
	//C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了
	{
		int a = 10;

		//自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
		int& ref = a;
		ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;

		cout << "a:" << a << endl;
		cout << "ref:" << ref << endl;

		func(a);
	}
	cout << endl;

	//常量引用：常量引用主要用来修饰形参，防止误操作
	//在函数形参列表中，可以加==const修饰形参==，防止形参改变实参
	{
		//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
		//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
		const int& ref = 10;
		//ref = 100;  //加入const后不可以修改变量
		cout << ref << endl;
		//函数中利用常量引用防止误操作修改实参
		int a = 10;
		showValue(a);

	}
	cout << endl;

	return 0;
}