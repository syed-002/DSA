#include<bits/stdc++.h>
using namespace std;

void perm(string a, vector<string>&ans, int l, int r){
    
    if(l==r){
        ans.push_back(a);
        return;
    }
    for(int i=l; i<=r; i++){
        swap(a[l], a[i]);
        perm(a, ans, l+1, r);
        swap(a[l], a[i]);
    }
    
    
}

void remove_dup(vector<string> &ans){
	int i=1;
	while(i<ans.size()){
		if(ans[i]==ans[i-1]){
			ans.erase(ans.begin()+i);
			continue;
		}
		i++;
	}
	return;
}

vector<string> findSortedPermutations(string s){
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
    //cout<<s<<endl;
    vector<string> ans;
    perm(s, ans, 0, s.size()-1);
    sort(ans.begin(), ans.end());
    remove_dup(ans); 
       
    return ans;
}
int main(){
	string s="abcb" ;
	vector<string> ans;
	ans = findSortedPermutations(s);
	for(string x:ans) cout<< x << " ";
	return 0;
}