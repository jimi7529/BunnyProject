#include "Board.hpp"

unsigned int Bunny::population = 0;
unsigned int Bunny::male = 0;
unsigned int Bunny::female = 0;

int main()
{
	srand(time(NULL));
	using namespace std::literals::chrono_literals;
	float timeElapsed = 0.0;
	unsigned int count = 0;
//	unsigned int timer = 1;
	float totalTime = 0;
	float frame = 1;
	unsigned int tempPopulation = 0;
	std::ofstream file;
	std::list<Bunny*> list;
	int n;
	bool cull = 0;
	Position p;
	Board board;

	// file.open("file.txt");

	Bunny* B1 = new Bunny();
	Bunny* B2 = new Bunny();
	Bunny* B3 = new Bunny();
	Bunny* B4 = new Bunny();
	Bunny* B5 = new Bunny();

	B1 -> setMutation(false);
	B2 -> setMutation(false);
	B3 -> setMutation(false);
	B4 -> setMutation(false);
	B5 -> setMutation(false);

	board.placeBunny(B1);
	board.placeBunny(B2);
	board.placeBunny(B3);
	board.placeBunny(B4);
	board.placeBunny(B5);

	list.push_back(B1);
	list.push_back(B2);
	list.push_back(B3);
	list.push_back(B4);
	list.push_back(B5);

	std::list<Bunny*>::iterator iter;

	while(Bunny::population != 0)
	{
		auto start = std::chrono::high_resolution_clock::now();

		if(true)
		{

			iter = list.begin();
			while(iter != list.end()) 
			{
				p = (*iter) -> getPosition();

				// board.update((*iter));
				board.move((*iter));

				if(!((*iter) -> grow(1)))
				{
					board.removeBunny(p);
					list.erase(iter++);
				}
				else
					++iter;
			}				

			for (auto it = list.begin(); it != list.end(); ++it) 
			{
				for (auto ip = list.begin(); ip != list.end(); ++ip) 
				{
					if(((*it) -> getSex() != (*ip) -> getSex()) && ((*ip) -> getAge() >= 2 && (*it) -> getAge() >= 2)
						&& (*it) -> getMutation() == false && (*ip) -> getMutation() == false)
						{
							if((*it) -> getSex() == "Male")
							{
								if(board.isAdjacentFree((*ip)))
									{
										list.push_back((*it) -> reproduceWith(*ip));
										list.back() -> mother = (*ip);
										board.placeBunnyAt(list.back());
									}
							}
							else
								if(board.isAdjacentFree((*it)))
									{
										list.push_back((*it) -> reproduceWith(*ip));
										list.back() -> mother = (*it);
										board.placeBunnyAt(list.back());
									}
						}
					if((*it) -> getCarrier() == true && (*ip) -> getMutation() == false)
						(*it) -> transmitMutation(*ip);
				}
			}

			// file << "This is the " << time++ << " generation:" << std::endl;
			// file << std::endl;
			// file << "The population is" << Bunny::population << std::endl;
			// file << std::endl;

			// for (auto it = list.begin(); it != list.end(); ++it) 
			// {
			// 	file << (*it) -> getName() << " ";
			// 	file << (*it) -> getSurname() << std::endl;
			// 	file << (*it) -> getAge() << std::endl;
			// 	file << (*it) -> getColor() << std::endl;
			// 	file << (*it) -> getMutation() << std::endl;
			// 	file << std::endl;
			// }

			file.open("file.txt", std::ofstream::out | std::ofstream::trunc);

			file << std::endl;

			file << "This is the table now:" << std::endl;

			file << board << std::endl;

			if(Bunny::population > 1000)
			{
				tempPopulation = Bunny::population / 10;
				
				while(Bunny::population > tempPopulation)
				{
					iter = list.begin();
					advance(iter, rand() % Bunny::population);
					p = (*iter) -> getPosition();
					board.removeBunny(p);
					delete (*iter);
					list.erase(iter);
				}		
			}

			file << std::endl;

			file.close();

			// std::cout << "Do you want to make a cull ('1' for yes, '0' for no)" << std::endl << std::endl;

			// do{std::cin >> cull;}while(cull != true && cull!= false);
			// std::cout << std::endl;
			
		}

		timeElapsed = 0;

		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> duration = end - start;

		timeElapsed += duration.count();

		totalTime = totalTime + timeElapsed;
	}

	std::cout << totalTime << std::endl;

	return 0;
}