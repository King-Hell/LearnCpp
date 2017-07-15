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
	cout << "英文字母：" << letters << endl;
	cout << "空格：" << blanks << endl;
	cout << "数字：" << nums << endl;
	cout << "其他字符：" << others << endl;
	system("pause");
	return 0;
}