//#include<iostream>
//using namespace std;
//int func(int, int);
//int main() {
//	int (*p)(int, int);
//	p = func;
//	int a, b, c, d;
//	cout << "Please enter two nums here: ";
//	cin >> a >> b;
//	c = p(a, b);//可以不加*访问；
//	cout << "No star example: " << c << endl;
//	d = (*p)(a, b);//加*访问；
//	cout << "Exist star Example: " << d << endl;
//	return 0;
//}
//int func(int x, int y) {
//	if (x > y) {
//		return x;
//	}
//	return y;
//}