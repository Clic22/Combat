#pragma once
#include <string>
#include "../Object.h"

class GreatSword : public Object{
    public:
        GreatSword();
        int Attack(const Warrior& attacker,const Warrior& opponent, int penality) final;
    private:
        int attack_ = 0;
};