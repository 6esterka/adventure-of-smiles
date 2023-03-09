#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<Windows.h>
#include<mmsystem.h>
#include<conio.h>
#include<ctype.h>
#include <fstream>
#include <vector>
#include<algorithm>
#include<string>
#include <cstdio>
//Line of code for background music
#pragma comment(lib,"WinMM.lib")
//Local libraries
//#include "consoleColor.h"
#include "Level1.h"
#include "UnitData.h"
#include "UnitType.h"
#include "WeaponType.h"
#include "GameMenu.h"
#include "ConsoleColor.h";
#include "GameMenu.h";

using namespace std;
class Game{
private:
///////////////////////////
//Constants
	static const int maxUnits = 50;
	static const int initial_row = 40;
	static const int initial_col = 40;
	////////////////////////
	HANDLE consoleHandle = 0;
	bool isGameActive = true;
	bool checkWin = false;
	bool level_secret = false;
	///////////////////////////
	bool fogofwar[rowCount_level_3][columsCount_level_3];



	////In Default we will set the size of first level
	unsigned char levelData[initial_row][initial_col]{};

	UnitData unitsData[maxUnits];
	int unitsCount = 0;
	int heroIndex = 0;
	int coins = 0;

	void SetupSystem() {
		srand(time(0));
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		//Hide console cursor
		CONSOLE_CURSOR_INFO cursorInfo;
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = 0;
		SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	}

	void ClearMist(int row, int column) {
		for (int i = row - 1; i <= row + 1; ++i) {
			for (int j = column - 1; j <= column + 1; ++j) {
				fogofwar[i][j] = false;
			}
		}
	}

	void Initialize(int save_coins) {
		unitsCount = 0;
		coins = save_coins;
		int rowcount = 0;
		int columscount = 0;
		//Set the level
		if (level_1) {
			rowcount = rowCount_level_1;
			columscount = columsCount_level_1;
		}
		else if (level_2) {
			rowcount = rowCount_level_2;
			columscount = columsCount_level_2;
		}
		else if (level_3) {
			rowcount = rowCount_level_3;
			columscount = columsCount_level_3;
		}
		else if (levelSecret) {
			rowcount = rowCount_secret;
			columscount = columsCount_secret;
		}
		//Loading of level
		for (int i = 0; i < rowcount; ++i) {
			for (int j = 0; j < columscount; ++j) {
				unsigned char cellSymbol;
				if (level_1) {
					cellSymbol = levelData1[i][j];
					levelData[i][j] = cellSymbol;
				}
				else if (level_2) {
					cellSymbol = levelData2[i][j];
					levelData[i][j] = cellSymbol;
				}
				else if (level_3) {
					cellSymbol = levelData3[i][j];
					levelData[i][j] = cellSymbol;
					fogofwar[i][j] = true;
				}
				else if (levelSecret) {
					cellSymbol = levelSecret[i][j];
					levelData[i][j] = cellSymbol;
				}
				switch (cellSymbol) {
				    case CellSymbol_Hero:
				    	heroIndex = unitsCount;
				    case CellSymbol_Orc:
				    case CellSymbol_Skeleton:
				    case CellSymbol_Zombie:
				    {
				    	UnitType unitType = GetUnitTypeFromCell(cellSymbol);
				    	unitsData[unitsCount].type = unitType;
				    	unitsData[unitsCount].row = i;
				    	unitsData[unitsCount].column = j;
				    	unitsData[unitsCount].weapon = GetUnitDefaultWeapon(unitType);
				    	unitsData[unitsCount].health = GetUnitDefaultHealth(unitType);
				    	unitsCount++;
				    
				    	break;
				    
				    }

				}
			}
		}
		//Clear mist from initial position of hero
		if (level_3) {
			ClearMist(unitsData[heroIndex].row, unitsData[heroIndex].column);
		}
	}


