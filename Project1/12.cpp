#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int num, num2;
	int digit = 0;
	int mod = 0;
	cin >> num;

	if (num == 0) {
		cout << "λ��:" << 1 << endl << "��1λ��0" << endl << "�����ӡ��0" << endl;
		return 0;
	}

	num2 = num;
	while (num2>0) {
		digit++;
		num2 /= 10;
	}
	cout << "λ��:" << digit << endl;

	num2 = num;
	for (int i = digit; i>0; i--) {
		num2 /=(int) pow(10, i - 1);
		num2 = num2 % 10;
		cout << "��" << digit - i + 1 << "λ��" << num2 << endl;
		num2 = num;
	}

	cout << "�����ӡ��";
	while (num>0) {
		mod = num % 10;
		num /= 10;
		cout << mod;
	}
	cout << endl;

	system("pause");
	return 0;
}
