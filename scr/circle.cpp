#include "../include/Circle.hpp"

void Circle::validator(double r)
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
}

Circle::Circle(double r)
{ 
    try{
        validator(r);
    }
    catch(std::exception &e)
    {
        throw;
    }

    this->radius = r;
}

Circle::Circle(const std::vector<double>& v)
{
    if(v.size() != 1)
    {
        throw std::invalid_argument("number of arguments is invalid");
    }

    try
    {
        validator(v[0]);
    }
    catch(const std::exception& e)
    {
        throw;
    }

    this->radius = v[0];
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