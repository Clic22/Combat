#pragma once
#include <string>
#include "Object.h"

class Sword : public Object{
    public:
        Sword();
        int Attack(Warrior& attacker, Warrior& opponent, int penality) final;
};