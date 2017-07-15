#include<iostream>
using namespace std;
//将分数作为一种对象
class Fraction {

public:
	long long dm;
	long long m;
	Fraction(long long int a, long long int b) {
		dm = a;
		m = b;
	}
	//利用辗转相除法对分子分母进行约分
	static long long int measure(long long int x, long long int y)
	{
		long long int z = y;
		while (x%y != 0)
		{
			z = x%y;
			x = y;
			y = z;
		}
		return z;
	}
	//定义分数的加法运算
	static Fraction plus(Fraction a, Fraction b) {
		long long int ndm = a.dm*b.dm;
		long long int nm = a.m*b.dm + b.m*a.dm;
		long long int z = measure(ndm, nm);
		ndm /= z;
		nm /= z;
		cout << z << endl;
		return Fraction(ndm, nm);
	}
};
int main() {
	int a = 1, b = 2, temp;
	Fraction fra(a, b);
	Fraction sum(1, 1);
	Fraction fra2(1, 1);
	//当n取20时即使long long型也会溢出，因此这里n取10
	for (int i = 2; i <= 10; i++) {
		temp = b;
		b = a + b;
		a = temp;
		fra2 = Fraction(a, b);
		sum = Fraction::plus(fra, fra2);
		fra = sum;
	}
	cout << sum.m << "/" << sum.dm << endl;
	system("pause");
	return 0;
}