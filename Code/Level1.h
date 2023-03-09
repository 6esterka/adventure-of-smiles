#pragma once
#pragma once
#include "ConsoleColor.h"
//Sizes for level_1
const int rowCount_level_1 = 25;
const int columsCount_level_1 = 30;
//Sizes for level_2
const int rowCount_level_2 = 32;
const int columsCount_level_2 = 32;
//Sizes for secret room
const int rowCount_secret = 12;
const int columsCount_secret = 11;
//Sizes for level_3
const int rowCount_level_3 = 17;
const int columsCount_level_3 = 23;

//CellSymbols of the levels
const unsigned char CellSymbol_Empty = ' ';
const unsigned char CellSymbol_Wall = '#';
const unsigned char CellSymbol_Hero = 'h';
const unsigned char CellSymbol_Exit = 'e';
const unsigned char CellSymbol_Orc = 'o';
const unsigned char CellSymbol_Skeleton = 's';
const unsigned char CellSymbol_Zombie = 'z';
const unsigned char CellSymbol_Coin = 'c';
const unsigned char CellSymbol_Stick = '1';
const unsigned char CellSymbol_Club = '2';
const unsigned char CellSymbol_Spear = '3';
const unsigned char CellSymbol_Saber = '4';
const unsigned char CellSymbol_Chain = '@';
const unsigned char CellSymbol_Scythe = '5';
const unsigned char CellSymbol_Secret = '$';

//For fog of war
const unsigned char fogOfWarRenderSymbol = 176;
ConsoleColor fogofWarRenderColor = ConsoleColor_DarkGray;

//Level 1
const unsigned char levelData1[rowCount_level_1][columsCount_level_1 + 1] = {
	"##############################",
	"#           #  o  o ######   #",
	"#                        # # #",
	"# ###########  o  o ## # # # #",
	"#           #5c   cc#  # # # #",
	"# ######### ##########s# #s#o#",
	"# #cco               # # # # #",
	"# #ccs    # ######## ### # # #",
	"# ######### #4cccccc # # #o#o#",
	"# # o  s  # ########## # # # #",
	"# # o  s    ##@        # # # #",
	"######### # ########## # # #c#",
	"#   #  o# #          # # # #c#",
	"#c# # #c# # #  o  o  # # # #c#",
	"#c# # ### # #        # # # #c#",
	"#c#ccccccc# #ccs  scc# #   #c#",
	"#c######### ########## ##### #",
	"#       o      o         #s  #",
	"########### ###### ### # #s  #",
	"# cccc    #      # #3# # ### #",
	"# #### #  ###### # #s# #o#c# #",
	"#  s2# #  s  s s #   # #c#c# e",
	"###### ############### ###c###",
	"#h     ccccccccccccccc     s1#",
	"##############################"
};

//Level 2
const unsigned char levelData2[rowCount_level_2][columsCount_level_2 + 1]{
	"################################",
	"#ccc#o      #h#        o o  o  #",
	"#ccc# ###  1#c#cc ########### 2#",
	"#   # # # ###c### #ccccccccc####",
	"#o o# # # ccccccc   s    z  #cc#",
	"#   # # #####z### #   z    4#cc#",
	"# s         ### # ###########cc#",
	"# s # #####     #o#ccc   s     #",
	"#ccc#     #     # #ccc   s s   #",
	"##### ### ## #### ########### ##",
	"#       #     z      z      z  #",
	"#c### # ######### ############ #",
	"#c#3# #     o   # #     c#ccc# #",
	"#c# # ######### # # ####c#c# # #",
	"### ########### #   #c4#c#c# # #",
	"#5#               ###cc#ccc#o#o#",
	"# ########### ### # ss ##### # #",
	"#   o       # #c# ### ##   #   #",
	"#    ###### # #c#          #####",
	"#     s   # # #c########## #z z#",
	"### ##### #      s  s    #     $",
	"#       # ### ########   # # s #",
	"# o o o #     ##ccccc##### #####",
	"#  ##   #      #c#c####        #",
	"#  ##   ###### #c#c#cc# ###### #",
	"# o o #      # #@#c#cc# #cccc# #",
	"#     ###### # ###c#cc# #cccc# #",
	"#  ## #cccc# #s    #cc# #cccc# #",
	"#  ##  cccc# ## ####  o #cccc# #",
	"# o o ###### ## z z  ###### ## #",
	"#     #ccccc  #      ### o     #",
	"#############e##################"
};

const unsigned char levelSecret[rowCount_secret][columsCount_secret + 1]{
	"###########",
	"#hcccccccc#",
	"#ccccccccc#",
	"#ccccccccc#",
	"#ccccccccc#",
	"#ccccccccc#",
	"#ccccccccc#",
	"#ccccccccc#",
	"#ccccccccc#",
	"#ccccccccc#",
	"#ccccccccc#",
	"#####$#####",
};



const unsigned char levelData3[rowCount_level_3][columsCount_level_3 + 1]{
	"#######################",
	"#         #h#      o  #",
	"# o o o o # #    o    #",
	"#           #         #",
	"#         #      o    #",
	"#  s  s   # #      o  #",
	"### #######@#### ######",
	"#  s  s   ###c   z   c#",
	"#         # #c       c#",
	"#  s   s  # #cz z z  c#",
	"######## ## ######## ##",
	"#ccccccccc# #ccccccccc#",
	"#   o  o    #c z     c#",
	"# o       # #c   z z c#",
	"#   o  o  # #c   z z c#",
	"#ccccccccc# #ccccccccc#",
	"###########e###########"
};


unsigned char GetRenderCellSymbol(unsigned char cellSymbol) {
	switch (cellSymbol) {
	case CellSymbol_Empty:     return 32;
	case CellSymbol_Wall:      return 177;
	case CellSymbol_Hero:      return 2;
	case CellSymbol_Orc:       return 2;
	case CellSymbol_Skeleton:  return 2;
	case CellSymbol_Zombie:    return 2;
	case CellSymbol_Stick:     return 47;
	case CellSymbol_Club:      return 33;
	case CellSymbol_Spear:     return 24;
	case CellSymbol_Saber:     return 108;
	case CellSymbol_Exit:      return 178;
	case CellSymbol_Coin:      return 111;
	case CellSymbol_Chain:     return 64;
	case CellSymbol_Scythe:    return 251;
	case CellSymbol_Secret:    return 177;
	}
	return '?';
}

ConsoleColor GetRenderCellSymbolColor(unsigned char cellSymbol)
{
	switch (cellSymbol) {
	case CellSymbol_Empty:     return ConsoleColor_Black;
	case CellSymbol_Wall:      return ConsoleColor_White;
	case CellSymbol_Coin:      return ConsoleColor_Yellow;
	case CellSymbol_Club:      return ConsoleColor_DarkRed;
	case CellSymbol_Hero:      return ConsoleColor_Yellow;
	case CellSymbol_Orc:       return ConsoleColor_Green;
	case CellSymbol_Skeleton:  return ConsoleColor_White;
	case CellSymbol_Zombie:    return ConsoleColor_DarkRed;
	case CellSymbol_Saber:     return ConsoleColor_Cyan;
	case CellSymbol_Exit:      return ConsoleColor_DarkRed;
	case CellSymbol_Spear:     return ConsoleColor_DarkCyan;
	case CellSymbol_Stick:     return ConsoleColor_DarkYellow;
	case CellSymbol_Chain:     return ConsoleColor_Blue;
	case CellSymbol_Scythe:    return ConsoleColor_DarkGreen;
	case CellSymbol_Secret:    return ConsoleColor_White;
	}
}