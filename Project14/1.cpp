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
	cout << "(a)����n�����������η��������У�\n(b) ��������׷�����ɸ�����\n(c) ��ð�ݷ��������е�Ԫ�ؽ�������\n(d) �������Ԫ�������ţ�\n(e) ����һ���������ö��ַ�����������������е�λ�ã�\n(f) ����һ����������������ɾ�������ж������ȫ��ɾ������" << endl;
	while (true)
	{
		cout << "�����빦����ţ� " << endl;
		cin >> type;
		cout << "��ʼִ��" << type << "����" << endl;
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
			cout << "������Ҫ׷�ӵ�����" << endl;
			int num;
			cin >> num;
			cout << "������Ҫ׷�ӵ�λ��" << endl;
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
				cout << "����ִ���������" << endl;
				continue;
			}
			cout << "������Ҫ����������" << endl;
			int n, index;
			cin >> n;
			index = fune(n);
			if (index == -1) {
				cout << "δ�ҵ�������" << endl;
			}
			else {
				cout << n << "���±�Ϊ" << index << endl;
			}
			break;
		case 'f':
			cout << "������Ҫɾ��������" << endl;
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
	cout << "������n������N����" << endl;
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