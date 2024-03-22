#pragma once
#include "Entity.h"
#include "MonsterNamespace.h"
// #include "Player.h"

using namespace MonsterInfo;

class Monster : public Entity
{
protected:
    Type m_type{};

public:
    Monster(int monster) : m_type{static_cast<Type>(monster)}, Entity{monsterNames[monster], monsterHealth[monster], monsterXP[monster], monsterGold[monster], monsterAttack[monster] }
    {
    }

    Type getType() { return m_type; }

    /*
    void attack(Player& p) {
        p.setCurrentHp(this->getAttack());
    }
    */
};