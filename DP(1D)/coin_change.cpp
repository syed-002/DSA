#include<bits/stdc++.h>
using namespace std;

int coin_change_tp(int m, vector<int> denoms, vector<int> &dp){

    if(m==0) return 0;
    if(dp[m]!= -1) return dp[m];
    
    int minimum = INT_MAX;

    for(int i=0; i< denoms.size(); i++){
        dp[m-denoms[i]] = coin_change_tp(m-denoms[i], denoms, dp);
        minimum = min(minimum, dp[m-denoms[i]]);
    }
    
    dp[m] = minimum + 1;
    return dp[m];
}

//bottom up
int min_coin_change(int m, vector<int> denoms){
    vector<int> dp(m+1, 0);

    dp[0] = 0;
    for(int i=1; i<=m; i++){
        dp[i] = INT_MAX;
        for(int c: denoms){ 
            //WHERE CHANGE IS IMPOSSIBLE IE DOESNT MAKE 0, THEN PUT INFINITY IN THAT PLACE
            //SUCH THAT THE ANS IS NOT INFINITY
            if(i-c>=0 and dp[i-c]!=INT_MAX){
                dp[i] =  min(dp[i], dp[i-c]+1);
            }
        }
    }
    return dp[m]==INT_MAX? -1 : dp[m];
}

int main(){
    vector<int> denoms = {1,3,7,10};
    int m = 15;

    vector<int> dp(m+1, -1);
    dp[0] = 0;
    cout<<coin_change_tp(m, denoms, dp)<<endl;
    // cout<< min_coin_change(m, denoms)<< endl;
}