#ifndef METHODINTEGRALS_H
#define METHODINTEGRALS_H


class MethodIntegrals
{
public:
    MethodIntegrals(double lowerLimit, double upperLimit, int numberOfsplits);
    void changeLimits(double lowerLimit, double upperLimit, int numberOfsplits);
    void setSidesOfFigure(float a, float b);
    float trapezoidalIntegral(float (*function)(float, float, float));
    float rightRectangleIntegral(float (*function)(float, float, float));
    float leftRectangleIntegral(float (*function)(float, float, float));
    float centralRectangleIntegral(float (*function)(float, float, float));
    float simpsonIntegral(float (*function)(float, float, float));

private:
    float m_sideA;
    float m_sideB;
    double m_lowerLimit;
    double m_upperLimit;
    int m_numberOfsplits;

};

#endif // METHODINTEGRALS_H
