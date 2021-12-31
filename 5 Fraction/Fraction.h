#pragma once
#include <iostream>

class Fraction{
public:
    Fraction();
    Fraction(const Fraction& obj);
    explicit Fraction(int num, int den = 1);

    Fraction& operator = (const Fraction& obj);
    Fraction& operator = (int x);

    friend Fraction operator + (const Fraction& obj1, const Fraction& obj2);
    friend Fraction operator + (const Fraction& obj, int x);
    friend Fraction operator + (int x, const Fraction& obj);

    friend Fraction operator - (const Fraction& obj1, const Fraction& obj2);
    friend Fraction operator - (const Fraction& obj, int x);
    friend Fraction operator - (int x, const Fraction& obj);

    friend Fraction operator * (const Fraction& obj1, const Fraction& obj2);
    friend Fraction operator * (const Fraction& obj, int x);
    friend Fraction operator * (int x, const Fraction& obj);

    friend Fraction operator / (const Fraction& obj1, const Fraction& obj2);
    friend Fraction operator / (const Fraction& obj, int x);
    friend Fraction operator / (int x, const Fraction& obj);

    friend bool operator == (const Fraction& obj1, const Fraction& obj2);
    friend bool operator == (const Fraction& obj1, int x);
    friend bool operator == (int x, const Fraction& obj);

    friend bool operator != (const Fraction& obj1, const Fraction& obj2);
    friend bool operator != (const Fraction& obj, int x);
    friend bool operator != (int x, const Fraction& obj);

    friend bool operator > (const Fraction& obj1, const Fraction& obj2);
    friend bool operator > (const Fraction& obj, int x);
    friend bool operator > (int x, const Fraction& obj);

    friend bool operator < (const Fraction& obj1, const Fraction& obj2);
    friend bool operator < (const Fraction& obj, int x);
    friend bool operator < (int x, const Fraction& obj);

    friend bool operator >= (const Fraction& obj1, const Fraction& obj);
    friend bool operator >= (const Fraction& obj, int x);
    friend bool operator >= (int x, const Fraction& obj);
    friend bool operator <= (const Fraction& obj1, const Fraction& obj2);

    friend bool operator <= (const Fraction& obj, int x);
    friend bool operator <= (int x, const Fraction& obj);

    friend Fraction operator + (const Fraction& obj);
    friend Fraction operator -(const Fraction& obj);

    Fraction& operator += (Fraction& obj);
    Fraction& operator -= (Fraction& obj);
    Fraction& operator *= (Fraction& obj);
    Fraction& operator /= (Fraction& obj);
    Fraction& operator += (int x);
    Fraction& operator -= (int x);
    Fraction& operator *= (int x);
    Fraction& operator /= (int x);
    friend std::ostream& operator << (std::ostream& os, const Fraction& obj);
    friend std::istream& operator >> (std::istream& is, Fraction& obj);
    explicit operator float() const;
    explicit operator double()const;

private:
    int num, den;
    void reduction();
};