#include<bits/stdc++.h>

using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string S){
    
    unordered_map<char, int>map;

    queue<char> q;
    vector<char> op;
    for(auto ch:S){
        if(map.find(ch)==map.end()){
            //not found
            map.insert(make_pair(ch, 1));
            q.push(ch);
        }
        else {
            map[ch]++;
        }
        if(map[q.front()] >1){
            q.pop();
        }
        if(!q.empty() and map[q.front()]==1) op.push_back(q.front());
        else op.push_back('0');
    }
    return op;
}

int main(){
    //string s="aabccbcd";
    string s="aabcbcd";
    vector<char> op=FindFirstNonRepeatingCharacter(s);
    for(auto ch:op) cout<< ch << " ";
}