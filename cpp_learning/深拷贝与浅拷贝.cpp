//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_Age;
//	int* m_Height;
//	Person()
//	{
//		cout << "Ĭ���޲ι��캯��" << endl;
//	}
//	Person(int age, int height)
//	{
//		m_Age = age;
//		m_Height = new int(height);
//	}
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		m_Height = new int(*p.m_Height);
//	}
//	~Person()
//	{
//		delete m_Height;
//		m_Height = NULL;
//		cout << "������������" << endl;
//	}
//
//};
//void test01()
//{
//	Person p1(10, 170);
//	cout << "p1��age: " << p1.m_Age << "p1��height��" << p1.m_Height << endl;
//	Person p2 = p1;
//	cout << "p2��age: " << p2.m_Age << "p2��height��" << p2.m_Height << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}