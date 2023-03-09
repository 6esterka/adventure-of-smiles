#pragma once
#include"Level1.h"
enum WeaponType {
	WeaponType_None,
	WeaponType_Fist,
	WeaponType_Stick,
	WeaponType_Club,
	WeaponType_Spear,
	WeaponType_Saber,
	WeaponType_Chain,
	WeaponType_Scythe,
};

const char* WeaponName_None = "None";
const char* WeaponName_Fist = "Fist";
const char* WeaponName_Stick = "Stick";
const char* WeaponName_Club = "Club";
const char* WeaponName_Spear = "Spear";
const char* WeaponName_Saber = "Saber";
const char* WeaponName_Scythe = "Scythe";
const char* WeaponName_Chain = "Chain";

const char* GetWeaponName(WeaponType weaponType) {
	switch (weaponType) {
	case WeaponType_Fist:       return WeaponName_Fist;
	case WeaponType_Stick:      return WeaponName_Stick;
	case WeaponType_Club:       return WeaponName_Club;
	case WeaponType_Spear:      return WeaponName_Spear;
	case WeaponType_Saber:      return WeaponName_Saber;
	case WeaponType_Chain:      return WeaponName_Chain;
	case WeaponType_Scythe:     return WeaponName_Scythe;
	}
	return WeaponName_None;
}

int GetWeaponDamage(WeaponType weaponType) {
	switch (weaponType)
	{
	case WeaponType_Fist:       return 10;
	case WeaponType_Stick:      return 26;
	case WeaponType_Club:       return 30;
	case WeaponType_Spear:      return 40;
	case WeaponType_Saber:      return 50;
	case WeaponType_Chain:      return 70;
	case WeaponType_Scythe:     return 200;
	}

	return 0;
}

WeaponType GetWeaponTypeFromCell(unsigned char cellSymbol) {
	switch (cellSymbol) {
	case CellSymbol_Stick:      return WeaponType_Stick;
	case CellSymbol_Saber:      return WeaponType_Saber;
	case CellSymbol_Club:       return WeaponType_Club;
	case CellSymbol_Spear:      return WeaponType_Spear;
	case CellSymbol_Chain:      return WeaponType_Chain;
	case CellSymbol_Scythe:     return WeaponType_Scythe;
	}
	return WeaponType_None;
}