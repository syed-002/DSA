#include<bits/stdc++.h>
using namespace std;

string find_window(string s, string p){

    int FS[256] = {0};
    int FP[256] = {0};

    for(int i=0; i<p.length(); i++){
        FP[p[i]]++;
    }

    int cnt = 0;
    int start = 0;
    int min_so_far = INT_MAX;
    int window_size;
    int start_ind = -1;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        
        FS[ch]++;

        //maintaing count if same no.of chars present
        if(FP[ch]!=0 and FS[ch] <= FP[ch]){
            cnt++;
        }

        //if all the chars are present, contraction
        if(cnt==p.length()){
            
            while(FS[s[start]]> FP[s[start]] or FP[s[start]]==0){
                FS[s[start]]--;
                start++;
            }

            window_size = i-start+1;
            if(window_size<min_so_far){
                //cout<<  s.substr(start, window_size)<< endl;
                min_so_far = window_size;
                start_ind = start;
            }

        }

    }
     if(start_ind == -1) return "No string found";

    return s.substr(start_ind, min_so_far);

}

string runner_fun(string str){

    
    int FS[256] = {0};
    int FP[256] = {0};
    
    for(int i=0; i< str.length(); i++){
        FS[str[i]]++;
        if(FP[str[i]]==0) FP[str[i]]++;
    }
    
    string pattern = "";
    
    for(int i=0; i<256; i++){
        if(FP[i]){
             pattern+= (char)i;
        }
    }

    return pattern;


}

int main(){

     string str = "aabcbcdbcaaad";
    
    string pattern = runner_fun(str);
   
    cout<< find_window(str, pattern) <<endl; 
}