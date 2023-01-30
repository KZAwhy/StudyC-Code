#include <iostream>

using namespace std;

int func1(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

//函数占位参数 ，占位参数也可以有默认参数
void func3(int a, int) {
	cout << "this is func" << endl;
}

//函数重载需要函数都在同一个作用域下
void func()
{
	cout << "func 的调用！" << endl;
}
void func(int a)
{
	cout << "func (int a) 的调用！" << endl;
}
void func(double a)
{
	cout << "func (double a)的调用！" << endl;
}
void func(int a, double b)
{
	cout << "func (int a ,double b) 的调用！" << endl;
}
void func(double a, int b)
{
	cout << "func (double a ,int b)的调用！" << endl;
}

//函数返回值不可以作为函数重载条件
//int func(double a, int b)
//{
//	cout << "func (double a ,int b)的调用！" << endl;
//}

//函数重载注意事项
//1、引用作为重载条件

void func4(int& a)
{
	cout << "func (int &a) 调用 " << endl;
}

void func4(const int& a)
{
	cout << "func (const int &a) 调用 " << endl;
}


//2、函数重载碰到函数默认参数

void func5(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 调用" << endl;
}

void func5(int a)
{
	cout << "func2(int a) 调用" << endl;
}



int main()
{
	//函数默认参数
	//在C++中，函数的形参列表中的形参是可以有默认值的。
	//语法：返回值类型  函数名 （参数= 默认值）{}
	{
		cout << "ret = " << func1(20, 20) << endl;
		cout << "ret = " << func1(100) << endl;
	}
	cout << endl;


	//函数占位参数,C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
	//语法:返回值类型 函数名 (数据类型){}
	{
		func3(10, 10); //占位参数必须填补
	}
	cout << endl;


	//函数重载
	//函数重载概述:函数名可以相同，提高复用性
	//函数重载满足条件：1.同一个作用域下 2.函数名称相同 3.函数参数类型不同或者个数不同或者顺序不同
	//注意:函数的返回值不可以作为函数重载的条件
	{
		func();
		func(10);
		func(3.14);
		func(10, 3.14);
		func(3.14, 10);
	}
	cout << endl;

	//函数重载注意事项
	//1.引用作为重载条件 2.函数重载碰到函数默认参数
	{
		int a = 10;
		func4(a); //调用无const
		func4(10);//调用有const

		//func2(10); //碰到默认参数产生歧义，需要避免
	}
	cout << endl;

	return 0;
}