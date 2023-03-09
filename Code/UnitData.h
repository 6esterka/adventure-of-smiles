#pragma once
#pragma once
#include"unitType.h"
#include"WeaponType.h"

struct UnitData {
	UnitType type;
	int row;
	int column;
	int health;
	WeaponType weapon;
};