#pragma once
#include <string>
#include <memory>

class Warrior;

class Trait{
    public:
        explicit Trait(const std::string& name);
        virtual ~Trait() = default;
        virtual int BonusAttack(int damage,const Warrior& attacker){return damage;};
        std::string Name() const;

    private :
        std::string name_;
};