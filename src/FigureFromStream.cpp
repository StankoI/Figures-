#include "../include/FigureFromStream.hpp"
#include "../include/StringToFigure.hpp"


FigureFromStream::FigureFromStream(std::istream *s) : stream(s)
{
    if (!stream || !stream->good())
    {
        throw std::ios_base::failure("Stream is not in a good state for reading.");
    }
}

std::unique_ptr<Figure> FigureFromStream::create()
{
    if (!stream){throw std::ios_base::failure("Failed to read from stream");}

    std::string str;
    if(!std::getline(*stream, str)){return nullptr;}

    return StringToFigure().stringToFigure(str);
}

FigureFromStream::~FigureFromStream() 
{
    delete this->stream;
}