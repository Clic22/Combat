#pragma once
#include <string>
#include "Object.h"

class Armor : public Object{
    public:
        Armor();
        int Defense(std::shared_ptr<Object> weapon, int damage) final;
};