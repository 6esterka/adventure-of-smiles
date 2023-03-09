#pragma once
#include"Level1.h"
#include"WeaponType.h"

enum UnitType
{
	UnitType_None,
	UnitType_Hero,
	UnitType_Orc,
	UnitType_Skeleton,
	UnitType_Zombie
};

const char* UnitName_None = "None";
const char* UnitName_Orc = "Orc";
const char* UnitName_Skeleton = "Skeleton";
const char* UnitName_Hero = "Zombie";
const char* UnitName_Zombie = "Hero";

const char* GetUnitName(UnitType unitType) {
	switch (unitType) {
	case UnitType_Hero:    return UnitName_Hero;
	case UnitType_Orc:     return UnitName_Orc;
	case UnitType_Skeleton:return UnitName_Skeleton;
	case UnitType_Zombie:  return UnitName_Zombie;
	}
	return UnitName_None;
}

WeaponType GetUnitDefaultWeapon(UnitType unitType) {
	switch (unitType) {
	case UnitType_Hero:        return WeaponType_Fist;
	case UnitType_Orc:         return WeaponType_Club;
	case UnitType_Skeleton:    return WeaponType_Saber;
	case UnitType_Zombie:      return WeaponType_Stick;
	}
	return WeaponType_None;
}

int GetUnitDefaultHealth(UnitType unitType) {
	switch (unitType) {
	case UnitType_Hero:      return 500;
	case UnitType_Orc:       return 100;
	case UnitType_Zombie:    return 110;
	case UnitType_Skeleton:  return 150;
	}
	return 0;
}

UnitType GetUnitTypeFromCell(unsigned char cellSymbol) {
	switch (cellSymbol) {
	case CellSymbol_Zombie:    return UnitType_Zombie;
	case CellSymbol_Hero:      return UnitType_Hero;
	case CellSymbol_Orc:       return UnitType_Orc;
	case CellSymbol_Skeleton:  return UnitType_Skeleton;
	}
	return UnitType_None;
}