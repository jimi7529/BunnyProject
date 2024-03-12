#include "Bunny.hpp"

Bunny::Bunny()
{
    population++;
    setSex();
    setName();
    setSurname();
    setColor();
    if((rand() % 50) == 0)
        rAdIoMuTvAmP = true;
    else
        rAdIoMuTvAmP = false;
}

Bunny::Bunny(const Bunny& mother)
{
    population++;
    setSex();
    setName();
    color = mother.color;
    if((rand() % 50) == 0)
        rAdIoMuTvAmP = true;
    else 
        rAdIoMuTvAmP = false;
    if(rAdIoMuTvAmP)
        isCarrier = true;
}

void Bunny::setName()
{
    if(sex == "Male")
    {
        int num = rand() % (NUM_NAMES / 2);
        name = BUNNY_NAMES[num];
        male++;
    }

    if(sex == "Female")
    {
        int num = rand() % (NUM_NAMES / 2) + 3;
        name = BUNNY_NAMES[num];
        female++;
    }
}

void Bunny::setSurname()
{
    int num = rand() % NUM_SURNAMES;
    surname = BUNNY_SURNAMES[num];
}

void Bunny::setSex()
{
    int num = rand() % NUM_SEX;
    sex = BUNNY_SEX[num];
}

void Bunny::setColor()
{
    int num = rand() % NUM_COLOR;
    color = BUNNY_COLOR[num];
}

void Bunny::setAge(int num)
{
    age = num;
}

void Bunny::setMutation(bool value)
{
    rAdIoMuTvAmP = value;
}

void Bunny::setPosition(Position pos)
{
    position.x = pos.x;
    position.y = pos.y;
}

std::string Bunny::getSex()
{
    return sex;
}

std::string Bunny::getName()
{
    return name;
}

std::string Bunny::getSurname()
{
    return surname;
}

std::string Bunny::getColor()
{
    return color;
}

Position Bunny::getPosition()
{
    return position;
}

int Bunny::getAge()
{
    return age;
}

bool Bunny::getMutation()
{
    return rAdIoMuTvAmP;
}

bool Bunny::getCarrier()
{
    return isCarrier;
}

bool Bunny::grow(const unsigned int& time)
{

    if((rAdIoMuTvAmP != true && (age + time) <= MAX_AGE) || (rAdIoMuTvAmP == true && (age + time) <= MAX_AGE_VAMPIRE))
    {
        age = age + time;
        return true;
    }
    else
    {
        delete this;
        return false;
    }

}

void Bunny::transmitMutation(Bunny* other)
{
    if(rand() % 100 == 0)
        other -> rAdIoMuTvAmP = true;
}
        
Bunny* Bunny::reproduceWith(Bunny* other)
{
        if(this -> sex.compare("Female"))
        {
            this -> child = new Bunny(*this);
            this -> child -> mother = this;
            this -> child -> surname = other -> surname;
            std::cout << child -> name << " " << child -> surname << " is born now" << std::endl << std::endl;
            return child;
        }
        else
        {
            child = new Bunny(*other);
            this -> child -> father = this;
            this -> child -> surname = this -> surname;
            std::cout << child -> name << " " << child -> surname << " is born now" << std::endl << std::endl;
            return child;
        }					
}

bool Bunny::isAdjacent(Bunny* bunny)
{
    for(int i = 0; i < NUM_ADIACENT; i++)
        if(bunny -> getPosition().x == this -> position.x + ADIACENT[i].first && 
            bunny -> getPosition().y == this -> position.x + ADIACENT[i].second)
                return true;
    return false;
}

Bunny::~Bunny()
{
    population--;
    if(sex == "Male")
        male--;
    else
        female--;
    std::cout << name << " is gonna die" << std::endl << std::endl;
}