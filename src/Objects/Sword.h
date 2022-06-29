#pragma once
#include <string>
#include "Object.h"

class Sword : public Object{
    public:
        Sword();
        int Attack(Warrior& opponent, int penality) final;
        int Defense(std::shared_ptr<Object> weapon) final;
};