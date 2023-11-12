#include<bits/stdc++.h>
using namespace std;

int countSub_rec(string a, string b, int m, int n){
	//base
	if(m==-1 and n==-1){
		return 1;
	}
	if(n==-1){ //substring b is over
		return 1;
	}
	if(m==-1){
		return 0; //since string b is bigger than a
	}

	//rec
	if(a[m]!= b[n]){
		return countSub_rec(a, b, m-1, n);
	}
	//matches
	return countSub_rec(a, b, m-1,n-1) + countSub_rec(a, b, m-1, n);
	
}

int countSub_tp(string a, string b, int m, int n, vector<vector<int>> dp){
	//base
	if(dp[m][n]!= -1) return dp[m][n];
	if(m==-1 and n==-1){
		return 1;
	}
	if(n==-1){ //substring b is over
		return 1;
	}
	if(m==-1){
		return 0; //since string b is bigger than a
	}

	//rec
	if(a[m]!= b[n]){
		return dp[m][n] = countSub_rec(a, b, m-1, n);
	}
	//matches
	return dp[m][n] = countSub_rec(a, b, m-1,n-1) + countSub_rec(a, b, m-1, n);
	
}

int countSub_bu(string a, string b){
	int m = a.size();
	int n = b.size();
	

	vector<vector<int>> dp(m+1, vector<int>(n+1,0));

	for(int i=0;i <=m; i++){
		dp[i][0] = 1;
	}

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){

			if(a[i]==b[j]){
				dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}

		}
	}
	return dp[m][n];

}



int main(){
	string a = "ABBCDCECC";
	string b = "ABC";
	//ans is 4

	cout<< countSub_rec(a, b, a.size()-1, b.size()-1) << endl;
		
	vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
	cout<< countSub_tp(a, b, a.size()-1, b.size()-1, dp) << endl;

	cout<< countSub_bu(a, b) << endl;
}