#include<bits/stdc++.h>
using namespace std;

int rec(int sum, vector<int> c, int i){

	if(i<0) return 0;
	if(sum < 0) return 0;
	if(sum == 0) return 1;

	int inc = rec(sum - c[i], c, i);
	int exc = rec(sum, c, i-1);

	return inc + exc;

}

int rec_dp(int sum, vector<int> c, int i, vector<vector<int>> dp){
	
	//sum can be -ve so it will give seg fault, so keep it down
	//if(dp[sum][i]!= -1) return dp[sum][i];

	if(i<0) return 0;
	if(sum < 0) return 0;
	if(sum == 0) return dp[sum][i] = 1;

	if(dp[sum][i]!= -1) return dp[sum][i];

	return dp[sum][i] = rec_dp(sum - c[i], c, i, dp) + rec_dp(sum, c, i-1, dp);
}

//dp tabular approach// works in leetcode, least tc
int dp_tab(int amount, vector<int> coins){

	//rows are coin demonniations
	//cols are 0 to amount
	int rows = coins.size()+1;
	int cols = amount+1;
	vector<vector<int>> dp(rows, vector<int>(cols, 0));
	

	for(int i=0; i<rows; i++){
		dp[i][0] = 1; //takes 1 way to make 0 for all denominations
	}
	for(int j=1; j<cols; j++){
		dp[0][j] = 0; //takes 0 ways since no coins at all
	}

	//all cells are 0 since already initiated

	for(int i=1; i<rows; i++){

		for(int j=1; j<cols; j++){

			//exc coin
			dp[i][j] += dp[i-1][j];

			//inc coin
			if(j-coins[i-1] >=0){
				dp[i][j] += dp[i][j-coins[i-1]];
			}

		}
	}
	return dp[rows-1][cols-1];

}

int main(){

	int sum = 50;
	vector<int> coins{1, 2, 5};
	int n = 3;
	int i = 3;

	//cout<< rec(sum, coins, i-1) << endl;

	vector<vector<int>> dp(sum+1, vector<int>(coins.size()+1, -1));
	
    cout<<  rec_dp(sum, coins, coins.size()-1, dp);

    cout<< endl;

    cout<< dp_tab(sum, coins) << endl;
}