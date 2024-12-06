#include "../include/FigureFromSTDIN.hpp"
#include "../include/StringToFigure.hpp"

FigureFromSTDIN::FigureFromSTDIN(std::size_t f):numberOfFigures(f){}

FigureFromSTDIN::~FigureFromSTDIN(){}

std::unique_ptr<Figure> FigureFromSTDIN::create()
{
    if(numberOfFigures <= 0)
    {
        return nullptr;
    }
    
    std::cout << ">";
    std::string str;
    
    std::getline(std::cin ,str);
  
    auto figure = StringToFigure().stringToFigure(str);
    numberOfFigures--;
    return figure;
}