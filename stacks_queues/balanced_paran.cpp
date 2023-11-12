#include<bits/stdc++.h>
using namespace std;

bool balanced_para(string input){
	stack<char> s;
	// for(auto i:input){
	// 	if(i=='(') s.push(i);
	// 	else if(i=='[') s.push(i);
	// 	else if(i==')'){
	// 		if(s.top()=='('){
	// 			s.pop(); //removing (
	// 		}
	// 	}
	// 	else if(i==']'){
	// 		if(s.top()=='['){
	// 			s.pop();
	// 		}
	// 	}
	// }

	for(auto ch:input){

		switch(ch){
			case '(':
			case '[':
			case '{': s.push(ch);
						break;
			case ')': if(!s.empty() and s.top()=='(') s.pop();
						else return false;
						break;

			case ']': if(!s.empty() and s.top()=='[') s.pop();
						else return false;
						break;

			case '}': if(!s.empty() and s.top()=='{') s.pop();
						else return false;
						break;
			default:continue;
		}
	}

	if(s.empty()) return true;
	else return false;
}

int main(){
	string s = "((a+b)*x-d)";
	string t = "((a+b]+c*(d*e)";

	cout<< balanced_para(s) << "\n" << balanced_para(t) << "\n";

}