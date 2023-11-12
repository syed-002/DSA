#include<bits/stdc++.h>
using namespace std;

int ladder(int n){
	if(n<0) return 0; //negative n it stops
 	if(n==0) return 1;

 	return ladder(n-1) + ladder(n-2) + ladder(n-3); 
	
}

int main(){
	int n=5;
	cout<<ladder(n)<<"\n";
	return 0;
}