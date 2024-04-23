#include <iostream>

class Fraction{
private:
    int numerator; //top )
    int denminator; // bottom )

public:
    Fraction();
    Fraction(const int numerator, const int denminator);
    Fraction(const int number): Fraction(number, 1) {};
    Fraction(const double fraction);
    Fraction(const Fraction& fraction);

friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2);
friend Fraction operator+(const double number, const Fraction& fraction);
friend Fraction operator+(const Fraction& fraction, const double number);
};