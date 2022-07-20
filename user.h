#pragma once
#ifndef USER_H
#define USER_H

class user
{
	string		user_id,
			gender,
			sity,
			want_gender, 
			want_sity;
	short int	age,
			want_age;
	vector<string>	interest,
			want_interest;
public:
	user();
	user(string _user_id, string _gender, short int _age, string _sity,
		string _want_gender, short int _want_age, string _want_sity);
	~user() {};
	user read_user(int base_number);
	friend ostream& operator << (ostream& os, const user& student);
	void print();
	void print_user_info();
	void print_user_dreams();
	void push_interest(string i);
	void push_w_interest(string i);
};

user::user()
{
	user_id = " ";
	gender = " ";
	age = 0;
	sity = " ";
	want_gender = " ";
	want_age = 0;
	want_sity = " ";
}

user::user(string _user_id, string _gender, short int _age, string _sity,
			string _want_gender, short int _want_age, string _want_sity)
{
	user_id = _user_id;
	gender = _gender;
	age = _age;
	sity = _sity;
	want_gender = _want_gender;
	want_age = _want_age;
	want_sity = _want_sity;
}

void user::push_interest(string i)
{
	interest.push_back(i);
}

void user::push_w_interest(string i)
{
	want_interest.push_back(i);
}

user user::read_user(int base_number)
{
	user temp;
	string line;
	
	stringstream user_info_path; user_info_path << "user_info/" << base_number << ".ub";
	ifstream in_info(user_info_path.str(), std::ios::binary | std::ios::out);
		if (in_info.is_open())
		{
			getline(in_info, line);
			line = remove_rn(line);
			temp.user_id = line;
			getline(in_info, line);
			line = remove_rn(line);
			temp.gender = line;
			getline(in_info, line);
			line = remove_rn(line);
			temp.age = stoi(line);
			getline(in_info, line);
			line = remove_rn(line);
			temp.sity = line;
			while (!in_info.eof())
			{
				getline(in_info, line);
				line = remove_rn(line);
				temp.interest.push_back(line);
			}
		}
	in_info.close();

	stringstream user_dreams_path; user_dreams_path << "user_dreams/" << base_number << ".ub";
	ifstream in_dreams(user_dreams_path.str(), std::ios::binary | std::ios::out);
	if (in_dreams.is_open())
	{
		getline(in_dreams, line);
		line = remove_rn(line);
		temp.user_id = line;
		getline(in_dreams, line);
		line = remove_rn(line);
		temp.want_gender = line;
		getline(in_dreams, line);
		line = remove_rn(line);
		temp.want_age = stoi(line);
		getline(in_dreams, line);
		line = remove_rn(line);
		temp.want_sity = line;
		while (!in_dreams.eof())
		{
			getline(in_dreams, line);
			line = remove_rn(line);
			temp.want_interest.push_back(line);
		}
	}
	in_dreams.close();

	return temp;
}

ostream& operator << (ostream& os, const user& u)
{
	if (u.gender == "Мужской") set_color_console(White, Cyan); else set_color_console(White, LightRed);
	string_center("Пользователь: " + u.user_id);
	os << setw(15) << u.gender << setw(10) << u.age << setw(15) << u.sity << endl;
	for (string n : u.interest) os << setw(15) << n; os << endl;
	set_color_console(White, Black);
	if (u.want_gender == "Мужской") set_color_console(White, Cyan); else set_color_console(White, LightRed);
	string_center("Ищет пользователь: " + u.user_id);
	os << setw(15) << u.want_gender << setw(10) << u.want_age << setw(15) << u.want_sity << endl;
	for (string n : u.want_interest) os << setw(15) << n; os << endl;
	set_color_console(White, Black);
	os << endl;
	return os;
}

void user::print()
{
	if (gender == "Мужской") set_color_console(White, Cyan); else set_color_console(White, LightRed);
	string_center("Пользователь: " + user_id);
	cout << setw(15) << gender << setw(10) << age << setw(15) << sity << endl;
	for (string n : interest) cout << setw(15) << n; cout << endl;
	set_color_console(White, Black);
	if (want_gender == "Мужской") set_color_console(White, Cyan); else set_color_console(White, LightRed);
	string_center("Ищет пользователь: " + user_id);
	cout << setw(15) << want_gender << setw(10) << want_age << setw(15) << want_sity << endl;
	for (string n : want_interest) cout << setw(15) << n; cout << endl;
	set_color_console(White, Black);
	cout << endl;
}

void user::print_user_info()
{
	if (gender == "Мужской") set_color_console(White, Cyan); else set_color_console(White, LightRed);
	string_center("Пользователь: " + user_id);
	cout << setw(15) << gender << setw(10) << age << setw(15) << sity << endl;
	for (string n : interest) cout << setw(15) << n; cout << endl;
	set_color_console(White, Black);
	cout << endl;
}

