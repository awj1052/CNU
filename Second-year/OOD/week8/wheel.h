#ifndef _WHEEL_H_
#define _WHEEL_H_

#include <string>
#include "part.h"

class Wheel : public Part {
 public:
    explicit Wheel(std::string factory_name);
    std::string GetInfo() const override;
};

#endif   // _WHEEL_H_
