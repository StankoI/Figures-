#pragma once
#include "FigureFactory.hpp"
#include <fstream>

class FigureFromStream : public  FigureFactory
{
private:
    std::istream* stream;
public:
    FigureFromStream(std::istream* s);
    ~FigureFromStream();
    std::unique_ptr<Figure> create() override;
};