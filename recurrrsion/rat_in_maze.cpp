#include<bits/stdc++.h>
using namespace std;
vector<int> ans;

bool recur(vector<vector<char>> c, int i, int j, int n){

    if(i==n-1 and j==n-1) return true;


    //when you find the o
    if(c[i][j+1] == 'O'){
        ans.push_back((i)*n + (j+1));
       //cout<<"pushes1 " << (i) << " " <<(j+1) <<"\n";
        
        bool nexxt = recur(c, i, j+1, n);
        if(nexxt) {
            //cout<< "nexxt\n";
            return true;
        }
        //here both right and down elemnent is x, so you pop it and go back
        // you only pop when both the right and down elements are x and no where else
        cout<<"pops " << ans[ans.size()-1]<<"\n";
        ans.pop_back();
        //and run for the down element of that element
        if(c[i+1][j] == 'O'){
            ans.push_back((i+1)*n + j);
            //cout<<"pushes2 " << (i+1) << " " << (j) <<"\n";
            bool next = recur(c, i+1, j, n);
            if(next){
                //cout<<"NEXT\n";
                return true;
            }
        }
    }
    //here the element itself is x when you go right, so you search for down elemtn
    if(c[i+1][j] == 'O'){
        ans.push_back((i+1)*n + j);
        cout<<"pushes2 " << (i+1) << " " << (j) <<"\n";
        
        bool next = recur(c, i+1, j, n);
        if(next){
            cout<<"NEXT\n";
            return true;
        }
    }
    //returns false when both the right and down elements are x, then you go back 
    //and do recursion for the down element
    return false;
}


vector<int> findPath(int n, vector<vector<char>> c){

    ans.push_back(0);
    recur(c, 0, 0, n);   
    return ans;
    
}

int main(){

    ans.clear();
    //or else will have answer of the previous question also
    vector<vector<char>> c =
    {
        {'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O'},      
        {'O', 'O', 'O', 'X'},
        {'X' , 'X', 'O', 'O'}
    };

    ans = findPath(4, c);
    //converting to 1-based index from 0th based 
     for(int i=0; i<ans.size(); i++){
        ans[i]++;
    }
    for(int i=0; i<ans.size(); i++) cout<< ans[i] << "\n";

}