#include<bits/stdc++.h>
using namespace std;

bool redundant_para(string input){
	stack<char> s;
	bool oper;

	for(auto ch:input){
		if(ch==')'){
			oper=false;
			while(s.top()!='('){
				if(s.top()=='+' or s.top()=='-' or s.top()=='*' or s.top()=='/') oper=true;
				s.pop();
			}
			s.pop(); //remaning '('

			if(oper==false) return true; //reduntant
		}
		else{
			s.push(ch);
		}
	}
	return false; //not redundant
}

int main(){
	string s = "((a+b)*x-d)";
	string t = "((a+b))";

	cout<< redundant_para(s) << "\n" << redundant_para(t) << "\n";

}