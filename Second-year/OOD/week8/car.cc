#include "car.h"

std::string Car::GetSpec() const {
    std::string parts[4];
    if (door_ != nullptr) {
        parts[0] = door_->GetInfo();
    } else {
        parts[0] = "";
    }
    if (wheel_ != nullptr) {
        parts[1] = wheel_->GetInfo();
    } else {
        parts[1] = "";
    }
    if (roof_ != nullptr) {
        parts[2] = roof_->GetInfo();
    } else {
        parts[2] = "";
    }
    parts[3] = color_;
    std::string result = "";
    for (int i = 0; i < 4; i++) {
        if (parts[i] == "") continue;
        if (result != "") {
            result += ", ";
        }
        result += parts[i];
    }
    return "Car(" + result + ")";
}
Car::Car(const Car& car) : color_(car.color_) {
    if (car.door_ != nullptr) {
        door_ = new Door(car.door_->factory_name());
    }
    if (car.wheel_ != nullptr) {
        wheel_ = new Wheel(car.wheel_->factory_name());
    }
    if (car.roof_ != nullptr) {
        roof_ = new Roof(car.roof_->factory_name());
    }
}
Car& Car::operator=(const Car& car) {
    delete door_;
    delete wheel_;
    delete roof_;
    if (car.door_ != nullptr) {
        door_ = new Door(car.door_->factory_name());
    } else {
        door_ = nullptr;
    }
    if (car.wheel_ != nullptr) {
        wheel_ = new Wheel(car.wheel_->factory_name());
    } else {
        wheel_ = nullptr;
    }
    if (car.roof_ != nullptr) {
        roof_ = new Roof(car.roof_->factory_name());
    } else {
        roof_ = nullptr;
    }
    color_ = car.color_;
    return *this;
}
Car::~Car() {
    delete door_;
    delete wheel_;
    delete roof_;
}
Car::Car(Part* door, Part* wheel, Part* roof, std::string color) :
    door_(door),
    wheel_(wheel),
    roof_(roof),
    color_(color) {}
