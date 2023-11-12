#include<bits/stdc++.h>
using namespace std;

bool wildcard_pattern_matching(string str, string pat){

	int rows = str.size();
	int col = pat.size();

	vector<vector<bool>> dp(rows+1, vector<bool> (col+1));

	//for pattern starts with * then true until then

	bool flag = true;
	for(int j=1; j<=col; j++){
		if(pat[j-1]== '*' and flag == true){
			dp[0][j] = true;
		}
		else{
			flag = false;
			dp[0][j] = false;
		} 
	}

	for(int i=1; i<=rows; i++){
		dp[i][0] = false;
	}
	dp[0][0] = true;

	for(int i=1; i<=rows; i++){
		for(int j=1; j<=col; j++){

			if(str[i-1] == pat[j-1] or pat[j-1] == '?'){
				dp[i][j] = dp[i-1][j-1];
			}
			else if(pat[j-1] == '*'){
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
			else{
				dp[i][j] = false;
			}

		}
	}

	return dp[rows][col];
}


int main(){

	string pattern = "x?y*z";
	string str = "xaylmz";

	cout<< wildcard_pattern_matching(str, pattern) << endl;

}