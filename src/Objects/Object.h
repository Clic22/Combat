#pragma once
#include <string>

class Object{
    public:
        Object(std::string name, int damage);
        std::string Name();
        int Damage();

    private:
        std::string name_;
        int damage_;
};