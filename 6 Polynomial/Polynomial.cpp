#include "Polynomial.h"
#include <cmath>

Polynomial::Polynomial(int len)
{
    length = len;
    arr = new double [length];
    for(int i = 0; i < length; i++)
        arr[i] = 0;
}

Polynomial::Polynomial():length(0), arr(nullptr){}

Polynomial::Polynomial(const double *arr, int len): length(len)
{
    this -> arr = new double[length];

    for(int i = 0; i < length; i++)
        this -> arr[i] = arr[i];

    decrease();
}

Polynomial::Polynomial(const float *arr, int len): length(len)
{
    this -> arr = new double[length];

    for(int i = 0; i < length; i++)
        this -> arr[i] = arr[i];

    decrease();
}

Polynomial::Polynomial(const Polynomial &pol)
{
    *this = pol;
}

 Polynomial::Polynomial(Polynomial &&pol) noexcept
{
    *this = pol;
    pol = Polynomial();
}

Polynomial::Polynomial(std::initializer_list<double>list): length(list.size())
{
    this -> arr = new double[length];
    int i = 0;
    for(auto &el: list)
    {
        this -> arr[i] = el;
        i++;
    }

    decrease();
}

Polynomial::~Polynomial()
{
    delete [] arr;
}

double Polynomial::at(const int &index) const
{
    return arr[index];
}

double &Polynomial::operator[](int index) const
{
    return arr[index];
}

double Polynomial::answer(const double &x) const
{
    double res = 0;
    for (int i = 0; i < length; i++)
        res += arr[i] * pow(x, i);

    return res;
}

Polynomial operator+(const Polynomial& pol1, const Polynomial& pol2)
{
    Polynomial res(pol1.length > pol2.length? pol1.length: pol2.length);

    for(int i = 0; i < pol1.length; i++) res.arr[i] += pol1.arr[i];
    for(int i = 0; i < pol2.length; i++) res.arr[i] += pol2.arr[i];

    res.decrease();

    return res;
}

Polynomial operator-(const Polynomial& pol1, const Polynomial& pol2)
{
    return -pol1 + pol2;
}

Polynomial operator*(const Polynomial& pol1, const Polynomial& pol2)
{
    Polynomial res(pol1.length + pol2.length);

    for (int i = 0; i < pol1.length; i++)
        for (int j = 0; j < pol2.length; j++)
            res.arr[i + j] += pol1.arr[i] * pol2.arr[j];

    res.decrease();

    return res;
}

Polynomial operator/(const Polynomial& pol1, const Polynomial& pol2)
{
    if (pol2.length > pol1.length)
        return Polynomial();

    Polynomial temp(pol1);
    Polynomial res(pol1.length - pol2.length + 1);

    for (int i = 0; i < res.length; i++)
    {
        res.arr[res.length-i-1] = temp.arr[temp.length-i-1] / pol2.arr[pol2.length-1];
        for (int j = 0; j < pol2.length; j++)
            temp.arr[temp.length-j-i-1] -= pol2.arr[pol2.length-j-1] * res.arr[res.length-i-1];
    }
    res.decrease();

    return res;
}

Polynomial operator%(const Polynomial& pol1, const Polynomial& pol2)
{
    if(pol1.length < pol2.length)
        return pol1;

    return -(pol1 - (pol1 / pol2 * pol2));
}

Polynomial operator-(const Polynomial &pol)
{
    Polynomial copy(pol);
    for(int i = 0; i < copy.length; i++)
        copy.arr[i] = -copy.arr[i];

    return copy;
}

Polynomial operator+(const Polynomial &pol)
{
    return pol;
}



std::ostream &operator<<(std::ostream &out, const Polynomial &pol)
{
    if (pol.length == 0)
    {
        out << 0;
        return out;
    }

    for(int i = (int)pol.length - 1; i >= 0; i--)
    {
        if(pol.arr[i] != 0)
        {
            if(pol.arr[i] >= 1 && i != pol.length - 1) out << "+";
            if(pol.arr[i] == -1 && i != 0) out << "-";
            if((pol.arr[i] != 1 && pol.arr[i] != -1) || i == 0) out << pol.arr[i];
            if(i != 0) out << "X";
            if(i > 1) out << "^" << i;
        }
    }
    return out;
}

std::istream &operator>>(std::istream &in, Polynomial &pol)
{
    delete[] pol.arr;
    std::cout << "\nLength: ";
    in >> pol.length;
    std::cout << "Elements: ";

    pol.arr = new double[pol.length];
    for (int i = 0; i < pol.length; i++)
        in >> pol.arr[i];

    return in;
}

Polynomial &Polynomial::operator+=(const Polynomial &pol)
{
    *this = *this + pol;
    return *this;
}

Polynomial &Polynomial::operator=(const Polynomial &pol)
{
    if (&pol == this)
        return *this;

    delete[] arr;
    arr = new double[length = pol.length];

    for (int i = 0; i < length; i++)
        arr[i] = pol.arr[i];

    return *this;
}



Polynomial &Polynomial::operator-=(const Polynomial &pol)
{
    *this = *this - pol;
    return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &pol)
{
    *this = *this * pol;
    return *this;
}

Polynomial &Polynomial::operator/=(const Polynomial &pol)
{
    *this = *this / pol;
    return *this;
}

Polynomial &Polynomial::operator%=(const Polynomial &pol)
{
    *this = *this % pol;
    return *this;
}

bool operator==(const Polynomial &pol1, const Polynomial &pol2)
{
    if(pol1.length != pol2.length)
        return false;

    for(int i = 0; i < pol2.length; i++)
        if(pol1.arr[i] != pol2.arr[i])
            return false;

    return true;
}

bool operator!=(const Polynomial &pol1, const Polynomial &pol2)
{
    return !(pol1 == pol2);
}

//bool operator>(const Polynomial &pol1, const Polynomial &pol2)
//{
//    return pol1.answer(1) > pol2.answer(1);
//}
//
//bool operator>=(const Polynomial &pol1, const Polynomial &pol2)
//{
//    return!(pol1 < pol2);
//}
//
//bool operator<(const Polynomial &pol1, const Polynomial &pol2)
//{
//    return (pol1 > pol2);
//}
//
//bool operator<=(const Polynomial &pol1, const Polynomial &pol2)
//{
//    return!(pol1 < pol2);
//}

void Polynomial::decrease()
{
    while (length > 0 && arr[length - 1] == 0)
        length--;
}