#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int i, int j){

	if(i==s1.length() or j== s2.length()) return 0;

	if(s1[i] ==  s2[i]){
		return 1+lcs(s1, s2, i+1, j+1);

	}

	int opt1 = lcs(s1, s2, i+1, j);
	int opt2 = lcs(s1, s2, i, j+1);

	return max(opt1, opt2);
}

int lcs_td_mem(string s1, string s2, int i, int j, vector<vector<int>> &dp){

	if(i==s1.length() or j== s2.length()) return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	if(s1[i] ==  s2[j]){
		return dp[i][j] =  1+lcs_td_mem(s1, s2, i+1, j+1, dp);

	}

	int opt1 = lcs_td_mem(s1, s2, i+1, j, dp);
	int opt2 = lcs_td_mem(s1, s2, i, j+1, dp);

	return dp[i][j] = max(opt1, opt2);
}



int lcs_bt_up(string s1, string s2, vector<vector<int>>dp, vector<char> &ans){

	int n1 = s1.length();
	int n2 = s2.length();

	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2 ; j++){

			if(s1[i-1] == s2[j-1]){
				// cout<< s1[i] << endl; 
				//ans.push_back(s1[i]);
				//---------------------------------------------------------->
				//dont pushback here since in the given example
				//z which is not common char at the begging of the string 2
				//is seen at the end
				//hence z will aslo be added and it becomes a mistake
				//so traverse back from the dp array
				//----------------------------------------------------------->
				dp[i][j] = dp[i-1][j-1] +1; 
			}
			
			else{
				// dp[i+1][j+1] = max( dp[i][j+1], dp[i+1][j]); if you start from  0th index to n-1
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int i = n1;
	int j = n2;

	
	while(i>0 and j>0){  //if equal to zero gives seg fualt since cant go -1 position
		
		if(dp[i][j] == dp[i-1][j]){
			i--;
		}	
		else if(dp[i][j] == dp[i][j-1]){
			j--;

		}
		else{
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());


	return dp[n1][n2];
}

int main(){

	string s1 = "ZXVVYZW";
	string s2 = "XKYKZPW";
	// ans "xyzw"

	// string s1 = "abcd";
	// string s2 = "abedg";


	//---------------------------------------------------->
	//recursion
	//cout<< lcs(s1, s2, 0, 0)<< endl;

	int n1 = s1.length();
	int n2 = s2.length();

	//---------------------------------------------------->
	//top_down mem
	//you can print the dp array to understand how it traverses

	vector<vector<int>> dp(n1, vector<int>(n2, -1)); 
	cout<< lcs_td_mem(s1, s2, 0, 0,dp) << endl;
	//answer is stored at dp[0][0] since it starts from last and reaches to top and returns the same
	
	//---------------------------------------------------->
	//bottom_up
	// vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	// vector<char>ans;

	// cout<<lcs_bt_up(s1, s2, dp, ans)<< endl;
	// for(auto i: ans){
	// 	cout<< i << " ";
	// }
	// cout<< endl;


}