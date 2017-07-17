#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main() {
	srand((unsigned)time(NULL));
	int a[10];
	int index[10];
	int table[10];
	cout << "数组：" << endl;
	for (int i = 0; i < 10; i++) {
		a[i] = rand()%10;
	}
	for (int x : a) {
		cout << x << "\t";
	}
	cout << endl;
	int count = 0;
	for (int i = 0; i < 10; i++) {
		int j = 0;
		bool find = false;
		for (j; j < count; j++) {
			if (a[i] == table[j]) {
				index[i] = j;
				find = true;
			}
		}
		if (!find) {
			table[j] = a[i];
			index[i] = j;
			count++;
		}
	}
	cout << "索引：" << endl;
	for (int x : index) {
		cout << x << "\t";
	}
	cout << endl;
	cout << "查找表：" << endl;
	for (int i = 0; i < count; i++) {
		cout << table[i] << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}