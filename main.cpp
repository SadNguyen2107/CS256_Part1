#include "Menus/Menu1.h"
#include "Menus/Menu2.h"
#include "Menus/Menu3.h"
#include "Menus/SharedResource.h"

int main()
{
    loadMenu1();

    std::system("cls");

    loadMenu2();

    std::system("cls");

    loadMenu3();

    return 0;
}
