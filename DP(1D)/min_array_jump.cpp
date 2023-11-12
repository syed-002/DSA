#include<bits/stdc++.h>
using namespace std;

//top down
int min_jumps(vector<int> arr, int n, vector<int> dp, int i=0){

    //try all possible jumps, but not the largest

    //base case
    if(i==n-1) return 0;
    if(i>=n) return INT_MAX;

    if(dp[i]!=0) return dp[i];

    //assume
    int steps = INT_MAX;
    int max_jump = arr[i];

    for(int jump = 1; jump<= max_jump; jump++){
        int next_cell = i+jump;
        int subprob = min_jumps(arr, n, dp, next_cell);
        if(subprob!=INT_MAX){
            steps = min(steps, subprob+1);
        }
    }
    return dp[i] =  steps;

        //this also works

        // //base cases
        // if(i>=(n-1)) return 0;
        // if(dp[i]!=0) return dp[i];

        // int step = INT_MAX;
        // int max_jump = a[i];
        // for(int jump=1; jump<=max_jump; jump++){
        //     int next_cell = i+jump;
        //     int subprob = min_jumps(a, n, dp, next_cell);
        //     if(subprob!=INT_MAX){ //if its int_max then we are doing nothing..equivalent to returning zero
        //         step = min(step, subprob+1);
        //     }  
        // }

        // return dp[i] = step;

}

int min_jumps_bottom_up(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int max_jump = arr[i];

        for (int j = 1; j <= max_jump && i+j < n; j++) {
           // cout<< dp[j] << " ";
            dp[i] = min(dp[i], dp[i+j] + 1);
        }
        //cout<<"\n";
    }
    return dp[n - 1];

}

int main(){

    vector<int> arr{3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 3};
    int n = arr.size();

    vector<int> dp(n, 0);
    cout<< min_jumps(arr, n, dp, 0) << endl;

    //top down approach gives tle ..so bottom up
   // cout<< min_jumps_bottom_up(arr)<< endl;
}