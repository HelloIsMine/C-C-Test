//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_A;
//	int m_B;
//	Person()
//	{
//		m_A = 10;
//		m_B = 20;
//	}
//	/*Person operator+(const Person& a)
//	{
//		Person temp;
//		temp.m_A = this->m_A + a.m_A;
//		temp.m_B = this->m_B + a.m_B;
//		return temp;
//	}*/
//};
//
//Person operator+(Person& a, Person& b)
//{
//	Person temp;
//	temp.m_A = a.m_A + b.m_A;
//	temp.m_B = a.m_B + b.m_B;
//	return temp;
//}
//
//void test01()
//{
//	Person a;
//	Person b;
//	Person c;
//	//c = a + b;
//	//c = a.operator+(b);
//	//c = operator+(a, b);
//	cout << "c.m_A = " << c.m_A << " c.m_B = " << c.m_B << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}