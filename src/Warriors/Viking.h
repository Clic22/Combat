#include "Warrior.h"

class Viking : public Warrior{
    public:
        Viking() : Warrior(120,Object("axe",6)){};
};