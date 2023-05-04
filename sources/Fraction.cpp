#include <iostream>
#include "Fraction.hpp"


using namespace ariel;
using namespace std;

// Constructors
Fraction::Fraction(){
    this->numerator = 0;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0 && numerator != 0) {
        throw std::invalid_argument("Denominator can't be zero");
    }
    if (denominator < 0){
        this ->numerator = -1* numerator;
        this ->denominator = -1 * denominator;
    }
    else{
        this -> numerator = numerator;
        this -> denominator = denominator;
    }
    reduce();
}

 Fraction::Fraction(float number) {
    this->numerator = 0;
    this->denominator = 1;
}

Fraction::Fraction(const Fraction& other): numerator(other.numerator), denominator(other.denominator) {}


//help function
int Fraction :: getGCD (int numerator, int denominator){
    if (numerator < 0){
        numerator = abs(numerator);
    }
    if (denominator < 0){
        denominator = abs(denominator);
    }
    if (denominator == 0){
        return numerator;
    }
    return (this -> getGCD(denominator, numerator%denominator));
}

void Fraction :: reduce(){
    int gcd = this->getGCD(this -> numerator, this -> denominator);
    this -> numerator /= gcd;
    this -> denominator /= gcd;
}



// Getters and Setters
int Fraction::getNumerator() const{
    return this->numerator;
}
int Fraction::getDenominator() const{
    return this->denominator;
}
void Fraction::setNumerator(int numerator){
    this->numerator = numerator;
}
void Fraction::setDenominator(int denominator){
    this->denominator = denominator;
}

//arithmetic operators
Fraction Fraction::operator+(const Fraction& other) const{
  return Fraction();  
} 
Fraction Fraction::operator+(const float& other) const{
  return Fraction();  
} 

Fraction Fraction::operator-(const Fraction& other) const{
    return Fraction();
}
Fraction Fraction::operator-(const float& other) const{
    return Fraction();
}

Fraction Fraction::operator*(const Fraction& other) const{
    return Fraction();
}
Fraction Fraction::operator*(const float& other) const{
    return Fraction();
}

Fraction Fraction::operator/(const Fraction& other) const{
    return Fraction();
}
Fraction Fraction::operator/(const float& other) const{
    return Fraction();
}


//comparison operators 
bool Fraction::operator==(const Fraction& other) const{
    return true;
}
bool Fraction::operator!=(const Fraction& other) const{
    return true;
}
bool Fraction::operator>(const Fraction& other) const{
    return true;
}
bool Fraction::operator>=(const Fraction& other) const{
    return true;
}
bool Fraction::operator<(const Fraction& other) const{
    return true;
}
bool Fraction::operator<=(const Fraction& other) const{
    return true;
}

//increment and decrement methods
Fraction& Fraction::operator++(){
    this -> numerator += this -> denominator;
    return *this;
}
Fraction Fraction::operator++(int){
    return Fraction();
}
Fraction& Fraction::operator--(){
    return *this;
}
Fraction Fraction::operator--(int){
    return Fraction();
}



std::ostream& operator<<(std::ostream& oss, const Fraction& fraction){
    oss << fraction.getNumerator() << "/" << fraction.getDenominator();
    return oss;
}
std::istream& operator>>(std::istream& iss, const Fraction& fraction){
    return iss;
}







