#pragma once
#include <string>
#include "Object.h"

class Armor : public Object{
    public:
        Armor();
        int Attack(Warrior& opponent, int penality) final;
        int Defense(std::shared_ptr<Object> weapon) final;
};