	void RenderInterface() {
		//Moving the cursor to the point(0,0)
		COORD cursorCoord;
		cursorCoord.X = 0;
		cursorCoord.Y = 0;
		SetConsoleCursorPosition(consoleHandle, cursorCoord);
		//Draw Level Title
		SetConsoleTextAttribute(consoleHandle, ConsoleColor_Green);
		if (level_1) {
			cout << "\n\tMaze of Mysterious";
		}
		else if (level_2 || levelSecret) {
			cout << "\n\tSecret of the wall";
		}
		else if (level_3) {
			cout << "\n\tMint war";
		}
		//Draw hero HP
		SetConsoleTextAttribute(consoleHandle, ConsoleColor_Red);
		cout << "\n\n\tHP: ";
		if (unitsData[heroIndex].health < 100) {
			SetConsoleTextAttribute(consoleHandle, ConsoleColor_White);
			cout << " " << unitsData[heroIndex].health;
		}
		else {
			SetConsoleTextAttribute(consoleHandle, ConsoleColor_White);
			cout << unitsData[heroIndex].health;
		}
		//Draw hero weapon
		SetConsoleTextAttribute(consoleHandle, ConsoleColor_Blue);
		cout << "\t\tWeapon: ";
		SetConsoleTextAttribute(consoleHandle, ConsoleColor_White);
		cout << GetWeaponName(unitsData[heroIndex].weapon);
		SetConsoleTextAttribute(consoleHandle, ConsoleColor_DarkGray);
		cout << " (Dmg: " << GetWeaponDamage(unitsData[heroIndex].weapon) << " )";
		//Draw heros coins
		SetConsoleTextAttribute(consoleHandle, ConsoleColor_Yellow);
		cout << "\n\tCoins: ";
		if (coins < 100) {
			cout << " " << coins;
		}
		else {
			cout << coins;
		}

	}


	void Render_level() {
		RenderInterface();
		//Draw level
		cout << "\n\n\t";
		////////////////////////////////////////
		//If player has choosed level_1 we will limit the size of map by sizes of level_1 and so on
		int rowCounter = 0;
		int columsCounter = 0;
		if (level_1) {
			rowCounter = rowCount_level_1;
			columsCounter = columsCount_level_1;
		}
		else if (level_2) {
			rowCounter = rowCount_level_2;
			columsCounter = columsCount_level_2;
		}
		else if (level_3) {
			rowCounter = rowCount_level_3;
			columsCounter = columsCount_level_3;
		}
		else if (levelSecret) {
			rowCounter = rowCount_secret;
			columsCounter = columsCount_secret;
		}
		//////////////////////////////////////////
		for (int i = 0; i < rowCounter; ++i) {
			for (int j = 0; j < columsCounter; ++j) {
				if (level_3 && (fogofwar[i][j] == true)) {
					SetConsoleTextAttribute(consoleHandle, fogofWarRenderColor);
					cout << fogOfWarRenderSymbol;
				}
				else {
					unsigned char cellSymbol = levelData[i][j];
					unsigned char renderCellSymbol = GetRenderCellSymbol(cellSymbol);
					ConsoleColor cellColor = GetRenderCellSymbolColor(cellSymbol);
					SetConsoleTextAttribute(consoleHandle, cellColor);
					cout << renderCellSymbol;
				}
			}
			cout << "\n\t";
		}
	}

