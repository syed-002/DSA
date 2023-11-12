#include<bits/stdc++.h>
using namespace std;

    bool isPlace(vector<vector<char>> &board, int i, int j, char no, int n){
        //row or col
        for(int k=0; k<n; k++ ){
            if(board[k][j]==no || board[i][k]==no) return false;
        }
        //subgrid
        int sub_x, sub_y;
        sub_x= (i/3)*3;
        sub_y= (j/3)*3;
        
        for(int x=sub_x; x<sub_x+3; x++){
            for(int y=sub_y; y<sub_y+3; y++){
                if(board[x][y]==no) return false;
            }
        }
        return true;
    }
    
    bool sudoku(vector<vector<char>> &board, int i, int j, int n){
        if(i==n){
            return true;
        }
        //corner cases
        if(j==n){
            return sudoku(board, i+1, 0, n);
        }
        if(board[i][j]!='.'){
            return sudoku(board, i, j+1, n);
        }
        //recursive
        for(char no='1'; no<='9'; no++){
            if(isPlace(board, i, j, no, n)){
                board[i][j] = no;
                bool next = sudoku(board, i, j+1, n);
                if(next) return true;
            }
        }
        board[i][j]='.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n=9;
        sudoku(board, 0, 0, n);
    }



    //there were dots instead of zero
int main(){

	int n=9;
	vector<vector<char>> mat=
	{

{'5','3','0','0','7','0','0','0','0'},
{'6','0','0','1','9','5','0','0','0'},
{'0','9','8','0','0','0','0','6','0'},
{'8','0','0','0','6','0','0','0','3'},
{'4','0','0','8','0','3','0','0','1'},
{'7','0','0','0','2','0','0','0','6'},
{'0','6','0','0','0','0','2','8','0'},
{'0','0','0','4','1','9','0','0','5'},
{'0','0','0','0','8','0','0','7','9'}

	};

	// if(!sudoku(mat, 0, 0, n)){
	// 	cout<<'NO SOL EXISTS!!\n';
	// }

	solveSudoku(mat);


}