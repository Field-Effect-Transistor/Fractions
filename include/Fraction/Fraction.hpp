#include <iostream>
#include <vector>
#include <sstream>
#include <string>

namespace dev{
    template<typename T>
    class Fraction{
    protected:
        T numerator;
        T denominator;
    public:
        Fraction(): Fraction(0, 1) {};
        Fraction(const T& numerator, const T& denominator) {
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
        Fraction(double number) {
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
        Fraction(const Fraction<T>& fraction): Fraction(fraction.numerator, fraction.denominator) {};


        T getNumerator(void)const { return numerator;}
        T getDenominator(void)const { return denominator;}
        void setNumerator(T numerator){ this->numerator = numerator;}
        void setDenominator(T denominator){ this->denominator = denominator;}

        /**
         * Calculates the greatest common divisor (GCD) of two numbers.
         *
         * @param a the first number
         * @param b the second number
         *
         * @return the GCD of the two numbers
         *
         * @throws std::invalid_argument if both a and b are zero
         */
        T getGCD(T a, T b)const {
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
        T getLCM(T a, T b)const {
            if(a == 0 && b == 0){
                throw std::invalid_argument("Zero Values");
            }
            return a / getGCD(a, b) * b;
        }

        //operator double(void) const {return (double)numerator / denominator;}
        //operator bool(void) const {return this->numerator != 0;}
        
        template<typename U>
        friend std::ostream& operator<<(std::ostream& out, const Fraction<U>& fraction) {
            if(fraction.denominator == 1)
                return out << fraction.numerator;
            return out << fraction.numerator << '/' << fraction.denominator;
        }
        template<typename U>
        friend std::istream& operator>>(std::istream& in, Fraction<U>& fraction) {
            std::vector<std::string> tokens;
            size_t prev = 0, pos;
            std::string str;
            std::string delimiters = " /"; // роздільники: пробіл та "/"

            std::getline(in, str); // отримати ввідний рядок

            while(tokens.size() <= 2) {
                while ((pos = str.find_first_of(delimiters, prev)) != std::string::npos) {
                    if (pos > prev) {
                        tokens.push_back(str.substr(prev, pos-prev));
                    }
                    prev = pos + 1;
                }
                if (prev < str.length()) {
                    tokens.push_back(str.substr(prev, std::string::npos));
                }
            }

            U numerator, denominator;
            std::istringstream(tokens[0]) >> numerator;
            std::istringstream(tokens[1]) >> denominator;
            fraction = Fraction<U>(numerator, denominator);
            return in;
        }

        template<typename U>
        friend Fraction<U> operator+(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return Fraction<U>(
                fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator,
                fraction1.denominator * fraction2.denominator
            );
        }
        template<typename U>
        friend Fraction<U> operator+(const Fraction<U>& fraction, const double number) {
            return fraction + Fraction<U>(number);
        };
        template<typename U>
        friend Fraction<U> operator+(const double number, const Fraction<U>& fraction) {
            return Fraction<U>(number) + fraction;
        };

        template<typename U>
        friend Fraction<U> operator-(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return Fraction<U>(
                fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator,
                fraction1.denominator * fraction2.denominator
            );
        }
        template<typename U>
        friend Fraction<U> operator-(const Fraction<U>& fraction, const double number) {
            return fraction - Fraction<U>(number);
        };
        template<typename U>
        friend Fraction<U> operator-(const double number, const Fraction<U>& fraction) {
            return Fraction<U>(number) - fraction;
        };

        template<typename U>
        friend Fraction<U> operator*(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return Fraction<U>(
                fraction1.numerator * fraction2.numerator,
                fraction1.denominator * fraction2.denominator
            );
        }
        template<typename U>
        friend Fraction<U> operator*(const Fraction<U>& fraction, const double number) {
            return fraction * Fraction<U>(number);
        };
        template<typename U>
        friend Fraction<U> operator*(const double number, const Fraction<U>& fraction) {
            return fraction * Fraction<U>(number);
        };

        template<typename U>
        friend Fraction<U> operator/(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return Fraction<U>(
                fraction1.numerator * fraction2.denominator,
                fraction1.denominator * fraction2.numerator
            );
        }
        template<typename U>
        friend Fraction<U> operator/(const Fraction<U>& fraction, const double number) {
            return fraction / Fraction<U>(number);
        };
        template<typename U>
        friend Fraction<U> operator/(const double number, const Fraction<U>& fraction) {
            return Fraction<U>(number) / fraction;
        };

        Fraction<T> operator=(const Fraction<T>& fraction) {
            this->numerator = fraction.numerator;
            this->denominator = fraction.denominator;
            return *this;
        }
        Fraction<T> operator=(const double number) {
            return (*this = Fraction<T>(number));
        }
        Fraction<T> operator+=(const Fraction<T>& fraction) {
            return *this = *this + fraction;
        }
        Fraction<T> operator+=(const double number) {
            return *this += Fraction<T>(number);
        }
        Fraction<T> operator-=(const Fraction<T>& fraction) {
            return *this = *this - fraction;
        }
        Fraction<T> operator-=(const double number) {
            return *this -= Fraction<T>(number);
        }
        Fraction<T> operator*=(const Fraction<T>& fraction) {
            return *this = *this * fraction;
        }
        Fraction<T> operator*=(const double number) {
            return *this *= Fraction<T>(number);
        }
        Fraction<T> operator/=(const Fraction<T>& fraction) {
            return *this = *this / fraction;
        }
        Fraction<T> operator/=(const double number) {
            return *this /= Fraction<T>(number);
        }

        template<typename U>
        friend bool operator==(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return fraction1.numerator == fraction2.numerator && fraction1.denominator == fraction2.denominator;
        }
        template<typename U>
        friend bool operator==(const Fraction<U>& fraction, const double number) {
            return fraction == Fraction<U>(number);
        }
        template<typename U>
        friend bool operator==(const double number, const Fraction<U>& fraction) {
            return Fraction<U>(number) == fraction;
        }

        template<typename U>
        friend bool operator!=(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return !(fraction1 == fraction2);
        }
        template<typename U>
        friend bool operator!=(const Fraction<U>& fraction, const double number) {
            return fraction != Fraction<U>(number);
        }
        template<typename U>
        friend bool operator!=(const double number, const Fraction<U>& fraction) {
            return Fraction<U>(number) != fraction;
        }

        template<typename U>
        friend bool operator<(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return fraction1.numerator * fraction2.denominator < fraction2.numerator * fraction1.denominator;
        }
        template<typename U>
        friend bool operator<(const Fraction<U>& fraction, const double number) {
            return fraction < Fraction<U>(number);
        }
        template<typename U>
        friend bool operator<(const double number, const Fraction<U>& fraction) {
            return Fraction<U>(number) < fraction;
        }

        template<typename U>
        friend bool operator>(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return fraction1.numerator * fraction2.denominator > fraction2.numerator * fraction1.denominator;
        }
        template<typename U>
        friend bool operator>(const Fraction<U>& fraction, const double number) {
            return fraction > Fraction<U>(number);
        }
        template<typename U>
        friend bool operator>(const double number, const Fraction<U>& fraction)  {
            return Fraction<U>(number) > fraction;
        }

        template<typename U>
        friend bool operator<=(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return !(fraction1 > fraction2);
        }
        template<typename U>
        friend bool operator<=(const Fraction<U>& fraction, const double number) {
            return fraction <= Fraction<U>(number);
        }
        template<typename U>
        friend bool operator<=(const double number, const Fraction<U>& fraction) {
            return Fraction<U>(number) <= fraction;
        }

        template<typename U>
        friend bool operator>=(const Fraction<U>& fraction1, const Fraction<U>& fraction2) {
            return !(fraction1 < fraction2);
        }
        template<typename U>
        friend bool operator>=(const Fraction<U>& fraction, const double number) {
            return fraction >= Fraction<U>(number);
        }
        template<typename U>
        friend bool operator>=(const double number, const Fraction<U>& fraction) {
            return Fraction<U>(number) >= fraction;
        }

        template<typename U>
        friend bool operator!(const Fraction<U>& fraction) {
            return fraction.numerator == 0; 
        }

        template<typename U>
        friend Fraction<U> operator-(const Fraction<U>& fraction) {
            return Fraction<U>(-fraction.getNumerator(), fraction.getDenominator());
        }
    };
}