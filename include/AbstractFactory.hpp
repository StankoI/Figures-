#pragma once
#include "FigureFromSTDIN.hpp"
#include "FigureRandom.hpp"
#include "FigureFromStream.hpp"
#include <any>

class AbstractFactory
{
private:
    using FactoriesFactory = std::function<std::unique_ptr<FigureFactory>(std::string)>;
    std::unordered_map<std::string, FactoriesFactory> factoriesFactories;

public:
    AbstractFactory();
    std::unique_ptr<FigureFactory> createFactory(std::string);
    ~AbstractFactory();
};