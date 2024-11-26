#include "../include/AbstractFactory.hpp"
#include <filesystem>

AbstractFactory::AbstractFactory()
{
    factoriesFactories["random"] = [](std::string a)
    {
        try
        {
            std::stringstream stream(a);
            std::size_t num;
            stream >> num;

            return std::make_unique<FigureRandom>(num);
        }
        catch (std::exception &e)
        {
            throw std::invalid_argument("Invalid argument for FigureRandom creation: " + std::string(e.what()));
        }
    };

    factoriesFactories["stdin"] = [](std::string a)
    {
        try
        {
            std::stringstream stream(a);
            std::size_t num;
            stream >> num;
            return std::make_unique<FigureFromSTDIN>(num);
        }
        catch (std::exception &e)
        {
            throw std::invalid_argument("Invalid argument for FigureFromSTDIN creation: " + std::string(e.what()));
        }
    };

    factoriesFactories["stream"] = [](std::string a)
    {
        if (!std::filesystem::exists(a))
        {
            std::ofstream outFile(a);
            if (!outFile)
            {
                throw std::invalid_argument("Failed to create file: " + a);
            }

            outFile << "triangle 3 4 5\n";
            outFile.close();
        }

        try
        {
            std::ifstream* is = new std::ifstream(a);
            if (!is->is_open())
            {
                throw std::invalid_argument("Failed to open file: " + a);
            }

            return std::make_unique<FigureFromStream>(is); 
        }
        catch (std::exception &e)
        {
            throw std::invalid_argument("Invalid argument for FigureFromStream creation: " + std::string(e.what()));
        }
    };
}

std::unique_ptr<FigureFactory> AbstractFactory::createFactory(std::string factoryInfo)
{
    std::stringstream stream(factoryInfo);

    std::string factoryType;
    std::string par;

    stream >> factoryType;
    stream >> par;

    if (factoriesFactories.find(factoryType) == factoriesFactories.end())
    {
        throw std::invalid_argument("factory type does not exist");
    }

    return factoriesFactories.at(factoryType)(par);
}

AbstractFactory::~AbstractFactory() {}