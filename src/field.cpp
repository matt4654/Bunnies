#include "../include/field.h"

#include <iostream>
#include <memory>
#include <iomanip>

int field::infected = 0;

//Constructor
field::field()
{
    bunny::setNumberOfPossibleNames();
    addBunnies(5);
    viewAllBunnyInfo();
};

//Other Methods

void field::addBunnies(int n)
{
    for(int i = 0; i < n; i++)
    {
        std::shared_ptr<bunny> b = std::make_shared<bunny>();
        bunnies.push_back(b);
    }
}

void field::turn()
{
    infectedCount();
    bunnyLifeCycle();
    bunnies.sort(compareAge);
    viewAllBunnyInfo();
    viewEvents();
}

int field::bunnyCount() const
{
    return bunnies.size();
}

int field::infectedCount()
{
    infected = 0;
    std::list<std::shared_ptr<bunny>>::iterator i;
    for(i = bunnies.begin(); i != bunnies.end(); ++i)
    {
        if((**i).getIsInfected() == true)
        {
            ++infected;
        }
    }
    return infected;
}

void field::bunnyLifeCycle()
{
    newBirths.clear();
    newDeaths.clear();
    newInfected.clear();
    std::list<std::shared_ptr<bunny>>::iterator i = bunnies.begin();
    int j = 0;
    while(i != bunnies.end())
    {
        if((**i).getAge() >= 10 && (**i).getIsInfected() == false)
        {
            newDeaths.push_back(*i);
            bunnies.erase(i++);
            continue;
        }
        if((**i).getAge() >= 50 && (**i).getIsInfected() == true)
        {
            newDeaths.push_back(*i);
            bunnies.erase(i++);
            continue;
        }
        if((**i).getSex() == Sex::Female && (**i).getAge() >= 2 && (**i).getIsInfected() == false && fertileMale() == true)
        {
            std::shared_ptr<bunny> b = std::make_shared<bunny>(*i);
            bunnies.push_front(b);
            newBirths.push_back(b);
        }
        if((**i).getIsInfected() == false && j < infected)
        {
            (**i).infect();
            newInfected.push_back(*i);
            ++j;
        }
        (**i).ageBunny();
        ++i;
    } 
    
}

void field::viewAllBunnyInfo() const
{
    std::cout << std::setw(10) << "Name" << std::setw(10) << "Age" << std::setw(10) << "Sex" << std::setw(10) << "Colour" << std::setw(10) << "Infected" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::list<std::shared_ptr<bunny>>::const_iterator i;
    for(i = bunnies.begin(); i != bunnies.end(); ++i)
    {
        (**i).viewBunnyInfo();
    }
}

void field::killHalf()
{
    int half = bunnyCount() / 2; 
    bunnies.sort(compareID);
    std::list<std::shared_ptr<bunny>>::iterator i = bunnies.begin(), j = bunnies.begin();
    advance(j,half);
    bunnies.erase(i, j);
}

void field::viewEvents() const
{
    std::cout << "--------------------------------------------------------" << std::endl;
    for(int i = 0; i < newBirths.size(); i++)
    {
        std::cout << std::setw(23) << "Bunny " << newBirths[i]->getName() << " was born!" << std::endl;
    }
    for(int i = 0; i < newDeaths.size(); i++)
    {
        std::cout << std::setw(23) << "Bunny " << newDeaths[i]->getName() << " died!" << std::endl;
    }
    for(int i = 0; i < newInfected.size(); i++)
    {
        std::cout << std::setw(23) << "Bunny " << newInfected[i]->getName() << " got infected!" << std::endl;
    }
}

bool field::fertileMale() const
{
    bool fertileMale = false;
    std::list<std::shared_ptr<bunny>>::const_iterator i;
    for(i = bunnies.begin(); i != bunnies.end(); ++i)
    {
        if((**i).getSex() == Sex::Male && (**i).getAge() >= 2 && (**i).getIsInfected() == false)
        {
            fertileMale = true;
            return fertileMale;
        }
    }
    return fertileMale;
}

bool field::compareAge(const std::shared_ptr<bunny> &first, const std::shared_ptr<bunny> &second)
    {
        return(first->getAge() > second->getAge());
    }

bool field::compareID(const std::shared_ptr<bunny> &first, const std::shared_ptr<bunny> &second)
{
    return(first->getID() > second->getID());
}
