#include<iostream>
using namespace std;
bool isLeap(int y);
int main() {
	while (true) {

		int y = 0, m = 0, d = 0, sum = 0;
		int days[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
		cout << "�������꣺" << endl;
		cin >> y;
		cout << "�������£�" << endl;
		cin >> m;
		cout << "�������գ�" << endl;
		cin >> d;
		if (m == 2 && d == 29) {
			sum = 31 + 29;
		}
		else if (m == 1) {
			sum = d;
		}
		else if (m == 2) {
			sum = 31 + d;
		}
		else {
			for (int i = 1; i < m;i++) {
				sum += days[i];
			}
			sum += d;
			if (isLeap(y)) {
				sum++;
			}
		}
		cout << y << "��" << m << "��" << d << "���Ǹ����" << sum << "��" << endl;
	}
	system("pause");
	return 0;
}
bool isLeap(int y) {
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}