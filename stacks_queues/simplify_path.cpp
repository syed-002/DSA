#include<bits/stdc++.h>
using namespace std;

string simplify_path(string path){

	//tokenizsation
	istringstream iss(path);
	vector<string> tokens;
	string token;
	while(getline(iss, token, '/')){
		if(token=="." or token==""){
			continue;
		}
		tokens.push_back(token);
		
	}
	// for(string s:tokens){
	// 	cout<<s<<"\n";
	// }

	//handling ..
	vector<string> stack;
	if(path[0]=='/'){
		stack.push_back("");
	}
	for(string s:tokens){
		//2 cases abs and relative
		if(s==".."){
			//relative
			if(stack.size()==0 or stack[stack.size()-1]==".."){
				//either first position or previous element was ..
				stack.push_back("..");
			}
			else if(stack[stack.size()-1]!=""){
				stack.pop_back(); 
				//popping if the path has .. and if its not null.. 
				//ie anything except null is removed
			}
		}
		else{
			stack.push_back(s);
		}
	}

	//single elem
	if(stack.size()==1 and stack[stack.size()-1]=="") return "/";

	//joining the simplified path in stack
	ostringstream oss;
	int i=0;
	for(auto token:stack){
		if(i!=0){
			oss<<"/";
		}
		i++;
		oss<<token;
	}
	return oss.str();
}

int main(){
	string path = "/../x/y/../z/././w/a///../../c/./";
	//op: /x/z/c
	cout<<simplify_path(path) <<endl;


}