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
    int a = 10;
    int b = 5;
    MethodIntegrals integral(0, PI / 2, 10);
    integral.setSidesOfFigure(a, b);
    std::cout << 4 * a * integral.centralRectangleIntegral(function) << std::endl;
    std::cout << 4 * a * integral.leftRectangleIntegral(function) << std::endl;
    std::cout << 4 * a * integral.rightRectangleIntegral(function) << std::endl;
    std::cout << 4 * a * integral.simpsonIntegral(function) << std::endl;
    std::cout << 4 * a * integral.trapezoidalIntegral(function) << std::endl;
    return 0;
}
