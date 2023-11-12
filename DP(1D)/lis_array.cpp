#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> a) {
  // Write your code here.
  int n = a.size();
  vector<int> dp(a.size(), 1);
  dp[0] =1;

  for(int i=1; i<n; i++){
    int maxx = INT_MIN;
    for(int j=0; j<i; j++){
      if(a[j] < a[i]){
        dp[i] = 1 + max(maxx, dp[j]);
      }
    }
  }
  
  int maxx = INT_MIN;
  for(auto i: dp){
    // cout<< i << " ";
    maxx = max(maxx, i);
  }

  //maxx is the max lenght of lis

  int i = n-1, temp;
  int temp_maxx = maxx;
  vector<int> ans;

  while(i>=0 and maxx>0){
    if(dp[i]==maxx){
      ans.push_back(a[i]);
      maxx--;
    }
    i--;
  }
  
  // for(auto i: ans) {
  //   cout<< i << endl;
  // }
  reverse(ans.begin(), ans.end());


  return ans;

}

int main(){
  vector<int> a{5, 7, -24, 12, 10, 2, 3, 12, 5, 6, 35};
  vector<int> ans = longestIncreasingSubsequence(a);
  for(auto i:ans){
    cout<< i << " ";
  }
  cout<< endl;
}