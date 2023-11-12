#include<bits/stdc++.h>
using namespace std;

string fun(string s){

    int i=0, j=0;
    unordered_map<char, int>ind;

    int wind_size=0;
    int max_wind_size=0;
    int start_ind_wind = -1;//startijng index of max window to return the answer substring

    while(j<s.size()){

        char ch = s[j];

        //if the char is present in the hashmap and current index is greater than i-->(start of the curr window)
        if(ind.count(ch) and ind[ch]>=i){
            i = ind[ch]+1;
            wind_size = j-i; //since +1 is added anyhow down when the window is being updated
            cout<<s.substr(i, wind_size)<<endl;
        }

    //update the last occurence which is not peresnt in the hashmap
        ind[ch] = j;
        j++;
        wind_size++;

        //updating maxwindow size

        if(wind_size>max_wind_size){
            max_wind_size = wind_size;
            start_ind_wind = i;
            //so the answer substring would be from ith index of length max_wind_size

        }

    }

        return s.substr(start_ind_wind, max_wind_size);
    
}

int main(){
    //string s = "abcaeba";
    //bcae is ans
    string s;
    cin>>s;
    cout<< fun(s) << endl;
}