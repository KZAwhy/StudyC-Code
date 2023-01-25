#include <iostream>
#include <string>
#include <vector>	//vector�ж�̬���飬��һ�ִ�ű���������(����)

using namespace std;

int main()
{
	//2.1����
	/*�䳤���飨������*/
	vector<int> arr;//����������һ��ʼ����û���κ�Ԫ�أ����ԣ���ʱ����Ĵ�С��0��
	size_t c = arr.size();//��ʱ����c��ֵΪ0,size������vector�ĳ�Ա������ר����������ʹ�����������������Ԫ���м�����
	cout << c << endl; //c = 0��size_t = unsigned long��64λϵͳ��
	//���ں�������������һ��Բ���ű�ʾ�����Ե���sizeӦ��д��size()
	//����������arr�����Լ��ĳ�Ա�����������ó�Ա���ʲ������������ã�����д��arr.size()
	bool b = arr.empty();
	//�ж������Ƿ�Ϊ�յĳ�Ա������empty()���˺�������һ��boolֵ��
	arr.push_back(25);//arr������һ��Ԫ��25
	//���� push_back��Ա���������������һ���������ͱ�����������������ĳ�ʼֵ����Ϊ25
	int i = arr[0];//���±�λ�ã��ţ�Ϊ0��Ԫ�أ���������ֵ��25����ֵ�����ͱ���i
	cout << arr[0] << endl;
	//��̬����,����ĳ��Ȼ��������Ԫ�ض��䳤�����Խж�̬����
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

	/*�䳤�ַ���*/
	//string��vector<char>������һ���ġ�
	//����string�����˸�����ַ���ר�ŵĲ���������ӷ��������������Ӵ�����ȡ�Ӵ����ַ������еĹ��ܡ�
	//���ԣ�����Ǵ����ַ�����string�ܷ���
	string you_say("I love you");
	cout << "�ַ�������:" << you_say << endl;//�ַ�������ֱ�����
	cout << "�ַ�������:" << you_say.size() << endl;
	cout << "�ַ�������:";
	for (size_t i = 0; i < you_say.size(); ++i)
	{
		cout << you_say[i];//ʹ���±�����ַ���
	}
	cout << endl;
	//ƴ���ַ���
	string i_say = you_say;//���ƹ���һ�����ַ���
	i_say += " too";//�ַ���ƴ��
	cout << "�ַ�������:" << i_say << endl;//�ַ�������ֱ�����


	//2.2������
	//auto �ؼ���,auto ���ڱ��������ʱ���ñ��˵�������Ϊ�Լ����͵�һ�ֶ�������ķ�ʽ��
	int  a = 1;
	auto b1 = a;		//b1������Ϊa������int
	const int a1 = 1;
	int  b2 = a1;		//b2������Ϊint
	auto b3 = a1;	//b3������Ϊint
	//auto& ,auto& a = b; ��ʾ a��b�����ã�������b��ͬ��
	int a2 = 1;
	int& b4 = a2;		//b4��a�ı�����Ҳ�������ã�
	auto& b5 = a2;	//b5��a�ı�����Ҳ�������ã�

	//auto��õĳ����Ƕ��ڸ������͵ļ򻯡�
	//���磬�� ������ �У����ǿ���������ı���vector�Ĵ��룺
	//��ʹ��auto
	vector<int>::iterator i1;  //�������������
	for (i1 = arr.begin(); i1 != arr.end(); ++i1) {  //�õ�������������
		cout << *i1 << " ";  //*i ���ǵ�����iָ���Ԫ��
		*i1 *= 2;  //ÿ��Ԫ�ر�Ϊԭ����2��
	}
	cout << endl;
	//ʹ��auto
	for (auto itr = arr.begin(); itr != arr.end(); ++itr)
	{
		cout << *itr << " "; // ʹ�ý����ò����� * ��õ�������������Ԫ�ص�����
	}
	//�������
	cout << endl;
	for (auto itr = arr.rbegin(); itr != arr.rend(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;

	//���ںܶ��������ṩ�����������ҵ����������Ĵ��뼸��һģһ��
	//���ԣ�C++�������������������򻯳ɷ�Χforѭ����
	//ר������������͵�forѭ����ʹ��ð��:��������������е�ÿһ��Ԫ�ء�
	for (auto& item : arr)
	{
		cout << item << " ";//item����list1��ÿһ��Ԫ��
	}
	cout << endl;

	//���������˱���������Ҳ����ɾ��������Ԫ�ء�
	//ɾ����һ��ָ��ֵ��Ԫ�أ�ʹ�õ�������
	//����Ĵ���Ӱ���{ 1,2,3,4,5,3,9,3 } ��8������������ɾ����һ��3��
	vector<int> arr1{ 1,3,8,4,3,5,3,4,9,3,4 };
	//����
	for (auto item : arr1)
	{
		cout << item << " ";
	}
	cout << endl;
	//ɾ��
	for (auto itr = arr1.begin(); itr != arr1.end(); ++itr)
	{
		if (*itr == 3)
		{
			arr1.erase(itr);//ɾ������������ֵ
			break;
		}
	}
	//���ڴ�ӡ���������ֵ�һ��3û����
	for (auto item : arr1)
	{
		cout << item << " ";
	}
	cout << endl;
	//ɾ����һ��ָ��ֵ��Ԫ�أ�ʹ��find�㷨��
	auto itr1 = find(arr1.begin(), arr1.end(), 3);
	arr1.erase(itr1);// ɾ����1��3

	for (auto item : arr1)
	{
		cout << item << " ";
	}
	cout << endl;
	//ɾ������ָ��Ԫ��
	for (auto itr = arr1.begin(); itr != arr1.end();)
	{
		if (*itr == 3)
		{
			itr = arr1.erase(itr);//���ʵ����++itr��������ָ���˱�ɾ��Ԫ�ص���һ��Ԫ��
		}
		else
		{
			++itr;
		}
	}
	//���ڴ�ӡ����������3û����
	for (auto item : arr1)
	{
		cout << item << " ";
	}
	cout << endl;
	//ɾ������ָ��ֵ��Ԫ�أ�ʹ��remove�㷨��,��Ҫ#include <algorithm>
	/*remove ����Ҫ���������ݽ��յı����������ǰ�棬
	 �����ص�һ����Ӧ�������������Ԫ�صĵ�������
	 ���������շ�Χɾ��
	 remove ֮������Ԫ���������£�
	 1, 2, 4, 5, 9, #, #, #
	*/
	auto itr = remove(arr1.begin(), arr1.end(), 3);
	arr1.erase(itr, arr1.end());// ɾ�� { # # # }

	//now print all int in arr : no 3 anymore.
	for (auto item : arr1)
	{
		cout << item << " ";
	}

	return 0;
}