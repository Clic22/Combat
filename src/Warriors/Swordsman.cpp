#include "Swordsman.h"

constexpr int healthPoint = 100;

Swordsman::Swordsman(): Warrior(healthPoint,"sword"){};

Swordsman::Swordsman(const std::string& trait): Warrior(healthPoint,"sword",trait){};