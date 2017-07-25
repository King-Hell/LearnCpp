#include<iostream>
#include<stdlib.h>
using namespace std;
bool isNum(char a) {
	if (a >= '0'&&a <= '9') {
		return true;
	}
	return false;
}
int getNumbers(const char *str, int *num) {
	char *a = new char[10];
	int count = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (isNum(str[i])) {
			a[0] = str[i];
			int j = 1;
			while (isNum(str[i + j])) {
				a[j] = str[i + j];
				j++;
			}
			i += j;
			a[j] = 0;
			num[count] = atoi(a);
			count++;
		}
	}
	return count;
}
int main() {
	char str[] = "a89c63ef#/32";
	int num[100];
	int count=getNumbers(str, num);
	cout << count << endl;
	for (int i = 0; i < count; i++) {
		cout << num[i] << endl;
	}
	system("pause");
	return 0;
}