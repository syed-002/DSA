#include <bits/stdc++.h>
using namespace std;

int findSubaaySum(vector<int> a, int n, int sum)
{
    // STL map to store number of subaays starting from
    // index zero having particular value of sum.
    unordered_map<int, int> prevSum;
 
    int res = 0;
 
    // Sum of elements so far.
    int currSum = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Add current element to sum so far.
        currSum += a[i];
 
        // If currsum is equal to desired sum, then a new
        // subaay is found. So increase count of
        // subaays.
        if (currSum == sum)
            res++;
 
        // currsum exceeds given sum by currsum  - sum. Find
        // number of subaays having this sum and exclude
        // those subaays from currsum by increasing count
        // by same amount.
        if (prevSum.find(currSum - sum) != prevSum.end())
            res += (prevSum[currSum - sum]);
 
        // Add currsum value to count of different values of
        // sum.
        prevSum[currSum]++;

        for(auto i:prevSum){
            cout<< i.first << " " << i.second << "\n";
        }
        cout<<"\n";
    }
 
    return res;
}

int main() {
    // your code goes here
    // vector<int> a = {1,3,2,1,4,1,3,2,1,1,2};
    // int k=8;
    // vector<int> a = {-1, 1, -1, 2, -1};
    // int k=0;
    // vector<int> a ={-1, -1 ,1};
    // int k=0;
    //  vector<int> a ={10, 15, -5, 15, -10, 5};
    // int k=5;
     // vector<int> a = {10, 2, -2, -20, 10};
     // int k=-10;
    vector<int> a = {10,2,-2,-20,10,10,-10,40,-50,-60,100,-30,-10};
    int k = -10;
    cout<< findSubaaySum(a,a.size(),k);
    return 0;
}