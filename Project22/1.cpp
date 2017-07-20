#include<iostream>
using namespace std;
//class Rectangle {
//private:
//	double lenth;
//	double width;
//	class Point2d {
//	private:
//		double x;
//		double y;
//		double *p = new double[2];
//	public:
//		Point2d(double x = 0, double y = 0) :x(x), y(y) {}
//		~Point2d() {
//			cout << "delete" << endl;
//		}
//		double *getPoint() {
//			*p = x;
//			*(p + 1) = y;
//			return p;
//
//			/*double c[2];
//			c[0] = x;
//			c[1] = y;
//			return c;*/
//		}
//	};
//	Point2d point;
//public:
//	Rectangle(double a, double b, double x, double y) :lenth(a), width(b) {
//		point = Point2d(x, y);
//	}
//	double getArea() {
//		return lenth*width;
//	}
//	double getCirc() {
//		return 2 * (lenth + width);
//	}
//	double *getPoint() {
//		return point.getPoint();
//	}
//};
template<class T> class ArrayList {
private:
	T *_arr;
	T *p;
	int _size;//数组大小
	int arrSize;//数组所占内存大小
public:
	void creat(int size) {
		if (_arr) {
			delete[]_arr;
		}
		_arr = new T[size];
		this->_size = size;
		p = _arr;
	}
	~ArrayList() {
		delete[]_arr;
	}
	void add(T data) {
		if (isFull()) {
			T *temp = new T[arrSize * 2];
			for (int i = 0; i < _size; i++) {
				temp[i] = ;
			}
			delete[]_arr;
			_arr = temp;

		}
		else {
			_arr[_size] = data;
		}
		_size++;
	}
	bool isFull() {
		return arrSize==_size;
	}
	void print() {
		cout << "{";
		int i = 0;
		for (i; i < _size - 1; i++) {
			cout << _arr[i] << ",";
		}
		cout << _arr[i] << "}" << endl;
	}

};
int main() {
	/*Rectangle r(5, 4, 1, 1);
	cout << "面积为：" << r.getArea() << endl;
	cout << "周长为：" << r.getCirc() << endl;
	double *p = r.getPoint();
	cout << "矩形左上角坐标为：（" << *p << "，" << *(p + 1) << "）" << endl;*/
	ArrayList<int> a;
	a.creat(2);
	a.add(1);
	a.add(2);
	a.print();
	system("pause");
	return 0;
}