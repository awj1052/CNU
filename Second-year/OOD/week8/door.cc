#include "door.h"

Door::Door(std::string factory_name) : Part(factory_name) {}
std::string Door::GetInfo() const {
    return "[" + Part::factory_name() + "] Door"; 
}
