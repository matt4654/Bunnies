#ifndef BUNNY_H
#define BUNNY_H

#include <string>
#include <memory>

enum class Sex {Male, Female};
enum class Colour {White, Brown, Black, Spotted};

class bunny
{
    private:
        const int id;
        const std::string name;
        int age;
        const Sex sex;
        const Colour colour;
        bool isInfected;
        static int numberOfPossibleNames;

    public:
        //Constructors
        bunny();
        explicit bunny(const std::shared_ptr<bunny>&);

        //Get/Set
        int getID() const;
        std::string getName() const;
        int getAge() const;
        Sex getSex() const;
        std::string getSexString(const Sex&) const;
        Colour getColour() const;
        std::string getColourString(const Colour&) const;
        bool getIsInfected() const;
        static void setNumberOfPossibleNames();

        //Return Random Attributes
        int returnRandomID();
        std::string returnRandomName();
        Sex returnRandomSex();
        Colour returnRandomColour();
        bool returnRandomIsInfected();

        //Other Methods
        void ageBunny();
        void viewBunnyInfo() const;
        void infect();
};

#endif