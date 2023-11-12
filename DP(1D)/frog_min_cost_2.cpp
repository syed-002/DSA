#include<bits/stdc++.h>
using namespace std;



long long minimumCost(vector<int> a, int k){
    //Write your code here. Do not modify the function or the parameters. Use a helper function if needed.

     vector<long long>dp(a.size());
     dp[0]=0;
     dp[1] = abs(a[1]-a[0]);


     for(int i=2; i<k; i++){

        long long val = INT_MAX;

        for(int j=i-1; j>=0; j--){
            val = min( val, dp[j] + abs(a[i]-a[j]));
        }
        dp[i] = val;
        cout<<dp[i] << endl;



    }

    for(int i=k; i<a.size(); i++){


        long long val = INT_MAX;
        for(int j=1; j<=k; j++){
           val = min( val, (dp[i-j]+ abs(a[i]-a[i-j])) );
       }
       dp[i] = val;
       cout<<dp[i] << endl;

    }

    for(auto i:dp){
        cout<< i << " ";
    }cout<<endl;

return dp[a.size() - 1];


}


int main(){

    vector<int> arr{10, 20,10};
    int k = 1;
    // int n = arr.size();

    // vector<int> dp(n, 0);
    // cout<< min_jumps(arr, n, dp, 0) << endl;

    //top down approach gives tle ..so bottom up
    cout<< minimumCost(arr, k) << endl;
}

