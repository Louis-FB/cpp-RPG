#pragma once
#include <vector>
#include "Entity.h"
#include "PotionNamespace.h"
// #include "Monster.h"
// #include "MonsterNamespace.h"



class Player : public Entity
{
protected:
	int m_level{0};
	std::vector<PotionNamespace::Type> m_inventory{};
	int m_potionEffect{};
	

public:
	Player(std::string name) : Entity{name, 20, 0, 0, 5} {};

	void addGold(int gold) {
		m_gold += gold;
	}

	void addXP(int xp) {
		m_xp += xp;
	}

	void addPotion(PotionNamespace::Type potion) {
		m_inventory.emplace_back(potion);
	}

	void assignPotion(PotionNamespace::Type potion) {
		m_potionEffect = static_cast<int>(potion); // Pass as enum, assign single potion as int
	}

	std::vector<PotionNamespace::Type>& getInventory() {
		return m_inventory;
	}

	int getPotionEffect() { return m_potionEffect; }

	void removePotion() {
		m_potionEffect = -1; // Remove potion effect
	}

	/*
	void attack(Entity& monster) { // Or put in base
		m.setCurrentHp(this->getAttack());
	}
	*/

	void attack(Entity& monster) override { 
		monster.setCurrentHp(this->getAttack());
	}

};