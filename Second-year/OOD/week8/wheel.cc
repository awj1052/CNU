#include "wheel.h"

Wheel::Wheel(std::string factory_name) : Part(factory_name) {}
std::string Wheel::GetInfo() const {
    return "[" + Part::factory_name() + "] Wheel"; 
}
