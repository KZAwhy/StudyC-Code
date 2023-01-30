#include <iostream>

using namespace std;

int func1(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//1. ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴������ң����붼Ҫ��Ĭ��ֵ
//2. �������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ�ϲ���
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

//����ռλ���� ��ռλ����Ҳ������Ĭ�ϲ���
void func3(int a, int) {
	cout << "this is func" << endl;
}

//����������Ҫ��������ͬһ����������
void func()
{
	cout << "func �ĵ��ã�" << endl;
}
void func(int a)
{
	cout << "func (int a) �ĵ��ã�" << endl;
}
void func(double a)
{
	cout << "func (double a)�ĵ��ã�" << endl;
}
void func(int a, double b)
{
	cout << "func (int a ,double b) �ĵ��ã�" << endl;
}
void func(double a, int b)
{
	cout << "func (double a ,int b)�ĵ��ã�" << endl;
}

//��������ֵ��������Ϊ������������
//int func(double a, int b)
//{
//	cout << "func (double a ,int b)�ĵ��ã�" << endl;
//}

//��������ע������
//1��������Ϊ��������

void func4(int& a)
{
	cout << "func (int &a) ���� " << endl;
}

void func4(const int& a)
{
	cout << "func (const int &a) ���� " << endl;
}


//2������������������Ĭ�ϲ���

void func5(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) ����" << endl;
}

void func5(int a)
{
	cout << "func2(int a) ����" << endl;
}



int main()
{
	//����Ĭ�ϲ���
	//��C++�У��������β��б��е��β��ǿ�����Ĭ��ֵ�ġ�
	//�﷨������ֵ����  ������ ������= Ĭ��ֵ��{}
	{
		cout << "ret = " << func1(20, 20) << endl;
		cout << "ret = " << func1(100) << endl;
	}
	cout << endl;


	//����ռλ����,C++�к������β��б��������ռλ������������ռλ�����ú���ʱ�������λ��
	//�﷨:����ֵ���� ������ (��������){}
	{
		func3(10, 10); //ռλ���������
	}
	cout << endl;


	//��������
	//�������ظ���:������������ͬ����߸�����
	//������������������1.ͬһ���������� 2.����������ͬ 3.�����������Ͳ�ͬ���߸�����ͬ����˳��ͬ
	//ע��:�����ķ���ֵ��������Ϊ�������ص�����
	{
		func();
		func(10);
		func(3.14);
		func(10, 3.14);
		func(3.14, 10);
	}
	cout << endl;

	//��������ע������
	//1.������Ϊ�������� 2.����������������Ĭ�ϲ���
	{
		int a = 10;
		func4(a); //������const
		func4(10);//������const

		//func2(10); //����Ĭ�ϲ����������壬��Ҫ����
	}
	cout << endl;

	return 0;
}