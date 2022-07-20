#pragma once
#ifndef FORMAT_H
#define FORMAT_H

enum ConsoleColor 
{
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void set_color_console(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

string remove_rn(string n)
{
	size_t found_r = n.find('\r');
	if (found_r != string::npos)
		n.erase(found_r, 1);
    size_t found_esc = n.find(27);
    if (found_esc != string::npos)
        n.erase(found_esc, 1);
	return n;
}

void goto_xy(int X, int Y)
{
    HANDLE hConsole;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

bool file_exist(int base_number)
{
    stringstream path_1; stringstream path_2;
    path_1 << "user_info/" << base_number << ".ub";
    path_2 << "user_dreams/" << base_number << ".ub";
    bool exist_1 = false;
    bool exist_2 = false;
    ifstream file_1(path_1.str());
    if (file_1.is_open())
        exist_1 = true;
    file_1.close();
    ifstream file_2(path_2.str());
    if (file_2.is_open())
        exist_2 = true;
    file_2.close();
    return (exist_1 & exist_2);
}

void string_center(string str)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(h, &info);
    short x = 122 / 2 - (str.size() / 2);
    info.dwCursorPosition.X = x;
    SetConsoleCursorPosition(h, info.dwCursorPosition);
    cout << str << endl;
}

void string_center(string str, int y)
{
    HANDLE hConsole;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    short x = 122 / 2 - (str.size() / 2);
    COORD coord = { x, y };
    SetConsoleCursorPosition(hStdOut, coord);
    cout << str << endl;
}

template <typename T>
void var_cin(T* var, string message = "Попробуйте снова!")
{
    cin >> *var;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cin.sync();
        cout << message + ": ";
        cin >> *var;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    cin.sync();
}

#endif
