#include "../include/FigureRandom.hpp"

FigureRandom::FigureRandom(std::size_t a):numberOfFigures(a)
{
    figureInfo[0] = {"circle",1};
    figureInfo[1] = {"rectangle",2};
    figureInfo[2] = {"triangle",3};
}

std::string FigureRandom::paramsToString(std::vector<double> par)
{
    std::string res;
    for(double a: par)
    {
        res += std::to_string(a) + " ";
    }

    return res;
}


FigureRandom::~FigureRandom(){}

std::unique_ptr<Figure> FigureRandom::create()
{
    if(this->numberOfFigures == 0)
    {
        return nullptr;
    }

    int randomIndex = rand() % figureInfo.size();
    FigureData data = figureInfo.at(randomIndex);

    std::vector<double> params;

    for(std::size_t i = 0; i < data.paramsCount; i++)
    {
        params.push_back(double(rand() % 50 / 10. + 5));
    }

    std::string figureStr = data.type + ' ' + paramsToString(params); 

    StringToFigure STF;

    std::unique_ptr<Figure> ptr;

    try{
        ptr = STF.stringToFigure(figureStr);
    }
    catch(std::exception& e)
    {
        throw;
    }
    if(this->numberOfFigures != -1)
    {
        this->numberOfFigures--;
    }
    
    return ptr;
}