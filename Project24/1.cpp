#include<iostream>
using namespace std;
//class Array {
//private:
//	int *arr;
//	int size;
//public:
//	Array(int size) :size(size) {
//		arr = new int[size];
//	}
//
//	friend std::ostream &operator<<(std::ostream &os, const Array &a) {
//		os << "{";
//		int i = 0;
//		for (; i < a.size - 1; i++) {
//			os << a.arr[i] << ",";
//		}
//		os << a.arr[i] << "}" <<"\n";
//	}
//	bool operator==(Array &b) {
//		if (size != b.size) {
//			return false;
//		}
//		for (int i = 0; i < size; i++) {
//			if (arr[i] != b.arr[i]) {
//				return false;
//			}
//		}
//		return true;
//	}
//	bool operator!=(Array &b) {
//		/*if (size != b.size) {
//			return true;
//		}
//		for (int i = 0; i < size; i++) {
//			if (arr[i] != b.arr[i]) {
//				return true;
//			}
//		}
//		return false;*/
//		return !operator==(b);
//	}
//};
template<class T> class Array
{
private:
	T *_arr;
	int  _size;
public:
	Array()
		:_arr(NULL), _size(0)
	{}
	Array(int size)
		:_arr(NULL), _size(0)
	{
		create(size);
	}
	Array(const Array &val)
		:_arr(NULL), _size(0)
	{
		this->create(val.size());
		for (int i = 0; i < val.size(); ++i)
			(*this)[i] = val[i];
	}
	void swap(Array &val)
	{
		std::swap(_arr, val._arr);
		std::swap(_size, val._size);
	}
	void clear()
	{
		delete[]_arr;
		_size = 0;
	}
	void create(int size)
	{
		clear();
		_arr = new T[size];
		_size = size;
	}
	int size() const
	{
		return _size;
	}
	Array& operator=(const Array &val)
	{
		if (this != &val)
		{
			Array t(val);
			swap(t);
		}
		return *this;
	}
	const int& operator[](int i) const
	{
		return _arr[i];
	}
	int& operator[](int i)
	{
		return _arr[i];
	}

	friend bool operator==(const Array &a, const Array &b)
	{
		bool eq = false;
		if (a.size() == b.size())
		{
			eq = true;
			for (int i = 0; i < a.size(); ++i)
				if (a[i] != b[i])
				{
					eq = false;
					break;
				}
		}
		return eq;
	}
	friend bool operator!=(const Array &a, const Array &b)
	{
		return !(a == b);
	}
	friend ostream &operator<<(ostream &os, const Array &a)
	{
		os << "{";
		int i = 0;
		for (; i < a._size - 1; i++)
		{
			os << a[i] << ",";
		}
		os << a[i] << "}" << endl;
		return os;
	}

	~Array()
	{
		cout << "destructing...size=" << _size << endl;
		clear();
	}
};



int main() {
	Array<char> a(10);
	system("pause");
	return 0;
}