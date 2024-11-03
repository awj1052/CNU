#include <iostream>
#include "car_builder.h"
#include "car.h"
#include "kia_parts_factory.h"

int main() {
    KiaPartsFactory* kia = KiaPartsFactory::GetInstance();
    CarBuilder* car_builder_ = new CarBuilder(kia);
    std::cout << "Hello World!\n";
    auto car = car_builder_->CreateDoor()
                        .CreateWheel()
                        .CreateRoof()
                        .SetColor("red").Build();
    std::cout << "FUCK" << "\n";
    std::cout << car->GetSpec() << "\n";

    delete car;
    delete car_builder_;
    return 0;
}