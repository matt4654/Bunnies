#ifndef FIELD_H
#define FILED_H

#include "bunny.h"

#include <list>
#include <vector>
#include <memory>

class field
{
    private:
        std::list<std::shared_ptr<bunny>> bunnies;
        std::vector<std::shared_ptr<bunny>> newDeaths;
        std::vector<std::shared_ptr<bunny>> newBirths;
        static int infected;
        std::vector<std::shared_ptr<bunny>> newInfected;

    public:
        //Constructor
        field();

        //Other Methods
        void addBunnies(int);
        void turn();
        int bunnyCount() const;
        int infectedCount();
        void ageBunnies();
        void bunnyLifeCycle();
        void viewAllBunnyInfo() const;
        void killHalf();
        void viewEvents() const;
        bool fertileMale() const;
        static bool compareAge(const std::shared_ptr<bunny>&, const std::shared_ptr<bunny>&);
        static bool compareID(const std::shared_ptr<bunny>&, const std::shared_ptr<bunny>&);
};

#endif