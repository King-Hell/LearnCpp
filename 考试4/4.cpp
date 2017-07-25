#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Rational {
private:
	int member;
	int denominator;
public:
	Rational() {}
	Rational(int m, int d) :member(m), denominator(d) {}
	friend istream &operator>>(istream &is, Rational &b) {
		char a[10];
		is >> a;
		char *c_m=new char[10];
		char *d_m=new char[10];
		char *p;
		c_m = strtok_s(a, "/", &p);
		d_m = strtok_s(NULL, "/", &p);
		b.member = atoi(c_m);
		b.denominator = atoi(d_m);
		return is;
	}
	friend ostream &operator<<(ostream &os, Rational &b) {
		os << b.member << "/" << b.denominator;
		return os;
	}
	operator double() {
		return (double)member / (double)denominator;
	}
	Rational &operator+(Rational &b) {
		int n_m;
		int n_d;
		n_d = this->denominator*b.denominator;
		n_m = this->member*b.denominator + b.member*this->denominator;
		int common =getCommon (n_m, n_d);
		n_m /= common;
		n_d /= common;
		Rational *a= new Rational(n_m, n_d);
		return *a;
	}
	void operator-=(Rational &b) {
		int n_m;
		int n_d;
		n_d = this->denominator*b.denominator;
		n_m = this->member*b.denominator - b.member*this->denominator;
		int common = getCommon(n_m, n_d);
		n_m /= common;
		n_d /= common;
		member = n_m;
		denominator = n_d;
	}
	int getCommon(int m, int n) {
		while (n != 0) {
			int r = m % n;
			m = n;
			n = r;
		}
		return m;
	}

};
int main() {
	Rational a(1, 6), b;
	cin >> b;
	cout << a + b << endl;
	b -= a;
	cout << double(b) << endl;
	system("pause");
	return 0;
}