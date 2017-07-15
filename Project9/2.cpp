#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main() {
	int a[10];
	int min=0,temp=0;
	int size = sizeof(a) / sizeof(a[0]);
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		a[i] = rand();
	}
	for (int x : a) {
		cout << x << "\t";
	}
	cout << endl;
	for (int i = 0; i <size-1; i++) {
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
		cout << x<< "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}
