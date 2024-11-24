#include "doctest.h"
#include "TestRectangle.imp"
#include "TestCircle.imp"
#include "TestTriangle.imp"
#include "TestStringToFigure.imp"

int main()
{
    doctest::Context().run();
    return 0;
}