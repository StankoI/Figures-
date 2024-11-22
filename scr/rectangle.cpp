#include "../include/rectangle.hpp"

Rectangle::Rectangle(double a, double b)
{
    if(a <= 0 || b <= 0)
    {
        throw std::invalid_argument("Side lengths must be positive");
    }

    if(a+b > std::numeric_limits<double>::max() / 2)
    {
        throw std::overflow_error("Sum of the sides exceeds the maximum allowable value for a double");
    }

    this->sideA = a;
    this->sideB = b;
}

double Rectangle::perimeter() const
{
    return 2*(this->sideA + this->sideB);
}

std::string Rectangle::to_string() const
{
    return "rectangle "+ std::to_string(this->sideA) + " " + std::to_string(this->sideB);
}

Rectangle* Rectangle::clone() const
{
    return new Rectangle(*this);
}

Rectangle::~Rectangle(){};