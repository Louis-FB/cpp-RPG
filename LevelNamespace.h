#pragma once
#include <array>

namespace Level {

	constexpr int maxLevel{ 10 };

	std::array<int, maxLevel> lvlAttack{ 9, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	std::array<int, maxLevel> lvlHp{ 9, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	std::array<int, maxLevel> xpRequirements{ 0, 40, 60, 80, 90, 120, 150, 190, 220, 300 };
}