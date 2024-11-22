#include "../include/circle.hpp"

Circle::Circle(double r)
{ 
    if (r <= 0)
    {
        throw std::invalid_argument("Radius lengths must be positive");
    }

    const double pi = 3.14;

    if (2 * r * pi > std::numeric_limits<double>::max())
    {
        throw std::overflow_error("Radius is too big");
    }

    this->radius = r;
}

double Circle::perimeter() const
{
    const double pi = 3.14;
    return 2 * pi * this->radius;
}

std::string Circle::to_string() const
{
    return "circle " + std::to_string(this->radius);
}

Circle* Circle::clone() const
{
    return new Circle(*this);
}

Circle::~Circle(){}