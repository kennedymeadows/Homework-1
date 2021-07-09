/*Simon Lewis
* CSIS 137
* Homework # 1
*/

#include <iostream>
#include <iomanip>
#include "TicTacToe.h"

using namespace std;

// Default constructor which initializes the array with 0's
TicTacToe::TicTacToe() {
   winner = 0;
   turns = 0;
   for (int r = 0; r < ROW; r++) {
	 for (int c = 0; c < COL; c++) {
	    board[r][c] = 0;
	 }
   }
}


void TicTacToe::getPlayerMove() {
   int row, column;
   int player = (turns % 2) + 1;
   cout << "Player " << player << " choose which column and row you would like.\n";
   bool spaceTaken;
   do {              //I added this do-while input validation to check if a space is already taken
	 spaceTaken = false; 
	 do {           //Another do-while loop for input validation of the row
	    cout << "Row: ";
	    cin >> row;
	    if (row < 1 || row > 3) {
		  cout << "Invalid entry. Try again." << endl;
	    }
	 } while (row < 1 || row > 3);
	 do {	     //Another do-while loop for input validation of the column
	    cout << "Column: ";
	    cin >> column;
	    if (column < 1 || column > 3) {
		  cout << "Invalid entry. Try again." << endl;
	    }
	 } while (column < 1 || column > 3);
	 if (board[row-1][column-1] > 0) {
	    cout << "That space is already taken! Choose again." << endl;
	    spaceTaken = true;
	 }
   } while (spaceTaken);
   setPlayerMove(player, row, column);
   printBoard();  //Display board again before determining if there is a winner
   if (checkWin(player, row, column)) {
	 setWinner(player);
   }
   turns++;
   printResults();
}

void TicTacToe::setPlayerMove(int p, int r, int c) {
   board[r-1][c-1] = p;
}

void TicTacToe::printBoard() {
   cout << fixed << setw(5) << " ";  //Unelegant way of making column headers
   for (int i = 0; i < COL; i++) {
	 cout << setw(5) << i+1;
   }
   cout << endl;                     //Which ends here
   for (int r = 0; r < ROW; r++) {
	 cout << setw(5) << r+1;
	 for (int c = 0; c < COL; c++) {
	    cout << setw(5) << board[r][c];
	 }
	 cout << endl << endl;
   }
}

void TicTacToe::printResults() {
   if (getWinner() > 0) {
	 cout << "Player " << getWinner() << " is the winner!" << endl;
   }
   else if (getTurns() == 9) {
	 cout << "The game is a draw. Try harder next time!" << endl;
   }
}

void TicTacToe::printMenu() {
   cout << "Welcome to Tic Tac Toe." << endl
	   << "Players will switch off taking turns until there is a winner or a draw. Good luck." << endl;
}

bool TicTacToe::checkWin(int p, int r, int c) {
   int row = r-1;
   int column = c-1;
   if (board[row][0] == p && board[row][1] == p && board[row][2] == p)
	 return true;
   else if (board[0][column] == p && board[1][column] == p && board[2][column] == p)
	 return true;
   else if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
	 return true;
   else if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
	 return true;
   else
	 return false;
}

void TicTacToe::setWinner(int p) {
   winner = p;
}

int TicTacToe::getWinner() {
   return winner;
}

int TicTacToe::getTurns() {
   return turns;
}