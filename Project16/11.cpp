#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
void tran(int n);
char *exp();
int main() {
	int num = 0;
	cout << "请输入一个数字:" << endl;
	cin >> num;
	tran(num);
	char *p = exp();
	cout << p << endl;
	system("pause");
	return 0;
}
void tran(int n) {
	s.push(n % 10);
	if (n<10) {
		return;
	}
	tran(n/10);
}
char *exp() {
	int size = s.size();
	char *p = new char[size+1];
	for (int i = 0; i < size; i++) {
		p[i] = s.top()+'0';
		s.pop();
	}
	p[size] = 0;
	return p;
}