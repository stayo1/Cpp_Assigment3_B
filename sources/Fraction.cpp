#include "Fraction.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <climits>
#include <cmath>

namespace ariel
{
    // Constructors
    Fraction::Fraction()
    {
        this->denominator = 1;
        this->numerator = 1;
    }

    Fraction::Fraction(float esroni)
    {
        if (esroni == 0)
        {
            this->denominator = 1;
            this->numerator = 0;
        }

        this->numerator = (int)(esroni * max);
        this->denominator = max;
        reduction();
    }

    Fraction::Fraction(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw std ::invalid_argument("fraction with denominator = 0 is not defined");
        }
        this->denominator = denominator;
        this->numerator = numerator;
        reduction();
        negativeTest();
    }

    // Auxiliary functions
    void Fraction::reduction()
    {
        int GCD = std::__gcd(this->numerator, this->denominator);
        this->numerator = numerator / GCD;
        this->denominator = denominator / GCD;
    }

    void Fraction::negativeTest()
    {
        if ((this->denominator < 0 && this->numerator < 0) || (this->denominator < 0 && this->numerator > 0))
        {
            setDenominator((-1) * getDenominator());
            setNumerator((-1) * getNumerator());
        }
    }

    // Getter N' Setter
    int Fraction::getDenominator() const
    {
        return this->denominator;
    }

    void Fraction::setDenominator(int denominator)
    {
        this->denominator = denominator;
    }

    int Fraction::getNumerator() const
    {
        return this->numerator;
    }

    void Fraction::setNumerator(int numerator)
    {
        this->numerator = numerator;
    }

    // Fraction N' Fraction opertions
    Fraction Fraction::operator+(const Fraction &other)
    {
        long long new_deno = (long long)this->denominator * (long long)other.denominator;
        long long new_nume = (long long)this->numerator * (long long)other.denominator + (long long)this->denominator * (long long)other.numerator;
        if (new_nume > INT_MAX || new_nume < INT_MIN || new_deno > INT_MAX || new_deno < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return Fraction((int)new_nume, (int)new_deno);
    }

    Fraction Fraction::operator-(const Fraction &other)
    {
        long long new_deno = (long long)this->denominator * (long long)other.denominator;
        long long new_nume = (long long)(this->numerator * other.denominator) - (long long)(this->denominator * other.numerator);
        if (new_nume > INT_MAX || new_nume < INT_MIN || new_deno > INT_MAX || new_deno < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return Fraction((int)new_nume, (int)new_deno);
    }

    Fraction Fraction::operator/(const Fraction &other)
    {
        long long new_deno = (long long)this->denominator * (long long)other.numerator;
        long long new_nume = (long long)this->numerator * (long long)other.denominator;

        if (new_nume > INT_MAX || new_nume < INT_MIN || new_deno > INT_MAX || new_deno < INT_MIN)
            throw std::overflow_error("overflow error");

        if (new_deno == 0)
            throw std::runtime_error("fraction with denominator = 0 is not defined");

        return (Fraction((int)new_nume, (int)new_deno));
    }

    Fraction Fraction::operator*(const Fraction &other)
    {
        long long new_deno = (long long)this->denominator * (long long)other.denominator;
        long long new_nume = (long long)this->numerator * (long long)other.numerator;
        if (new_nume > INT_MAX || new_nume < INT_MIN || new_deno > INT_MAX || new_deno < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }

        return (Fraction((int)new_nume, (int)new_deno));
    }

    // Fraction++
    Fraction Fraction::operator++(int)
    {
        Fraction Tmp = *this;
        this->numerator += this->denominator;
        if (this->numerator > INT_MAX)
            throw std::overflow_error("overflow error");
        return Tmp;
    }

    // Fraction--
    Fraction Fraction::operator--(int)
    {
        Fraction Tmp = *this;
        this->numerator -= this->denominator;
        if (this->numerator < INT_MIN)
            throw std::overflow_error("overflow error");
        return Tmp;
    }

    // ++Fraction
    Fraction &Fraction::operator++()
    {
        this->numerator += this->denominator;
        if (this->numerator > INT_MAX)
            throw std::overflow_error("overflow error");
        return *this;
    }

    // --Fraction
    Fraction &Fraction::operator--()
    {
        this->numerator -= this->denominator;
        if (this->numerator < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return *this;
    }

    bool Fraction::operator==(const Fraction &other) const
    {
        float res1 = (float)(this->numerator) / (float)(this->denominator);
        float res2 = (float)(other.numerator) / (float)(other.denominator);
        if (res1 == res2)
            return true;
        return false;
    }

    bool Fraction::operator!=(const Fraction &other) const
    {
        float res1 = (float)(this->numerator) / (float)(this->denominator);
        float res2 = (float)(other.numerator) / (float)(other.denominator);
        if (res1 != res2)
            return true;
        return false;
    }

    bool Fraction::operator<=(const Fraction &other) const
    {
        float res1 = (float)(this->numerator) / (float)(this->denominator);
        float res2 = (float)(other.numerator) / (float)(other.denominator);
        if (res1 <= res2)
            return true;
        return false;
    }

    bool Fraction::operator>=(const Fraction &other) const
    {
        float res1 = (float)(this->numerator) / (float)(this->denominator);
        float res2 = (float)(other.numerator) / (float)(other.denominator);
        if (res1 >= res2)
            return true;
        return false;
    }

    bool Fraction::operator<(const Fraction &other) const
    {
        float res1 = (float)(this->numerator) / (float)(this->denominator);
        float res2 = (float)(other.numerator) / (float)(other.denominator);
        if (res1 < res2)
            return true;
        return false;
    }

    bool Fraction::operator>(const Fraction &other) const
    {
        float res1 = (float)(this->numerator) / (float)(this->denominator);
        float res2 = (float)(other.numerator) / (float)(other.denominator);
        if (res1 > res2)
            return true;
        return false;
    }

    // Fraction N' Float opertions
    Fraction Fraction::operator+(float esroni)
    {
        Fraction tmp = Fraction(esroni);
        Fraction res = tmp + *this;
        if (res.numerator > INT_MAX || res.numerator < INT_MIN || res.denominator > INT_MAX || res.denominator < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return res;
    }

    Fraction Fraction::operator-(float esroni)
    {
        Fraction tmp = Fraction(esroni);
        Fraction res = *this - tmp;
        if (res.numerator > INT_MAX || res.numerator < INT_MIN || res.denominator > INT_MAX || res.denominator < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return res;
    }

    Fraction Fraction::operator*(float esroni)
    {
        Fraction tmp = Fraction(esroni);
        Fraction res = *this * tmp;
        if (res.numerator > INT_MAX || res.numerator < INT_MIN || res.denominator > INT_MAX || res.denominator < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return res;
    }

    Fraction Fraction::operator/(float esroni)
    {
        Fraction tmp = Fraction(esroni);
        Fraction res = *this / tmp;
        if (res.numerator > INT_MAX || res.numerator < INT_MIN || res.denominator > INT_MAX || res.denominator < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return res;
    }

    Fraction operator+(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        Fraction res = tmp + frac;
        if (res.getNumerator() > INT_MAX || res.getNumerator() < INT_MIN || res.getDenominator() > INT_MAX || res.getDenominator() < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return res;
    }

    Fraction operator-(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        Fraction res = tmp - frac;
        if (res.getNumerator() > INT_MAX || res.getNumerator() < INT_MIN || res.getDenominator() > INT_MAX || res.getDenominator() < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return res;
    }

    Fraction operator*(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        Fraction res = tmp * frac;
        if (res.getNumerator() > INT_MAX || res.getNumerator() < INT_MIN || res.getDenominator() > INT_MAX || res.getDenominator() < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return res;
    }

    Fraction operator/(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        Fraction res = tmp / frac;
        if (res.getNumerator() > INT_MAX || res.getNumerator() < INT_MIN || res.getDenominator() > INT_MAX || res.getDenominator() < INT_MIN)
        {
            throw std::overflow_error("overflow error");
        }
        return res;
    }

    bool operator==(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        if (tmp == frac)
            return true;
        return false;
    }

    bool operator!=(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        if (tmp != frac)
            return true;
        return false;
    }

    bool operator<=(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        if (tmp <= frac)
            return true;
        return false;
    }

    bool operator>=(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        if (tmp >= frac)
            return true;
        return false;
    }

    bool operator<(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        if (tmp < frac)
            return true;
        return false;
    }

    bool operator>(float esroni, const Fraction &frac)
    {
        Fraction tmp = Fraction(esroni);
        if (tmp > frac)
            return true;
        return false;
    }

    // Input N' Output
    std::ostream &operator<<(std::ostream &stream, const Fraction &fraction)
    {
        stream << fraction.numerator << "/" << fraction.denominator;
        return stream;
    }

    std::istream &operator>>(std::istream &stream, Fraction &fraction)
    {
        int inumber;

        if (stream >> inumber)
        {
            if (stream >> fraction.denominator)
            {
                if (inumber > 0 && fraction.denominator < 0)
                {
                    fraction.denominator = fraction.denominator * (-1);
                    fraction.numerator = inumber * (-1);
                }

                else if (inumber < 0 && fraction.denominator < 0)
                {
                    fraction.denominator = fraction.denominator * (-1);
                    fraction.numerator = inumber * (-1);
                }

                else
                {
                    fraction.numerator = inumber;
                }
            }

            else
            {
                throw std::runtime_error("Expected two integers");
            }
        }

        else
        {
            throw std::runtime_error("Expected one number");
        }

        if (fraction.denominator == 0)
            throw std::runtime_error("fraction with denominator = 0 is not defined");

        fraction.reduction();
        return stream;
    }
}