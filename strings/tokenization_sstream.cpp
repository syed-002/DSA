#include<iostream>
#include <sstream>
#include<vector>
using namespace std;

int main(){
	string input;
	getline(cin, input);

	//create string stream object
	stringstream ss(input);
	vector<string> tokens;
	string temp;
	while(getline(ss, temp, ' ')){
		//reads one word until space and push in vector
		tokens.push_back(temp);
	}
	for(auto i: tokens) cout<< i << "\n";

}