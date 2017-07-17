#include<iostream>
using namespace std;
char dir[] = "C:\\Program Files\\Common files\\Adobe\\data.txt";

int getLength();
char *getName();
bool setName(char a[]);
bool setDir(char a[]);
int getPos(char a);

int main() {
	cout << dir << endl;
	while (true) {
		cout << "--------------------------------------" << endl;
		cout << "(a)����·�����ȣ�\n(b)��ȡ�ļ�����\n(c)�޸��ļ�����չ����\n(d)�޸��ļ�����Ŀ¼��" << endl;
		cout << "�����빦����ţ�" << endl;
		char type;
		cin >> type;
		cout << "ִ��" << type << "����" << endl;
		switch (type)
		{
		case 'a':
			cout << "·������Ϊ��" << getLength() << endl;
			break;
		case 'b':
			cout << "�ļ���Ϊ��" << getName() << endl;
			break;
		case 'c':
			cout << "������Ҫ�滻����չ��" << endl;
			char name[10];
			cin >> name;
			if (setName(name)) {
				cout << "��·��Ϊ��" << dir << endl;
			}
			break;
		case 'd':
			cout << "��������Ŀ¼" << endl;
			char ndir[100];
			cin >> ndir;
			if (setDir(ndir)) {
				cout << "��·��Ϊ��" << dir << endl;
			}
			break;
		default:
			cout << "�����������������" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
int getLength() {
	return sizeof(dir) / sizeof(dir[0]) - 1;
}
char *getName() {
	return &dir[getPos('\\') + 1];
}
bool setName(char a[]) {
	for (int i = 0; a[i] != 0; i++) {
		dir[getPos('.') + 1 + i] = a[i];
	}
	return true;
}
bool setDir(char a[]) {
	char *name = getName();
	int i = 0;
	for (i; i < a[i] != 0; i++) {
		dir[i] = a[i];
	}
	dir[i] = '\\';
	i++;
	int j = 0;
	while (name[j] != 0) {
		dir[i] = name[j];
		j++;
		i++;
	}
	dir[i] = 0;
	return true;

}
int getPos(char a) {
	int size = getLength() + 1;
	int flag = 0;
	for (int i = size - 2; i >= 0; i--) {
		if (dir[i] == a) {
			flag = i;
			break;
		}
	}
	return flag;
}