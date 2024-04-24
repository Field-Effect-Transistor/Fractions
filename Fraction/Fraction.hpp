#include <iostream>

//convert Fraction<int> to Fraction
// oerator-(void, Fraction)'
// operator!(void, Fraction)
// operator bool()

namespace dev{
    template<typename T>
    class Fraction{
    protected:
        T numerator;
        T denominator;
    public:
        Fraction(): Fraction(0, 1) {};
        Fraction(int number): Fraction(number, 1) {};
        Fraction(const T& numerator, const T& denominator);
        Fraction(double number);
        Fraction(const Fraction<T>& fraction): Fraction(fraction.numerator, fraction.denominator) {};


        T getNumerator(void)const { return numerator;}
        T getDenominator(void)const { return denominator;}
        void setNumerator(T numerator){ this->numerator = numerator;}
        void setDenominator(T denominator){ this->denominator = denominator;}

        T getGCD(T a, T b)const;
        T getLCM(T a, T b)const;

        //operator double(void) const {return (double)numerator / denominator;}
        
        template<typename U>
        friend std::ostream& operator<<(std::ostream& out, const Fraction<U>& fraction);
        template<typename U>
        friend std::istream& operator>>(std::istream& in, Fraction<U>& fraction);

        template<typename U>
        friend Fraction<U> operator+(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend Fraction<U> operator+(const Fraction<U>& fraction, const double number) { return fraction + Fraction<U>(number); };
        template<typename U>
        friend Fraction<U> operator+(const double number, const Fraction<U>& fraction) { return Fraction<U>(number) + fraction; };

        template<typename U>
        friend Fraction<U> operator-(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend Fraction<U> operator-(const Fraction<U>& fraction, const double number) { return fraction - Fraction<U>(number); };
        template<typename U>
        friend Fraction<U> operator-(const double number, const Fraction<U>& fraction) { return Fraction<U>(number) - fraction; };

        template<typename U>
        friend Fraction<U> operator*(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend Fraction<U> operator*(const Fraction<U>& fraction, const double number) { return fraction * Fraction<U>(number); };
        template<typename U>
        friend Fraction<U> operator*(const double number, const Fraction<U>& fraction) { return fraction * Fraction<U>(number); };

        template<typename U>
        friend Fraction<U> operator/(const Fraction<U>& fraction1, const Fraction<U>& fraction2);
        template<typename U>
        friend Fraction<U> operator/(const Fraction<U>& fraction, const double number) { return fraction / Fraction<U>(number); };
        template<typename U>
        friend Fraction<U> operator/(const double number, const Fraction<U>& fraction) { return Fraction<U>(number) / fraction; };

        Fraction<T> operator=(const Fraction<T>& fraction);
        Fraction<T> operator+=(const Fraction<T>& fraction) { return *this = *this + fraction; };
        Fraction<T> operator-=(const Fraction<T>& fraction) { return *this = *this - fraction; };
        Fraction<T> operator*=(const Fraction<T>& fraction) { return *this = *this * fraction; }; 
        Fraction<T> operator/=(const Fraction<T>& fraction) { return *this = *this / fraction; };

        friend bool operator==(const Fraction<T>& fraction1, const Fraction<T>& fraction2) { return fraction1.numerator == fraction2.numerator && fraction1.denominator == fraction2.denominator; }
        friend bool operator!=(const Fraction<T>& fraction1, const Fraction<T>& fraction2) { return !(fraction1 == fraction2); }
        friend bool operator<(const Fraction<T>& fraction1, const Fraction<T>& fraction2) { return fraction1.numerator * fraction2.denominator < fraction2.numerator * fraction1.denominator; }
        friend bool operator>(const Fraction<T>& fraction1, const Fraction<T>& fraction2) { return fraction1.numerator * fraction2.denominator > fraction2.numerator * fraction1.denominator; }
        friend bool operator<=(const Fraction<T>& fraction1, const Fraction<T>& fraction2) { return !(fraction1 > fraction2); }
        friend bool operator>=(const Fraction<T>& fraction1, const Fraction<T>& fraction2) { return !(fraction1 < fraction2); }

    };
}