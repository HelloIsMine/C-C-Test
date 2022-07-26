//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//void test01()
//{
//	ofstream ofs;
//	ofs.open("test.txt", ios::out);
//	ofs << "Your name: weijiang" << endl;
//	ofs << "Your phone number: 17673472518" << endl;
//	ofs.close();
//}
//
//void test02()
//{
//	ifstream ifs;
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "the file open failed;" << endl;
//	}
//	//1).
//	/*char buf[1024];
//	while (ifs >> buf)
//	{
//		cout << buf;
//	}*/
//
//	//2).
//	/*char buf[1024];
//	while (ifs.getline(buf, sizeof(buf)))
//	{
//		cout << buf << endl;
//	}*/
//	
//	//3).
//	/*string buf;
//	while (getline(ifs, buf))
//	{
//		cout << buf << endl;
//	}*/
//
//	//4).
//	/*char c;
//	while ((c = ifs.get()) != EOF)
//	{
//		cout << c;
//	}*/
//}
//
//class Person
//{
//public:
//	char name[64];
//	int age;
//};
//
//void test03()
//{
//	ofstream ofs;
//	ofs.open("Person.txt", ios::out | ios::binary);
//	Person p = { "Zhang San", 26 };
//	ofs.write((const char*)&p, sizeof(Person));
//	ofs.close();
//}
//
//void test04()
//{
//	ifstream ifs;
//	ifs.open("Person.txt", ios::in | ios::binary);
//	Person p;
//	ifs.read((char*)&p, sizeof(Person));
//	cout << "p.name = " << p.name << " p.age = " << p.age << endl;
//}
//
//int main()
//{
//	//写文件实例
//	//test01();k
//
//	//读文件实例
//	//test02();
//
//	//写文件（二进制）
//	//test03();
//
//	//读文件(二进制)
//	//test04();
//	return 0;
//}