#pragma once
#include <array>
#include <string>
#include <iostream>
#include <cassert>
#include "Random.h"

namespace MonsterInfo
{
    enum Type
    {
        centaur,
        dragon,
        ogre,
        goblin,
        max_monsters
    };

    std::array<int, max_monsters> monsterAttack{ 6, 7, 2, 1 };                                   
    std::array<int, max_monsters> monsterHealth{ 12, 14, 4, 2 };                                 
    std::array<int, max_monsters> monsterGold{ 20, 30, 20, 30 }; 
    std::array<int, max_monsters> monsterXP{ 20, 30, 20, 30 }; 
    std::array<std::string, max_monsters> monsterNames{ "centaur", "dragon", "ogre", "goblin" }; 
    // Assert length

    // Generate monster function here, returns int from 0 to Type::max_monsters
    int generateMonster()
    {
        return Random::generate(0, (max_monsters - 1));
    }

}