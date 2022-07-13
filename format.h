#pragma once
#ifndef FORMAT_H
#define FORMAT_H

enum ConsoleColor 
{
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

string remove_rn(string n)
{
	size_t found = n.find('\r');
	if (found != std::string::npos)
		n.erase(found, 1);
	return n;
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
    short x = 120 / 2 - (str.size() / 2);
    info.dwCursorPosition.X = x;
    SetConsoleCursorPosition(h, info.dwCursorPosition);
    cout << str << endl;
}

#endif