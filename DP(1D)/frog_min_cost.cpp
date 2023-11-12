#include<bits/stdc++.h>
using namespace std;

//top down iterative
int min_frog_cost(vector<int> a){

    vector<int>dp(a.size());

    dp[0] = 0;
    dp[1] = abs(a[0]-a[1]);

    for(int i=2; i<a.size(); i++){

        int val1, val2;
        val1 = dp[i-1] + abs(a[i] - a[i-1]);
        val2 = dp[i-2] + abs(a[i] - a[i-2]);
        dp[i] = min(val2, val1);

    }

    return dp[a.size() - 1];

}

int main(){

    vector<int> arr{30, 10, 60, 10, 60, 50};
    // int n = arr.size();

    // vector<int> dp(n, 0);
    // cout<< min_jumps(arr, n, dp, 0) << endl;

    //top down approach gives tle ..so bottom up
    cout<< min_frog_cost(arr) << endl;
}