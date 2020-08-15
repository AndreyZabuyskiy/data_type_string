#include "ValidationString.h"
#include <Windows.h>

#define LENGTH 50

void menu();
void write_str();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu();

	return 0;
}

void menu()
{
	int user;
	do
	{
		cout << "[1] Ввод строки;" << endl
			<< "[0] Выход" << endl
			<< "-> ";
		cin >> user;

		system("cls");

		if (user == 1)
			write_str();

	} while (user != 0);
}

void write_str()
{
	cin.ignore();

	cout << "Введите строку, конец строки ';'" << endl;
	char* str = new char[LENGTH];
	cin.getline(str, LENGTH);

	ValidationString::check_correctness(str);

	system("pause");
	system("cls");

	delete[] str;
}