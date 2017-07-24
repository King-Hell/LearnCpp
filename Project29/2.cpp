/*
文件格式:
学号  姓名
{课程号 分数｝｛课程号 分数｝……
.....
*/
#include<fstream>
#include<iostream>
#include<strstream>
using namespace std;
class Course
{
public:
	Course() {}
	Course(char *courseID,char *score){
		this->courseID = char2int(courseID);
		this->score = char2float(score);
	}
	int		courseID;
	float	score;
	int char2int(char *ch) {
		istrstream is(ch, 10);
		int i = 0;
		is >> i;
		return i;
	}
	float char2float(char *ch) {
		istrstream is(ch, 10);
		float f = 0;
		is >> f;
		return f;
	}
};
class Student
{
public:
	Student(){}
	Student(int id, char *name) :id(id) {
		strcpy_s(this->name, name);
	}
	int	   id;
	char   name[256];
	int	   ncourse;
	Course  vcourse[128];
};

int main() {
	ifstream is("data.txt");
	Student arr[20];
	int i = 0;
	while (is.peek()!=EOF) {
		int id;
		char name[256];
		is >> id;
		is >> name;
		arr[i]=Student(id, name);
		is.ignore();
		int ncourse=0;
		while (is.get()=='{') {
			char courseID[6];
			is.get(courseID, 6);
			is.ignore(2);
			char score[5];
			is.get(score, 5);
			arr[i].vcourse[ncourse] = Course(courseID, score);
			is.ignore(1);
			ncourse++;
		}
		arr[i].ncourse = ncourse;
		i++;
	}
	is.close();
	system("pause");
	return 0;
}