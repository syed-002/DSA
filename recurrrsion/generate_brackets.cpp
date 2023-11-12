#include<bits/stdc++.h>
using namespace std;

void generate_brackets(string s, int n, int open, int close){
	if(open==n and close==n) {
		cout<< s<<"\n";
		return;
	}
	if(open<n){
		  generate_brackets(s+ '(', n, open+1, close);
	}
	if(close<open){
		generate_brackets(s+ ')', n, open, close+1);
	}
	
}

int main(){
	int n=3;
	string s;
	generate_brackets(s, n, 0, 0);
}