//#include<iostream>
//using namespace std;
//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();
//	Building* building;
//};
//
//class Building
//{
//	friend class GoodGay;
//public:
//	Building();
//	string livingRoom;
//private:
//	string bedroom;
//};
//
//Building::Building()
//{
//	livingRoom = "����";
//	bedroom = "����";
//}
//
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "�ι�" << building->livingRoom << endl;
//	cout << "�ι�" << building->bedroom << endl;
//}
//
//
//void test01()
//{
//	GoodGay goodGay;
//	goodGay.visit();
//	
//}
//int main()
//{
//	test01();
//	return 0;
//}