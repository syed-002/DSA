#include<bits/stdc++.h>
using namespace std;

void printBoard(int n, int board[][20]){

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<< board[i][j]<< " ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

bool canPlace(int board[][20], int x, int y, int n){
	//x, y is the place at which queen is placed
	
	//column checking
	for(int i=0; i<x; i++){
		if(board[i][y]==1) return false;
	}

	//left diag
	int i = x;
	int j = y;
	while(i>=0 and j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--; j--;
	}

	//right diag
	i = x;
	j = y;
	while(i>=0 and j<n){
		if(board[i][j]==1){
			return false;
		}
		i--; j++;
	}
	return true;
}

bool n_queen(int n, int board[][20], int i, int j){

	//i is the row which are currently in

	//base case
	if(i==n){
		//print board
		printBoard(n, board);
		int last_j;
		for(int k=0; k<n; k++){
			if(board[0][k] == 1){
				last_j= k;
				board[n][n]={0};
				n_queen(n, board, 0, last_j+1);
			}
		}
	}

	//recursive case
	//try to place a queen in every row
	for(int k=j; k<n; k++){
		if(board[i][k]==0){
			if(canPlace(board, i, k, n)){
				board[i][k]=1;
				bool success = n_queen(n, board, i+1, 0); //starts from the start of the row
				if(success){
					return true;
				}
				//if you cant place queen there then
				//return back to the old position (backtrack)
				//and continue checking if we can place q there
				board[i][k]=0;
				//in the next iteration j will start from the pos which it ended
			}
			
		}
	}

	//you will come out of the for loop iff there are no more columns left in the row to place to queen
	//in that case you backtrack and give false
	return false;
	//after getting false, code starts from line board[i][j]=0 and continue from j+1
}


int main(){
	int n=4;
	int board[20][20] = {0}; // its more complex for 13, 14 so choose small board
	n_queen(n, board, 0, 0);
}