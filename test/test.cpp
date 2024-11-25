#include "doctest.h"
#include "TestRectangle.imp"
#include "TestCircle.imp"
#include "TestTriangle.imp"
#include "TestStringToFigure.imp"
#include "TestFigureFromStream.imp"
#include "TestRandomFigure.imp"

int main()
{
    doctest::Context().run();
    return 0;
}