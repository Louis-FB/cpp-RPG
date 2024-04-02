#pragma once
#include <vector>
#include "Entity.h"
#include "PotionNamespace.h"
#include "LevelNamespace.h"
// #include "Monster.h"
// #include "MonsterNamespace.h"



class Player : public Entity
{
protected:
	int m_level{0};
	std::vector<PotionNamespace::Type> m_inventory{};
	int m_potionEffect{};
	

public:
	Player(std::string name) : Entity{name, Level::lvlHp[0], 0, 0, Level::lvlAttack[0] } {};

	void addGold(int gold) {
		m_gold += gold;
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

	void addPotionEffect(PotionNamespace::Type potion, int index) { // implicit conversion?
		
		m_potionEffect = static_cast<int>(potion);
		
		if (m_potionEffect == PotionNamespace::health) {
			m_currentHp = m_maxHp;
			std::cout << "**Health restored!**\n";
		}
		else {
			std::cout << "Test: potion not matched with health enum\n";
		}
			
		m_inventory.erase(m_inventory.begin() + index);
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
	int getAttack() override { 
		PotionNamespace::Type attack{};
		if (m_potionEffect == PotionNamespace::Type::strength) {
			
			removePotion();
			return m_attack + 10;
		}
		else {
			return m_attack; 
		}
	}

	void levelUp(int level) {
		
		m_level = level;
		std::cout << "**You are now level " << level << "**\n";
			m_attack = Level::lvlAttack[level];
			m_maxHp = Level::lvlHp[level];
		
	}

	void addXP(int xp) {
		m_xp += xp;
		
		if (m_level < Level::maxLevel) {
			// check if need to level up
			for (int index{ 0 }; index < Level::maxLevel; ++index) {
				if (Level::xpRequirements[index] < m_xp && Level::xpRequirements[index + 1] > m_xp) {
					if (index == m_level) {
						std::cout << "Same level\n";
						break;
					}
					else {
						this->levelUp(index);
						break;
					}
					
				}
			}
			
		}
	}

	void attack(Entity& monster) { // override keyword?
		//using namespace PotionNamespace;
		
		monster.setCurrentHp(this->getAttack());
	}

	
};