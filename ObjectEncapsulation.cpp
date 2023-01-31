#include <iostream>
//面向对象封装，三大特性之一
using namespace std;

//4.1.1圆周率--------------------
const double PI = 3.14;
//1、封装的意义
//将属性和行为作为一个整体，用来表现生活中的事物
//封装一个圆类，求圆的周长
//class代表设计一个类，后面跟着的是类名
class Circle
{
public:						 //访问权限：公共的权限
	int m_r = 0;				 //属性：半径
	double calculateZC()	 //行为：获取到圆的周长
	{
		return  2 * PI * m_r;//2 * pi  * r；获取圆的周长
	}
};
//--------------------------------------------------
//学生类
class Student {

public:
	void setName(string name) {
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}
	void showStudent() {
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
public:
	string m_name;
	int m_id = 0;
};
//2.封装的意义
class Person
{
public:
	string m_Name;//姓名  公共权限	
protected:
	string m_Car;//汽车  保护权限
private:
	int m_Password = 0;//银行卡密码  私有权限
public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

//4.1.2 struct和class区别----------------------
class C1
{
	int  m_A; //默认是私有权限
};

struct C2
{
	int m_A;  //默认是公共权限
};

//4.1.3 成员属性设置为私有----------------------
class Person1 {
public:
	void setName(string name)
	{
		m_Name = name;
	}//姓名设置可读可写
	string getName()
	{
		return m_Name;
	}

	int getAge()
	{
		return m_Age;
	}//获取年龄 

//设置年龄
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "你个老妖精!" << endl;
			return;
		}
		m_Age = age;
	}

	//情人设置为只写
	void setLover(string lover) {
		m_Lover = lover;
	}
private:
	string m_Name; //可读可写  姓名
	int m_Age = 0; //只读  年龄
	string m_Lover; //只写  情人
};




int main()
{
	//4.1.1封装的意义----------------------------------------------------------
	//1.将属性和行为作为一个整体，表现生活中的事物： 在设计类的时候，属性和行为写在一起，表现事物
	//语法：class 类名{   访问权限： 属性  / 行为  };
	{	//例1：求圆周长
		//通过圆类，创建圆的对象；c1就是一个具体的圆
		Circle c1;
		c1.m_r = 10; //给圆对象的半径 进行赋值操作
		//2 * pi * 10 = = 62.8
		cout << "圆的周长为： " << c1.calculateZC() << endl;

		//例2：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
		Student stu;
		stu.setName("德玛西亚");
		stu.setID(250);
		stu.showStudent();
	}
	cout << endl;

	//2.类在设计时，可以把属性和行为放在不同的权限下，加以控制,访问权限有三种：
	//公共权限  public     类内可以访问  类外可以访问
	//保护权限  protected  类内可以访问  类外不可以访问
	//私有权限  private    类内可以访问  类外不可以访问
	{
		Person p;
		p.m_Name = "李四";
		//p.m_Car = "奔驰";  //保护权限类外访问不到
		//p.m_Password = 123; //私有权限类外访问不到
	}
	cout << endl;

	//4.1.2 struct和class区别----------------------------------------------------------
	//struct 默认权限为公共,class 默认权限为私有
	{
		C1 c1{};
		//c1.m_A = 10; //错误，访问权限是私有

		C2 c2{};
		c2.m_A = 10; //正确，访问权限是公共
	}
	cout << endl;

	//4.1.3 成员属性设置为私有------------------------------------
	{
		Person1 p;
		//姓名设置
		p.setName("张三");
		cout << "姓名： " << p.getName() << endl;

		//年龄设置
		p.setAge(50);
		cout << "年龄： " << p.getAge() << endl;

		//情人设置
		p.setLover("设置");
		//cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取
	}
	return 0;
}