#include<list>
#include<iostream>
using namespace std;

class Object {
public:
	static list<Object*> objList;
	Object() {
		objList.push_back(this);
	}
	Object(const Object &obj) {
		objList.push_back(this);
	}
	~Object() {
		objList.remove(this);
	}

};
list<Object*> Object::objList;
list<Object*>::iterator v;
void print() {
	for (v = Object::objList.begin(); v != Object::objList.end(); ++v) {
		cout << *v << endl;
	}
}
void exec() {
	Object *a = new Object, &b(*new Object(*a));
	Object c;
	print();
	delete a;
}
int main() {
	exec();
	print();
	system("pause");
	return 0;
}