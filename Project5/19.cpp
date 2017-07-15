#include<iostream>
using namespace std;
int main(){
	int f,s,t;
	for(int i=100;i<=999;i++){
		t=i%10;
		s=i/10%10;
		f=i/100%10;
		if(i==f*f*f+s*s*s+t*t*t){
			cout<<i<<endl;
		}
	}
}