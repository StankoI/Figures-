#pragma once
#include "FigureFactory.hpp"
#include <fstream>

class FigureFromStream : public  FigureFactory
{
private:
    std::fstream& stream;
public:
    FigureFromStream(std::fstream& s);
    ~FigureFromStream();
    std::unique_ptr<Figure> create() override;
};