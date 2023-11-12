#include<bits/stdc++.h>
using namespace std;

int count_subsets(vector<int> arr, int n, int i, int tar){
	
	if(i==n){
		if(tar==0)
			return 1;
		return 0;
	}
	return count_subsets(arr, n, i+1, tar-arr[i])+count_subsets(arr, n, i+1, tar);
	// int inc = count_subsets(arr, n, i+1, tar-arr[i]);
	// int exc =  count_subsets(arr, n, i+1, tar);
	// return inc+exc;
}


int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	int sum;
	cin>>sum;
	cout<<count_subsets(v, n, 0, sum)<<"\n";
	return 0;
}