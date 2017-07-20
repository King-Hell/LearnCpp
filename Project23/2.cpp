#include<iostream>
#include<math.h>
using namespace std;
class Polygon {
	class Vertex {
	private:
		double x;
		double y;
	public:
		Vertex() {}
		Vertex(double x, double y) :x(x), y(y) {}
		double getX() {
			return x;
		}
		double getY() {
			return y;
		}
	};
private:
	int size;
	int maxSize;
	Vertex *arr;
	double *pos;
public:
	Polygon(int size, double a[][2]) :size(size) {
		arr = new Vertex[size];
		for (int i = 0; i < size; i++) {
			arr[i] = Vertex(a[i][0], a[i][1]);
		}
		maxSize = size;
	}
	double getArea() {
		double sum = 0;
		int i = 0;
		for (; i < size - 1; i++) {
			sum += (arr[i].getX()*arr[i + 1].getY() - arr[i + 1].getX()*arr[i].getY());
		}
		sum += (arr[i].getX()*arr[0].getY() - arr[0].getX()*arr[i].getY());
		sum /= 2;
		return sum;
	}
	double getCirc() {
		double sum = 0;
		int i = 0;
		for (; i < size - 1; i++) {
			sum += sqrt(pow(arr[i].getX() - arr[i + 1].getX(), 2) + pow(arr[i].getY() - arr[i + 1].getY(), 2));
		}
		sum += sqrt(pow(arr[i].getX() - arr[0].getX(), 2) + pow(arr[i].getY() - arr[0].getY(), 2));
		return sum;
	}
	int getAmount() {
		return size;
	}
	double *getPos(int index) {
		if (!pos) {
			pos = new double[2];
		}
		pos[0] = arr[index].getX();
		pos[1] = arr[index].getY();
		return pos;
	}
	bool addV(double x, double y) {
		if (size == maxSize) {
			Vertex *temp = new Vertex[maxSize * 2];
			for (int i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
		}
		arr[size] = Vertex(x, y);
		size++;
		return true;
	}
	bool deleteV(int index) {
		for (int i = index; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
		return true;
	}
	void print() {
		cout << "这是一个" << size << "边形" << endl;
		for (int i = 0; i < size; i++) {
			cout << "第" << i+1 << "个顶点的坐标为：（" << arr[i].getX() << "," << arr[i].getY() << ")" << endl;
		}
	}
};
int main() {
	double v_rect[][2] = { {0,0},{1,0} ,{1,1},{0,1} };
	Polygon rect(4,v_rect);
	rect.print();
	cout << "面积为" << rect.getArea()<<endl;
	cout << "周长为" << rect.getCirc() << endl;
	cout << "------------------------------" << endl;
	Polygon tri = rect;
	tri.deleteV(3);
	tri.print();
	cout << "面积为" << tri.getArea() << endl;
	cout << "周长为" << tri.getCirc() << endl;
	cout << "------------------------------" << endl;
	Polygon pent = rect;
	pent.addV(-1, 0);
	pent.print();
	cout << "面积为" << pent.getArea() << endl;
	cout << "周长为" << pent.getCirc() << endl;
	system("pause");
	return 0;
}