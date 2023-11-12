#include<bits/stdc++.h>
using namespace std;

// vector<int> stockSpan(vector<int> v) {
// //Write your code here. Do not modify the function or parameters.
// 	stack<pair<int, int>> s;
// 	vector<int> ans;

// 	for(int i=0; i<v.size(); i++){
// 		if(i ==0){
// 			ans.push_back(1);
// 			s.push(make_pair(i, v[i]));
// 			continue;
// 		}

// 		int curr_price=v[i];
// 		while(!s.empty() and s.top().second<=curr_price){
// 			s.pop();
// 		}		

// 		if(!s.empty()){
// 			int prev_price_ind = s.top().first;
// 			ans.push_back(i- prev_price_ind);
// 		}
// 		else{
// 			ans.push_back(i+1);
// 		}

// 		s.push(make_pair(i, v[i]));
// 	}
// 	return ans;
    
// }

vector<int> stockSpan(vector<int> v){

	stack<int> s;
	s.push(0);
	vector<int> span;
	span.push_back(1);

	for(int i=1; i<v.size(); i++){
		int curr_price = v[i];
		while(!s.empty() and v[s.top()]<=curr_price){
			s.pop();
		}
		if(!s.empty()){
			int prev_highest = s.top();
			span.push_back(i- prev_highest);
		}
		else{
			span.push_back(i+1);
		}
		s.push(i);
	}
	return span; 
}
int main(){
	 //vector<int> v= {100, 80, 60, 70, 60, 75, 85};
	vector<int> v= {10, 4, 5, 90, 120, 80};

	vector<int> ans= stockSpan(v);
	for(auto i:ans){
		cout<< i<< " ";
	}
	cout<<endl;
}