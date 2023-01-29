#include <iostream>

using namespace std;

//1. ֵ����
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. ��ַ����
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. ���ô���
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//���ؾֲ���������
int& test01() {
	int a = 10; //�ֲ�����
	return a;	//warning C4172: ���ؾֲ���������ʱ�����ĵ�ַ: a
}

//���ؾ�̬�������ã�ȫ����
int& test02() {
	static int a = 20;
	return a;
}

//����ʹ�õĳ�����ͨ�����������β�
void showValue(const int& v) {
	//v += 10;  
	//error C3892: ��v��: ���ܸ�������ֵ
	cout << v << endl;
}

//���������ã�ת��Ϊ int* const ref = &a;
void func(int& ref) {
	ref = 100; // ref�����ã�ת��Ϊ*ref = 100
	cout << "ref:" << ref << endl;
}

int main()
{
	//���ã� �����������
	//�﷨����������& ���� = ԭ��
	{
		int a = 10;
		int& b = a;//���ñ����ʼ��,һ����ʼ���󣬾Ͳ����Ը���
		cout << "a = " << a;
		cout << "   b = " << b << endl;

		b = 79;//���Ǹ�ֵ����,ʹa=100
		cout << "a = " << a;
		cout << "   b = " << b << endl;

		int c = 56;
		b = c;//���Ǹ�ֵ���������Ǹ�������
		cout << "a = " << a;
		cout << "   b = " << b << endl;
	}
	cout << endl;

	//��������������
	//��������ʱ�������������õļ������β�����ʵ��,���Լ�ָ���޸�ʵ��
	{
		int a = 10;
		int b = 20;

		mySwap01(a, b);
		cout << "a:" << a << " b:" << b << endl;//ֵ���ݣ�û�з��أ��βθı䣬ʵ�β���

		mySwap02(&a, &b);
		cout << "a:" << a << " b:" << b << endl;//��ַ���ݣ��ı�ʵ�Σ��β�����ʵ��

		mySwap03(a, b);
		cout << "a:" << a << " b:" << b << endl;//���ô��ݣ��ı�ʵ�Σ��β�����ʵ��
		//ͨ�����ò���������Ч��ͬ����ַ������һ���ġ����õ��﷨�������
	}
	cout << endl;

	//��������������ֵ�������ǿ�����Ϊ�����ķ���ֵ���ڵģ�
	//1.��Ҫ���ؾֲ��������ã�
	//2.����������Ϊ��ֵ
	{
		//���ܷ��ؾֲ�����������
		int& ref = test01();
		cout << "ref = " << ref << endl;//��ֵ����
		cout << "ref = " << ref << endl;

		//�����������ֵ����ô���뷵������
		int& ref2 = test02();//��̬����
		cout << "ref2 = " << ref2 << endl;//��ֵ��ȷ
		cout << "ref2 = " << ref2 << endl;

		test02() = 1000;//�����������ֵ�����ã������ʽ������Ϊ��ֵ��

		cout << "ref2 = " << ref2 << endl;
		cout << "ref2 = " << ref2 << endl;
	}
	cout << endl;

	//���õı��ʣ����õı�����c++�ڲ�ʵ����һ��ָ�볣��
	//C++�Ƽ������ü�������Ϊ�﷨���㣬���ñ�����ָ�볣�����������е�ָ�����������������������
	{
		int a = 10;

		//�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
		int& ref = a;
		ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;

		cout << "a:" << a << endl;
		cout << "ref:" << ref << endl;

		func(a);
	}
	cout << endl;

	//�������ã�����������Ҫ���������βΣ���ֹ�����
	//�ں����β��б��У����Լ�==const�����β�==����ֹ�βθı�ʵ��
	{
		//int& ref = 10;  ���ñ�����Ҫһ���Ϸ����ڴ�ռ䣬������д���
		//����const�Ϳ����ˣ��������Ż����룬int temp = 10; const int& ref = temp;
		const int& ref = 10;
		//ref = 100;  //����const�󲻿����޸ı���
		cout << ref << endl;
		//���������ó������÷�ֹ������޸�ʵ��
		int a = 10;
		showValue(a);

	}
	cout << endl;

	return 0;
}