#include<bits/stdc++.h>
using namespace std;

//recursive //exponential time
int countBST(int n) {
    if(n==0 or n==1) return 1; //null node for n==0

    int ans = 0;

    for(int i=1; i<=n; i++){
        ans+= countBST(i-1) * countBST(n-i);
    }
    return ans;
}

//topdown dp code for memoisation
//order of n^2
int countBSTdp(int n, int dp[]) {
    if(n==0 or n==1) return 1; //null node for n==0

    if(dp[n]!=0){
        return dp[n];
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans+= countBSTdp(i-1, dp) * countBSTdp(n-i, dp);
    }
    return dp[n] = ans;
}

int countBSTBottomUp(int n){
    vector<int>dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++){

        for(int j=1; j<=i; j++){
            //if jth node is the root node, j-1 nodes are before 
            // and i-j nodes are after 
            dp[i]+= dp[j-1]* dp[i-j];

        }
    }
    return dp[n];

}


int main(){

   int n = 5;
   cout<< countBST(n) << endl;
   int dp[n+1] = {0};
   cout<< countBSTdp(n, dp) << endl;
   cout<< countBSTBottomUp(n) << endl;
   
 
}

