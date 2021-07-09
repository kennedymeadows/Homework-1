/*Simon Lewis
* CSIS 137
* Homework # 1
--------------------------------------------
			   TicTacToe
--------------------------------------------
-board[ROW][COL]:integer
-winner:integer // intialized at 0
-turns:integer
--------------------------------------------
+TicTacToe()
+getPlayerMove():void // use % to see if turns is even or odd to prompt which player, ask for column and row
+setPlayerMove(p:integer, c:integer, r:integer):void // change a square on the board - should run checkWin here too - if true runs setWinner - turns++ - 
+printBoard():void
+printResults():void // if getWinner() > 0 says who won and ends game, else if checkDraw() = true ends game, else getPlayerMove()
+printMenu():void
+getWinner():integer  // returns winner
+getTurns():integer
-checkWin(integer, integer, integer):boolean // checks array to see if there is a winner
-setWinner(integer):void // 


--------------------------------------------
*/

#ifndef TICTACTOE_H
#define TICTACTOE_H

int const ROW = 3;
int const COL = 3;

class TicTacToe
{
public:
   TicTacToe();
   void getPlayerMove();
   void setPlayerMove(int, int, int);
   void printBoard();
   void printResults();
   void printMenu();
   int getWinner();
   int getTurns();
private:
   int board[ROW][COL];
   int winner;
   int turns;
   bool checkWin(int, int, int);
   void setWinner(int);
};

#endif