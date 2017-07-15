#include<iostream>
using namespace std;
int main() {
	int num;
	char mark;
	cin >> num;
	if (num == 100)
		mark = 'A';
	else if (num < 100 && num >= 60)
		mark = 'J' - num / 10;
	else if (num < 60 && num >= 0)
		mark = 'E';
	cout << mark << endl;
	system("pause");
	return 0;
}