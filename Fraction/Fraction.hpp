#include <iostream>

namespace dev{
    template<typename T = long>
    class Fraction{
    protected:
        T numerator;
        T denominator;
    public:
        Fraction(const T& numerator, const T& denominator);
        Fraction(double number);

        T getNumerator(void)const { return numerator;}
        T getDenominator(void)const { return denominator;}
        void setNumerator(T numerator){ this->numerator = numerator;}
        void setDenominator(T denominator){ this->denominator = denominator;}

        T getGCD(T a, T b)const;
        T getLCM(T a, T b)const;

        
    };
}