#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

int main()
{
	// map��c++�з���Ϊӳ��,��STL�����ı�׼ģ��⣩��һ�������������ֵ䣩��
	// ���������key��ֵ��value����������map�ļ���key���������������ظ���һ������Ӧ��һ��ֵ
	// valueΪ�ؼ��ֵ�ֵ�������ظ���map�е�Ԫ�ػ��Զ����򣬲�����ɾ�Ĳ������϶��ܿ�

	// 1.map�Ķ���
	// ��ʽΪmap<typename1��typename2> universities������typename1Ϊ�������ͣ�typename2Ϊֵ������
	// ����һ��key��value�����Ͷ���������map�����ѧ����ѧ�źͳɼ�
	map<int, int> student_score{
		// ѧ�Ų��������ظ�
		// ѧ�ſ��Բ���˳�򴴽�
		// ѧ���ڴ������֮������ڲ��Զ��ź�˳��
		// ѧ�������մ�С˳��int���͵����ݾͰ���ֵ��С����
		{003, 90},
		{004, 88},
		{001, 88}, // ������������ͬ�ķ���
		{002, 78},
	}; // �������봴����map�����ݻ��Զ�����key�ź�˳��

	// item����������student_score ��ÿһ��Ԫ��
	for (auto item : student_score)
	{
		// item��һ��pair<int, int>����
		cout << "id=" << item.first << " "
			<< " score=" << item.second << endl;
	}

	// ʵ��һ����ѧ�ļ�ƺ�ȫ�ƶ�Ӧ��ϵ��map
	map<string, string> universities;
	universities["MIT"] = "��ʡ��ѧԺ Massachussets  Institute of Technology";
	// ����Ĵ��뿴�����Ǹ�Ԫ�ظ�ֵ��ʵ����������Ԫ�ز����ڣ���ᴴ�����Ԫ�أ����Էǳ�����
	cout << "size=" << universities.size() << endl; // �ɼ�Ԫ��������1��
	cout << universities["MIT"] << endl;            // ����ȡ�����keyΪ��MIT����Ԫ�ص�value�����
	// ʹ��insert��Ա��������Ԫ�أ�
	universities.insert({ "Harvard", "�����ѧ" });
	cout << "size=" << universities.size() << endl;
	cout << universities["Harvard"] << endl;


	{
		// ��ʼ��map
		// map���Զ��Բ����Ԫ�ذ���key��С��������
		// ����key��string���ͣ�����ʹ��string��С�ں�������
		// string��С�ںűȽϴ�С����ASCII�����ĸ������
		map<string, string> universities1{
			{"MIT", "��ʡ��ѧԺ Massachussets  Institute of Technology"},
			{"UCB", "���ݴ�ѧ��������У University of  California - Berkeley"},
			{"CMU", "���ڻ�÷¡��ѧ Carnegie Mellon  University"},
			{"CC", "���ױ��Ǵ�ѧ Columbia University  /Community College"},
			{"CU", "���ζ���ѧ Cornell University"},
			{"UNC", "���������ɴ�ѧ University of North  Carolina - Chapel Hill"},
			{"UWM", "��˹������ѧ���ѷ��У University of  Wisconsin - Madison"},
			{"GWU", "���λ�ʢ�ٴ�ѧ George Washington  University"},
			{"JHU", "Լ�����ս�˹��ѧ Johns Hopkins  University"},
			{"MSU", "��Ъ��������ѧ Michigan State  University"},
		};

		// ����ʱ����ҵ����Ҫ������һ����¼
		universities1["Penn"] = "��Ϧ�����Ǵ�ѧ University of  Pennsylvania";

		// ������ĸ��˳��������д�ѧ
		cout << "All " << universities1.size() << " universities:" << endl;
		for (auto& item : universities1)
		{
			cout << "key=" << item.first << " , value= " << item.second << endl;
		}
	}
	//map��ÿһ��Ԫ�ذ���������key��value��
	//key�ڲ����Ͳ��ٿ��Ըı䣬���Ա�ɾ����ͬʱ��Ӧ��valueһ��ɾ������
	//key��Ӧ��value���Ա����ʺͶ�д��
	//mapʹ��������[]����������ȡkey��Ӧ��value��
	//map��Ԫ���ڲ���Ĺ����л��Զ�����ʹ��С�ں� < ��Ԫ�ذ���key���򣩡�

	system("pause");
	return 0;
}