#include <iostream>                                                    
using namespace std;
//1��const_cast   ����ȡ��const���ԣ�ȥ�����͵�const��volatile���ԣ���const���͵�ָ���Ϊ��const���͵�ָ��
//int main() {
//    const int n = 100;
//    int* p = const_cast<int*>(&n); //&n������Ϊconst int*��ֻ�н�������ת��Ϊint *�ſ��Զ�p������Ϊint *)���и�ֵ                                            �������ܸ��ǳ�����ֵ�����³������ܱ��޸ġ�        
//    *p = 234;                      //����n��ֹ��ջ�ڴ��У���д��Ȩ�޿���ͨ��p���޸�n��ֵ                                                    
//    cout << "n = " << n << endl;
//    cout << "*p = " << *p << endl;
//
//    
//
//    return 0;
//}

//2��dynamic_cast  ��Ҫ�����������°�ȫת�͡���������ĳһ�����Ƿ�����ڼ̳���ϵ�е�ĳһ�����ͣ�������̳в��֮���ת�����Խ����������͵�ת����
//�ڽ�����������ת����ʱ�򣬲����а�ȫ��⡣��Ҫ���ã����������͵�ָ����������ð�ȫ��ת��Ϊ�������͵����ú�ָ�롣
//�﷨��dynamic_cast <type - id> (expression)
//
//���1����� type - id ��ָ�� expression����ȷ�Ŀɷ��ʵ�ֱ�ӻ��ӻ����ָ�룬������ָ�� type - id ���͵�Ψһ�Ӷ����ָ��


//class B {};
//
//class C :public B {};
//
//class D :public C {};
//
//void(D* pd) {
//    C* pc = dynamic_cast<C*>(pd);
//    B* pb = dynamic_cast<B*>(pd);
//}


//���2����� type - id Ϊ void* ����������ʱ���м��ȷ�� expression��ʵ�����͡������ָ�� expression �������Ķ����ָ�롣
//class A { virtual void f(); };
//class B { virtual void f(); };
//
//void f() {
//	A* pa = new A;
//	B* pb = new B;
//	void* pv = dynamic_cast<void*>(pa);// pv now points to an object of type A     
//	pv = dynamic_cast<void*>(pb);// pv now points to an object of type B 
//}

//���3����� expression ������ type - id�Ļ��࣬��������ʱ��������Ƿ� expression ȷʵָ�� type - id���͵���������
//���Ϊ true��������ָ��type - id���͵����������ָ��
class B { virtual void f(); };
class D : public B { virtual void f(); };

void f() {
    B* pb = new D;   // unclear but ok                                            
    B* pb2 = new B;
    D* pd = dynamic_cast<D*>(pb);            // ok: pb actually points to D object                                            
    D* pd2 = dynamic_cast<D*>(pb2);        // pb2 points to  B object  not D object����ʱ����ָ��û��ָ���������                                            
}
//��ת�����ͳ�Ϊ������ת��������Ϊ���������νṹ�µ�ָ�룬�Ӹ��������Ƶ������������ࡣ

//3.static_cast
//
//��õ�����ת������������״���µ�����ת�������intת��Ϊfloat���磺int i��float f�� f = ��float��i������f = static_cast<float>(i);

//4.reinterpret_cast
//
//interpret�ǽ��͵���˼��reinterpret��Ϊ���½��ͣ��˱�ʶ������˼��Ϊ���ݵĶ�������ʽ���½��ͣ����ǲ��ı���ֵ���磺int i; char* ptr = "hello freind!"; i = reinterpret_cast<int>(ptr);���ת����ʽ����ʹ�á