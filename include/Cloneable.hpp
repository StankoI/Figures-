#pragma once
#include <memory>
#include <functional>
#include <sstream>

class Cloneable
{
public: 
    virtual Cloneable* clone() const = 0;
};