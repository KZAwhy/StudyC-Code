#include <iostream>
//��������װ����������֮һ
using namespace std;

//4.1.1Բ����--------------------
const double PI = 3.14;
//1����װ������
//�����Ժ���Ϊ��Ϊһ�����壬�������������е�����
//��װһ��Բ�࣬��Բ���ܳ�
//class�������һ���࣬������ŵ�������
class Circle
{
public:						 //����Ȩ�ޣ�������Ȩ��
	int m_r = 0;				 //���ԣ��뾶
	double calculateZC()	 //��Ϊ����ȡ��Բ���ܳ�
	{
		return  2 * PI * m_r;//2 * pi  * r����ȡԲ���ܳ�
	}
};
//--------------------------------------------------
//ѧ����
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
//2.��װ������
class Person
{
public:
	string m_Name;//����  ����Ȩ��	
protected:
	string m_Car;//����  ����Ȩ��
private:
	int m_Password = 0;//���п�����  ˽��Ȩ��
public:
	void func()
	{
		m_Name = "����";
		m_Car = "������";
		m_Password = 123456;
	}
};

//4.1.2 struct��class����----------------------
class C1
{
	int  m_A; //Ĭ����˽��Ȩ��
};

struct C2
{
	int m_A;  //Ĭ���ǹ���Ȩ��
};

//4.1.3 ��Ա��������Ϊ˽��----------------------
class Person1 {
public:
	void setName(string name)
	{
		m_Name = name;
	}//�������ÿɶ���д
	string getName()
	{
		return m_Name;
	}

	int getAge()
	{
		return m_Age;
	}//��ȡ���� 

//��������
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "���������!" << endl;
			return;
		}
		m_Age = age;
	}

	//��������Ϊֻд
	void setLover(string lover) {
		m_Lover = lover;
	}
private:
	string m_Name; //�ɶ���д  ����
	int m_Age = 0; //ֻ��  ����
	string m_Lover; //ֻд  ����
};




int main()
{
	//4.1.1��װ������----------------------------------------------------------
	//1.�����Ժ���Ϊ��Ϊһ�����壬���������е���� ��������ʱ�����Ժ���Ϊд��һ�𣬱�������
	//�﷨��class ����{   ����Ȩ�ޣ� ����  / ��Ϊ  };
	{	//��1����Բ�ܳ�
		//ͨ��Բ�࣬����Բ�Ķ���c1����һ�������Բ
		Circle c1;
		c1.m_r = 10; //��Բ����İ뾶 ���и�ֵ����
		//2 * pi * 10 = = 62.8
		cout << "Բ���ܳ�Ϊ�� " << c1.calculateZC() << endl;

		//��2�����һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
		Student stu;
		stu.setName("��������");
		stu.setID(250);
		stu.showStudent();
	}
	cout << endl;

	//2.�������ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ���,����Ȩ�������֣�
	//����Ȩ��  public     ���ڿ��Է���  ������Է���
	//����Ȩ��  protected  ���ڿ��Է���  ���ⲻ���Է���
	//˽��Ȩ��  private    ���ڿ��Է���  ���ⲻ���Է���
	{
		Person p;
		p.m_Name = "����";
		//p.m_Car = "����";  //����Ȩ��������ʲ���
		//p.m_Password = 123; //˽��Ȩ��������ʲ���
	}
	cout << endl;

	//4.1.2 struct��class����----------------------------------------------------------
	//struct Ĭ��Ȩ��Ϊ����,class Ĭ��Ȩ��Ϊ˽��
	{
		C1 c1{};
		//c1.m_A = 10; //���󣬷���Ȩ����˽��

		C2 c2{};
		c2.m_A = 10; //��ȷ������Ȩ���ǹ���
	}
	cout << endl;

	//4.1.3 ��Ա��������Ϊ˽��------------------------------------
	{
		Person1 p;
		//��������
		p.setName("����");
		cout << "������ " << p.getName() << endl;

		//��������
		p.setAge(50);
		cout << "���䣺 " << p.getAge() << endl;

		//��������
		p.setLover("����");
		//cout << "���ˣ� " << p.m_Lover << endl;  //ֻд���ԣ������Զ�ȡ
	}
	return 0;
}