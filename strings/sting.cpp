#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    int n=big.size();
    //int i=0;
    size_t index=0;
    while(index<n){
        if(index==0) {
        	index=big.find(small);
        	if(index!=-1) 	result.push_back(index);
        	else break;
        }
        else{
        	index=big.find(small, index+1);
        	if(index!=-1){
        		result.push_back(index);
        	}
        	else break;
        }   
    }
    return result;
}


int main(){
	// char string_in_c[100]={'1','a','b'};
	// string s("hello");//dynamic array
	// //or string s="hello";

	// //input
	// string t;
	// getline(cin,t);
	// cout<<t<<"\n";

	// string u;
	// getline(cin,u, '.'); //delimiter.. ie takes input only upto fullstop
	// cout<<u<<"\n";

	// //array of strings
	// //vector<string>...

	// for (char ch:s) cout<<ch <<" ";
	// //these strings are automatically null terminated

	// int n=5;
	// vector<string> sarr;
	// string temp;
	// //strings terminates at a newline
	// //since you caxnnot give all 5 input strings
	// //in a single line
	// //it will assume it as a single string
	// //so put newline at the end of each string 
	// while(n--){
	// 	getline(cin, temp);
	// 	sarr.push_back(temp);
	// }

	// for (string s:sarr) cout<<s <<" ";
//----------------
	//find function--gives the index of the word, if not some largest number for unsigned int..it can stored in type size_t
	// string para="hi IM working on strings. Im excited to learn about strings";
	// string word;
	// getline(cin, word);
	// size_t index = para.find(word);
	// if(index==-1) cout<<"string not found\n";
	// else cout<<"first occ at: "<< index <<"\n";

	// //find the next occ
	// index = para.find(word, index+1);
	// if(index!=-1) cout<< "sec occ: " <<index<<"\n";

	// cout<< para.size()<<"\n";
//--------------
	vector<int>a;
	a=stringSearch("We are stl stlstl stll learning about stl strings. stl string class stl is quite powerful", "stl");
	for(int i:a) cout<<i<<" ";

}