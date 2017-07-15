#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int*getArray();

int main() {
	int *a;
	a = getArray();
	int size = 10;
	int n = 0, target = size - 1;
	cout << "请输入一个数："<< endl;
	cin >> n;
	int *b = new int[size + 1];
	for (int i = 0; i < size; i++) {
		if (n < a[i]) {
			target = i;
			break;
		}
	}
	
	for (int i = 0; i < target; i++) {
		b[i] = a[i];
	}
	b[target] = n;
	for (int i = target + 1; i < size+1; i++) {
		b[i] = a[i - 1];
	}
	for (int i = 0; i < size+1; i++) {
		cout << b[i] << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}


int* getArray() {
	static int a[10];
	int min = 0, temp = 0;
	int size = sizeof(a) / sizeof(a[0]);
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++) {
		a[i] = rand();
	}
	for (int x : a) {
		cout << x << "\t";
	}
	cout << endl;
	for (int i = 0; i <size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}

	}
	for (int x : a) {
		cout << x << "\t";
	}
	cout << endl;
	return a;
}