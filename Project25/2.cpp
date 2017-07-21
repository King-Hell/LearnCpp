#include<iostream>
using namespace std;
class String {
private:
	char *arr;
public:
	String() {
		arr = new char[100];
	}
	String(const String &str) {
		arr = new char[100];
		int i = 0;
		for (; str.arr[i] != 0; i++) {
			arr[i] = str.arr[i];
		}
		arr[i] = 0;
	}
	String(char *arr) :arr(arr) {}
	friend ostream &operator<<(ostream &os, const String &str);
	friend istream &operator>>(istream &is, const String &str);
	bool operator==(const String &str) {
		for (int i = 0; arr[i] != 0 && str.arr[i] != 0; i++) {
			if (arr[i] != str.arr[i]) {
				return false;
			}
		}
		return true;
	}
	void operator+=(const char str[]) {
		char *p = arr;
		while (*p != 0) {
			p++;
		}
		int i = 0;
		for (; arr[i] != 0; i++, p++) {
			*p = str[i];
		}
		*p = 0;
	}
	String &operator=(String &str) {
		if (arr != NULL) {
			int i = 0;
			for (; str.arr[i] != 0; i++) {
				arr[i] = str.arr[i];
			}
			arr[i] = 0;
			return *this;
		}
		else {
			static String s(str);
			return s;
		}
	}
	~String() {

	}
};
ostream &operator<<(ostream &os, const String &str) {
	os << str.arr;
	return os;
}
istream &operator>>(istream &is, const String &str) {
	is >> str.arr;
	return is;
}
int main() {
	String str1("hello");
	cout << str1 << endl;

	String str2;
	cin >> str2;

	cout << (str1 == str2 ? "Equval" : "Unequval") << endl;

	String t(str1);

	t = str2 = str1;
	t += ",world"; //字符串连接，将",world"连接到t后边；
	cout << t << endl;
	system("pause");
	return 0;
}
