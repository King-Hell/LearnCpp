#include<iostream>
using namespace std;

int main(){
	int a=0;
	double x=0,xn=0;
	cin>>a;
	x=a/2.0;
	while(true){
		xn=(x+a/x)/2;
		if(x-xn<0.00001&&x-xn>=0||xn-x<0.00001&&xn-x>0){
			break;
		}
		x=xn;
	}
	cout<<xn<<endl;
	system("pause");
	return 0;
}