#pragma once
#include "figure.hpp"

class Rectangle : public Figure
{
private:
    double sideA;
    double sideB;
public:
    Rectangle(double, double);
    ~Rectangle();
    
    double perimeter() const override;
    std::string to_string() const override;
    Rectangle* clone() const override;

};

