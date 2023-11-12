#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a={1,9,4,2,5};
	cout<< a.size() <<"\n";
	cout<<a.capacity()<<"\n";

	// fill constructor
	vector<int> fill(100, 123);
	// for(int i:fill){
	// 	cout<< i <<" ";
	// }
	// cout<<"\n";

	//sort
	int n=a.size();
	//sort(a, a +n) --> this is not working in mine

	sort(a.begin(), a.end());

	for(int i:a){
		cout<<i <<" ";
	}

}