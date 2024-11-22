#pragma once
#include <memory>

class Cloneable
{
public: 
    virtual Cloneable* clone() const = 0;
};