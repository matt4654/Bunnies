#include "../include/randomAttributes.h"

#include <fstream>
#include <stdlib.h>

int randAt::returnRandomID()
{
    int randomNum = rand() % 1001;
    return randomNum;
}

std::string randAt::returnRandomName()
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

Sex randAt::returnRandomSex()
{
    int randNum = rand() % 100;
    return randNum % 2 == 0 ? Sex::Male : Sex::Female;
}

Colour randAt::returnRandomColour()
{
    int randNum = rand() % 100;
    if(randNum < 25) {return Colour::White;}
    else if(randNum < 50) {return Colour::Brown;}
    else if(randNum < 75) {return Colour::Black;}
    else {return Colour::Spotted;}
}

bool randAt::returnRandomIsInfected()
{
    int randNum = rand() % 100;
    return randNum < 2 ? true : false;
}

void randAt::setNumberOfPossibleNames() 
{
    int numberOfLines = 0;
    std::string line;
    std::ifstream myfile("exampleNames.txt");
    while(std::getline(myfile, line)) {++numberOfLines;}

    numberOfPossibleNames = numberOfLines;
}