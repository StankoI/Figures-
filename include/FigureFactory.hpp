#pragma once
// #include "StringToFigure.hpp"
#include "Figure.hpp"

class FigureFactory
{
public:
    virtual std::unique_ptr<Figure> create() = 0;
    virtual ~FigureFactory() = default;
};