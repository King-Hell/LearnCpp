#include<iostream>
using namespace std;
#include<math.h>
#define PI 3.1415926535;
using namespace std;
class Circle {
private:
	double radius;
	double center[2];
public:
	Circle(double r, double x, double y) :radius(r) {
		center[0] = x;
		center[1] = y;
	}
	double area() {
		return radius*radius*PI;
	}
	double circu() {
		return 2 * radius*PI;
	}
	void print() {
		cout << "Բ�ģ�(" << center[0] << "��" << center[1] << ")" << endl;
		cout << "�뾶��" << radius << endl;
	}
};
int main() {
	Circle c(1, 0, 0);
	cout << c.area() << endl;
	cout << c.circu() << endl;
	c.print();
	system("pause");
	return 0;
}
