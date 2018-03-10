#pragma once
class Player;

enum GameState {TurnP1,TurnP2,P1Won,P2Won,Draw};
enum BoardField  {Player1=1,Player2=2,Empty=0};
class Game {
public:// Creates an empty matrix of size 0 times 0.

	static const int BoardWidth = 7;
	static const int BoardHeight = 6;
	Game(Player & p1,Player& p2);// Move constructor
	int getState();
	bool isRunning();
	int Game ::operator() (int x, int y) const;
	void nextTurn();

private:
	Player* player1;
	Player* player2;
	int** board;
	bool checkifwin(int BoardHeight,int BoardWidth);
	bool Game::checkifdraw();

};