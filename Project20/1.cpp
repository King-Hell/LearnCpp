#include<iostream>
using namespace std;
void my_strcat(char *str1, const char *str2);
void remove_space(char *str);
void my_strcopy(char *dest, const char *src);
void str_swap(char *str1, char *str2);
int main() {
	char a[100] = "abc";
	char b[100] = "def";
	char c[] = "a b c";
	//str_swap(a, b);
	//cout << a << endl;
	//cout << b << endl;
	//my_strcopy(a, b);
	//cout << a << endl;
	//my_strcat(a, b);
	//cout << a << endl;
	remove_space(c);
	cout << c << endl;
	system("pause");
	return 0;
}
void my_strcopy(char *dest, const char *src) {
	while (*src != 0) {
		cout << *src << endl;
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

void str_swap(char *str1, char *str2) {
	char *temp = new char[strlen(str1)+1];
	my_strcopy(temp, str1);
	my_strcopy(str1, str2);
	my_strcopy(str2, temp);
}
void my_strcat(char *str1, const char *str2) {
	while (*str1 != 0) {
		str1++;
	}
	while (*str2 != 0) {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = 0;
}
void remove_space(char *str) {
	char *p = str;
	while (*p!=0) {
		if (*p == ' ') {
			p++;
			continue;
		}
		*str = *p;
		str++;
		p++;
	}
	*str = 0;
}