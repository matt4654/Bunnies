#include "../include/bunny.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

int bunny::numberOfPossibleNames = 0;

//Constructors
bunny::bunny() : id(returnRandomID()), name(returnRandomName()), age(0), sex(returnRandomSex()), colour(returnRandomColour()), isInfected(returnRandomIsInfected()) {}

bunny::bunny(const std::shared_ptr<bunny> &mother) : id(returnRandomID()), name(returnRandomName()), age(0), sex(returnRandomSex()), colour(mother->getColour()), isInfected(returnRandomIsInfected()) {}


//Get/Set
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

void bunny::setNumberOfPossibleNames()
{
    int numberOfLines = 0;
    std::string line;
    std::ifstream myfile("exampleNames.txt");
    while(std::getline(myfile, line)) {++numberOfLines;}

    numberOfPossibleNames = numberOfLines;
}


//Return Random Attributes
int bunny::returnRandomID()
{
    int randomNum = rand() % 1000;
    return randomNum;
}

std::string bunny::returnRandomName()
{
    int randomNum = rand() % numberOfPossibleNames;
    int counter = 0;
    std::string name;
    std::ifstream input("exampleNames.txt");
    while(getline(input, name))
    {
        if(randomNum == counter)
        {
            return name;
        }
        counter++;
    }
    return name;
}

Sex bunny::returnRandomSex()
{
    int randNum = rand() % 100;
    return randNum % 2 == 0 ? Sex::Male : Sex::Female;
}

Colour bunny::returnRandomColour()
{
    int randNum = rand() % 100;
    if(randNum < 25) {return Colour::White;}
    else if(randNum < 50) {return Colour::Brown;}
    else if(randNum < 75) {return Colour::Black;}
    else {return Colour::Spotted;}
}

bool bunny::returnRandomIsInfected()
{
    int randNum = rand() % 100;
    return randNum < 2 ? true : false;
}


//Other Methods
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