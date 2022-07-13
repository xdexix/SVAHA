#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

#include "format.h"
#include "user.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("mode con cols=120 lines=50");

    vector<user> users; int i = 1;
    while (users.size() < users.max_size())
    {
        if (file_exist(i))
        {
            user temp;
            users.push_back(temp.read_user(i));
            i++;
        }
        else break;
    }
    for (user n : users)
    {
        n.print_user_info();
        n.print_user_dreams();
        cout << endl;
    }
}
