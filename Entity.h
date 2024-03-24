#pragma once
#include <string_view>


class Entity
{
protected:
    std::string m_name{};
    int m_maxHp{};     // Total HP
    int m_currentHp{}; // HP after sustaining damage
    int m_xp{};        // XP points
    int m_gold{};      // gold
    int m_attack{};    // attack damage
    
public:
    Entity(std::string name, int maxHp = 0, int xp = 0, int gold = 0, int attack = 0)
        : m_name{ name }
        , m_maxHp{ maxHp }
        , m_currentHp{ maxHp }
        , m_xp{ xp }
        , m_gold{ gold }
        , m_attack{ attack }
    {
    };

    std::string& getName() { return m_name; }

    bool checkAlive() { return m_currentHp > 0; } // Return true if current HP > 0

    int getAttack() { return m_attack; }

    int getGold() { return m_gold; }
    
    int getMaxHp() { return m_maxHp; }

    int getXP() { return m_xp; }

    int getCurrentHp() { return m_currentHp; }

    void setCurrentHp(int hp) { m_currentHp -= hp; };

    //virtual void attack() = 0;
     // Parameter is the attacker (or is target), is pure virtual and assigned by derived?
    
    virtual void attack(Entity& enemy) = 0;
    
    
};