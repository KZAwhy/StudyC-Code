#include <iostream>
#include <string>
#include <iomanip>//控制格式fixed setw setprecision

using namespace std;

template<typename T>	//C++使用模板函数（也叫函数模板 template function）来实现。
bool biggerThan(const T& lhs, const T& rhs)		//T可以代替string、double、int等
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
	cin.ignore();//让cin把用户为了输入value1而输入的回车吃掉,清空输入缓冲区

	string line;
	/*等待用户输入一行内容*/
	getline(cin, line);//这里用户输入了abcdef和一个回车
	cout << line << endl; //这里输出abcdef和一个回车

	double i = 100 / 3.0; //33.33333333333...... fixed使用小数计数法(而不是科学计数法)显示浮点数
	double you = 200 / 3.0; //66.66666666666......  setprecision(4) 小数部分保留4位，最后一位四舍五入
	cout << fixed << setprecision(7) << i << endl << you << endl;

	cout << "abc > def ? : " << biggerThan("abc", "def") << endl;//使用ASCII码顺序来比较
	cout << "1.0 > 2.0 ? : " << biggerThan(1.0, 2.0) << endl;
	//两个字符串长度相同的时候，按照ASCII码的顺序比较大小。
	//两个字符串长度不相同的时候，先比较开头的部分，再比较长度，具体参考下面的示例代码
	string s("123");
	//compare函数返回值为int类型， 1 表示大于；0表示等于；-1表示小于
	cout << s.compare("123") << endl;	//0		s=="123"
	cout << s.compare("1") << endl;		//1		1=1,123比1长，大于
	cout << s.compare("9") << endl;		//1		1<"9"，小于
	cout << s.compare("1234") << endl;	//-1	s<"1234"
	cout << s.compare("129") << endl;	//-1	s<"129"
	cout << (s < "129") << endl;			//true  s<"129"

	int* a = new int;//创建一个地址变量a存储了堆上一个无名变量的地址。堆变量申请
	*a = 99;//解引用：用乘法符号和地址变量结合得到无名整形变量。并给无名变量赋值2
	cout << *a << endl;//输出无名变量的值
	delete a;//释放a指向的无名变量(堆变量)

	//动态整形数组的每一个元素是一个整数。
	int* a = new int[10];//申请数组
	for (int i = 0; i < 10; ++i)
	{
		a[i] = 0;//a[i]得到变量的引用
		*(a + i) = 0;// 和上一行等价的写法
	}
	delete[] a;//释放数组


	return 0;

}