#include "ValidationString.h"

void ValidationString::check_correctness(const char* str)
{
	if (isComplete(str))
	{
		char* txt = new char[strlen(str)];
		copy(str, txt);
		search_errors(txt);
	}
	else
		cout << "Строка незавершина" << endl;
}

bool ValidationString::isComplete(const char* str)
{
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] == ';') 
			return true;
	}

	return false;
}

void ValidationString::copy(const char* destination, char* sourse)
{
	for (int i = 0; i < strlen(destination); ++i)
	{
		sourse[i] = destination[i];

		if (destination[i] == ';')
		{
			sourse[i + 1] = '\0';
			break;
		}
	}
}

void ValidationString::search_errors(const char* str)
{
	int idx_error = 0;
	bool isError = false;
	
	for (int i = 0; i < strlen(str); ++i)
	{
		if (is_close_brackets(str, i))
		{
			isError = true;
			idx_error = i;
			break;
		}

		if (is_open_brackets(str, i))
		{
			isError = true;
			idx_error = i;
			break;
		}
	}

	system("cls");

	isError ? show_error(str, idx_error) : show(str);
}

bool ValidationString::is_close_brackets(const char* str, int current_idx)
{
	if (str[current_idx] == ')') return true;
	if (str[current_idx] == ']') return true;
	if (str[current_idx] == '}') return true;

	return false;
}

bool ValidationString::is_open_brackets(const char* str, int& current_idx)
{
	if (str[current_idx] == '(')
		return go_inside_parenthesis(str, current_idx);

	if (str[current_idx] == '[')
		return go_inside_square_bracket(str, current_idx);

	if (str[current_idx] == '{')
		return go_inside_brace(str, current_idx);

	return false;
}

bool ValidationString::go_inside_parenthesis(const char* str, int& current_idx)
{
	for (int i = current_idx + 1; i < strlen(str); ++i)
	{
		if (str[i] == ')')
		{
			current_idx = i;
			return false;
		}

		if (is_close_brackets(str, i))
		{
			current_idx = i;
			return true;
		}

		if (is_open_brackets(str, i))
			return true;
	}

	return true;
}

bool ValidationString::go_inside_square_bracket(const char* str, int& current_idx)
{
	for (int i = current_idx + 1; i < strlen(str); ++i)
	{
		if (str[i] == ']')
		{
			current_idx = i;
			return false;
		}

		if (is_close_brackets(str, i))
		{
			current_idx = i;
			return true;
		}

		if (is_open_brackets(str, i))
			return true;
	}

	return true;
}

bool ValidationString::go_inside_brace(const char* str, int& current_idx)
{
	for (int i = current_idx + 1; i < strlen(str); ++i)
	{
		if (str[i] == '}')
		{
			current_idx = i;
			return false;
		}

		if (is_close_brackets(str, i))
		{
			current_idx = i;
			return true;
		}

		if (is_open_brackets(str, i))
			return true;
	}

	return true;
}

void ValidationString::show(const char* str)
{
	cout << "Строка введина корректно:" << endl;

	for (int i = 0; i < strlen(str); ++i)
	{
		cout << str[i];
	}
	cout << endl;
}

void ValidationString::show_error(const char* str, int idx_error)
{
	cout << "Ошибка:" << endl;

	for (int i = 0; i < idx_error + 1; ++i)
	{
		cout << str[i];
	}
	cout << endl;
}
