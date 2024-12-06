#pragma once
#include "Figure.hpp"

class Circle: public Figure
{
private:
    double radius;

private:
    void validate(double radius);  
public:

    Circle(double radius);
    explicit Circle(const std::vector<double>&);

    // ~Circle() override;

    double perimeter() const override;
    std::string to_string() const override;
    Circle* clone() const override;



};