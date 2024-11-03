#include "hyundai_parts_factory.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"

HyundaiPartsFactory* HyundaiPartsFactory::instance_ = nullptr;
HyundaiPartsFactory::HyundaiPartsFactory() {}
HyundaiPartsFactory* HyundaiPartsFactory::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new HyundaiPartsFactory();
    }
    return instance_;
}
Part* HyundaiPartsFactory::CreateDoor() const {
    return new Door("hyundai");
}
Part* HyundaiPartsFactory::CreateWheel() const {
    return new Wheel("hyundai");
}
Part* HyundaiPartsFactory::CreateRoof() const {
    return new Roof("hyundai");
}
