#pragma once
#include <string>
#include "Object.h"

constexpr int MAX_DURABILITY = 3;
constexpr int DAMAGE = 0;

class Buckler : public Object{
    public:
        Buckler();
        int Defense(std::shared_ptr<Object> weapon, int damage) final;
    private:
        int durability_ = MAX_DURABILITY;
        bool block_ = true;
};