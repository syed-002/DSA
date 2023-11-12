#include<bits/stdc++.h>
using namespace std;

int levenshteinDistance(string str1, string str2) {
  // Write your code here.
  int rows = str1.size();
  int cols = str2.size();
  vector<vector<int>> dp(rows+1, vector<int>(cols+1));

  //empty string with empty string
  dp[0][0] = 0;
  for(int i=1; i<=rows; i++){
    dp[i][0] = i;
  }
  for(int j=1; j<=cols; j++){
    dp[0][j] = j;
  }

  for(int i=1; i<=rows; i++){
    for(int j=1; j<=cols; j++){
      //if string matchess then just get the (i-1, j-1) position value since
      //no operations are performed
      if(str1[i-1] == str2[j-1]){
        
        dp[i][j] = dp[i-1][j-1];
      }
      else{
         
        //comparing the three boxes, top(insert), left(remove), diagnoal(replace) top and getting min and add one to it
        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) +1;
      }
    }
  }

  // for(int i=0; i<=rows; i++){
  //   for(int j=0; j<=cols; j++){
  //     cout<< dp[i][j] << " ";
  //   }
  //   cout<< endl;
  // }

  return dp[rows][cols];
}


int main(){
  
  string s1 = "horse";
  string s2 = "ros";
  cout<< levenshteinDistance(s1, s2) << endl;

}