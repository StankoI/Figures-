#include "../include/FigureFromStream.hpp"

FigureFromStream::FigureFromStream(std::istream *s) : stream(s)
{
    if (!stream || !stream->good())
    {
        throw std::ios_base::failure("Stream is not in a good state for reading.");
    }
}

std::unique_ptr<Figure> FigureFromStream::create()
{
    if (!stream)
    {
        throw std::ios_base::failure("Failed to read from stream");
    }

    if (!stream->good())
    {
        throw std::ios_base::failure("Stream is not in a good state before reading.");
    }

    StringToFigure STF;
    std::string str;

    // stream >> str;

    // std::cout << str;

    std::getline(*stream, str);

    //!
    try
    {
        return STF.stringToFigure(str);
    }
    catch (std::exception &e)
    {
        throw;
    }
}

FigureFromStream::~FigureFromStream() {};