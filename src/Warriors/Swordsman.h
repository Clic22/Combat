#include "Warrior.h"

class Swordsman : public Warrior{
    public:
        Swordsman(): Warrior(100,"sword"){};
        Swordsman(std::string trait): Warrior(100,"sword",trait){};
};