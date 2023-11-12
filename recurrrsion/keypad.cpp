#include<bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypad(string in, string out, int i){

	if(in[i]=='\0'){
		cout<<out<<"\n";
		return;
	}
	int key = in[i]- '0';
	//cout<<key<<"\n"; 
	//this gives seg fault, so it should run exactly
	//the no of times the keypad digit size is
	//coz 7 and 9 has 4 digits and 0 and 1 are empty
	// printKeypad(in, out+keypad[key][0], i+1);
	// printKeypad(in, out+keypad[key][1], i+1);
	// printKeypad(in, out+keypad[key][2], i+1);
	// printKeypad(in, out+keypad[key][3], i+1);

	if(key==0 or key == 1){
		printKeypad(in, out, i+1); //empty
	}
	for(int j=0; j< keypad[key].size(); j++){
		printKeypad(in, out+ keypad[key][j], i+1);
	}
}

int main(){
	string input;
	input = "234";

	string out;
	printKeypad(input, out, 0);
}