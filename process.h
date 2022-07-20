#pragma once
#ifndef PROCESS_H
#define PROCESS_H

int MAX;

int add_user(vector <user> base)
{
    base.push_back(new_user());
    return MAX + 1;
}

void gallery(vector <user> base)
{
    system("cls");
    int i; 
    cout << "\tВведите ID: ";
    var_cin(&i, "\tНекорректное ID");
    system("cls"); i--;
    cout << endl << endl << base[i] << endl;
    cout << "\t-> следующий пользователь" << endl;
    cout << "\t<- предыдущий пользователь" << endl;
    cout << "\tEnter - выход в меню" << endl << endl << endl << endl;
    cout << "\tПользователь #" << i + 1;
    while (_getch() != 13)
    {
        switch (_getch())
        {
        case 75: // left
            i--; if (i < 0) i = MAX - 2;
            break;
        case 77: // right
            i++; if (i > MAX - 2) i = 0;
            break;
        }
        system("cls");
        cout << endl << endl << base[i] << endl;
        cout << "\t-> следующий пользователь" << endl;
        cout << "\t<- предыдущий пользователь" << endl;
        cout << "\tEnter - выход в меню" << endl << endl << endl << endl;
        cout << "\tПользователь #" << i + 1;
    }
}

void menu()
{
    string_center("Загрузка...", 25);
    vector<user> users; MAX = 1;
    while (users.size() < users.max_size())
    {
        if (file_exist(MAX))
        {
            user temp;
            users.push_back(temp.read_user(MAX));
            MAX++;
        }
        else break;
    }

    while (true)
    {
        system("cls"); int v = 0;
        string_center("Выберите дейтвие", 15);
        string_center("Регистрация", 16);
        string_center("Просмотр пользователей", 17);
        string_center("Найти подходящего", 18);
        goto_xy(45, 16);
        cout << "->";
        while (_getch() != 13)
        {
            switch (_getch())
            {
            case 72: // up
                v--; if (v < 0) v = 0;
                break;
            case 80: // down
                v++; if (v > 2) v = 2;
                break;
            }
            for (int i = 0; i < 3; i++)
            {
                goto_xy(47, 16 + i);
                cout << "\b \b\b ";
            }
            goto_xy(45, 16 + v);
            cout << "->";
        }
        switch (v)
        {
        case 0:
            MAX = add_user(users);
            break;
        case 1:
            gallery(users);
            break;
        }
    }
}

#endif
