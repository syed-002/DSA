#include<bits/stdc++.h>
using namespace std;

//topdown
int max_wine(vector<vector<int>>&dp, vector<int>p, int l, int r, int y){

	//base 
	if(l>r) return 0;

	if(dp[l][r] != 0 ) return dp[l][r];

	// rec 
	int pick_left = y*p[l] + max_wine(dp, p, l+1, r, y+1);
	int pick_right = y*p[r] + max_wine(dp, p, l, r-1, y+1);

	return dp[l][r] = max(pick_right, pick_left);

}

int wines_bot_up(vector<int> p, int n){

	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for(int i = n-1; i>=0; i--){//goin from bottom, see notes to understand clearly

		for(int j = 0; j<n; j++){

			if(i>j){
				dp[i][j] = 0;
			}
			if(i==j){
				dp[i][i] = n*p[i]; //since (j-i) is zero and also cant take the dp[-1][0] valuce since its garbage
			}
			else{ // i<j case
				int y = n- (j-i);
				int pick_left = p[i]*y + dp[i+1][j]; //these dp are alreay computed since bottom up
				int pick_right = p[j]*y + dp[i][j-1];
				dp[i][j] = max(pick_right,pick_left);
			}
		}
	}

	// for(auto i:dp){
	// 	for(auto j:i){
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;
	// }

	
	return dp[0][n-1];

}

int main(){
	vector<int> arr{2,3,5,1,4};
	int n= arr.size();
	int left = 0, right = n-1, year = 1;

	
	vector<vector<int>> dp(n, vector<int>(n, 0));
	//int dp[10][10] = {0}; 

	cout<< max_wine(dp, arr, left, right, year) <<endl; 

	
	// for(int i=0; i<n ; i++){
	// 	for(int j=0; j<n; j++){
	// 		cout<< dp[i][j] << " ";
	// 	}
	// 	cout<< endl;
	// }

	// for(auto i:dp){
	// 	for(auto j:i){
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;
	// }

	cout<< wines_bot_up(arr, n) << endl;
}