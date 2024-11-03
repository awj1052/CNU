#ifndef _PART_H_
#define _PART_H_

#include <string>

class Part {
 public:
    explicit Part(std::string factory_name);
    virtual std::string GetInfo() const = 0;
    std::string factory_name() const;
 private:
    const std::string factory_name_;
};

#endif   // _PART_H_
