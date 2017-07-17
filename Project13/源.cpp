#include<iostream>
using namespace std;
//void func(char a[]) {
//	cout << sizeof(a) / sizeof(a[0]) << endl;
//}
//int main() {
//	char a[] = "C:\\hju\\jih";
//	char *b;
//	int d[] = { 1,2,3,4,5 };
//	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
//	{
//		cout << a[i]<<endl;
//	}
//	//cout << *(a + 2)<<endl;
//	b = &a[3]+1;
//	cout << b << endl;
//	cout << sizeof(a) / sizeof(a[0]) << endl;
//	/*char c[100];
//	cin >> c;
//	cout << c << endl;*/
//	func(a);
//	system("pause");
//	return 0;
//}
int main() {
	//char a[] = "Hello,world";
	//char b[] = "Hello,world";
	static int a[5];
	for (int x : a) {
		cout << x << "\t";
	}
	cout << endl;
	//cout << b-1 << endl;
	system("pause");
	return 0;
}