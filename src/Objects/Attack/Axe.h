#pragma once
#include <string>
#include "Object.h"

class Axe : public Object{
    public:
        Axe();
        int Attack(const Warrior& attacker,const Warrior& opponent, int penality) final;
};