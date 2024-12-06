#include "../include/FigureRandom.hpp"
#include "../include/StringToFigure.hpp"


FigureRandom::FigureRandom(std::size_t a) : numberOfFigures(a)
{
    figureInfo[0] = {"circle", 1};
    figureInfo[1] = {"rectangle", 2};
    figureInfo[2] = {"triangle", 3};
}

std::string FigureRandom::paramsToString(std::vector<double> par)
{
    std::string res;
    for (double a : par)
    {
        res += std::to_string(a) + " ";
    }

    return res;
}

FigureRandom::~FigureRandom() {}

void FigureRandom::createRandomParams(std::vector<double>& params, size_t numOfPars)
{
    for (std::size_t i = 0; i < numOfPars; i++)
    {
        params.push_back(double(rand() % 50 / 10. + 5));
    }
}

std::string FigureRandom::createRandomFigure()
{
    int randomIndex = rand() % figureInfo.size();
    FigureData data = figureInfo.at(randomIndex);
    
    std::vector<double> params;
    createRandomParams(params,data.paramsCount);

    std::string figureStr = data.type + ' ' + paramsToString(params);
    return figureStr;
}


std::unique_ptr<Figure> FigureRandom::create()
{
    if (this->numberOfFigures == 0)
    {
        return nullptr;
    }

    std::unique_ptr<Figure> ptr = StringToFigure().stringToFigure(createRandomFigure());
    this->numberOfFigures--;
    return ptr;
}