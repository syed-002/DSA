#include<bits/stdc++.h>
using namespace std;

int max_profit(int prices[], int n){
    //base case
    if(n<=0) return 0;

    //rec case
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int cut = i+1;

        int curr_ans = prices[i] + max_profit(prices, n-cut);
        ans = max(ans, curr_ans);
    }

    return ans;
}
//you can use topdown + memoization... just add dp array to the above code
//avoiding overlapping subproblems

//bottom up solution
int max_profit_dp(int prices[], int n){

    int dp[n+1];
    dp[0] = 0;

    for(int len = 1; len<=n; len++){
        int ans = INT_MIN;
        for(int i = 0; i<len; i++){
            int cut = i+1;
            int curr_ans = prices[i] + dp[len-cut];
            ans = max(curr_ans, ans);
        }
        dp[len] = ans;
    }

    // for(int i:dp){
    //     cout<< i << " ";
    // }
    //0 1 5 8 10 13 17 18 22
    return dp[n]; //ie 9th ele.. since 0th ele is 0
    
    
}

int main(){
    int prices[] = {1,5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices)/sizeof(int);
    //length of 6+2 = price of 5+17 = 22
    cout<<max_profit_dp(prices, n)<<endl;
}
