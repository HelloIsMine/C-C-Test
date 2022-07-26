#include <iostream>                                                    
using namespace std;
//1、const_cast   用于取出const属性，去掉类型的const或volatile属性，把const类型的指针变为非const类型的指针
//int main() {
//    const int n = 100;
//    int* p = const_cast<int*>(&n); //&n的类型为const int*，只有将其类型转换为int *才可以对p（类型为int *)进行赋值                                            常量不能给非常量赋值，导致常量可能被修改。        
//    *p = 234;                      //变量n防止在栈内存中，有写入权限可以通过p来修改n的值                                                    
//    cout << "n = " << n << endl;
//    cout << "*p = " << *p << endl;
//
//    
//
//    return 0;
//}

//2、dynamic_cast  主要是用来”向下安全转型“，决定了某一对象是否归属于继承体系中的某一个类型，用在类继承层次之间的转换可以进行向上类型的转换（
//在进行向上类型转换的时候，不进行安全检测。主要作用：将基类类型的指针或者是引用安全的转化为子类类型的引用和指针。
//语法：dynamic_cast <type - id> (expression)
//
//情况1、如果 type - id 是指向 expression的明确的可访问的直接或间接基类的指针，则结果是指向 type - id 类型的唯一子对象的指针


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


//情况2、如果 type - id 为 void* ，则做运行时进行检查确定 expression的实际类型。结果是指向 expression 的完整的对象的指针。
//class A { virtual void f(); };
//class B { virtual void f(); };
//
//void f() {
//	A* pa = new A;
//	B* pb = new B;
//	void* pv = dynamic_cast<void*>(pa);// pv now points to an object of type A     
//	pv = dynamic_cast<void*>(pb);// pv now points to an object of type B 
//}

//情况3、如果 expression 类型是 type - id的基类，则做运行时检查来看是否 expression 确实指向 type - id类型的完整对象。
//如果为 true，则结果是指向type - id类型的完整对象的指针
class B { virtual void f(); };
class D : public B { virtual void f(); };

void f() {
    B* pb = new D;   // unclear but ok                                            
    B* pb2 = new B;
    D* pd = dynamic_cast<D*>(pb);            // ok: pb actually points to D object                                            
    D* pd2 = dynamic_cast<D*>(pb2);        // pb2 points to  B object  not D object，此时基类指针没有指向子类对象。                                            
}
//此转换类型称为“向下转换”，因为它将在类层次结构下的指针，从给定的类移到该类派生的类。

//3.static_cast
//
//最常用的类型转换符，在正常状况下的类型转换，如把int转换为float，如：int i；float f； f = （float）i；或者f = static_cast<float>(i);

//4.reinterpret_cast
//
//interpret是解释的意思，reinterpret即为重新解释，此标识符的意思即为数据的二进制形式重新解释，但是不改变其值。如：int i; char* ptr = "hello freind!"; i = reinterpret_cast<int>(ptr);这个转换方式很少使用。