#include "Bunny.hpp"

#ifndef BOARD_H
#define BOARD_H

class Board
{
	private:
		char gameBoard[BOARD_DIM][BOARD_DIM];
        Position position;
	public:
		Board();
		Board(const Board &oldBoard);
		Board& operator=(const Board &right);
		~Board() {return;}; // standard destructor - no dynamically memory;
		void printPublicBoard();
		char getSpaceValue(int x, int y) const;
        bool isFree(int x, int y);
		bool isAdjacentFree(Bunny* bunny);
        Position getFreePosition();
		void placeBunny(Bunny* bunny);
		void placeBunnyAt(Bunny* bunny);
		void removeBunny(Position& p);
		void update(Bunny* bunny);
		void move(Bunny* bunny);
		friend std::ofstream& operator<<(std::ofstream& os, const Board& board);
};

#endif