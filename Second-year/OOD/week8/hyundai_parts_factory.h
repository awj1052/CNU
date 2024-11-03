#ifndef _HYUNDAI_PARTS_FACTORY_H_
#define _HYUNDAI_PARTS_FACTORY_H_

#include "car_parts_factory.h"
#include "part.h"

class HyundaiPartsFactory : public CarPartsFactory {
 public:
    static HyundaiPartsFactory* GetInstance();
    Part* CreateDoor() const override;
    Part* CreateWheel() const override;
    Part* CreateRoof() const override;
 private:
    HyundaiPartsFactory();
    static HyundaiPartsFactory* instance_;
};

#endif   // _HYUNDAI_PARTS_FACTORY_H_
