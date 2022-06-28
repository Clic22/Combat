#pragma once
#include <string>
#include "Object.h"

constexpr int MAX_DURABILITY = 3;
constexpr int DAMAGE = 0;

class Buckler : public Object{
    public:
        Buckler();
        int Attack(Warrior& opponent) final;
        int Defense(std::shared_ptr<Object> weapon) final;
    private:
        int durability_ = MAX_DURABILITY;
        bool block_ = true;
};