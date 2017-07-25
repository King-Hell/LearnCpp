#include<iostream>
#include<cmath>
using namespace std;
void func(float a[], float b[],int a_size,int b_size) {
	float min = abs(a[0] - b[0]);
	int a_min = 0;
	int b_min = 0;
	for (int i = 0; i < a_size; i++) {
		for (int j = 0; j < b_size; j++) {
			if (abs(a[i] - b[j]) < min) {
				a_min = i;
				b_min = j;
			}
		}
	}
	cout << a_min << endl;
	cout << b_min << endl;
}
int main() {
	float a[] = { 5,3.1f,8 };
	int a_size = sizeof(a) / sizeof(a[0]);
	float b[] = { 6,7,9,3.5f };
	int b_size = sizeof(b) / sizeof(b[0]);
	func(a, b, a_size, b_size);
	system("pause");
	return 0;

}