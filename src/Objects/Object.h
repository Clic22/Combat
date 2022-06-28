#pragma once
#include <string>
#include <memory>

class Warrior;

class Object{
    public:
        Object(std::string name, int damage);
        virtual ~Object() = default;
        virtual int Attack(Warrior& opponent){return 0;};
        virtual int Defense(std::shared_ptr<Object> weapon){return 0;};
        std::string Name();
        int Damage();

    private :
        std::string name_;
        int damage_;
};