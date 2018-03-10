#include <iostream>
#include <algorithm>
#include <assert.h>
#include "game.h"
#include "player.h"

int state=0;

Game::Game(Player &p1,Player &p2) {

	//set up the board according to the boardwith and boardheight
	board = new int*[BoardWidth];
	for (int i = 0;i < BoardWidth;i++) {
		board[i] = new int[BoardHeight]();
	}
	player1 = &p1;
	player2 = &p2;

}

int Game::getState()
{
	//return the current state of the game
	return state;
}


bool Game::isRunning()
{
	//if state is turn p1 or turn p2
	return (state==TurnP1 ||state==TurnP2);
}

int Game::operator() (int x, int y) const {
	//return piece at current index
	return board[x][y];
}

void Game::nextTurn() {
	int col = 0;
	int i=0;
	bool temp = false;

	//check the current state(player 1 and player 2)
	if (state == 0) {
		col = player1->getNextTurn(*this);
		if (col >= 1 && col <= 7) { //if the number of column is valid
			while (temp == false) { //going down until you reach X or O
				if (board[col-1][i] == 0) {
					i++;
				}
				else {
					temp = true;
				}
			}
			board[col-1][i-1] = Player1; //assign the X or O to the board
		}
		state++;
		state = (state % 2);
	}
	else  {
		col = player2->getNextTurn(*this);
		if (col >= 1 && col <= 7) { //if the number of column is valid
			while (temp == false) { //going down until you reach X or O
				if (board[col-1][i] == 0) {
					i++;
				}
				else {
					temp = true;
				}
			}
			board[col-1][i - 1] = Player2; //assign the X or O to the board
		}
		state++;
		state = (state % 2);
	}

	checkifwin(BoardHeight, BoardWidth);
	checkifdraw();

	//check if win or draw for player 1 and 2 after calling checkifwin and checkifdraw
	if (checkifwin(BoardHeight, BoardWidth) == true&& state==P1Won) {
		state=P1Won;
	}
	else if(checkifwin(BoardHeight, BoardWidth) == true&& state==P2Won) {
		state=P2Won;
	}

	if(checkifdraw()==true) {
		state=Draw;
	}

}

bool Game::checkifwin(int column, int row) {

	//check if win horizontally
	for (int j = 0; j<column-3 ; j++ ){
		for (int i = 0; i<row; i++){
			//if P1 won
			if (board[i][j] == 1 && board[i][j+1] == 1 && board[i][j+2] == 1 && board[i][j+3] == 1){
				state=P1Won;
				return true;
			}       
			//if P2 won
			else if (board[i][j] == 2 && board[i][j+1] == 2 && board[i][j+2] == 2 && board[i][j+3] == 2){
				state=P2Won;
				return true;
			}    
		}
	}

	//check if win vertically
	for (int i = 0; i<row-3 ; i++ ){
		for (int j = 0; j<column; j++){
			//if P1 won
			if (board[i][j] == 1 && board[i+1][j] == 1 && board[i+2][j] == 1 && board[i+3][j] == 1){
				state=P1Won;
				return true;
			}
			//if P2 won
			else if(board[i][j] == 2 && board[i+1][j] == 2 && board[i+2][j] == 2 && board[i+3][j] == 2) {
				state=P2Won;
				return true;
			}
		}
	}

	//check if win diagonally
	for (int i=3; i<row; i++){
		for (int j=0; j<column-3; j++){
			//if P1 won
			if (board[i][j] == 1 && board[i-1][j+1] == 1 && board[i-2][j+2] == 1 && board[i-3][j+3] ==1) {
				state=P1Won;
				return true;
			}
			//if P2 won
			else if (board[i][j] == 2 && board[i-1][j+1] == 2 && board[i-2][j+2] == 2 && board[i-3][j+3] ==2) {
				state=P2Won;
				return true;
			}
		}
	}

	for (int i=3; i<row; i++){
		for (int j=3; j<column; j++){
			if (board[i][j] == 1 && board[i-1][j-1] == 1 && board[i-2][j-2] == 1 && board[i-3][j-3] == 1) {
				//if P1 won
				state=P1Won;
				return true;
			}
			//if P2 won
			else if (board[i][j] == 2 && board[i-1][j-1] == 2 && board[i-2][j-2] == 2 && board[i-3][j-3] == 2) {
				state=P2Won;
				return true;
			}
		}
	}

	return false;
}

bool Game::checkifdraw() {

	//check if the game is draw
	for(int i=0;i<BoardWidth;i++) {
		if (board[i][0]==Empty) {
			return false;
		}

	}
	return true;
}

