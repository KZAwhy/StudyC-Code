#include <iostream>
#include <string>
#include <iomanip>//���Ƹ�ʽfixed setw setprecision

using namespace std;

template<typename T>	//C++ʹ��ģ�庯����Ҳ�к���ģ�� template function����ʵ�֡�
bool biggerThan(const T& lhs, const T& rhs)		//T���Դ���string��double��int��
{
	return lhs > rhs;
}

int main()
{
	int value1 = 0;
	cout << "please init" << endl;
	cin >> value1;
	cout << "output" << endl;
	cout << "value1=" << value1 << endl;
	cin.ignore();//��cin���û�Ϊ������value1������Ļس��Ե�,������뻺����

	string line;
	/*�ȴ��û�����һ������*/
	getline(cin, line);//�����û�������abcdef��һ���س�
	cout << line << endl; //�������abcdef��һ���س�

	double i = 100 / 3.0; //33.33333333333...... fixedʹ��С��������(�����ǿ�ѧ������)��ʾ������
	double you = 200 / 3.0; //66.66666666666......  setprecision(4) С�����ֱ���4λ�����һλ��������
	cout << fixed << setprecision(7) << i << endl << you << endl;

	cout << "abc > def ? : " << biggerThan("abc", "def") << endl;//ʹ��ASCII��˳�����Ƚ�
	cout << "1.0 > 2.0 ? : " << biggerThan(1.0, 2.0) << endl;
	//�����ַ���������ͬ��ʱ�򣬰���ASCII���˳��Ƚϴ�С��
	//�����ַ������Ȳ���ͬ��ʱ���ȱȽϿ�ͷ�Ĳ��֣��ٱȽϳ��ȣ�����ο������ʾ������
	string s("123");
	//compare��������ֵΪint���ͣ� 1 ��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
	cout << s.compare("123") << endl;	//0		s=="123"
	cout << s.compare("1") << endl;		//1		1=1,123��1��������
	cout << s.compare("9") << endl;		//1		1<"9"��С��
	cout << s.compare("1234") << endl;	//-1	s<"1234"
	cout << s.compare("129") << endl;	//-1	s<"129"
	cout << (s < "129") << endl;			//true  s<"129"

	int* a = new int;//����һ����ַ����a�洢�˶���һ�����������ĵ�ַ���ѱ�������
	*a = 99;//�����ã��ó˷����ź͵�ַ������ϵõ��������α�������������������ֵ2
	cout << *a << endl;//�������������ֵ
	delete a;//�ͷ�aָ�����������(�ѱ���)

	//��̬���������ÿһ��Ԫ����һ��������
	int* a = new int[10];//��������
	for (int i = 0; i < 10; ++i)
	{
		a[i] = 0;//a[i]�õ�����������
		*(a + i) = 0;// ����һ�еȼ۵�д��
	}
	delete[] a;//�ͷ�����


	return 0;

}