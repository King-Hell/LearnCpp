#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
double m[5][3];
vector<double> r_ave;
vector<double> c_ave;
void fa();
void fb();
void fc();
int main() {
	char type;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = rand() / 100.0;
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
	while (true) {
		cout << "--------------------------------------" << endl;
		cout << "(a)�����еľ�ֵ��\n(b)�����еľ�ֵ��\n(c)����һ��3ά�����������������֮�ĳ˻���" << endl;
		cout << "�����빦����ţ�" << endl;
		cin >> type;
		cout << "ִ��" << type << "����" << endl;
		switch (type)
		{
		case 'a':
			fa();
			break;
		case 'b':
			fb();
			break;
		case 'c':
			fc();
			break;
		default:
			cout << "�����������������" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
void fa() {
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			sum += m[i][j];
		}
		sum /= 3;
		r_ave.push_back(sum);
	}
	for (double x : r_ave) {
		cout << x << endl;
	}
}
void fb() {
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			sum += m[j][i];
		}
		sum /= 5;
		c_ave.push_back(sum);
	}
	for (double x : c_ave) {
		cout << x << "\t";
	}
	cout << endl;
}
void fc() {
	cout << "������һ��3ά������" << endl;
	vector<double> a;
	for (int i = 0; i < 3; i++) {
		double n;
		cin >> n;
		a.push_back(n);
	}
	for (int i = 0; i < 5; i++) {
		double sum = 0;
		for (int j = 0; j < 3; j++) {
			sum = +m[i][j] * a[j];
		}
		cout << sum << endl;
	}
}