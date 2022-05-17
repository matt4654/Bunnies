#ifndef FIELD_H
#define FILED_H

#include "bunny.h"

#include <list>
#include <vector>
#include <memory>

class field
{
    private:
        int numberOfInfected;
        std::list<std::shared_ptr<bunny>> bunnies;
        std::vector<std::shared_ptr<bunny>> newDeaths;
        std::vector<std::shared_ptr<bunny>> newBirths;
        std::vector<std::shared_ptr<bunny>> newInfected;

    public:
        field();

        void addBunnies(int);
        void turn();
        int bunnyCount() const;
        int infectedCount();
        void bunnyLifeCycle();
        void viewAllBunnyInfo() const;
        void killHalf();
        void viewEvents() const;
        bool isFertileMale() const;
        static bool compareAge(const std::shared_ptr<bunny>&, const std::shared_ptr<bunny>&);
        static bool compareID(const std::shared_ptr<bunny>&, const std::shared_ptr<bunny>&);
};

#endif