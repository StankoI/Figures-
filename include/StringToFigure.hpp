#pragma once
#include <memory>
#include <sstream>
#include <functional>
#include<unordered_map>
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"

class StringToFigure
{
private:

    using FigureFactories = std::function<std::unique_ptr<Figure>(const std::vector<double>&)>;
    std::unordered_map<std::string, FigureFactories> figureFactories;

public:

    StringToFigure();

    std::unique_ptr<Figure> stringToFigure(std::string) const;
};
