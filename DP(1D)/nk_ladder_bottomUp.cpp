#include<bits/stdc++.h>
using namespace std;

int nk_bottomUp(int n, int k){

    //iterative

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        int ans = 0;
        for(int j = 1; j <= k; j++){
            if(i-j>=0){
                 ans+= dp[i-j];
            }
        }
        dp[i] = ans;
    }
    return dp[n];

}

//dp[i] is calculated in o(1) TC instead of o(k)
int nk_bottomUp_Optimized(int n, int k){

    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++){

        // //filling first k+1 steps
        // if(i<=k){
        //     for(int j=1; j<=k; j++){
        //         if(i-j>=0){
        //             dp[i]+= dp[i-j];
        //         }
        //     }
        // }

        //filling first k+1 steps its just the doubling of the last value
        if(i<=k){
            dp[i] = 2*dp[i-1];
        }

        //after k+1, we subtract i-k-1 index and add the next index like sliding window
        if(i-k-1>=0){
            dp[i]= (2*dp[i-1]) - dp[i-k-1];
        }
    }
    return dp[n];
}

int main(){
    int n, k;
    cin>>n>>k;

   
    cout<< nk_bottomUp_Optimized(n,k)<< endl;
}