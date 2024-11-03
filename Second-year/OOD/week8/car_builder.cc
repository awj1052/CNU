#include "car_builder.h"

CarBuilder::CarBuilder(const CarPartsFactory* factory) :
    door_(nullptr),
    wheel_(nullptr),
    roof_(nullptr),
    factory_(factory) {
}
CarBuilder& CarBuilder::CreateDoor() {
    assert(door_ == nullptr && "Duplicated Parts retain : Door");
    door_ = factory_->CreateDoor();
    return *this;
}
CarBuilder& CarBuilder::CreateWheel() {
    assert(wheel_ == nullptr && "Duplicated Parts retain : Wheel");
    wheel_ = factory_->CreateWheel();
    return *this;
}
CarBuilder& CarBuilder::CreateRoof() {
    assert(roof_ == nullptr && "Duplicated Parts retain : Roof");
    roof_ = factory_->CreateRoof();
    return *this;
}
CarBuilder& CarBuilder::SetColor(std::string color) {
    color_ = color;
    return *this;
}
Car* CarBuilder::Build() {
    Car* newCar = new Car(door_, wheel_, roof_, color_);
    door_ = nullptr;
    wheel_ = nullptr;
    roof_ = nullptr;
    color_ = "";
    return newCar;
}
