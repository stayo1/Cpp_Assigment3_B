#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int denominator;
        int numerator;
        int max = 1000;

    public:
        // Constructors
        Fraction();
        Fraction(float);
        Fraction(int, int);

        // Auxiliary functions
        void reduction();
        void negativeTest();

        // Getter N' Setter
        int getDenominator() const;
        void setDenominator(int);
        int getNumerator() const;
        void setNumerator(int);

        // Fraction N' Fraction opertions
        Fraction operator+(const Fraction &other);
        Fraction operator-(const Fraction &other);
        Fraction operator/(const Fraction &other);
        Fraction operator*(const Fraction &other);
        Fraction operator++(int);
        Fraction operator--(int);
        Fraction &operator++();
        Fraction &operator--();

        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator>(const Fraction &other) const;

        // Fraction N' Float opertions
        Fraction operator+(float);
        Fraction operator-(float);
        Fraction operator*(float);
        Fraction operator/(float);

        friend Fraction operator+(float, const Fraction &frac);
        friend Fraction operator-(float, const Fraction &frac);
        friend Fraction operator*(float, const Fraction &frac);
        friend Fraction operator/(float, const Fraction &frac);

        friend bool operator==(float, const Fraction &frac);
        friend bool operator!=(float, const Fraction &frac);
        friend bool operator<=(float, const Fraction &frac);
        friend bool operator>=(float, const Fraction &frac);
        friend bool operator<(float, const Fraction &frac);
        friend bool operator>(float, const Fraction &frac);

        // Input N' Output
        friend std::ostream &operator<<(std::ostream &stream, const Fraction &fraction);
        friend std::istream &operator>>(std::istream &stream, Fraction &fraction);
    };
};