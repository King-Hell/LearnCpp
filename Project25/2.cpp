#include<iostream>
using namespace std;
class String {
private:
	char *arr;
	int maxSize;
	int size;
public:
	String() {
		creat();
	}
	String(const String &str) {
		creat();
		copy(str);
	}
	String(char str[]) {
		creat();
		int i = 0;
		for (; str[i] != 0; i++) {
			arr[i] = str[i];
		}
		arr[i] = 0;
		size += i + 1;
	}
	void creat() {
		arr = new char[100];
		maxSize = 100;
		size = 0;
	}
	operator char*() {
		return arr;
	}
	friend ostream &operator<<(ostream &os, const String &str);
	friend istream &operator>>(istream &is, const String &str);
	bool operator==(const String &str) {
		for (int i = 0; arr[i] != 0 && str[i] != 0; i++) {
			if (arr[i] != str[i]) {
				return false;

			}
		}
		return true;
	}
	char operator[](int i) {
		return arr[i];
	}
	char operator[](int i)const {
		return arr[i];
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
		size += i;
	}
	void copy(const String &str) {
		int i = 0;
		for (; str[i] != 0; i++) {
			arr[i] = str[i];
		}
		arr[i] = 0;
	}
	String &operator=(const String &str) {
		if (this != NULL) {
			copy(str);
			return *this;
		}
		else {
			static String s(str);
			return s;
		}
	}
	~String() {
		delete[]arr;
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
