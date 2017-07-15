#include<iostream>
using namespace std;
void hanoi(int n, char from, char to, char mid);
void move(int n, char from, char to);
int main() {
	cout << "���������Ӹ���" << endl;
	int n;
	cin >> n;
	cout << "��ʼ���в���" << endl;
	hanoi(n,'A','C','B');
	system("pause");
	return 0;
}

void hanoi(int n, char from, char to, char mid) {
	if (n == 1) {
		move(1, from, to);
		return;
	}
	hanoi(n - 1, from, mid, to);
	move(n, from, to);
	hanoi(n - 1, mid, to, from);
}

void move(int n, char from, char to) {
	cout << "��" << n << "���̴�" << from << "�Ƶ�" << to<<endl;
}