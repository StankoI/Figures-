#include "../include/FigureFromSTDIN.hpp"

FigureFromSTDIN::FigureFromSTDIN(std::size_t f):numberOfFigures(f){}

FigureFromSTDIN::~FigureFromSTDIN(){}

std::unique_ptr<Figure> FigureFromSTDIN::create()
{
    if(numberOfFigures == 0)
    {
        return nullptr;
    }
    StringToFigure STF;
    std::string str;

    std::getline(std::cin ,str);
    //!!! PITAI ok li e
    try{
        if(numberOfFigures != -1)
        {
            numberOfFigures--;
        }
        return STF.stringToFigure(str);
    }
    catch(std::exception& e)
    {
        numberOfFigures++;
        throw;
    }
}