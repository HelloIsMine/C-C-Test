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
//	////1.auto_ptr auto_ptrҪ�����ӵ�е�ָ����ȫռ�ã�����auto_ptr����ͬʱӵ��ͬһ����ָͨ��
//	//auto_ptr<string> p1(new string("hello world"));
//	//auto_ptr<string> p2;
//	//p2 = p1;
//	//cout << *p2 << endl;// No error;
//	//cout << *p1 << endl; //Will report error;
//
//	////2.unique_ptr unique_ptrͬ���Ƕ�ռʽռ��ָ�룬Ϊ�˱�֤��ȫ������������ͨ�Ŀ����͸��ƣ���֤��ͬһʱ��ֻ��һ������ָ��ָ��ö������Ե�unique_ptr������ʱ����ָ��Ķ���Ҳ�ᱻ���١�
//	//unique_ptr<string> p1(new string("hello world"));
//	//unique_ptr<string> p2(new string("I am weijiang"));//���ܶ���ʱ���и�ֵ
//	//cout << *p1 << endl;
//	//cout << *p2 << endl;
//	////p2 = p1; //������ֱ����ʾ����
//
//	///*3.share_ptr
//	//	hare_ptr�ǹ���ʽ����ָ�룬����������ָ��ָ��ͬһ������
//	//	Ĭ�ϴ�����share_ptr��һ����ָ�룬������new��make_ptr��ʼ�������ǲ���ֱ�ӳ�ʼ��*/
//	//shared_ptr<int> p1(new int(3));
//	//shared_ptr<int> p2 = make_shared<int>(4);
//	//cout << *p1 << endl;
//	//cout << *p2 << endl;
//	//cout << "p1 & = " << p1.use_count() << "p2 & = " << p2.use_count() << endl;
//	//p2 = p1;
//	//cout << *p1 << endl;
//	//cout << *p2 << endl;
//	//cout << "p1 & = " << p1.use_count() << "p2 & = " << p2.use_count() << endl;
//	////shared_ptr<int> p3 = new int(5);//�޷���ֵ��ʼ��
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