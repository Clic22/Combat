#include "Warrior.h"

class Swordsman : public Warrior{
    public:
        Swordsman();
        explicit Swordsman(const std::string& trait);
};