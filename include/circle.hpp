#pragma once
#include "figure.hpp"

class Circle: public Figure
{
private:
    double radius;

public:

    Circle(double);
    ~Circle() override;

    double perimeter() const override;
    std::string to_string() const override;
    Circle* clone() const override;

};