//#include<iostream>
//using namespace std;
//class MyInteger
//{
//public:
//	int number;
//	MyInteger()
//	{
//		number = 0;
//	}
//	MyInteger operator++()
//	{
//		number++;
//		return *this;
//	}
//
//	MyInteger operator++(int)
//	{
//		MyInteger temp;
//		temp.number = this->number;
//		this->number++;
//		return temp;
//	}
//};
//
//ostream& operator<<(ostream & coutm, MyInteger myinteger)
//{
//	cout << myinteger.number;
//	return cout;
//}
//
//void test01(){
//	MyInteger myInteger;
//	/*cout << ++(++myInteger) << endl;
//	cout << myInteger << endl;*/
//	cout << myInteger++ << endl;
//	cout << myInteger << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}