#include "kia_parts_factory.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"

KiaPartsFactory* KiaPartsFactory::instance_ = nullptr;
KiaPartsFactory::KiaPartsFactory() {}
KiaPartsFactory* KiaPartsFactory::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new KiaPartsFactory();
    }
    return instance_;
}
Part* KiaPartsFactory::CreateDoor() const {
    return new Door("kia");
}
Part* KiaPartsFactory::CreateWheel() const {
    return new Wheel("kia");
}
Part* KiaPartsFactory::CreateRoof() const {
    return new Roof("kia");
}
