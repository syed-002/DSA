#include<bits/stdc++.h>
using namespace std;

//bottomup
int lis(vector<int> a){

    int n= a.size();
    vector<int> dp(n, 1);
    //dont write dp[0] = 1;
    //since dp[i] is being compared in second loop
    //it should have some value
    //or else it will give wrong answer

    int len = INT_MIN;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], 1+dp[j]); 
                //dp[i] is keep getting updated with max in the j loop
                len = max(len, dp[i]);
            }
        }


    }
   return len;

}

int main(){

    vector<int> arr{50, 4, 10, 8, 30, 100};
   
    // int n = arr.size();

    // vector<int> dp(n, 0);
    // cout<< min_jumps(arr, n, dp, 0) << endl;

    //top down approach gives tle ..so bottom up
    cout<< lis(arr) << endl;
}

