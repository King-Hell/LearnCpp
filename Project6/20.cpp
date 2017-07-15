#include<iostream>
using namespace std;
int main(){
	for(int i=1;i<=1000;i++){
		int sum=0;
		for(int j=1;j<i;j++){
			if(i%j==0){
				sum+=j;
			}
		}
		if(i==sum){
			cout<<i<<",its factors are 1";
			
			for(int j=2;j<i;j++){
				if(i%j==0){
					cout<<","<<j;
				}
			}
			cout<<endl;
		}
	}
	system("pause");
	return 0;
}