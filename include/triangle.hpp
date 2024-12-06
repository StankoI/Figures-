#pragma once
#include"Figure.hpp"

class Triangle: public Figure
{
private:
    double sideA;
    double sideB;
    double sideC;
private:
    void validate(double sideA,double sideB,double sideC);
public:

    Triangle(double sideA, double sideB, double sideC);
    explicit Triangle(const std::vector<double>&);

    // ~Triangle();
    
    double perimeter() const override; 
    std::string to_string() const override; 
    Triangle* clone() const override;
};
