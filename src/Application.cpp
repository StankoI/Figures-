#include "../include/Application.hpp"
#include <iostream>
#include <fstream>

//НАЙ-ГНУСНИЯТ ФАЙЛ В ЦЕНИЯ ПРОЕКТ

Application::Application()
{
    commands["list"] = [](std::string str, std::vector<std::unique_ptr<Figure>>& v)
    {
        for(const auto& fig: v)
        {
            std::cout << fig->to_string();
            std::cout << '\n';
        }
    };

    commands["clone"] = [](std::string str, std::vector<std::unique_ptr<Figure>>& v)
    {
        std::stringstream stream(str);
        int ind = 0;
        
        if(!(stream >> ind))
        {
            throw std::invalid_argument("invalind index");
        }
        
        if(ind < 0 || ind > v.size())
        {
            throw std::invalid_argument("invalind index");
        }

        v.push_back(std::unique_ptr<Figure>(v[ind]->clone()));

    };

    commands["delete"] = [](std::string str, std::vector<std::unique_ptr<Figure>>& v)
    {
        std::stringstream stream(str);
        int ind = 0;
        
        if(!(stream >> ind))
        {
            throw std::invalid_argument("invalind index");
        }
        
        if(ind < 0 || ind > v.size())
        {
            throw std::invalid_argument("invalind index");
        }

        v.erase(v.begin() + ind);
    };

    commands["save"] = [](std::string str, std::vector<std::unique_ptr<Figure>>& v)
    {
        std::ofstream file(str);

        if(!file)
        {
            throw std::runtime_error("failed to open " + str);
        }

        for(const auto& fig: v)
        {
            file << fig->to_string();
            file << '\n';
        }

    };
}
Application::~Application() {}

std::string getCreationTypeAndParams()
{
    std::string creationType = "";

    while (creationType != "random" && creationType != "stdin" && creationType != "stream")
    {
        std::cout << ">";
        std::cin >> creationType;
        if (creationType != "random" && creationType != "stdin" && creationType != "stream")
        {
            std::cout << "unknown creation type plese try again!\n";
        }
    }

    if (creationType == "random")
    {
        std::cout << "please write the number of figures that you want to create\n";
        int a = 0;
        while (a <= 0)
        {
            std::cout << ">";
            std::cin >> a;
            if (a <= 0)
            {
                std::cout << "number of figures should be positive, please try again!\n";
            }
        }

        creationType += ' ' + std::to_string(a);
    }
    else if (creationType == "stdin")
    {
        std::cout << "please write the number of figures that you want to create\n";
        int a = 0;
        while (a <= 0)
        {
            std::cout << ">";
            std::cin >> a;
            if (a <= 0)
            {
                std::cout << "number of figures should be positive, please try again!\n";
            }
        }

        creationType += ' ' + std::to_string(a);
    }
    else //(creationType == "stream")
    {
        std::cout << "please write the name of the file that you want to create figures from\n";
        std::string a = "";
        while (a == "")
        {
            std::cout << ">";
            std::cin >> a;
            if (a == "" )
            {
                std::cout << "empty string, please try again!\n";
            }
        }

        creationType += ' ' +  a;
    }
    std::cin.ignore();
    return creationType;
}

void writeOpening()
{
    std::cout << "Hello please choose method for creating figures\n";
    std::cout << "random: creates random figures\n";
    std::cout << "stdin: creates figures from stdin\n";
    std::cout << "stream: creates figures from file\n";
}

void Application::start()
{
    writeOpening();

    std::string creationType = getCreationTypeAndParams();

    AbstractFactory AF;
    std::unique_ptr<FigureFactory> factory;
    try{
        factory = AF.createFactory(creationType); 
    }
    catch(std::exception& e)
    {
        throw;
    }

    while(true)
    {
        
        try{
            std::unique_ptr<Figure> f = factory->create();
            if(f == nullptr)
            {
                break;
            }
            figures.push_back(std::move(f));
            std::cout << "figure created\n";

        }
        catch(std::exception& e)
        {
            std::cerr << "error " << e.what() << std::endl;
        }
    }

    std::cout << "all figures were created\n";

    std::string currCommand = "";

    while(currCommand != "exit")
    {   
        std::string par;
        std::cout << ">";
        // std::getline(std::cin, currCommand);
        std::cin >> currCommand;



        if(currCommand == "exit")
        {
            std::cout << "goodbye\n";
            break;
        }

        if(commands.find(currCommand) == commands.end())
        {
            std::cerr << "command does not exist\n";
            continue;
        }

        std::cin >> par;

        commands.at(currCommand)(par,this->figures);

    }
    
}