#pragma once
#include"figure.hpp"

class Triangle: public Figure
{
private:
    double sideA;
    double sideB;
    double sideC;

public:

    Triangle(double, double, double);
    ~Triangle();
    
    double perimeter() const override; 
    std::string to_string() const override; 
    Triangle* clone() const override;
};
