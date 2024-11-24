#pragma once
#include "Figure.hpp"

class Rectangle : public Figure
{
private:
    double sideA;
    double sideB;
private:
    void validator(double, double);
public:
    Rectangle(double, double);
    explicit Rectangle(const std::vector<double>&);
    ~Rectangle();
    
    double perimeter() const override;
    std::string to_string() const override;
    Rectangle* clone() const override;

};

