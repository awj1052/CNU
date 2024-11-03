#ifndef _KIA_PARTS_FACOTRY_H_
#define _KIA_PARTS_FACOTRY_H_

#include "car_parts_factory.h"
#include "part.h"

class KiaPartsFactory : public CarPartsFactory {
 public:
    static KiaPartsFactory* GetInstance();
    Part* CreateDoor() const override;
    Part* CreateWheel() const override;
    Part* CreateRoof() const override;
 private:
    KiaPartsFactory();
    static KiaPartsFactory* instance_;
};

#endif   // _KIA_PARTS_FACOTRY_H_
