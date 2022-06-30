#pragma once
#include <string>
#include "../Object.h"

class GreatSword : public Object{
    public:
        GreatSword();
        int Attack(Warrior& attacker, Warrior& opponent, int penality) final;
    private:
        int attack_ = 0;
};