	void MoveUnitTo(UnitData* ptrToUnitData, int row, int column) {
		//Ignore dead units
		if (ptrToUnitData->health <= 0) {
			return;
		}
		//Current position of unit
		unsigned char unitSymbol = levelData[ptrToUnitData->row][ptrToUnitData->column];
		//The position on map where the unit will go
		unsigned char destinationCellSymbol = levelData[row][column];

		bool canMoveToCell = false;
		//All ways for movement of units
		switch (destinationCellSymbol) {
			//Empty cell
		case CellSymbol_Empty:
		{
			canMoveToCell = true;
			break;
		}
		case CellSymbol_Coin:
		{
			canMoveToCell = true;
			if (ptrToUnitData->type == UnitType_Hero) {
				coins += 10;
			}
			break;
		}
		//Units cells
		case CellSymbol_Hero:
		case CellSymbol_Orc:
		case CellSymbol_Skeleton:
		case CellSymbol_Zombie:
		{
			UnitType destinationUnitType = GetUnitTypeFromCell(destinationCellSymbol);
			//If destination unit have other type
			if (ptrToUnitData->type != destinationUnitType) {
				//Find enemy unit struct which is replacing in front of hero
				for (int u = 0; u < unitsCount; ++u) {
					//Ignore dead units
					if (unitsData[u].health <= 0) {
						continue;
					}
					if (unitsData[u].row == row && unitsData[u].column == column) {
						//Calculating weapon damage
						int damage = GetWeaponDamage(ptrToUnitData->weapon);
						//Make damage
						unitsData[u].health -= damage;
						//If enemy will die
						if (unitsData[u].health <= 0) {
							levelData[row][column] = CellSymbol_Empty;
						}
						break;
					}
				}
			}
			break;
		}
		}
		//Only hero actions
		if (ptrToUnitData->type == UnitType_Hero) {
			switch (destinationCellSymbol) {
				//Weapon cell
			case CellSymbol_Stick:
			case CellSymbol_Club:
			case CellSymbol_Spear:
			case CellSymbol_Saber:
			case CellSymbol_Chain:
			case CellSymbol_Scythe:
			{
				canMoveToCell = true;
				WeaponType weaponType = GetWeaponTypeFromCell(destinationCellSymbol);
				//If we've got more powerful weapon
				if (unitsData[heroIndex].weapon < weaponType) {
					unitsData[heroIndex].weapon = weaponType;
				}
				break;
			}
			case CellSymbol_Secret:
				if (level_secret) {
					level_secret = false;
					level_2 = true;
				}
				else {
					level_secret = true;
					level_2 = false;
				}
				canMoveToCell = true;
				break;
			case CellSymbol_Exit:
			{
				isGameActive = false;
				checkWin = true;
				break;
			}
			}
		}
		if (canMoveToCell) {
			//Remove unit symbol from old position
			levelData[ptrToUnitData->row][ptrToUnitData->column] = CellSymbol_Empty;
			//Set to the hero new position
			ptrToUnitData->row = row;
			ptrToUnitData->column = column;
			//Draw the hero at the new position on the map
			levelData[ptrToUnitData->row][ptrToUnitData->column] = unitSymbol;
			if (ptrToUnitData->type == UnitType_Hero && level_3) {
				ClearMist(row, column);
			}
		}

	}

	void UpdateAI() {
		//Pass all units
		for (int u = 0; u < unitsCount; u++) {
			//Ignore hero
			if (u == heroIndex) {
				continue;
			}
			//Distance to hero
			int distanceToHeroR = abs(unitsData[heroIndex].row - unitsData[u].row);
			int distanceToHeroC = abs(unitsData[heroIndex].column - unitsData[u].column);
			//If hero nearby
			if ((distanceToHeroR + distanceToHeroC) == 1) {
				//Attack hero
				MoveUnitTo(&unitsData[u], unitsData[heroIndex].row, unitsData[heroIndex].column);
			}
			else {
				//Random movement of mobs
				switch (rand() % 4) {
					//Up
				case 0:
					MoveUnitTo(&unitsData[u], unitsData[u].row - 1, unitsData[u].column);
					break;
					//Down
				case 1:
					MoveUnitTo(&unitsData[u], unitsData[u].row + 1, unitsData[u].column);
					break;
					//Left
				case 2:
					MoveUnitTo(&unitsData[u], unitsData[u].row, unitsData[u].column - 1);
					break;
					//Right
				case 3:
					MoveUnitTo(&unitsData[u], unitsData[u].row, unitsData[u].column + 1);
					break;
				}
			}
		}
	}

