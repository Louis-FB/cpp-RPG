#pragma once
#include "Entity.h"
// #include "Monster.h"
// #include "MonsterNamespace.h"



class Player : public Entity
{
protected:
	int m_level{0};
	

public:
	Player(std::string name) : Entity{name, 20, 0, 0, 5} {};

	void addGold(int gold) {
		m_gold += gold;
	}

	void addXP(int xp) {
		m_xp += xp;
	}
	/*
	void attack(Monster& m) {
		m.setCurrentHp(this->getAttack());
	}
	*/
};