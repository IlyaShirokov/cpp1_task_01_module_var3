#include "methodintegrals.h"

MethodIntegrals::MethodIntegrals(double lowerLimit, double upperLimit, int numberOfsplits) :
    m_lowerLimit(lowerLimit), m_upperLimit(upperLimit), m_numberOfsplits(numberOfsplits)
{
    m_sideA = 1;
    m_sideB = 1;
}

void MethodIntegrals::changeLimits(double lowerLimit, double upperLimit, int numberOfsplits)
{
    m_lowerLimit = lowerLimit;
    m_upperLimit = upperLimit;
    m_numberOfsplits = numberOfsplits;
}

void MethodIntegrals::setSidesOfFigure(float a, float b)
{
    m_sideA = a;
    m_sideB = b;
}

float MethodIntegrals::trapezoidalIntegral(float (*function)(float, float, float))
{
    const double width = (m_upperLimit - m_lowerLimit) / m_numberOfsplits;

    double trapezoidal_integral = 0;
    for(int step = 0; step < m_numberOfsplits; step++)
    {
        double x1 = m_lowerLimit + step*width;
        double x2 = m_lowerLimit + (step+1)*width;

        trapezoidal_integral += 0.5*(x2-x1)*(function(m_sideA, m_sideB, x1) + function(m_sideA, m_sideB, x2));
    }

    return trapezoidal_integral;
}

float MethodIntegrals::rightRectangleIntegral(float (*function)(float, float, float))
{
    const double width = (m_upperLimit - m_lowerLimit) / m_numberOfsplits;

    double rectangle_integral = 0;
    for(int step = 0; step < m_numberOfsplits; step++)
    {
        double x1 = m_lowerLimit + step*width;
        double x2 = m_lowerLimit + (step+1)*width;

        rectangle_integral += (x2 - x1) * function(m_sideA, m_sideB, x2);
    }

    return rectangle_integral;
}

float MethodIntegrals::leftRectangleIntegral(float (*function)(float, float, float))
{
    const double width = (m_upperLimit - m_lowerLimit) / m_numberOfsplits;

    double rectangle_integral = 0;
    for(int step = 0; step < m_numberOfsplits; step++)
    {
        double x1 = m_lowerLimit + step*width;
        double x2 = m_lowerLimit + (step+1)*width;

        rectangle_integral += (x2 - x1) * function(m_sideA, m_sideB, x1);
    }

    return rectangle_integral;
}

float MethodIntegrals::centralRectangleIntegral(float (*function)(float, float, float))
{
    const double width = (m_upperLimit - m_lowerLimit) / m_numberOfsplits;

    double rectangle_integral = 0;
    for(int step = 0; step < m_numberOfsplits; step++)
    {
        double x1 = m_lowerLimit + step*width;
        double x2 = m_lowerLimit + (step+1)*width;

        rectangle_integral += (x2 - x1) * function(m_sideA, m_sideB, (x2 + x1) / 2);
    }

    return rectangle_integral;
}

float MethodIntegrals::simpsonIntegral(float (*function)(float, float, float))
{
    const double width = (m_upperLimit - m_lowerLimit) / m_numberOfsplits;

    double simpson_integral = 0;
    for(int step = 0; step < m_numberOfsplits; step++)
    {
        const double x1 = m_lowerLimit + step*width;
        const double x2 = m_lowerLimit + (step+1)*width;

        simpson_integral += (x2-x1)/6.0*(function(m_sideA, m_sideB, x1) + 4.0*function(m_sideA, m_sideB, 0.5*(x1+x2)) + function(m_sideA, m_sideB, x2));
    }

    return simpson_integral;
}
