#include "Warrior.h"

class Swordsman : public Warrior{
    public:
        Swordsman() : Warrior(100,Object("sword",5)){};
};