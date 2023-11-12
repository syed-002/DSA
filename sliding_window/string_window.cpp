#include<bits/stdc++.h>
using namespace std;

string find_window(string s, string p){

    int freq_P[256] = {0}; //for string p
    int freq_S[256] = {0}; //for the window, you can use hashmap too

    for(int i=0; i<p.length(); i++){
        freq_P[p[i]]++;
    }

    //sliding window algo

    //for checking how many char matched with the pattern P
    int c=0;
    int start = 0;// left contraction
    int start_ind= -1; //start window for best window, which is yet to found
    int min_so_far = INT_MAX;
    int window_size;


    for(int i=0; i<s.length(); i++){

        char ch = s[i];
        //expand the wondow by including current char
        freq_S[ch]++;
        //count how mnay char matched till now
         if(freq_P[ch]!=0 and freq_S[ch]<=freq_P[ch]){
             c++;
         }

        //if all t he char of the pattern found in current window, start contracting
        if(c == p.length()){
            //start contracting from the left to remove unwanted char
            //not present in pattern
            //or freq is higher than required

            while(freq_P[s[start]]==0 or freq_S[s[start]]> freq_P[s[start]]){
                freq_S[s[start]]--;
                start++;
            }

            window_size = i-start+1;
            if(window_size< min_so_far){
                min_so_far = window_size;
                start_ind = start;
            }

        }
    }

    if(start_ind == -1){
        return "No window found";

    }
    return s.substr(start_ind, min_so_far);
}

int main(){
    string s, p;
    cin>>s>>p;
    // hlelo oel
    //return elo
    cout<< find_window(s,p)<<endl;

    return 0;
}