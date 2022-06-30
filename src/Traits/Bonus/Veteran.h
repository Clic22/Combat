#pragma once
#include <string>
#include "Trait.h"

class Veteran : public Trait{
    public:
        Veteran();
        int BonusAttack(int damage, Warrior& attacker) final;
};