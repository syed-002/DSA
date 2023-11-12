#include<bits/stdc++.h>
using namespace std;

void subseq(string s, string o, vector<string> &temp){ //should def use & or else you wont get the ans
	if(s.size()==0){
		temp.push_back(o);
		return;
	}
	char ch = s[0]; //first char
	string chopped = s.substr(1); // remaning chopped input string
	//included
	subseq(chopped, o+ch, temp);
	//excluded
	subseq(chopped, o, temp);
}


int main(){
	string str="abc";
	vector<string> temp;
	subseq(str, "", temp);
	for(auto s: temp){
		cout<< s << " ";
	}
	return 0;
}