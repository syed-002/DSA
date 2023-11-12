#include<bits/stdc++.h>
using namespace std;

//using deques for slideing window problem
void maxSubarrayK(vector<int> a, int k){

	deque<int> Q(k);
	int i;
	//in the deque we are stroing indexes
	//for the first k elements
	for(i=0; i<k; i++){
		while(!Q.empty() and a[i]>a[Q.back()]){
			Q.pop_back();
		}
		Q.push_back(i);
	}
	//for the remaining elemts of array
	for( ; i<a.size(); i++){
		cout<<a[Q.front()]<<" ";
		//contraction of the window
		//limiting to k elements
		while(!Q.empty() and Q.front()<=i-k){
			Q.pop_front();
		}
		while(!Q.empty() and a[i]>a[Q.back()]){
			Q.pop_back();
		}
		Q.push_back(i);
		if(i==a.size()-1){
			//printing last element in the queue
			cout<<a[Q.front()]<<" ";
		}
	}
}
int main(){
	vector<int>a={1, 2, 3, 1, 4, 5, 2, 3, 6};
	maxSubarrayK(a, 3);
}