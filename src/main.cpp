#include "../include/field.h"

#include <stdlib.h>
#include <iostream>

int main()
{
    srand(time(0));
    field myField;
    std::cout << "Press enter for next turn..." << std::endl;
    std::cin.get();
    while(myField.bunnyCount() > 0)
    {
        std::cout << std::endl;
        if(myField.bunnyCount() > 1000)
        {
            myField.killHalf();
        }
        myField.turn();
        std::cout << "Press enter for next turn..." << std::endl;
        std::cin.get();
    }
    
    return 0;
}