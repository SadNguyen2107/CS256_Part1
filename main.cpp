#include "Menus/Menu1.h"
#include "Menus/Menu2.h"
#include "Menus/Menu3.h"

int main()
{
    //Print Menu 1
    int status = loadMenu1();
    if (status == QUIT_PROGRAM)
    {
        return 0;
    }

    //Print Menu 2
    if (status == INPUT_SUCCESS)
    {
        status = loadMenu2();
    }

    if (status == QUIT_PROGRAM)
    {
        return 0;
    }

    // Load Menu3
    if(status == INPUT_SUCCESS)
    {
        status = loadMenu3();
    }
    if (status == QUIT_PROGRAM)
    {
        return 0;
    }

    return 0;
}                 
