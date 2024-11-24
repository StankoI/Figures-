#pragma once
#include "Figure.hpp"

class Circle: public Figure
{
private:
    double radius;

private:
    void validator(double);  
public:

    Circle(double);
    explicit Circle(const std::vector<double>&);

    ~Circle() override;

    double perimeter() const override;
    std::string to_string() const override;
    Circle* clone() const override;



};