//#include<iostream>
//#include<string.h>
//#include<stdio.h>
//using namespace std;
//
//int main() {
//	char src[8] = "helloWJ";
//	char cpy[8];
//	/*cout << "the return *value of strcpy: ";
//	cout << strcpy(cpy, src) << endl;*/
//	cout << "<< strcpy >>" << endl;
//
//	printf("the return value of strcpy: %p\n", strcpy(cpy, src));
//	printf("The src address: %p\n", src);
//	printf("The cpy address: %p\n", cpy);
//	cout << "The result shows that the return value of strcpy is cpy" << endl;
//
//	cout << "1.How to use strcpy  " << endl;
//	cout << cpy << endl;
//
//	cout << "2.If the source length is longer than the cpy: " << endl;
//	char src2[9] = "helloWJ!";
//	char cpy2[8];
//	//strcpy(cpy2, src2);
//	cout << "This will cause buffer overflow" << endl;
//
//	cout << "3.If the src length is shorter:" << endl;
//	char src3[8] = "helloWJ";
//	char cpy3[9];
//	cpy3[8] = '!';
//	strcpy(cpy3, src3);
//	cout << cpy3 << endl;
//	cout << cpy3[8] << endl;
//	cout << "It means that it will not change the values after the '\0'" << endl;
//
//	cout << "<< strncpy >>" << endl;
//	char ncpy[8];
//	cout << "If '\0' is not included in cnt, It will not print the right string" << endl;
//	//cout << "The return value of strncpy: " << strncpy(ncpy, src, 7) << endl;//wrong
//	cout << "The return value of strncpy: " << strncpy(ncpy, src, 8) << endl;//right
//
//	cout << "If the cnt is more than the src:" << endl;
//	char ncpy2[8];
//	//strncpy(ncpy2, src, 9);
//	cout << "This will cause buffer overflow" << endl;
//
//	return 0;
//}