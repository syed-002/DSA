#include<bits/stdc++.h>
using namespace std;

//bottomup
int maxSum(vector<int> a){

    vector<int>dp(a.size());
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);

    for(int i=2; i<a.size(); i++){
        dp[i] = max(dp[i-1], dp[i-2]+a[i]);
    }
    return dp[a.size()-1];

}

int main(){

    vector<int> arr{6,10,12,7,9,14};
   
    // int n = arr.size();

    // vector<int> dp(n, 0);
    // cout<< min_jumps(arr, n, dp, 0) << endl;

    //top down approach gives tle ..so bottom up
    cout<< maxSum(arr) << endl;
}

