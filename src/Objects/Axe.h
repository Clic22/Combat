#pragma once
#include <string>
#include "Object.h"

class Axe : public Object{
    public:
        Axe();
        int Attack(Warrior& opponent, int penality) final;
        int Defense(std::shared_ptr<Object> weapon) final;
};