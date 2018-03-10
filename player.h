class Game;


class Player {
public:
	
	virtual int getNextTurn(Game & curplayer) const=0;

};


class AiPlayer : public Player
{
public:
	AiPlayer();
	int getNextTurn(Game & curplayer) const;
};

class HumanPlayer:public Player
{
public:
	HumanPlayer();
	int getNextTurn(Game & curplayer) const;
};
