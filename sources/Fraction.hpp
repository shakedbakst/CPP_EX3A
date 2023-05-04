#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;
namespace ariel{}
class Fraction{

     private:
        int numerator;
        int denominator;

    public:
        // Constructors
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(float number);
        Fraction(const Fraction& other);    //copy constructor

        //help function
        void reduce();
        int getGCD(int numerator, int denominator);

        // Getters and Setters
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator_);
        void setDenominator(int denominator_);
        
        //arithmetic operators
        Fraction operator+(const Fraction& other) const;
        Fraction operator+(const float& other) const;

        Fraction operator-(const Fraction& other) const;
        Fraction operator-(const float& other) const;

        Fraction operator*(const Fraction& other) const;
        Fraction operator*(const float& other) const;

        Fraction operator/(const Fraction& other) const;
        Fraction operator/(const float& other) const;

        //comparison operators
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;

        //increment and decrement methods
        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        //arithmetic operators: float operator fraction
        friend Fraction operator + (const float& num, const Fraction& fraction) {
            return Fraction();
        }
        friend Fraction operator - (const float& num, const Fraction& fraction) {
            return Fraction();
        }
        friend Fraction operator * (const float& num, const Fraction& fraction) {
            return Fraction();
        }
        friend Fraction operator / (const float& num, const Fraction& fraction) {
            return Fraction();
        }
        

    
        friend std::ostream& operator<<(std::ostream& oss, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& iss, const Fraction& fraction);
        
};

#endif






