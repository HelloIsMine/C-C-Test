//#include<iostream>
//using namespace std;
//class B;
//class A
//{
//public:
//	shared_ptr<B> pb_;
//};
//
//class B
//{
//public:
//	shared_ptr<A> pa_;
//};
//
//int main()
//{
//	////1.auto_ptr auto_ptr要求对它拥有的指针完全占用，两个auto_ptr不能同时拥有同一个普通指针
//	//auto_ptr<string> p1(new string("hello world"));
//	//auto_ptr<string> p2;
//	//p2 = p1;
//	//cout << *p2 << endl;// No error;
//	//cout << *p1 << endl; //Will report error;
//
//	////2.unique_ptr unique_ptr同样是独占式占有指针，为了保证安全，它不允许普通的拷贝和复制，保证了同一时间只有一个智能指针指向该对象；所以当unique_ptr被销毁时，他指向的对象也会被销毁。
//	//unique_ptr<string> p1(new string("hello world"));
//	//unique_ptr<string> p2(new string("I am weijiang"));//仅能定义时进行赋值
//	//cout << *p1 << endl;
//	//cout << *p2 << endl;
//	////p2 = p1; //编译器直接提示错误
//
//	///*3.share_ptr
//	//	hare_ptr是共享式智能指针，允许多个智能指针指向同一个对象；
//	//	默认创建的share_ptr是一个空指针，可以用new和make_ptr初始化，但是不能直接初始化*/
//	//shared_ptr<int> p1(new int(3));
//	//shared_ptr<int> p2 = make_shared<int>(4);
//	//cout << *p1 << endl;
//	//cout << *p2 << endl;
//	//cout << "p1 & = " << p1.use_count() << "p2 & = " << p2.use_count() << endl;
//	//p2 = p1;
//	//cout << *p1 << endl;
//	//cout << *p2 << endl;
//	//cout << "p1 & = " << p1.use_count() << "p2 & = " << p2.use_count() << endl;
//	////shared_ptr<int> p3 = new int(5);//无法赋值初始化
//	shared_ptr<A> pa(new A());
//	shared_ptr<B> pb(new B());
//
//	pa->pb_ = pb;
//	pb->pa_ = pa;
//
//	cout << pa.use_count() << endl;
//	cout << pb.use_count() << endl;
//	return 0;
//}