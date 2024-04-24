#include "Fraction.hpp"

namespace dev{
    template <typename T>
    Fraction<T>::Fraction(const T& numerator, const T& denominator){
        if(denominator == 0){
            throw std::invalid_argument("Denominator cannot be 0");
        }
        T gcd = getGCD(numerator, denominator);
        
        this->numerator = numerator / gcd;
        this->denominator = denominator / gcd;

        if(this->denominator < 0){
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    template <typename T>
    T Fraction<T>::getGCD(T a, T b)const{
        if(a == 0 && b == 0){
            throw std::invalid_argument("Zero Values");
        }
        T temp;
        while(b != 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    template <typename T>
    T Fraction<T>::getLCM(T a, T b)const{
        if(a == 0 && b == 0){
            throw std::invalid_argument("Zero Values");
        }
        return a / getGCD(a, b) * b;
    }

    template <typename T>
    Fraction<T>::Fraction(double number){
        T denominator = 1;
        T numerator = (T)number;

        bool SF = false;
        if(number < 0) {
            SF = true;
            number *= -1;
        }

        while(number - numerator > 0){
            number *= 10;
            numerator = (T)number;
            denominator *= 10;
        }

        T gcd = getGCD(numerator, denominator);
        this->denominator = denominator / gcd;
        this->numerator = (SF ? -numerator : numerator) / gcd;
    }
}