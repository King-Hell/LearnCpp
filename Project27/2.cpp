#include<iostream>
using namespace std;
#define PI 3.1415926535;
class Shape {
public:
	virtual double getArea()=0;
};
class Circle:public Shape {
private:
	double radius;
public:
	Circle(double r) :radius(r) {};
	double getArea() {
		return radius*radius*PI;
	}
};
class Square :public Shape {
private:
	double length;
public:
	Square(double l) :length(l) {};
	double getArea() {
		return length*length;
	}
};
class Rectangle :public Shape {
private:
	double length;
	double width;
public:
	Rectangle(double l, double w) :length(l), width(w) {}
	double getArea() {
		return length*width;
	}
};
class Trapezoid :public Shape {
private:
	double bottom;
	double lower;
	double height;
public:
	Trapezoid(double b,double l,double h) :bottom(b),lower(l),height(h){}
	double getArea() {
		return (bottom + lower)*height / 2;
	}
};
class Triangle :public Shape {
private:
	double base;
	double height;
public:
	Triangle(double b, double h) :base(b), height(h) {}
	double getArea() {
		return base*height / 2;
	}
};
double getSum(Shape **arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i]->getArea();
	}
	return sum;
}
void print(Shape **arr, int size) {
	for (int i = 0; i < size; i++) {
		cout<<arr[i]->getArea()<<endl;
	}
}
int main() {
	Shape* arr[] = {new Circle(1),new Square(1),new Rectangle(2,1),new Trapezoid(1,2,2),new Triangle(1,2) };
	print(arr, 5);
	cout << getSum(arr, 5) << endl;
	system("pause");
	return 0;
}