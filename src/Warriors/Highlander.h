#include "Warrior.h"

class Highlander : public Warrior{
    public:
        Highlander();
        explicit Highlander(const std::string& trait);
};