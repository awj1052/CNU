#include "part.h"

Part::Part(std:: string factory_name) : factory_name_(factory_name) {}
std::string Part::factory_name() const {
    return factory_name_;
}
