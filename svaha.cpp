#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <conio.h>

using namespace std;

#include "format.h"
#include "user.h"
#include "process.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("mode con cols=122 lines=50");

    menu();
}
