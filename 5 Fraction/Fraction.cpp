#include "Fraction.h"
#include <iostream>
#include <string>

Fraction::Fraction(): num(0), den(1){}

Fraction::Fraction(const Fraction& obj)
{
    this -> num = obj.num;
    this -> den = obj.den;
}

Fraction::Fraction(int num, int den)
{
    if(den > 0)
    {
        this -> num = num;
        this -> den = den;
    }
    else if(den < 0)
    {
        this -> num = -num;
        this -> den = -den;
    }
    else exit(0);
    reduction();
}

Fraction& Fraction::operator=(const Fraction& obj)
{
    if(&obj != this)
    {
        num = obj.num;
        den = obj.den;
    }
    return *this;
}

Fraction& Fraction::operator=(const int x)
{
    num = x;
    den = 1;
    return *this;
}

Fraction operator + (const Fraction& obj)
{
    return obj;
}

Fraction operator - (const Fraction& obj)
{
    return Fraction(-obj.num, obj.den);
}

Fraction& Fraction::operator+=(Fraction& obj)
{
    *this= *this + obj;
    return *this;
}

Fraction& Fraction::operator-=(Fraction& obj)
{
    *this = *this - obj;
    return *this;
}

Fraction& Fraction::operator*=(Fraction& obj)
{
    *this = *this * obj;
    return *this;
}

Fraction& Fraction::operator/=(Fraction& obj)
{
    *this = *this / obj;
    return *this;
}

Fraction& Fraction::operator+=(int x)
{
    *this = *this + x;
    return *this;
}

Fraction& Fraction::operator-=(int x)
{
    *this = *this - x;
    return *this;
}

Fraction& Fraction::operator*=(int x)
{
    *this = *this * x;
    return *this;
}

Fraction& Fraction::operator/=(int x)
{
    *this = *this / x;
    return *this;
}

Fraction::operator float() const
{
    return (float)num/den;
}

Fraction::operator double() const
{
    return (double)num/den;
}

Fraction operator+(const Fraction& obj1, const Fraction& obj2)
{
    return Fraction(obj1.num * obj2.den + obj2.num * obj1.den, obj1.den * obj2.den );
}

Fraction operator+(const Fraction& obj, const int x)
{
    return Fraction(obj.num + x * obj.den, obj.den);
}

Fraction operator+(const int x, const Fraction& obj)
{
    return Fraction(obj.num + x * obj.den, obj.den);
}

Fraction operator-(const Fraction& obj1, const Fraction& obj2)
{
    return Fraction(obj1.num * obj2.den - obj2.num * obj1.den, obj1.den * obj2.den);
}

Fraction operator-(const Fraction& obj, const int x)
{
    return Fraction(obj.num - x * obj.den, obj.den);
}

Fraction operator-(const int x, const Fraction& obj)
{
    return Fraction(x * obj.den, obj.den) - obj;
}

Fraction operator * (const Fraction& obj1, const Fraction& obj2)
{
    return Fraction(obj1.num * obj2.num, obj1.den * obj2.den);
}

Fraction operator*(const Fraction& obj, const int x)
{
    return Fraction(obj.num * x, obj.den);
}

Fraction operator*(const int x, const Fraction& obj)
{
    return Fraction(obj.num * x, obj.den);
}

Fraction operator/(const Fraction& obj1, const Fraction& obj2)
{
    return Fraction(obj1.num * obj2.den, obj1.den * obj2.num);
}

Fraction operator/(const Fraction& obj, const int x)
{
    return Fraction(obj.num * 1, obj.den * x);
}

Fraction operator/(const int x, const Fraction& obj)
{
    return Fraction(obj.den * x, obj.num * 1);
}

bool operator==(const Fraction &drob1, const Fraction &drob2)
{
    return(drob1.num==drob2.num && drob1.den==drob2.den);
}
bool operator!=(const Fraction &drob1, const Fraction &drob2)
{
    return!(drob1==drob2);
}
bool operator> (const Fraction &drob1, const Fraction &drob2)
{
    return((drob1.num*drob2.den)>(drob2.num*drob1.den));
}
bool operator>=(const Fraction &drob1, const Fraction &drob2)
{
    return!(drob1<drob2);
}
bool operator< (const Fraction &drob1, const Fraction &drob2)
{
    return (drob2>drob1);
}
bool operator<=(const Fraction &drob1, const Fraction &drob2)
{
    return!(drob2<drob1);
}

bool operator==(int a, const Fraction &drob2)
{
    return(a*drob2.den == drob2.num);
}
bool operator!=(int a, const Fraction &drob2)
{
    return!(a==drob2);
}
bool operator> (int a, const Fraction &drob2)
{
    return(a*drob2.den > drob2.num);
}
bool operator>=(int a, const Fraction &drob2)
{
    return!(a<drob2);
}
bool operator< (int a, const Fraction &drob2)
{
    return(drob2>a);
}
bool operator<=(int a, const Fraction &drob2)
{
    return!(drob2<a);
}


bool operator==(const Fraction &drob1, int b)
{
    return(b*drob1.den == drob1.num);
}
bool operator!=(const Fraction &drob1, int b)
{
    return!(b==drob1);
}
bool operator> (const Fraction &drob1, int b)
{
    return(drob1.den*b > drob1.num);
}
bool operator>=(const Fraction &drob1, int b)
{
    return!(drob1<b);
}
bool operator< (const Fraction &drob1, int b)
{
    return(b>drob1);
}
bool operator<=(const Fraction &drob1, int b)
{
    return!(b>drob1);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
    if(obj.den==1||obj.num==0) return os<<obj.num;
    else return os<< obj.num<<'/'<<obj.den;
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
    std::string str;
    is >> str;
    if(str.find('/') != -1)
    {
        obj.num = std::stoi(str.substr(0, str.find('/')));
        obj.den = std::stoi(str.substr(str.find('/') + 1));
    }
    else
    {
        obj.num = std::stoi(str);
        obj.den = 1;
    }
    obj.reduction();
    return is;
}

void Fraction::reduction()
{
    for(int i=den; i>0; i--)
        if(num%i==0 && den%i==0)
        {
            num/=i;
            den/=i;
        }
}