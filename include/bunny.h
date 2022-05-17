#ifndef BUNNY_H
#define BUNNY_H

#include "randomAttributes.h"

#include <string>
#include <memory>

class bunny
{
    private:
        const int id;
        const std::string name;
        int age;
        const Sex sex;
        const Colour colour;
        bool isInfected;

    public:
        bunny();
        explicit bunny(const std::shared_ptr<bunny>&);

        int getID() const;
        std::string getName() const;
        int getAge() const;
        Sex getSex() const;
        std::string getSexString(const Sex&) const;
        Colour getColour() const;
        std::string getColourString(const Colour&) const;
        bool getIsInfected() const;

        void ageBunny();
        void viewBunnyInfo() const;
        void infect();
};

#endif