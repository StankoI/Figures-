#include "../include/StringToFigure.hpp"

StringToFigure::StringToFigure()
{
    figureFactories["triangle"] = [](const std::vector<double> &params)
    {
        try
        {
            return std::make_unique<Triangle>(params);
        }
        catch (std::exception &e)
        {
            throw std::invalid_argument("Error creating triangle: " + std::string(e.what()));
        }
    };

    figureFactories["rectangle"] = [](const std::vector<double> &params)
    {
        try
        {
            return std::make_unique<Rectangle>(params);
        }
        catch (std::exception &e)
        {
            throw std::invalid_argument("Error creating rectangle: " + std::string(e.what()));
        }
    };

    figureFactories["circle"] = [](const std::vector<double> &params)
    {
        try
        {
            return std::make_unique<Circle>(params);
        }
        catch (std::exception &e)
        {
            throw std::invalid_argument("Error creating circle: " + std::string(e.what()));
        }
    };
}

std::unique_ptr<Figure> StringToFigure::stringToFigure(std::string str) const
{
    if (str == "")
    {
        throw std::invalid_argument("empty string");
    }

    std::istringstream stream(str);

    std::string figureType;

    stream >> figureType;

    std::vector<double> params;

    double tmp;
    while (stream >> tmp)
    {                          
        params.push_back(tmp);
    }

    if (!stream.eof())
    { 
        throw std::invalid_argument("Invalid value in input string");
    }

    if (figureFactories.find(figureType) == figureFactories.end())
    {
        throw std::invalid_argument("fugure does not exist");
    }

    return figureFactories.at(figureType)(params);
}