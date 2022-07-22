#pragma once
#ifndef PROCESS_H
#define PROCESS_H

int MAX;
vector <user> base;

int add_user()
{
    base.push_back(new_user());
    return MAX + 1;
}

void gallery()
{
    system("cls");
    int i; 
    cout << "\tВведите ID: ";
    var_cin(&i, "\tНекорректное ID", MAX); i--;
    cout << endl << endl << base[i] << endl;
    cout << "\t-> следующий пользователь" << endl;
    cout << "\t<- предыдущий пользователь" << endl;
    cout << "\tEnter - выход в меню" << endl << endl << endl << endl;
    cout << "\tПользователь #" << i + 1;
    while (_getch() != 13)
    {
        switch (_getch())
        {
        case LEFT:
            i--; if (i < 0) i = MAX - 2;
            break;
        case RIGHT:
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

void find()
{
    system("cls");
    int i; map <int, user> res;
    cout << "\tВведите ID: ";
    var_cin(&i, "\tНекорректное ID", MAX);
    system("cls"); i--;
    string_center("Подождите! Идет поиск кандидатов!", 25);

    for (int j = 0; j < MAX - 2; j++)
    {
        if (j == i) continue;
        for (string n : base[i].want_interest)
        {
            for (string d : base[j].interest)
            {
                if (to_lower(n) == to_lower(d))
                {
                    if (base[i].want_age < base[j].age + 5 && base[i].want_age > base[j].age - 5
                        && to_lower(base[i].want_sity) == to_lower(base[j].sity) && base[i].want_gender == base[j].gender)
                        res.insert(pair <int, user>(j, base[j]));
                }
            }
        }
    }
    system("cls");

    bool t = false;
    if (!res.empty())
    {
        t = true;
        map<int, user>::iterator it = res.begin();
        base[i].print_user_dreams(); cout << endl << endl << "\tКандидат #" << it->first + 1 << endl << endl;
        it->second.print_user_info(); cout << endl << endl;
        cout << "\t-> следующий пользователь" << endl;
        cout << "\t<- предыдущий пользователь" << endl;
        cout << "\tEnter - выход в меню";
        while (_getch() != 13)
        {
            switch (_getch())
            {
            case LEFT:
                if (it == res.begin()) it = res.begin(); else it--;
                break;
            case RIGHT:
                if (it == res.end()) break; else it++;
                break;
            }
            system("cls");
            base[i].print_user_dreams(); cout << endl << endl << "\tКандидат #" << it->first + 1 << endl << endl;
            it->second.print_user_info(); cout << endl << endl;
            cout << "\t-> следующий пользователь" << endl;
            cout << "\t<- предыдущий пользователь" << endl;
            cout << "\tEnter - выход в меню";
        }
    }
    if (t == false)
    {
        string_center("Результатов нет! Enter для продолжения", 17);
        while (_getch() != 13) {};
    }
}

void menu()
{
    string_center("Загрузка...", 25);
    MAX = 1;
    while (base.size() < base.max_size())
    {
        if (file_exist(MAX))
        {
            user temp;
            base.push_back(temp.read_user(MAX));
            MAX++;
        }
        else break;
    }

    if (!base.empty())
    {
        while (true)
        {
            system("cls"); int v = 0;
            string_center("Выберите дейтвие", 15);
            string_center("Регистрация", 16);
            string_center("Просмотр пользователей", 17);
            string_center("Найти подходящего", 18);
            set_color_console(DarkGray, Black);
            string_center("ESC для выхода", 20);
            set_color_console(White, Black);
            goto_xy(45, 16);
            cout << "->";
            while (_getch() != 13)
            {
                switch (_getch())
                {
                case UP:
                    v--; if (v < 0) v = 0;
                    break;
                case DOWN:
                    v++; if (v > 2) v = 2;
                    break;
                case 27:
                    system("cls");
                    exit(0);
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
                MAX = add_user();
                break;
            case 1:
                gallery();
                break;
            case 2:
                find();
                break;
            }
        }
    }
    system("cls");
    string_center("База данных отсутствует! Enter для выхода из программы", 12);
    while (_getch() != 13) {};
}

#endif
