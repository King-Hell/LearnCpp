#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	int blanks = 0;
	int nums = 0;
	int letters = 0;
	int others = 0;
	getline(cin, str);
	
	for (char x : str) {
		if (x == ' ')
			blanks++;
		else if (x >= '0'&&x <= '9')
			nums++;
		else if (x >= 'a'&&x <= 'z' || x >= 'A'&&x <= 'Z')
			letters++;
		else
			others++;
	}
	cout << "Ӣ����ĸ��" << letters << endl;
	cout << "�ո�" << blanks << endl;
	cout << "���֣�" << nums << endl;
	cout << "�����ַ���" << others << endl;
	system("pause");
	return 0;
}