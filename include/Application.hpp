#pragma once
#include "AbstractFactory.hpp"

class Application
{
private:
    std::vector<std::unique_ptr<Figure>> figures;

    using Commands = std::function<void(std::string,std::vector<std::unique_ptr<Figure>>&)>;
    std::unordered_map<std::string,Commands> commands;

public:

    Application();
    ~Application();
    
    void start();

};
