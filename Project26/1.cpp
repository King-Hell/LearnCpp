#include<iostream>
#include<vector>
using namespace std;
class Window {
private:
	string title;
protected:
	int id;
public:
	void move(int x, int y);

	~Window() {
		cout << "Window:destructor\n";
	}
};
class Button:private Window  {
	Button() {
		this->id;

	}
	~Button() {
		cout << "Button:destructor\n";
	}
};
class Text {
public:
	virtual void print() {
		cout << "text\n";
	}
};
class URL :public Text {
public:
	 void print() {
		cout << "url\n";
	}
};

class DecParser {
	
};
void parseStr(char str[], vector<int> &v, DecParser &par) {

}
int main() {
	//Button b();
	//URL url;
	//Text &text=url;
	//
	//text.print();
	vector<int> v;
	
	system("pause");
	return 0;
}