#include<bits/stdc++.h>
using	 namespace std;

string extractStringAtKey(string str, int key){
	//string tokeniser
	stringstream ss(str);
	vector<string> tokens;
	string temp;
	while(getline(ss, temp, ' ')){
		tokens.push_back(temp);
	}
	return tokens[key-1];
}

int convertToInt(string a){

	int ans=0;
	int p=1;
	int n=a.size();
	for(int i=n-1; i>=0; i--){
		ans+= (a[i]-'0')*p;
		p*=10;
	}
	return ans;
}

bool numericCompare(pair<string, string> a, pair<string, string> b){
	string key1, key2;
	key1=a.second;
	key2= b.second;

	return convertToInt(key1)< convertToInt(key2);

}

bool lexicoCompare(pair<string, string> a, pair<string, string> b){
	string key1, key2;
	key1=a.second;
	key2= b.second;

	return key1 < key2;
	//string operators inherently compare lexiographically

}

int main(){
	int n;
	cin>>n;

	cin.get(); //consume extra \n char

	string temp;
	vector<string> v;
	for(int i=0; i<n; i++){
		getline(cin, temp); //getline includes white spaces
		v.push_back(temp);
	}
	int key;
	string reversal, ordering;
	cin>> key>> reversal>> ordering;


	// to extract keys for comparision and store 

	// string s = "20 30 40";
	// cout<<extractStringAtKey(s, 2)<<"\n";

	vector<pair<string, string>> vp;

	for(int i=0; i<n; i++){
		vp.push_back({v[i], extractStringAtKey(v[i],key)});	
	}

	//sorting

	if(ordering=="numeric"){
		sort(vp.begin(), vp.end(), numericCompare);
	}
	else{
		sort(vp.begin(), vp.end(), lexicoCompare);
	}

	if(reversal=="true"){
		reverse(vp.begin(), vp.end());
	}

	for(int i=0; i<n; i++){
		cout<<vp[i].first<<"\n";
	}

	// string s="1234567";
	// cout<< convertToInt(s)<<"\n";

}