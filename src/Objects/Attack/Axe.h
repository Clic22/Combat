#pragma once
#include <string>
#include "Object.h"

class Axe : public Object{
    public:
        Axe();
        int Attack(Warrior& attacker, Warrior& opponent, int penality) final;
};