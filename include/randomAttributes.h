#ifndef RANDOMATTRIBUTES_H
#define RANDOMATTRIBUTES_H

#include <string>

enum class Sex {Male, Female};
enum class Colour {White, Brown, Black, Spotted};

namespace randAt
{
    static int numberOfPossibleNames;
    int returnRandomID();
    std::string returnRandomName();
    Sex returnRandomSex();
    Colour returnRandomColour();
    bool returnRandomIsInfected();
    void setNumberOfPossibleNames();
}

#endif