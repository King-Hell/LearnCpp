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
//class Test {
//private:
//	int i;
//public:
//
//	Test(int i) :i(i) {}
//	void add() {
//		i++;
//	}
//	void print() {
//		cout << i << endl;
//	}
//};
//int *func() {
//	int a[2] = { 1,2 };
//	return a;
//}
//class Test {
//	int *arr;
//	Test(int i) {
//		
//	}
//	~Test() {
//		
//	}
//};
int main() {
	//char a[] = "Hello,world";
	//char b[] = "Hello,world";
	/*int b[3][4] = { {1,2,3,4},
	{5,6,7,8},
	{9,10,11,12}
	};*/
	//int *a = &b[0][0];
	//for (int i = 0; i < 12; i++) {
		//cout << b[0][i] << "\t";

	//}
	//cout << b[0] << endl;
	//cout << b[1] << endl;
	//cout << &b[0] << endl;
	//cout << &b[1] << endl;
	//int *a = b[0];
	//cout << b-1 << endl;
	/*Test a(1);
	a.print();
	Test *b = &a;
	b->add();
	Test c(a);
	a.print();
	a.add();
	a.print();
	c.print();
	cout << &a << endl;
	cout << b << endl;
	cout << &c << endl;*/
	char a[100];
	cin >> a;
	cout << a << endl;
	cin.getline(a,3);
	cout << a << endl;
	cin.get(a, 3);
	cout << a << endl;
	system("pause");
	return 0;
}