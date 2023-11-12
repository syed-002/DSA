#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, int wts[], int pr[]){

	if( n==0 or W==0) return 0;

		int inc=0, exc=0; //if yo0u dont initialize random valus will be taken
		if(wts[n-1] <=W){
			inc = pr[n-1] + knapsack(n-1, W-wts[n-1], wts, pr); //pr[n-1] is the index
		}
		exc = 0 + knapsack(n-1, W, wts, pr);
		
		return max(inc, exc);
}

int knapsack_Top_down(int n, int W, int wts[], int pr[], vector<vector<int>>dp){

	if( n==0 or W==0) return 0;

	if(dp[n][W]!= -1) return dp[n][W];

	int inc=0, exc=0; //if yo0u dont initialize random valus will be taken
	if(wts[n-1] <=W){
		inc = pr[n-1] + knapsack_Top_down(n-1, W-wts[n-1], wts, pr, dp); //pr[n-1] is the index
	}
	exc = 0 + knapsack_Top_down(n-1, W, wts, pr, dp);
	
	return dp[n][W] = max(inc, exc);
}

int knapsack_bot_up(int N, int W, int wts[], int pr[]){

	vector<vector<int>> dp(N+1, vector<int> (W+1, 0));

	for(int n=1; n<=N; n++){
		for(int w=1; w<=W; w++){
			int inc = 0, exc = 0;

			//all the weights w will be deposited in the dp array and the right most corner cell will give ans
			if(wts[n-1] <= w){
				inc = pr[n-1] + dp[n-1][w-wts[n-1]];
			}
			exc = 0+dp[n-1][w];

			dp[n][w] = max(inc, exc);
		}
	}
	return dp[N][W];

}

int main(){
	int wts[] = {2, 7, 3, 4};
	int prices[] = {5, 20, 20, 10};

	int W = 11;
	int n = sizeof(wts)/sizeof(wts[0]);

	// cout<< knapsack(n, W, wts, prices) << endl;

	//vector<vector<int>> dp(n+1, vector<int> (W+1, -1)); //+1 imp or else seg fualt
	//cout<< knapsack_Top_down(n,W, wts, prices, dp) << endl;

	cout<< knapsack_bot_up(n,W, wts, prices) << endl;

}