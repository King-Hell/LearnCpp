#include<iostream>
using namespace std;
int remove(int a[], int count, int val) {
	for (int i = 0; i < count; i++) {
		if (a[i] == val) {
			for (int j = i; j < count; j++) {
				a[j] = a[j + 1];
			}
			count--;
			i--;
		}
	}
	return count;
}
int main() {
	int a[] = { 3,1,1,2,1 };
	int val = 1;
	int count = sizeof(a) / sizeof(a[0]);
	count=remove(a, count, val);
	for (int i = 0; i < count; i++) {
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
}