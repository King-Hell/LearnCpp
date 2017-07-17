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
		cout << "(a)计算路径长度；\n(b)获取文件名；\n(c)修改文件的扩展名；\n(d)修改文件所在目录。" << endl;
		cout << "请输入功能序号：" << endl;
		char type;
		cin >> type;
		cout << "执行" << type << "操作" << endl;
		switch (type)
		{
		case 'a':
			cout << "路径长度为：" << getLength() << endl;
			break;
		case 'b':
			cout << "文件名为：" << getName() << endl;
			break;
		case 'c':
			cout << "请输入要替换的扩展名" << endl;
			char name[10];
			cin >> name;
			if (setName(name)) {
				cout << "新路径为：" << dir << endl;
			}
			break;
		case 'd':
			cout << "请输入新目录" << endl;
			char ndir[100];
			cin >> ndir;
			if (setDir(ndir)) {
				cout << "新路径为：" << dir << endl;
			}
			break;
		default:
			cout << "命令错误，请重新输入" << endl;
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