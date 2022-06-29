#pragma once
#include <string>
#include "Object.h"

class GreatSword : public Object{
    public:
        GreatSword();
        int Attack(Warrior& opponent, int penality) final;
        int Defense(std::shared_ptr<Object> weapon) final;
    private:
        int attack_ = 0;
};