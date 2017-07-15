#include<iostream>
#include<string>
#include<sstream>

using namespace std;
int msize = 0;
int *p;
void print();
int *funa();
void funb(int num, int pos);
void func();
void fund();
int fune(int num);
void funf(int num);
bool isSort = false;

int main() {
	char type = 'a';
	int *a;
	cout << "(a)输入n个数，并依次放入数组中；\n(b) 往数组中追加若干个数；\n(c) 用冒泡法对数组中的元素进行排序；\n(d) 将数组的元素逆序存放；\n(e) 输入一个数，并用二分法查找这个数在数组中的位置；\n(f) 输入一个数，并从数组中删除（如有多个，则全部删除）；" << endl;
	while (true)
	{
		cout << "请输入功能序号： " << endl;
		cin >> type;
		cout << "开始执行" << type << "操作" << endl;
		cout << "--------------------------------------" << endl;

		switch (type)
		{
		case 'a':
			a = funa();
			p = new int[msize];
			for (int i = 0; i < msize; i++) {
				p[i] = a[i];
			}
			print();
			break;
		case 'b':
			cout << "请输入要追加的数字" << endl;
			int num;
			cin >> num;
			cout << "请输入要追加的位置" << endl;
			int pos;
			cin >> pos;
			funb(num, pos);
			break;
		case 'c':
			func();
			break;
		case 'd':
			fund();
			break;
		case 'e':
			if (!isSort) {
				cout << "请先执行排序操作" << endl;
				continue;
			}
			cout << "请输入要搜索的数字" << endl;
			int n, index;
			cin >> n;
			index = fune(n);
			if (index == -1) {
				cout << "未找到该数字" << endl;
			}
			else {
				cout << n << "的下标为" << index << endl;
			}
			break;
		case 'f':
			cout << "请输入要删除的数字" << endl;
			int m;
			cin >> m;
			funf(m);

			break;
		default:
			break;
		}
		cout << "--------------------------------------" << endl;
	}
	system("pause");
	return 0;

}
void print() {
	for (int i = 0; i < msize; i++) {
		cout << p[i] << "\t";

	}
	cout << endl;
}
int *funa() {
	cout << "请输入n个数，N结束" << endl;
	string str;
	
	int temp;
	static int a[100];
	int count = 0;
	while (true) {
		stringstream ss;
		cin >> str;
		if (str == "n"||str=="N")
			break;
		ss << str;
		ss >> temp;
		a[count] = temp;
		count++;
	}
	msize = count;

	return a;
}
void funb(int num, int pos = msize) {
	msize++;
	int *q = new int[msize];
	for (int i = 0; i < pos; i++) {
		q[i] = p[i];
	}
	q[pos] = num;
	for (int i = pos + 1; i < msize; i++) {
		q[i] = p[i - 1];
	}
	p = q;
	print();
}
void func() {
	for (int i = 0; i < msize-1; i++) {
		bool flag = true;
		for (int j = 0; j < msize -1-i; j++) {
			if (p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				flag = false;
			}
		}
		if (flag) {
			break;
		}
	}
	print();
	isSort = true;
}
void fund() {
	for (int i = 0; i < msize / 2; i++) {
		int temp = p[i];
		p[i] = p[msize - i - 1];
		p[msize - i - 1] = temp;
	}
	print();
}
int fune(int num) {
	int low = 0;
	int high = msize - 1;
	int mid = (low + high) / 2;
	while (low < high) {
		if (num < p[mid]) {
			high = mid - 1;
		}
		else if (num > p[mid]) {
			low = mid + 1;
		}
		else {
			break;
		}
		mid = (high + low) / 2;
	}
	if (p[mid] == num) {
		return mid;
	}
	else {
		return -1;
	}
}
void funf(int num) {
	for (int i = 0; i < msize; i++) {
		if (p[i] == num) {
			for (int j = i; j < msize - 1; j++) {
				p[j] = p[j + 1];
			}
			msize--;
			i--;
		}
	}
	print();
}