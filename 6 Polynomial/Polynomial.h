#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class Polynomial
{
private:
    double *arr{};
    int length{};

    void decrease();
    explicit Polynomial(int len);
public:

    Polynomial();
    Polynomial(const double *arr, int len);
    Polynomial(const float *arr, int len);

    Polynomial(const Polynomial &pol);
    Polynomial(Polynomial &&pol) noexcept;
    Polynomial(std:: initializer_list<double>);
    ~Polynomial();

    [[nodiscard]] double at(const int &index) const;
    [[nodiscard]] double answer(const double &x) const;
    double& operator[](int index) const;

    friend Polynomial operator+(const Polynomial& pol1, const Polynomial& pol2);
    friend Polynomial operator-(const Polynomial& pol1, const Polynomial& pol2);
    friend Polynomial operator*(const Polynomial& pol1, const Polynomial& pol2);
    friend Polynomial operator/(const Polynomial& pol1, const Polynomial& pol2);
    friend Polynomial operator%(const Polynomial& pol1, const Polynomial& pol2);

    friend Polynomial operator +(const Polynomial &pol);
    friend Polynomial operator -(const Polynomial &pol);

    Polynomial& operator =(const Polynomial& pol);
    Polynomial& operator+=(const Polynomial& pol);
    Polynomial& operator-=(const Polynomial& pol);
    Polynomial& operator*=(const Polynomial& pol);
    Polynomial& operator/=(const Polynomial& pol);
    Polynomial& operator%=(const Polynomial& pol);

    friend bool operator ==(const Polynomial &pol1, const Polynomial &pol2);
    friend bool operator !=(const Polynomial &pol1, const Polynomial &pol2);
//    friend bool operator  >(const Polynomial &pol1, const Polynomial &pol2);
//    friend bool operator >=(const Polynomial &pol1, const Polynomial &pol2);
//    friend bool operator  <(const Polynomial &pol1, const Polynomial &pol2);
//    friend bool operator <=(const Polynomial &pol1, const Polynomial &pol2);

    friend std::ostream& operator<< (std::ostream& out, const Polynomial& pol);
    friend std::istream& operator>> (std::istream& in, Polynomial& pol);
};

#endif