	void Update() {
		unsigned char inputChar = _getch();
		inputChar = tolower(inputChar);
		switch (inputChar) {
			//Up
		case 'w':
			MoveUnitTo(&unitsData[heroIndex], unitsData[heroIndex].row - 1, unitsData[heroIndex].column);
			break;
			//Down
		case 's':
			MoveUnitTo(&unitsData[heroIndex], unitsData[heroIndex].row + 1, unitsData[heroIndex].column);
			break;
			//Left
		case 'a':
			MoveUnitTo(&unitsData[heroIndex], unitsData[heroIndex].row, unitsData[heroIndex].column - 1);
			break;
			//Right
		case 'd':
			MoveUnitTo(&unitsData[heroIndex], unitsData[heroIndex].row, unitsData[heroIndex].column + 1);
			break;
			//Restarting the level
		case 'r':
			Initialize(0);
			break;
		}
		//AI turn
		UpdateAI();
		//Hero death
		if (unitsData[heroIndex].health <= 0) {
			isGameActive = false;
		}
		else {
			//Health regeneration
			if (unitsData[heroIndex].health < GetUnitDefaultHealth(UnitType_Hero)) {
				++unitsData[heroIndex].health;
			}
		}
	}

	void SortResult() {
		string input_str;
		string output_str;
		char ch;
		//Read file for sorting
		ifstream infile;
		infile.open("highscore.txt");
		while (infile.get(ch)) {
			input_str.push_back(ch);
		}
		if (input_str != "") {
			input_str += to_string(coins) + "\n";
			vector<int> nums;
			string current_num = "";
			for (char& c : input_str) {
				if (isdigit(c)) {
					current_num += c;
				}
				else if (c == '\n') {
					if (!current_num.empty()) {
						nums.push_back(stoi(current_num));
						current_num = "";
					}
				}
			}
			if (!current_num.empty()) {
				nums.push_back(stoi(current_num));
			}
			//Sorting num by decreasing
			sort(nums.begin(), nums.end(), greater<int>());	
			for (int num : nums) {
				output_str += to_string(num) + "\n";
			}
		}
		else {
			output_str = to_string(coins) + '\n';
		}
		infile.close();
		ofstream ofs;
		ofs.open("highscore.txt", ios::out | ios::trunc);
		ofs << output_str;
		ofs.close();
	}

	void Shutdown(bool checkWin)
	{
		system("cls");
		SortResult();
		if (checkWin == false) {
			cout << "\n\tGame over...";
		}
		else {
			cout << "Congratulation My Friend" << endl;
		}
		PlaySound(NULL, 0, 0);
		_getch();
	}

public:
	void Start() {
		DrawMenu();
		HideCursor();
		do {
			MoveCursor();
			system("cls");
			DrawMenu();
		} while (menuActive);
		system("cls");
		//Level menu load if true
		if (level_menu) {
			Draw_Level_menu();
			while (level_menu) {
				MoveCursor();
				system("cls");
				Draw_Level_menu();
			}
			system("cls");
		}
		if (exit_button == false) {
			SetupSystem();
			PlaySound(TEXT("Pygmalion_m_-_Arachnodactylia.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			Initialize(0);
			system("cls");
			do {
				Render_level();
				Update();
				//If you have reached a secret level
				if (level_secret) {
					system("cls");
					//Save the map
					unsigned char tmplevelData[rowCount_level_2][columsCount_level_2]{};
					for (int i = 0; i < rowCount_level_2; ++i) {
						for (int j = 0; j < columsCount_level_2; ++j) {
							tmplevelData[i][j] = levelData[i][j];
						}
					}
					//Load level_secret
					SetupSystem();
					Initialize(coins);
					do {
						Render_level();
						Update();
					} while (level_secret);
					int tmpcoins = coins;
					system("cls");
					SetupSystem();
					Initialize(tmpcoins);
					continue;
				}
			} while (isGameActive);
			Shutdown(checkWin);
		}
	}
};
