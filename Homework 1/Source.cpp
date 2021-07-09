/*Simon Lewis
* CSIS 137
* Homework # 1
*/

#include "TicTacToe.h"
#include <iostream>

using namespace std;

int main() 
{
   int choice;
   do {
	 TicTacToe game;
	 game.printMenu();
	 game.printBoard();
	 do {
		 game.getPlayerMove();
	 } while (game.getWinner() == 0 && game.getTurns() < 9);
	 cout << "Type 0 to quit, otherwise type any key to play again: ";
	 cin >> choice;
   } while (choice != 0);
   return 0;
}