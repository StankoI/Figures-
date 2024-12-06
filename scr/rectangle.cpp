#include "../include/Rectangle.hpp"

void Rectangle::validate(double a, double b)
{
    if(a <= 0 || b <= 0){throw std::invalid_argument("Side lengths must be positive");}
    if(a+b > std::numeric_limits<double>::max() / 2){ throw std::overflow_error("Sum of the sides exceeds the maximum allowable value for a double");}
}

Rectangle::Rectangle(double a, double b)
{    
    validate(a,b);

    this->sideA = a;
    this->sideB = b;
}

Rectangle::Rectangle(const std::vector<double>& v)
{
    if(v.size() != 2)
    {
        throw std::invalid_argument("number of arguments is invalid");
    }

    validate(v[0],v[1]);
    
    this->sideA = v[0];
    this->sideB = v[1];
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
