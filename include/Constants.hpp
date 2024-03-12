#include <vector>
#include <iostream>
#include <string>

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

// constants
const int NUM_STEPS = 4;
const int NUM_BUNNY = 5;
const int NUM_SEX = 2;
const int NUM_ADIACENT = 8;
const int MAX_AGE = 10;
const int MAX_AGE_VAMPIRE = 50;
const int NUM_NAMES = 10;
const int NUM_SURNAMES = 10;
const int NUM_COLOR = 4;
const int BOARD_DIM = 80;

const int FAMILY_LENGTHS[NUM_BUNNY] = {5, 4, 3, 3, 2};
const int STEPS[NUM_STEPS] = {-1, 1};
const std::pair<int, int> ADIACENT[NUM_ADIACENT] = {{-1, 1}, {1, -1}, {-1, -1}, {1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const std::string BUNNY_COLOR[NUM_COLOR] = 
			{"Red", "Brown", "Yellow", "Orange"};
const std::string BUNNY_NAMES[NUM_NAMES] = 
			{"Fred", "Carl", "Richard", "Jessica", "Riley", "Belen", "Nelson", "Charlie", "Tina", "Gelsomina"};
const std::string BUNNY_SURNAMES[NUM_NAMES] = 
			{"Ronaldo", "Pearson", "Einstein", "Lewis", "Kamikaze", "Balotelli", "Jesus", "Wellington", "Kerry", "Palladius"};
const std::string BUNNY_SEX[NUM_SEX] = 
			{"Male", "Female"};

const char juvenileMale = 'm';
const char adultMale = 'M';
const char juvenileFemale = 'f';
const char adultFemale = 'F';
const char isRadioactive = 'X';
const char isUnknown = ' ';

#endif
