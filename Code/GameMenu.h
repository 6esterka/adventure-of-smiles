#pragma once
using namespace std;
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Level1.h"
FILE* fb;

bool menuActive = true;
bool level_menu = false;
bool exit_button = false;
bool level_1 = false;
bool level_2 = false;
bool level_3 = false;

int cursor_pos = 0;

enum Lines {
	Horizontal_Line = 205,
	Vertical_Line = 186,
	First_Corner = 201,
	Second_Corner = 187,
	Third_Corner = 188,
	Forth_Corner = 200,
	Empty_symbol = 32
};
void PrintMenuParts(int symbol_begin, int symbol_center, int symbol_end) {
	cout << (char)symbol_begin;
	for (int i = 0; i < 22; ++i) {
		cout << (char)symbol_center;
	}
	cout << (char)symbol_end << endl;
}

void DrawMenu() {
	PrintMenuParts(First_Corner, Horizontal_Line, Second_Corner);
	PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	cout << (char)Vertical_Line << "  Adventure of Smile  " << (char)Vertical_Line << endl;
	//Calling 2 times of function
	PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	cout << (char)Vertical_Line << "Game by casper_bool   " << (char)Vertical_Line << endl;
	PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	cout << (char)Vertical_Line << "Music Pygmalion_m     " << (char)Vertical_Line << endl;
	for (int i = 0; i < 3; i++) {
		PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      Start Game      " << (char)Vertical_Line << endl;
	if (cursor_pos == 0) {
		cout << (char)Vertical_Line << "      ----------      " << (char)Vertical_Line << endl;
	}
	else {
		PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "        Results       " << (char)Vertical_Line << endl;
	if (cursor_pos == 2) {
		cout << (char)Vertical_Line << "      ----------      " << (char)Vertical_Line << endl;
	}
	else {
		PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "         Exit         " << (char)Vertical_Line << endl;
	if (cursor_pos == 4) {
		cout << (char)Vertical_Line << "         ----         " << (char)Vertical_Line << endl;
	}
	else {
		PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	PrintMenuParts(Forth_Corner, Horizontal_Line, Third_Corner);
}

void Draw_Level_menu() {
	PrintMenuParts(First_Corner, Horizontal_Line, Second_Corner);
	PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	cout << (char)Vertical_Line << "  Adventure of Smile  " << (char)Vertical_Line << endl;
	//Calling 3 times of function
	for (int i = 0; i < 3; i++) {
		PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      Level 1         " << (char)Vertical_Line << endl;
	if (cursor_pos == 0) {
		cout << (char)Vertical_Line << "      -------         " << (char)Vertical_Line << endl;
	}
	else {
		PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      Level 2         " << (char)Vertical_Line << endl;
	if (cursor_pos == 2) {
		cout << (char)Vertical_Line << "      -------         " << (char)Vertical_Line << endl;
	}
	else {
		PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      Level 3         " << (char)Vertical_Line << endl;
	if (cursor_pos == 4) {
		cout << (char)Vertical_Line << "      -------         " << (char)Vertical_Line << endl;
	}
	else {
		PrintMenuParts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	PrintMenuParts(Forth_Corner, Horizontal_Line, Third_Corner);
}

void HideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}




void MoveCursor() {
	//Waiting for entering the key
	char inputCharMenu = _getch();
	inputCharMenu = tolower(inputCharMenu);
	switch (inputCharMenu) {
		//UP
	case 'w':
		if (cursor_pos > 0) {
			cursor_pos -= 2;
		}
		break;
		//DOWN
	case 's':
		if (cursor_pos < 4) {
			cursor_pos += 2;
		}
		break;
		//Enter (Going to the levels menu or Select the level)
	case 13:
		if (level_menu == false) {
			if (cursor_pos == 0) {
				menuActive = false;
				level_menu = true;
			}
			else if (cursor_pos == 2) {
				//open highscore.bin file for viewing
				string str;
				char c;
				ifstream infile;
				infile.open("highscore.txt");
				while (infile.get(c)) {
					str.push_back(c);
				}
				system("cls");
				cout << str;
				infile.close();
				system("pause");
			}
			else if (cursor_pos == 4) {
				menuActive = false;
				exit_button = true;
			}
			break;
		}
		else if (level_menu == true) {
			if (cursor_pos == 0) {
				level_1 = true;
				level_menu = false;

			}
			else if (cursor_pos == 2) {
				level_2 = true;
				level_menu = false;
				const int final_row = 1;
				const int final_col = 2;
			}
			else if (cursor_pos == 4) {
				level_3 = true;
				level_menu = false;
			}
		}
	}
}