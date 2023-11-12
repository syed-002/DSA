#include <bits/stdc++.h>
using namespace std;
int c=0;
bool canPlace(int board[][20], int i, int j, int n){
    //col 
    for(int k=0; k<i; k++){
        if(board[k][j]==1) return false;
    }
    //left diag
    int x=i, y=j;
    while(x>=0 and y>=0){
        if(board[x][y]==1) return false;
        x--, y--;
    }
    x=i, y=j;
    while(x>=0 and y<n){
        if(board[x][y]==1) return false;
        x--, y++;
    }
    return true;
}

bool allqueen(int board[][20], int i, int j, int n){
    
    if(i==n){
        c++;
        // for(int k=0; k<n; k++){
        //     for(int l=0; l<n; l++){
        //         cout<< board[k][l]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return true;
        int last_j;
        for(int k=0; k<n; k++){
            if(board[0][k]==1) {
                last_j=k;
                board[n][n]={0};
                allqueen(board, 0, last_j+1, n);
            }
        }
        
    }
    for(int k=j; k<n; k++){
        if(board[i][k]==0){
            if(canPlace(board, i, k, n)){
                board[i][k]=1;
                bool next = allqueen(board, i+1, 0, n);
                if(next) return true;
            }
            board[i][k]=0;
        }
    }
    return false;
}

int nQueen(int n){
//Write your code below. Do not modify this function or parameters. You can use helper function if needed.    
    int b[20][20] = {0};
    int ans = allqueen(b, 0, 0, n);
    return c;
}

int main(){
    int n=8;
    cout<<nQueen(n);
    return 0;
}