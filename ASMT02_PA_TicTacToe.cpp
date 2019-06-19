#include <iostream>
using namespace std;
int arr[9];
int arrindex=0;
bool isWon(char player, char board[][3]){
	int i=0;
	while(i<=2){
		if((board[i][0]==player && board[i][1] ==player && board[i][2]==player) || (board[0][i]==player && board[1][i]==player && board[2][i]==player)){
			return true;
		}	
		i++;
	}
	return(board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
			(board[0][2]==player && board[1][1]==player && board[2][0]==player);
}
bool isDraw(char board[][3]){
 int i=0;
 while(i <= 2){
	 int j=0;
	 while(j <=2){
		 if (board[i][j]==' '){
			 return false;
		 }
		 j++;
	 }
	 i++;
 }
 return false;
}
void displayBoard(char board[][3]){
	int i=0;
	while(i<=2){
		cout<<"--------"<<endl;
		cout<<"|"<<board[i][0]<<"|"<<board[i][1]<<"|"<<board[i][2]<< "|"<<endl;
		i++;
	}
	cout<<"--------"<<endl;
}
void makeAMove(char board[][3], char player){
	int row;
	int col;
	int sum;
	bool ismovevalid=true;

	cout<< "Enter you move for the row (0,1,2):"<<player<<" :";
	cin >> row;
	cout<<"Enter your move for the column (0,1,2)"<<player<<" :";
	cin>>col;
	sum=(row+1)*10 + (col+1);

	int i=0;
	while(i<=arrindex){
		if(arr[i]==sum){
			ismovevalid=false;
		}
		i++;
	}
	if(ismovevalid){
		board[row][col]=player;
		arr[arrindex]=sum;
		arrindex++;
	}else{
		cout<<"Move already made, chose an empty hole hoe"<<endl;
		makeAMove(board,player);
	}


}

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}