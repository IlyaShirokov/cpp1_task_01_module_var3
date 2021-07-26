#include <iostream>
#include <math.h>
#include <cassert>

#include "methodintegrals.h"

const float PI = 3.141592;

float function(float a, float b, float phi)
{
    assert(a >= b && "Error: a < b");
    return sqrt(1 - pow(fabs(((pow(a, 2) - pow(b, 2)) / pow(a, 2))), 2) * sin(phi));
}

int main()
{
    MethodIntegrals integral(0, PI / 2, 10);
    integral.setSidesOfFigure(10, 5);
    std::cout << 40 * integral.centralRectangleIntegral(function) << std::endl;
    std::cout << 40 * integral.leftRectangleIntegral(function) << std::endl;
    std::cout << 40 * integral.rightRectangleIntegral(function) << std::endl;
    std::cout << 40 * integral.simpsonIntegral(function) << std::endl;
    std::cout << 40 * integral.trapezoidalIntegral(function) << std::endl;
    return 0;
}
