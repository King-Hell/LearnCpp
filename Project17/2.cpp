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
		cout << "(a)计算行的均值；\n(b)计算列的均值；\n(c)输入一个3维向量，并计算矩阵与之的乘积。" << endl;
		cout << "请输入功能序号：" << endl;
		cin >> type;
		cout << "执行" << type << "操作" << endl;
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
			cout << "命令错误，请重新输入" << endl;
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
	cout << "请输入一个3维向量：" << endl;
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