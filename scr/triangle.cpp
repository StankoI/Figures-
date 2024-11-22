#include "../include/triangle.hpp"

Triangle::Triangle(double a, double b, double c)
{

    if (a <= 0 || b <= 0 || c <= 0)
    {
        throw std::invalid_argument("Side lengths must be positive");
    }

    if (a + b > std::numeric_limits<double>::max() - c)
    {
        throw std::overflow_error("Sum of the sides exceeds the maximum allowable value for a double");
    }

    if (a + b <= c || c + a <= b || b + c <= a)
    {
        throw std::invalid_argument("The length of one side cannot be greater than or equal to the sum of the other two sides");
    }

    this->sideA = a;
    this->sideB = b;
    this->sideC = c;
}

double Triangle::perimeter() const
{
    return this->sideA + this->sideB + this->sideC;
}

std::string Triangle::to_string() const
{
    return "triangle " + std::to_string(this->sideA) + " " + std::to_string(this->sideB) + " " + std::to_string(this->sideC);
}

Triangle* Triangle::clone() const
{
    return new Triangle(*this);
}

Triangle::~Triangle() {}