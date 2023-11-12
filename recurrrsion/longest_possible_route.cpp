#include<bits/stdc++.h>
using namespace std;

void find(vector<vector<int>> v, int x, int y, int r, int c, int pathlength, int &ans){
    if(x==r-1 and y==c-1){
        cout<<pathlength<<"\n";
        if(pathlength> ans) ans = pathlength;
        //dont return ans becoz you have to compare many possibilities
        return;
    }
    // marking matrix to not visist again
    v[x][y] = 2;

    vector<pair<int, int>> neighbours = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    for(auto i: neighbours){ 
        // using auto instead of pair<int, int>
        int new_x= x + i.first;
        int new_y= y + i.second;
        //if you add these neighbors to the cordinates, you move in all four directions
        //instead of writing four lines, you are writing one
        if(new_y>=0 && new_x>=0 && new_x<r && new_y<c && v[new_x][new_y]==1){
            find(v, new_x, new_y, r, c, pathlength+1, ans);
        }
    }

    //when backtracking, you make the v[i][j]=1 since you have to visit them again
    //during all the possiblities checking
    v[x][y]=1;
    
}


int findLongestPath(int r, int c, vector<vector<int>> v){
    //Complete this function. Do not modify the name or parameters. You can make a helper function if needed.
    int ans =0;
    int pathlength = 0;
    find(v, 0, 0, r, c, pathlength, ans);
    return ans;
}


int main(){
    vector<vector<int>> v =
    {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 1}
    };
    int r=3, c=3;
    findLongestPath(r, c, v);
}