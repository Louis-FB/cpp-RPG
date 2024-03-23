#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "MonsterNamespace.h"
#include "PotionNamespace.h"
#include "Entity.h"
#include "Monster.h"
#include "Player.h"
#include "Random.h"

std::string getName();
void greeting(std::string_view name);
void turn(Player& player, int stage);


int main()
{
    Player player{ getName() };
    greeting(player.getName());
    int stage{0};

    while (true) { // Play game
        if (player.checkAlive())
        {
            ++stage;
            turn(player, stage); // Each battle
            if (stage == 20) {
                std::cout << "*********************\n";
                std::cout << "Congratulations! you won!\n";
                std::cout << "*********************\n";
                break;
            }
        }
        else {
            std::cout << "You have died!\n";
            break;
        }
    }
    std::cout << "Thanks for playing!\n";
}

std::string getName() {
    std::cout << "What is your name, adventurer? ";
    while (true) {
        std::string name{};
        std::getline(std::cin >> std::ws, name);

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        return name;
    }
}

void greeting(std::string_view name) {
    std::cout << "Welcome to the labyrinth of C++ RPG, " << name << '\n';
    std::cout << "You will encounter a variety of monsters.\nIf you reach stage 20, you win!\n";
}

char makeChoice() {
    char choice{};
    do
    {
        std::cin >> choice;
        return choice;
    } while (choice != 'a' && choice != 'f');
}

bool attack(Entity& attacker, Entity& defender) {
    defender.setCurrentHp(attacker.getAttack());
    // check if successful attack or not
    return true;
}

bool flee() {
    // Evaluate if successful or not
    int success{ Random::generate(0, 1) };
    return success == 1;
}

void loot(Player& p, Monster& m) {
    p.addGold(m.getGold());
    p.addXP(m.getXP());
    std::cout << "You got " << m.getGold() << " gold, and you now have " << p.getXP() << " XP\n";
    // Find potion

    PotionNamespace::Type potion{ static_cast<PotionNamespace::Type>(PotionNamespace::generatePotion()) };
    std::cout << "[You have found a " << PotionNamespace::potionName[potion] << "]\n";
    std::cout << "--Options-----------------\n";
    std::cout << "| (p) Pick up (n) Ignore |\n";
    std::cout << "--------------------------\n";
    char choice{};
    std::cin >> choice;
    if (choice == 'p')
        p.addPotion(potion);
    
    //
    std::cout << "******\n";
}

void turn(Player& p, int stage) {
    Monster m{ MonsterInfo::generateMonster() };

    std::cout << "Enter any key to continue... ";
    char cont{};
    std::cin >> cont;

    //::cout << "-----------------\n";
    std::cout << "\n[Stage " << stage << "]\n";
    std::cout << "You have encountered a " << m.getName() << "!\n";
    while (true) {
        std::cout << m.getName() << ": " << m.getCurrentHp() << '/' << m.getMaxHp() << " hp\n";
        std::cout << p.getName() << ": " << p.getCurrentHp() << '/' << p.getMaxHp() << " hp\n";
        std::cout << "--Options---------------------------- \n";
        std::cout << "| (a) Attack (f) Flee (i) Inventory |\n";
        std::cout << "------------------------------------- \n";
        char choice{ makeChoice() };
        

        // Player attack monster (if successful)
        if (choice == 'a') {
            if (attack(p, m)) {
                std::cout << "You hit the " << m.getName() << " for " << p.getAttack() << " damage!\n";
            }
            else {
                std::cout << "You missed the " << m.getName() << '\n';
            }
        }
        else if(choice == 'f') {
            if (flee()) {
                std::cout << "You successfully evaded the " << m.getName() << "!\n";
                break;
            }
            else {
                std::cout << "You failed to escape!\n";
            }
            
        }
        else if (choice == 'i') {
            // checkInventory()
            std::cout << "Opening inventory...\n";
        }

        std::cout << "******\n";

        // Monster's attack
        if (m.checkAlive()) {
            if (attack(m, p)) {
                std::cout << "The " << m.getName() << " hit you for " << m.getAttack() << " damage!\n";
            }
            else {
                std::cout << "The " << m.getName() << " attacked and missed!\n";
            }
        }
        else {
            std::cout << "The " << m.getName() << " lies dead.\n";
            loot(p, m); // randomly acquire items
            break;
        }

        if (!p.checkAlive()) {
            break;
        }
    }
}