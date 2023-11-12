#include<bits/stdc++.h>
using namespace std;

bool compareBoxes(vector<int> b1, vector<int> b2){
    if(b1[2] < b2[2]) return true;
    else return false;
}


int boxst(vector<vector<int>> a){

    //sort them based on height
    sort(a.begin(), a.end(), compareBoxes);

    //dp
    int n = a.size();
    vector<int> dp(n+1, 0);

    for(int i=0; i<n; i++){
        dp[i] = a[i][2];//storing heights
    }

    for(int i=1; i<n; i++){
        //for boxes less than index i
        for(int j=0; j<i; j++){
            if(a[i][0]> a[j][0] and a[i][1] > a[j][1] and a[i][2]> a[j][2]){

                int curr_h = a[i][2];

                if(dp[j]+curr_h > dp[i]){
                    dp[i] = dp[j]+curr_h;
                }

            }
        }
    }

    int max_h=0;
    for(int i=0; i<n; i++){
        max_h = max(max_h, dp[i]);
    }

    return max_h;
}

int main(){

    vector<vector<int>> boxes= {
        {2, 1, 2},
        {3, 2, 3},
        {2, 2, 8}, 
        {2, 3, 4}, 
        {2, 2, 1},
        {4, 4, 5}
    };

    //10 (2+3+5) is out 
   
    // int n = arr.size();

    // vector<int> dp(n, 0);
    // cout<< min_jumps(arr, n, dp, 0) << endl;

    //top down approach gives tle ..so bottom up
    cout<< boxst(boxes) << endl;
}

