#pragma once 
#include<string>

class StringConvertable
{
public:
    virtual std::string to_string() const = 0;
    virtual ~StringConvertable() = default;
};