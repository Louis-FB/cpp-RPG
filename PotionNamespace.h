#pragma once
#include <array>
#include <string>
#include "Random.h"

namespace PotionNamespace {
	enum Type {
		health,
		strength,
		invisibility,
		max_potions
	};

	std::array<int, max_potions> potionCost{ 12, 30, 40 };
	std::array<std::string, max_potions> potionName{ "health potion", "strength potion", "invisibility potion"};

	int generatePotion() {
		return Random::generate(0, (max_potions - 1));
	}
}