void user::print_user_dreams()
{
	if (want_gender == "Мужской") set_color_console(White, Cyan); else set_color_console(White, LightRed);
	string_center("Ищет пользователь: " + user_id);
	cout << setw(15) << want_gender << setw(10) << want_age << setw(15) << want_sity << endl;
	for (string n : want_interest) cout << setw(15) << n; cout << endl;
	set_color_console(White, Black);
	cout << endl;
}

user new_user()
{
	system("cls");
	char name[256]; string gender = " "; int* age; char sity[256]; char interest[1024];
	string w_gender = " "; int* w_age; char w_sity[256]; char w_interest[1024];
	age = new int; w_age = new int;
	int n = 1; stringstream path_1; stringstream path_2;

	while (file_exist(n)) { n++; };
	path_1 << "user_info/" << n << ".ub";
	path_2 << "user_dreams/" << n << ".ub";

	set_color_console(Cyan, Black);
	cout << "\tВведите ваше имя\n\t>> ";
	set_color_console(LightRed, Black);
	cin.getline(name, 256, '\n');

	set_color_console(Cyan, Black);
	cout << "\tВведите ваш пол (стрелочка < или >)\n\tМужской\tЖенский\n\t>> ";
	set_color_console(LightRed, Black);

	while (gender == " ")
	{	
		_getch();
		switch (_getch())
		{
		case 75: // left
			gender = "Мужской";
			break;
		case 77: // right
			gender = "Женский";
			break;
		}
	}
	cout << gender << endl;

	set_color_console(Cyan, Black);
	cout << "\tВведите ваш возраст\n\t>> ";
	set_color_console(LightRed, Black);
	var_cin(age, "\tВведите корректный возраст");

	set_color_console(Cyan, Black);
	cout << "\tВведите ваш город\n\t>> ";
	set_color_console(LightRed, Black);
	cin.getline(sity, 256, '\n');

	set_color_console(Cyan, Black);
	cout << "\tВведите ваши увлечения (новая строка - Enter, для окончания ввода введите ~)\t>>\n";
	set_color_console(LightRed, Black);
	cin.getline(interest, 1024, '~');
	system("cls");

	set_color_console(LightBlue, Black);
	cout << "\t" << name << ", кого вы ищете?\n\t"; set_color_console(Cyan, Black);
	cout << "Введите требуемый пол(стрелочка < или >)\n\tМужской\tЖенский\n\t>> ";
	set_color_console(LightRed, Black);
	while (w_gender == " ")
	{
		_getch();
		switch (_getch())
		{
		case 75: // left
			w_gender = "Мужской";
			break;
		case 77: // right
			w_gender = "Женский";
			break;
		}
	}
	cout << w_gender << endl;

	set_color_console(Cyan, Black);
	cout << "\tВведите желаемый возраст\n\t>> ";
	set_color_console(LightRed, Black);
	var_cin(w_age, "\tВведите корректный возраст");

	set_color_console(Cyan, Black);
	cout << "\tВведите желаемый город\n\t>> ";
	set_color_console(LightRed, Black);
	cin.getline(w_sity, 256, '\n');

	set_color_console(Cyan, Black);
	cout << "\tВведите желаемые увлечения (новая строка - Enter, для окончания ввода введите ~)\t>>\n";
	set_color_console(LightRed, Black);
	cin.getline(w_interest, 1024, '~');

	ofstream out_1;
	out_1.open(path_1.str());
	if (out_1.is_open())
	{
		int a_1 = *age;
		out_1 << name << endl << gender << endl << a_1 << endl << sity << endl << interest;
	}
	out_1.close();
	ofstream out_2;
	out_2.open(path_2.str());
	if (out_2.is_open())
	{
		int a_2 = *w_age;
		out_2 << name << endl << w_gender << endl << a_2 << endl << w_sity << endl << w_interest;
	}
	out_2.close();

	user temp(name, gender, *age, sity, w_gender, *w_age, w_sity);
	int o = 0; string line ="";
	while (interest[o] != '\0')
	{
		line += interest[o];
		if (interest[o] != '\n')
		{
			temp.push_interest(line);
			line = "";
		}
		o++;
	}
	temp.push_interest(line); o = 0;
	while (w_interest[o] != '\0')
	{
		line += interest[o];
		if (interest[o] != '\n')
		{
			temp.push_w_interest(line);
			line = "";
		}
		o++;
	} temp.push_w_interest(line);
	char k = ' ';
	set_color_console(White, Black);
	cout << endl << "\tВаш ID: " << n << "\n\tНажимите любую клавишу для продолжения...";
	while (k == ' ') k = _getch();
	return temp;
}

#endif
