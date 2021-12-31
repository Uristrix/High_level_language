#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix
{
protected:
    int i_m, j_m;
    double **matrix;
public:
    Matrix(double **matrix, int I, int J);
    Matrix(const double *matrix, int I, int J);
    Matrix(double matrix, int I, int J);
    Matrix(const Matrix &matrix);
    Matrix(int I, int J);
    Matrix(Matrix &&matrix) noexcept;
    ~Matrix();

    friend Matrix operator+(const Matrix &a, const Matrix &b);
    friend Matrix operator-(const Matrix &a, const Matrix &b);
    friend Matrix operator*(const Matrix &a, const Matrix &b);
    friend Matrix operator/(const Matrix &a, const Matrix &b);

    friend Matrix operator+(const double &a, const Matrix &b);
    friend Matrix operator-(const double &a, const Matrix &b);
    friend Matrix operator*(const double &a, const Matrix &b);
    friend Matrix operator/(const double &a, const Matrix &b);

    friend Matrix operator+(const Matrix &a, const double &b);
    friend Matrix operator-(const Matrix &a, const double &b);
    friend Matrix operator/(const Matrix &a, const double &b);
    friend Matrix operator*(const Matrix &a, const double &b);

    friend Matrix operator-(const Matrix &a);
    friend Matrix operator+(const Matrix &a);

    Matrix &operator=(const Matrix &a);

    Matrix &operator+=(const Matrix &a);
    Matrix &operator-=(const Matrix &a);
    Matrix &operator*=(const Matrix &a);
    Matrix &operator/=(const Matrix &a);

    Matrix &operator+=(const double &b);
    Matrix &operator-=(const double &b);
    Matrix &operator*=(const double &b);
    Matrix &operator/=(const double &b);

    double &operator()(int index1, int index2);
    double operator()(int index1, int index2) const;
    double at(int index1, int index2) const;

    friend std::ostream &operator<<(std::ostream &out, const Matrix &a);

    [[nodiscard]] Matrix make_minor(int i_begin, int i_end, int j_begin, int j_end) const;
    [[nodiscard]] double Det() const;
    [[nodiscard]] Matrix reverse() const;
    [[nodiscard]] Matrix trans() const;
};

#endif //MATRIX_H
