#pragma once
#ifndef USER_H
#define USER_H

class user
{
	string user_id;
	string gender;
	short int age;
	string sity;
	vector<string> interest;
	string want_gender;
	short int want_age;
	string want_sity;
	vector<string> want_interest;
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

user user::read_user(int base_number)
{
	user temp("sdf", "sdf", 4, "sdf", "234", 12, "fre");
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
	os << setw(30) << "Пользователь:" << setw(15) << u.user_id << endl << setw(15) << u.gender << setw(10) << u.age << setw(15) << u.sity << endl;
	for (string n : u.interest) os << setw(15) << n; os << endl << setw(30) << "Ищет пользователь:" << setw(15) << u.user_id << endl;
	cout << setw(15) << u.want_gender << setw(10) << u.want_age << setw(15) << u.want_sity << endl;
	for (string n : u.want_interest) os << setw(15) << n; os << endl;
	return os;
}

void user::print()
{
	if (gender == "Мужской") SetColor(White, Blue); else SetColor(White, Red);
	string_center("Пользователь: " + user_id);
	if (gender == "Мужской") SetColor(White, LightBlue); else SetColor(White, LightRed);
	cout << setw(15) << gender << setw(10) << age << setw(15) << sity << endl;
	for (string n : interest) cout << setw(15) << n; cout << endl;
	if (want_gender == "Мужской") SetColor(White, Blue); else SetColor(White, Red);
	string_center("Ищет пользователь: " + user_id);
	if (want_gender == "Мужской") SetColor(White, LightBlue); else SetColor(White, LightRed);
	cout << setw(15) << want_gender << setw(10) << want_age << setw(15) << want_sity << endl;
	for (string n : want_interest) cout << setw(15) << n; cout << endl;
	SetColor(White, Black);
}

void user::print_user_info()
{
	if (gender == "Мужской") SetColor(White, Blue); else SetColor(White, Red);
	string_center("Пользователь: " + user_id);
	if (gender == "Мужской") SetColor(White, LightBlue); else SetColor(White, LightRed);
	cout << setw(15) << gender << setw(10) << age << setw(15) << sity << endl;
	for (string n : interest) cout << setw(15) << n; cout << endl;
}

void user::print_user_dreams()
{
	if (want_gender == "Мужской") SetColor(White, Blue); else SetColor(White, Red);
	string_center("Ищет пользователь: " + user_id);
	if (want_gender == "Мужской") SetColor(White, LightBlue); else SetColor(White, LightRed);
	cout << setw(15) << want_gender << setw(10) << want_age << setw(15) << want_sity << endl;
	for (string n : want_interest) cout << setw(15) << n; cout << endl;
	SetColor(White, Black);
}

#endif
