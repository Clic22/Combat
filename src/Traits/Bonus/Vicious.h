#pragma once
#include <string>
#include "Trait.h"

constexpr int maxBlow = 2;
constexpr int bonusDamage = 20;

class Vicious : public Trait{
    public:
        Vicious();
        int BonusAttack(int damage,const Warrior& opponent) final;
    private: 
        int blows = 0;
};