#include<bits/stdc++.h>
using namespace std;

//exponential n^k
//topdown
int nk_recur(int n, int k){
//base case
    if(n==0){
        return 1;
    }
    //if step goes negative
    if(n<0) {
        return 0;
    }

    int ans = 0;
    for(int i=1; i<=k; i++){
        ans+= nk_recur(n-i,k);
    }
    return ans;
}

int nk_top_down(int n, int k, int *dp){

      if(n==0){
        return 1;
    }
    //if step goes negative
    if(n<0) {
        return 0;
    }

    if(dp[n]!= 0){
        return dp[n];  
    }

    int ans = 0;
    for(int i=1; i<=k; i++){
        ans+= nk_recur(n-i,k);
    }
    return dp[n] = ans;

}




int main(){
    int n, k;
    cin>>n>>k;
    // cout<< nk_recur(n,k)<<endl;

    // top down approach using recursion and dp array
    int dp[1000] = {0};
     cout<< nk_top_down(n,k,dp)<<endl;


    return 0;
}