#include<bits/stdc++.h>
using namespace std;

//recursive  
int coin_change(int m, vector<int> a){

    if(m==0) return 0;

    int minn = INT_MAX;
    for(int i=0; i<a.size(); i++){
        if(m-a[i]>=0){
            int x = coin_change(m-a[i], a);
            minn = min(minn, x+1);
        }
        
    }

    return minn;
}

//dp
int coin_change_dp(int m, vector<int> a, vector<int>dp){

    if(m==0) return 0;

    if(dp[m]!=-1) return dp[m];

    int minn = INT_MAX;
    for(int i=0; i<a.size(); i++){
        if(m-a[i]>=0){
            dp[m-a[i]] = coin_change_dp(m-a[i], a, dp);
            minn = min(dp[m-a[i]], minn);
            
        }
        
    }
    if(minn==INT_MAX || minn <=0) return dp[m] = -1;
    return dp[m] = minn+1;
}


int coin_change_gpt(int m, vector<int> denoms, vector<int> &dp) {
    if (m == 0) return 0;
    if (dp[m] != -1) return dp[m];

    int minimum = INT_MAX;

    for (int i = 0; i < denoms.size(); i++) {
        if (m - denoms[i] >= 0) {
            int subproblem = coin_change_gpt(m - denoms[i], denoms, dp);
            if (subproblem != INT_MAX) {  // Check if a valid solution exists
                minimum = min(minimum, subproblem + 1);
            }
        }
    }

    dp[m] = (minimum == INT_MAX) ? -1 : minimum;
    return dp[m];
}



int main(){
    vector<int> denoms = {2, 4};
    int m = 7;

    vector<int> dp(m+1, -1);
    dp[0] = 0;
    cout<<coin_change(m, denoms)<<endl;
    // cout<< min_coin_change(m, denoms)<< endl;
    cout<< coin_change_dp(m, denoms, dp)<<endl;
    cout<< coin_change_gpt(m,denoms, dp)<< endl;
}