#include "Warrior.h"

class Highlander : public Warrior{
    public:
        Highlander() : Warrior(150,"greatSword"){};
        Highlander(std::string trait) : Warrior(150,"greatSword", trait){};
};