#include<iostream>
using namespace std;
long long int sum=0;
long long int k=1;
void f(int n){
	if(n<=20){
		cout<<k<<endl;
		sum+=k;
		k*=(n+1);
		f(n+1);
	}
}
int main(){
	f(1);
	cout<<sum<<endl;
	system("pause");
	return 0;
}
