#include <iostream>
#include <string>
#include <vector>	//vector�ж�̬���飬��һ�ִ�ű���������(����)
#include <list>		//list˫����������
#include <array>	//array ������ C++ 11 ��׼����������������
#include <forward_list>		//C++ 11 ��׼��������������list����
#include <iterator>			//ͷ�ļ� <iterator> �е� distance() ����

using namespace std;

bool demo(double first, double second)
{
	return (int(first) == int(second));
}

int main()
{
	//2.3����
	//list˫���������������������ĵײ�����˫���������ʽʵ�ֵġ�
	//list �����е�Ԫ�ؿ��Է�ɢ�洢���ڴ�ռ�������Ǳ���洢��һ�����������ڴ�ռ��С�
	//ʵ�ʳ����У������Ҫ�����н��д�����ӻ�ɾ��Ԫ�صĲ�������ֱ�ӷ���Ԫ�ص�����ȴ���٣������������ʹ�� list �����洢���С�
	//���ƣ�����������������֪���κ�λ�ÿ��ٲ����ɾ��Ԫ��,������ list �������ƶ�Ԫ��
	//ȱ���ǣ��������� array �� vector ������ͨ��λ��ֱ�ӷ���Ԫ�ء�
	list<int> values;			//����һ��û���κ�Ԫ�صĿ� list ����
	list<int> values1(10);		//����һ������ n ��Ԫ�ص� list ����
	list<int> values2(10, 5);	//������һ������ 10 ��Ԫ�ز���ֵ��Ϊ 5 �� values ����
	list<int> values3(values1);	//���� list ����������£�ͨ���������������Դ����µ� list ����
	//���ô˷�ʽ�����뱣֤�¾������洢��Ԫ������һ�¡�

	//ͨ��������������������������ͨ���飩��ָ�������ڵ�Ԫ�أ����Դ����µ� list ����
	//������ͨ���飬����list����
	int a[] = { 1,2,3,4,5 };
	std::list<int> values4(a, a + 5);
	//�����������͵����������� list ����
	std::array<int, 5>arr{ 11,12,13,14,15 };
	std::list<int>values5(arr.begin() + 2, arr.end());//����arr�����е�{13,14,15}
	//�����������Ԫ��
	values.push_back(3);
	values.push_back(2);
	values.push_back(9);
	values.push_back(7);
	cout << "values size��" << values.size() << endl;
	//�������е�Ԫ�ؽ�������
	values.sort();
	//ʹ�õ��������list�����е�Ԫ��
	for (std::list<int>::iterator it = values.begin(); it != values.end(); ++it)
	{
		std::cout << *it << " ";
	}
	cout << endl;


	/*C++ STL list���������÷����*/
	//list �������������Ĳ�ͬ���ڣ����䱸�ĵ���������Ϊ˫�����������������������ʵ�������
	//����֧��ʹ�� ++p1�� p1++�� p1--�� p1++�� *p1�� p1==p2 �Լ� p1!=p2 �����������֧�����²��������� i Ϊ������
	//p1[i]������ͨ���±���� list ������ָ��λ�ô���Ԫ�ء�
	//p1 -= i�� p1 += i�� p1 + i ��p1 - i��˫������� p1 ��֧��ʹ�� -= �� += �� + �� - �������
	//p1<p2�� p1>p2�� p1 <= p2�� p1 >= p2��˫������� p1��p2 ��֧��ʹ�� <�� >�� <= �� >= �Ƚ��������

	//�������������ʾ�����ʹ�ñ� 1 �еĵ��������� list �����еĸ���Ԫ�ء�
	//���� list ����
	std::list<char> values6{ 'h','t','t','p',':','/','/','c','.','b','i','a','n','c','h','e','n','g','.','n','e','t' };
	//ʹ��begin()/end()���������������list�����е�Ԫ��,����
	for (std::list<char>::iterator it = values6.begin(); it != values6.end(); ++it) {
		std::cout << *it;
	}
	cout << endl;
	//ʹ�� rbegin()/rend()������������� lsit �����е�Ԫ�أ�����
	for (std::list<char>::reverse_iterator it = values6.rbegin(); it != values6.rend(); ++it) {
		std::cout << *it;
	}
	cout << endl;
	//�����бȽϵ�����֮��Ĺ�ϵ���õ��� != ���������Ϊ����֧�� < ���������
	//������ʵ�ʳ����У����е����������ķ���ֵ�����Դ���ʹ�� auto �ؼ��ֶ���ı�����
	//��Ϊ���������������жϳ��õ����������͡�


	//list �����ڽ��в��루insert()�����Ӻϣ�splice()���Ȳ���ʱ�����������ԭ�е� list ������ʧЧ��
	//��������ɾ����������ֻ��ָ��ɾ��Ԫ�صĵ�����ʧЧ�����������������κ�Ӱ�졣������
	//���� begin �� end ������
	std::list<char>::iterator begin = values6.begin();
	std::list<char>::iterator end = values6.end();
	//ͷ����β�������ַ� '1'
	values6.insert(begin, '1');
	values6.insert(end, '1');
	while (begin != end)
	{
		std::cout << *begin;
		++begin;
	}
	//�ڽ��в������֮����ʹ����ǰ�����ĵ���������������
	//��Ȼ���򲻻���������ڲ���λ�õĲ�ͬ�����ܻ���©�²����Ԫ�ء�
	cout << endl;


	/*C++ list��STL list������Ԫ�صļ��ַ���*/
	//list ������֧��������ʣ�δ�ṩ�±������ [] �� at() ��Ա������Ҳû���ṩ data() ��Ա����
	//ͨ�� front() �� back() ��Ա���������Էֱ��� list �����е�һ��Ԫ�غ����һ��Ԫ�ص�������ʽ
	std::list<int> mylist{ 1,2,3,4 };
	int& first = mylist.front();
	int& last = mylist.back();
	cout << first << " " << last << endl;
	first = 10;
	last = 20;
	cout << mylist.front() << " " << mylist.back() << endl;
	//ͨ�� front() �� back() �ķ���ֵ�����ǲ����ֱܷ��ȡ��ǰ list �����е���βԪ�أ���Ҫʱ�����޸����ǵ�ֵ

	//�������� list �ݴ洢������Ԫ�أ���ֻ��ʹ�� list �����ĵ�����������
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
	//���ڷ� const ���͵� list �������������������Է��������е�Ԫ�أ�Ҳ���Զ�ָ��Ԫ�ص�ֵ�����޸ġ�
	//�����޸�����ָ��Ԫ�ص�ֵ��list ģ�����ṩ��ר�ŵĳ�Ա���� assign()


	/*C++ STL list��ӣ����룩Ԫ�ط������*/
	/*push_front()���� list �����׸�Ԫ��ǰ�����Ԫ�أ�
	push_back()���� list �������һ��Ԫ�غ������Ԫ�أ�
	emplace_front()���������׸�Ԫ��ǰֱ�������µ�Ԫ�أ�
	emplace_back()�����������һ��Ԫ�غ�ֱ�������µ�Ԫ�أ�
	emplace()����������ָ��λ��ֱ�������µ�Ԫ�أ�
	insert()����ָ��λ�ò�����Ԫ�أ�
	splice()�������� list �����洢�Ķ��Ԫ����ӵ���ǰ list ������ָ��λ�ô���*/
	//���� insert() �� splice() �����ж����﷨��ʽ�⣬������Ա���������� 1 ���﷨��ʽ
	std::list<int> values7{ 1,2,3 };
	values7.push_front(0);//{0,1,2,3}
	values7.push_back(4); //{0,1,2,3,4}
	values7.emplace_front(-1);//{-1,0,1,2,3,4}
	values7.emplace_back(5);  //{-1,0,1,2,3,4,5}
	//����Ҫ���ǣ�ʵ��ͬ���Ĺ��ܣ�emplace ϵ�з�����ִ��Ч�ʸ��ߡ�
	//emplace(pos,value),���� pos ��ʾָ��λ�õĵ�������valueΪҪ�����Ԫ��ֵ
	values7.emplace(values7.end(), 6);//{-1,0,1,2,3,4,5,6}
	for (auto p = values7.begin(); p != values7.end(); ++p) {
		cout << *p << " ";
	}
	cout << endl;

	//����ĳ�����ʾ�����ʹ�� insert() ������ list �����в���Ԫ��
	std::list<int> values8{ 1,2 };
	//��һ�ָ�ʽ�÷�
	values8.insert(values8.begin(), 3);//{3,1,2}
	//�ڶ��ָ�ʽ�÷�
	values8.insert(values8.end(), 2, 5);//{3,1,2,5,5}
	//�����ָ�ʽ�÷�
	//iterator insert(pos,first,last) 
	//�ڵ����� pos ָ����λ��֮ǰ�������������������� array��vector��deque �ȣ� 
	//��λ��[first,last) ���������Ԫ�أ������ر�ʾ��һ���²���Ԫ��λ�õĵ�������
	std::array<int, 3>test{ 7,8,9 };
	values8.insert(values8.end(), test.begin(), test.end());//{3,1,2,5,5,7,8,9}
	//�����ָ�ʽ�÷�
	values8.insert(values8.end(), { 10,11 });//{3,1,2,5,5,7,8,9,10,11}
	for (auto p = values8.begin(); p != values8.end(); ++p)
	{
		cout << *p << " ";
	}
	cout << endl;

	{
		//�� insert() ��Ա������ȣ�splice() ��Ա���������ö��������� list ������
		// �书���ǽ����� list �����е�Ԫ����ӵ���ǰ list ������ָ��λ�ô���
		//��������ʼ�� 2 �� list ����
		list<int> mylist1{ 1,2,3,4 }, mylist2{ 10,20,30 };
		list<int>::iterator it = ++mylist1.begin(); //ָ�� mylist1 �����е�Ԫ�� 2

		//���õ�һ���﷨��ʽ
		mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
		// mylist2:
		// it ��������Ȼָ��Ԫ�� 2��ֻ����������Ϊ�� mylist1
		//���õڶ����﷨��ʽ���� it ָ���Ԫ�� 2 �ƶ��� mylist2.begin() λ�ô�
		mylist2.splice(mylist2.begin(), mylist1, it);   // mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// it ��Ȼָ��Ԫ�� 2

		//���õ������﷨��ʽ���� [mylist1.begin(),mylist1.end())��Χ�ڵ�Ԫ���ƶ��� mylist2.begin() λ�ô�                  
		mylist2.splice(mylist2.begin(), mylist1, mylist1.begin(), mylist1.end());//mylist1:
		//mylist2:1 10 20 30 3 4 2

		cout << "mylist1 ���� " << mylist1.size() << "��Ԫ��" << endl;
		cout << "mylist2 ���� " << mylist2.size() << "��Ԫ��" << endl;
		//��� mylist2 �����д洢������
		cout << "mylist2:";
		for (auto iter = mylist2.begin(); iter != mylist2.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
	}


	/*C++ STL listɾ��Ԫ�����*/
	//pop_front()��pop_back() �� clear() ���÷��ǳ���
	{
		list<int>values9{ 1,2,3,4 };
		//ɾ����ǰ�������׸�Ԫ��
		values9.pop_front();//{2,3,4}
		//ɾ����ǰ�������һ��Ԫ��
		values9.pop_back();//{2,3}
		//���������ɾ�����������е�Ԫ��
		values9.clear(); //{}
		cout << "values9 ���� " << values9.size() << "��Ԫ��" << endl;
	}

	//iterator erase (iterator position);
	//��ʵ��ɾ�� list ������ position ��������ָλ�ô���Ԫ��
	{
		list<int>values{ 1,2,3,4,5 };
		//ָ��Ԫ�� 1 �ĵ�����
		auto del = values.begin();
		//���������ƣ���Ϊָ��Ԫ�� 2
		++del;
		values.erase(del); //{1,3,4,5}
		for (auto begin = values.begin(); begin != values.end(); ++begin)
		{
			cout << *begin << " ";
		}
		cout << endl;
	}

	//iterator erase (iterator first, iterator last);
	//��ʵ��ɾ�� list ������ first �������� last �������޶������ڵ�����Ԫ��
	//������ first ָ���Ԫ�أ��������� last ָ���Ԫ�أ�
	{
		list<int>values{ 1,2,3,4,5 };
		//ָ��ɾ���������߽�
		auto first = values.begin();
		++first;//ָ��Ԫ�� 2
		//ָ��ɾ��������ұ߽�
		auto last = values.end();
		--last;//ָ��Ԫ�� 5
		//ɾ�� 2��3 �� 4
		values.erase(first, last);
		for (auto begin = values.begin(); begin != values.end(); ++begin)
		{
			cout << *begin << " ";
		}
		cout << endl;
	}

	//erase() ��Ա�����ǰ��ձ�ɾ��Ԫ�����ڵ�λ����ִ��ɾ��������
	//��������Ԫ�ص�ֵ��ִ��ɾ������������ʹ�� remove() ��Ա����
	{
		list<char>values{ 'a','b','c','d','c','w' };
		values.remove('c');		//ɾ�����������е��� val ��Ԫ�ء�
		for (auto begin = values.begin(); begin != values.end(); ++begin)
		{
			cout << *begin << " ";
		}
		cout << endl;
	}

	//unique()	ɾ�����������ڵ��ظ�Ԫ�أ�ֻ����һ��,���������﷨
	//void unique()
	//void unique��BinaryPredicate��//����һ����Ԫν�ʺ���
	//�� 2 �ָ�ʽ���������ڣ��������Զ���ȥ�صĹ�������
	{
		list<double> mylist{ 1,1.2,1.2,3,4,4.5,4.6 };
		//ɾ�������ظ���Ԫ�أ�������һ��
		mylist.unique();//{1, 1.2, 3, 4, 4.5, 4.6}
		for (auto it = mylist.begin(); it != mylist.end(); ++it)
			cout << *it << ' ';
		cout << endl;
		//demo Ϊ��Ԫν�ʺ������������Զ����ȥ�ع���
		mylist.unique(demo);
		for (auto it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << *it << ' ';
		cout << endl;
	}

	//remove_if()	ɾ������������������Ԫ��
	//ͨ�����Զ����ν�ʺ��������޶��������������� remove_if() ��Ա������
	//list ��������ʹν�ʺ���������Ԫ�ض��ᱻɾ��
	{
		std::list<int> mylist{ 15, 36, 7, 17, 20, 39, 4, 1 };
		//ɾ�� mylist �������ܹ�ʹ lamba ���ʽ����������Ԫ�ء�
		mylist.remove_if([](int value) {return (value < 10); }); //{15 36 17 20 39}
		for (auto it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << *it << ' ';
		cout << endl;
	}


	/*C++ STL forward_list������ȫ����*/
	//forward_list �� C++ 11 ����ӵ�һ����������ײ�ʵ�ֺ� list ����һ����
	//���õ�Ҳ������ṹ��ֻ���� forward_list ʹ�õ��ǵ������� list ʹ�õ���˫������
	/*�洢��ͬ������ͬ����Ԫ�أ���������õ��ڴ�ռ���٣��ռ������ʸ��ߣ�
	s���Ҷ���ʵ��ĳЩ�����������ִ��Ч��Ҳ���ߡ�Ч�ʸ���ѡ��
	forward_list ������ list ��������Ҫ��ԭ�򣬻��仰˵��
	ֻҪ�� list ������ forward_list ��������ʵ�ֵĲ�����Ӧ����ѡ�� forward_list ������*/
	//---����forward_list�����ʹ���list����������ͬ
	//���в��ֳ�Ա�������÷�
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
	//forward_list �������ǲ��ṩ size() �����ģ��������Ҫ��ȡ forward_list 
	//�����д洢Ԫ�صĸ���������ʹ��ͷ�ļ� <iterator> �е� distance() ����
	{
		std::forward_list<int> my_words{ 1,2,3,4 };
		long long count = std::distance(std::begin(my_words), std::end(my_words));
		cout << count;
		cout << endl;
	}

	//forward_list �������������ƶ�����ʹ�� ++ ����������ƶ�������ʹ�� advance() ����
	{
		std::forward_list<int> values{ 1,2,3,4 };
		auto it = values.begin();
		advance(it, 2);//�� it ������ǰ������� n ��λ�á�
		while (it != values.end())
		{
			cout << *it << " ";
			++it;
		}
	}


	return 0;
}