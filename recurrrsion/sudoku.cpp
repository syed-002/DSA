#include<bits/stdc++.h>
using namespace std;


bool isSafe(int mat[][9], int i, int j, int no, int n){
	//whether present in row and col
	for(int k=0; k<n; k++){
		if(mat[i][k]==no || mat[k][j]==no) return false;
	}

	//present in subgrid

	int sub_x, sub_y;

	sub_x=(i/3)*3;
	sub_y=(j/3)*3;

	for(int k = sub_x; k < sub_x+3; k++){
		for(int l = sub_y; l < sub_y+3; l++){
			if(mat[k][l]==no){
				return false;
			}
		}
	}
	return true;
}

bool sudoku(int mat[][9], int i, int j, int n){

	//base
	if(i==n){
		//print sol
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<< mat[i][j] << " ";
			}
			cout<<"\n";
		}

		return true;
	}
	//recursive case

	//corner case
	if(j==n){//cross the boundary ie 9 from 0 to 8
		return (sudoku(mat, i+1, 0, n)); //if you forget return it will be an infinite loop
	}
	//skip the prefilled cell
	if(mat[i][j]!=0){
		return (sudoku(mat, i, j+1, n));
	}

	//now the cell to be filled
	//trying all possibilites
	for(int no=1; no<=9; no++){
		if( isSafe(mat, i, j, no, n)){
			mat[i][j] = no;
			bool subProblem= sudoku(mat, i, j+1, n);
			if(subProblem){
				return true;
			}
		}
	}
	//if no number works, then return false
	mat[i][j] = 0; //backtracking
	return false;
}

int main(){

	int n=9;
	int mat[9][9]=
	{
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9},

	};

	if(!sudoku(mat, 0, 0, n)){
		cout<<"NO SOL EXISTS!!\n";
	}


}