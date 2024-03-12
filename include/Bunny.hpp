#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <list>
#include <fstream>
#include "Constants.hpp"
#include <time.h>

#ifndef BUNNY_HPP
#define BUNNY_HPP

struct Position
{
	unsigned int x;
	unsigned int y;

	Position operator+ (Position pos1)
	{
		Position pos;
		pos.x = this -> x + pos1.x;
		pos.y = this -> y + pos1.y;
		return pos;
	}

	bool isInBound()
	{
		if((x < BOARD_DIM) && (y < BOARD_DIM))
			return true;
		else
			return false;
	}
};

class Bunny
{
	private:
		std::string name;
		std::string surname;
		std::string sex;
		std::string color;
		static unsigned int male, female;
		unsigned int age = 0;
		int numChild = 0;
		bool rAdIoMuTvAmP;
		bool isCarrier = false;
		Bunny* father = NULL;
		Bunny* child = NULL;
		Position position;
		// std::vector<Bunny*> children;
	public:
		static unsigned int population;

		Bunny* mother = NULL;

        Bunny();
        
        Bunny(const Bunny& mother);

		void setName();

		void setSurname();

		void setSex();

		void setColor();

		void setAge(int num);

		void setMutation(bool value);

		void setPosition(Position pos);

		std::string getSex();

		std::string getName();

		std::string getSurname();

		std::string getColor();

		int getAge();

		bool getMutation();

		bool getCarrier();

		Position getPosition();

		bool grow(const unsigned int& time);

		void transmitMutation(Bunny* other);
				
		Bunny* reproduceWith(Bunny* other);

		bool isAdjacent(Bunny* bunny);

		~Bunny();
};

#endif