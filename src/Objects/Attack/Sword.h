#pragma once
#include <string>
#include "Object.h"

class Sword : public Object{
    public:
        Sword();
        int Attack(const Warrior& attacker,const Warrior& opponent, int penality) final;
};