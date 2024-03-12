#include "Board.hpp"

Board::Board()
{
	for (int i = 0; i < BOARD_DIM; i++)
		for (int j = 0; j < BOARD_DIM; j++)
			gameBoard[i][j] = isUnknown;
}

Board::Board(const Board &oldBoard)
{
	for (int i = 0; i < BOARD_DIM; i++)
		for (int j = 0; j < BOARD_DIM; j++)
			gameBoard[i][j] = oldBoard.gameBoard[i][j];
}

Board& Board::operator=(const Board &right)
{
	if (this != &right)
	{
		for (int i = 0; i < BOARD_DIM; i++)
			for (int j = 0; j < BOARD_DIM; j++)
				gameBoard[i][j] = right.gameBoard[i][j];
	}

	return *this;
}

void Board::printPublicBoard()
{
	for (int i=0; i<BOARD_DIM; i++)
	{
		std::cout<<i<<" ";
		for (int j=0; j<BOARD_DIM; j++)
		{
			std::cout<<gameBoard[i][j]<<" ";
		}	
		std::cout<<std::endl;
	}

}

//return the value of a space
char Board::getSpaceValue(int x, int y) const
{
	return gameBoard[y][x];
}

bool Board::isFree(int x, int y)
{
	if(x > (BOARD_DIM - 1) && y > (BOARD_DIM - 1) && x < 0 && y < 0)
		return false;
		
	if (gameBoard[x][y] == isUnknown)
		return true;
	else
		return false;
}

bool Board::isAdjacentFree(Bunny* bunny)
{
    for(int i = 0; i < NUM_ADIACENT; i++)
        if(!isFree(bunny -> getPosition().x + ADIACENT[i].first, bunny -> getPosition().x + ADIACENT[i].second))
                return false;

    return true;
}

Position Board::getFreePosition()
{
    Position position;

    int x = rand() % (BOARD_DIM - 1);
    int y = rand() % (BOARD_DIM - 1);

    while(!isFree(x, y))
    {
        x = rand() % (BOARD_DIM - 1);
        y = rand() % (BOARD_DIM - 1);
    }
    
    position.x = x;
    position.y = y;

	return position;
}

void Board::placeBunny(Bunny* bunny)
{
	bunny -> setPosition(getFreePosition());

    if(bunny -> getSex() == "Male" && bunny -> getAge() < 2)
        gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = juvenileMale;
    else if(bunny -> getSex() == "Male" && bunny -> getAge() >= 2)
        gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = adultMale;
    else if(bunny -> getSex() == "Female" && bunny -> getAge() < 2)
        gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = juvenileFemale;
    else if(bunny -> getSex() == "Female" && bunny -> getAge() >= 2)
        gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = adultFemale;
}

void Board::placeBunnyAt(Bunny* bunny)
{
	std::pair<int, int> pair;
	Position pos;

	do
	{
		pair = ADIACENT[rand() % 8];
		pos.x = pair.first;
		pos.y = pair.second;
		pos = bunny -> mother -> getPosition() + pos;
	}while(!pos.isInBound());

	bunny -> setPosition(pos);

    if(bunny -> getSex() == "Male" && bunny -> getAge() < 2)
        gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = juvenileMale;
    else if(bunny -> getSex() == "Male" && bunny -> getAge() >= 2)
        gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = adultMale;
    else if(bunny -> getSex() == "Female" && bunny -> getAge() < 2)
        gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = juvenileFemale;
    else if(bunny -> getSex() == "Female" && bunny -> getAge() >= 2)
        gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = adultFemale;
}

void Board::removeBunny(Position& p)
{
    gameBoard[p.x][p.y] = isUnknown;
}

void Board::update(Bunny* bunny)
{
	if(bunny -> getAge() > 2 && bunny -> getSex() == "Male" && bunny -> getMutation() == false)
		gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = adultMale;
	else if(bunny -> getAge() > 2 && bunny -> getSex() == "Female" && bunny -> getMutation() == false)
		gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = adultFemale;
	else if(bunny -> getMutation() == true)
		gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = isRadioactive;
}

void Board::move(Bunny* bunny)
{
	Position pos;

	int x = rand() % 2;
	int y = rand() % 2;

	pos.x = STEPS[x];
	pos.y = STEPS[y];

	pos = bunny -> getPosition() + pos;

	gameBoard[bunny -> getPosition().x][bunny -> getPosition().y] = isUnknown;

	if(pos.isInBound())
		if(isFree(pos.x, pos.y))
			bunny -> setPosition(pos);

	update(bunny);
}

std::ofstream& operator<<(std::ofstream& os, const Board& board)
{
	for (int i=0; i<BOARD_DIM; i++)
	{
		for (int j=0; j<BOARD_DIM; j++)
		{
			os << board.getSpaceValue(i,j) << " ";
		}	
		os << std::endl;
	}
    return os;
}