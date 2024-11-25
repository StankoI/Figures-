#include "../include/FigureFromStream.hpp"

FigureFromStream::FigureFromStream(std::fstream& s):stream(s){}

std::unique_ptr<Figure> FigureFromStream::create()
{
    if(!stream)
    {
        throw std::ios_base::failure("Failed to read from stream");
    }

    StringToFigure STF;
    std::string str;

    std::getline(stream, str);

    try{
        return STF.stringToFigure(str);
    }
    catch(std::exception& e)
    {
        throw;
    }
}

FigureFromStream::~FigureFromStream(){};