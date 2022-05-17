#include "../include/bunny.h"
#include "../include/randomAttributes.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

bunny::bunny()
    : id(randAt::returnRandomID()), name(randAt::returnRandomName()), age(0), sex(randAt::returnRandomSex()), colour(randAt::returnRandomColour()), isInfected(randAt::returnRandomIsInfected()) {}

bunny::bunny(const std::shared_ptr<bunny> &mother) 
    : id(randAt::returnRandomID()), name(randAt::returnRandomName()), age(0), sex(randAt::returnRandomSex()), colour(mother->getColour()), isInfected(randAt::returnRandomIsInfected()) {}


int bunny::getID() const
{
    return id;
}

std::string bunny::getName() const
{
    return name;
}

int bunny::getAge() const
{
    return age;
}

Sex bunny::getSex() const
{
    return sex;
}

std::string bunny::getSexString(const Sex &s) const
{
    static const std::map<Sex, std::string> sexMap = {{Sex::Male, "Male"}, {Sex::Female, "Female"}};
    return sexMap.at(s);
}

Colour bunny::getColour() const
{
    return colour;
}

std::string bunny::getColourString(const Colour &c) const
{
    static const std::map<Colour, std::string> colourMap = {{Colour::White, "White"}, {Colour::Brown, "Brown"}, {Colour::Black, "Black"}, {Colour::Spotted, "Spotted"}};
    return colourMap.at(c);
}

bool bunny::getIsInfected() const
{
    return isInfected;
}


void bunny::viewBunnyInfo() const
{
    std::cout << std::setw(10) << name << std::setw(10) << age << std::setw(10) << getSexString(sex) << std::setw(10) << getColourString(colour);
    isInfected ? (std::cout << std::setw(10) << "Yes" << std::endl) : (std::cout << std::setw(10) << "No" << std::endl);
}

void bunny::ageBunny()
{
    age++;
}

void bunny::infect()
{
    isInfected = true;
}