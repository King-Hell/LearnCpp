#include<fstream>
#include<iostream>
using namespace std;
int main() {
	ofstream os("C:\\Users\\hasee\\Desktop\\test.txt");
	for (int i = 0; i < 10; i++) {
		os << i << endl;
	}
	ifstream is("C:\\Users\\hasee\\Desktop\\test.txt");
	int a[10];
	for (int i = 0; i < 10;i++) {
		is >> a[i];
		cout <<a[i] << endl;
		
	}
	
	system("pause");
	return 0;
}