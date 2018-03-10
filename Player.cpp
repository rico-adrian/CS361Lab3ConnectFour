#include "player.h"
#include "game.h"
#include <cstdlib>
#include <iostream>


HumanPlayer::HumanPlayer() {

}

AiPlayer::AiPlayer() {

}

int Player::getNextTurn(Game& curplayer) const
{
	return rand() % 7 + 1;
}



int HumanPlayer::getNextTurn(Game & curplayer) const
{
	int col=-1;
	std::cin.clear();
	std::cin.ignore();
	std::cin >> col; //input the column number for human player

	return col;
}



int AiPlayer::getNextTurn(Game & curplayer) const
{

	bool temp=false;
	while (temp == false) { //going down until you reach X or O
		int column = rand() % 7 ; //column number is random for AI player
		if (curplayer(column, 0) == 0) {
			temp = true;
			std::cout << column;
			return column; //return the random number of column
		}
		column++; //moves it if we reach unusuable row
	}
}
