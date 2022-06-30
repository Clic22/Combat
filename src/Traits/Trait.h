#pragma once
#include <string>
#include <memory>

class Warrior;

class Trait{
    public:
        Trait(std::string name);
        virtual ~Trait() = default;
        virtual int BonusAttack(int damage, Warrior& attacker){return damage;};
        std::string Name();

    private :
        std::string name_;
};