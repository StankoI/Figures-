#include <iostream>
#include "include/AbstractFactory.hpp"
#include <fstream>
#include <string>

int main()
{   
    AbstractFactory AF;

    std::unique_ptr<FigureFactory> ptr = AF.createFactory("stream file.txt");

    std::unique_ptr<Figure> figure1 = ptr->create();

    std::cout << figure1->to_string();

    std::cout << "a";


    return 0;
}