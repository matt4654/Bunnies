#include "../include/field.h"

#include <stdlib.h>
#include <iostream>

int main()
{
    srand(time(0));
    field myField;
    system("pause");
    while(myField.bunnyCount() > 0)
    {
        if(myField.bunnyCount() > 1000)
        {
            myField.killHalf();
        }
        system("cls");
        myField.turn();
        system("pause");
    }
    
    return 0;
}