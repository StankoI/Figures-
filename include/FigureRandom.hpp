#pragma once
#include "FigureFactory.hpp"

class FigureRandom : public FigureFactory
{
private:

    struct FigureData
    {
        std::string type;
        std::size_t paramsCount;
    };

private:
    std::size_t numberOfFigures;
    std::unordered_map<std::size_t, FigureData> figureInfo;
private:
    std::string paramsToString(std::vector<double>);

public:
    FigureRandom(std::size_t);
    ~FigureRandom();
    std::unique_ptr<Figure> create() override;
};