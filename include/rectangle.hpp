#pragma once
#include "Figure.hpp"

class Rectangle : public Figure
{
private:
    double sideA;
    double sideB;
private:
    void validate(double sideA, double sideB);
public:
    Rectangle(double sideA, double sideB);
    explicit Rectangle(const std::vector<double>&);

    double perimeter() const override;
    std::string to_string() const override;
    Rectangle* clone() const override;

};

