#include "Highlander.h"

constexpr int healthPoint = 150;

Highlander::Highlander() : Warrior(healthPoint,"greatSword"){};

Highlander::Highlander(const std::string& trait) : Warrior(healthPoint,"greatSword", trait){};