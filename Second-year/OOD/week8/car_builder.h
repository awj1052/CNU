#ifndef _CAR_BUILDER_H_
#define _CAR_BUILDER_H_

#include <string>
#include <assert.h>
#include "part.h"
#include "car.h"
#include "car_parts_factory.h"

class CarBuilder {
 public:
    explicit CarBuilder(const CarPartsFactory* factory);
    CarBuilder& CreateDoor();
    CarBuilder& CreateWheel();
    CarBuilder& CreateRoof();
    CarBuilder& SetColor(std::string color);
    Car* Build();
 private:
    Part* door_;
    Part* wheel_;
    Part* roof_;
    std::string color_;
    const CarPartsFactory* factory_;
};

#endif  //   _CAR_BUILDER_H_
