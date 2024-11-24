#pragma once 
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "StringConvertable.hpp"
#include "Cloneable.hpp"

class Figure : public StringConvertable, public Cloneable
{ 
public:
    virtual double perimeter() const = 0;
    virtual ~Figure() = default;
    virtual Figure* clone() const  override = 0;
};
