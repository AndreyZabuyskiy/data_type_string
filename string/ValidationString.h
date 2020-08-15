#pragma once
#include <iostream>
using namespace std;

class ValidationString
{
public:
	static void check_correctness(const char* str);

private:
	static bool isComplete(const char* str);
	static void copy(const char* destination, char* sourse);
	static void search_errors(const char* str);

	static bool is_close_brackets(const char* str, int current_idx);
	static bool is_open_brackets(const char* str, int& current_idx);

	static bool go_inside_parenthesis(const char* str, int& current_idx);
	static bool go_inside_square_bracket(const char* str, int& current_idx);
	static bool go_inside_brace(const char* str, int& current_idx);

	static void show(const char* str);
	static void show_error(const char* str, int idx_error);
};