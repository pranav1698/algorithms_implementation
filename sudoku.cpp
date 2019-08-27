// Important
#include<bits/stdc++.h>
using namespace std;

void printSudoku(int** board){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout << board[i][j] << "";
		}
		cout << endl;
	}
}

bool findEmpty(int** board, int* row, int*column){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(board[i][j] == 0){
				*row=i;
				*column=j;
				return true;
			}
		}
	}
	return false;
}

bool isPossible(int** board, int x, int y, int number){
	for(int j=0; j<9; j++){
		if(board[x][j] == number)
			return false;
	}
	for(int i=0; i<9; i++){
		if(board[i][y]==number){
			return false;
		}
	}
	int row_f=x-(x%3);
	int column_f=y-(y%3);
	for(int i=0; i<3;i++){
		for(int j=0; j<3; j++){
			if(board[i+row_f][j+column_f] == number)
				return false;
		}
	}
	return true;
}

bool sudoku(int** board){
	int row;
	int column;
	if(!findEmpty(board, &row, &column))
		return true;

	//cout << row << " " << column << endl;
	for(int number=1; number<=9; number++){
		if(isPossible(board, row, column, number)){	
			board[row][column]=number;
			if(sudoku(board))
				return true;
			board[row][column]=0;
		}
	}

	return false;
}

int main(){
	int** board= new int*[9];
	for(int i=0; i<9; i++){
		board[i]=new int[9];
	}
	for(int i=0; i<9; i++){
		string s;
		cin >> s;
		//cout << s << endl;
		for(int j=0;j<9; j++){
			board[i][j]=s[j]-'0';
		}
	}

	bool solved=sudoku(board);
	if(solved){
		printSudoku(board);
	}
}