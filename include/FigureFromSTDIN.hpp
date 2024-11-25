#pragma once
#include "FigureFactory.hpp"

class FigureFromSTDIN : public FigureFactory
{    
private:
    std::size_t numberOfFigures;
public:
    FigureFromSTDIN(std::size_t);
    std::unique_ptr<Figure> create() override;
    ~FigureFromSTDIN();
};