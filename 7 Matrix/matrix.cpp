#include <cmath>
#include "matrix.h"

Matrix::Matrix(int I, int J):i_m(I), j_m(J)
{
    matrix = new double* [i_m];
    for(int i = 0; i < i_m; i++)
        matrix[i] = new double [j_m];
}

Matrix::Matrix(double **matrix, int I, int J): Matrix(I, J)
{
    for(int i = 0; i < i_m; i++)
        for (int j = 0; j < j_m; j++)
            this -> matrix[i][j] = matrix[i][j];
}

Matrix::Matrix(const double *matrix, int I, int J): Matrix(I, J)
{
    for(int i = 0; i < i_m; i++)
        for (int j = 0; j < j_m; j++)
            this -> matrix[i][j] = matrix[i * j_m + j];
}

Matrix::Matrix(double matrix, int I, int J): Matrix(I, J)
{
    for(int i = 0; i < i_m; i++)
        for (int j = 0; j < j_m; j++)
            this -> matrix[i][j] = matrix;
}

Matrix::Matrix(const Matrix &matrix):i_m(0), j_m(0), matrix(nullptr)
{
    *this = matrix;
}

Matrix::Matrix(Matrix &&matrix) noexcept: Matrix(matrix)
{
    matrix = Matrix(0.0, 1, 1);
}

Matrix::~Matrix()
{
    for(int i = 0; i < i_m; i++)
        delete[] matrix[i];
    delete[] matrix;
}


Matrix operator+(const Matrix &a, const Matrix &b)
{
    Matrix res(0.0, a.i_m, a.j_m);
    if(a.i_m != b.i_m || a.j_m != b.j_m)
        return res;

    for (int i = 0; i < res.i_m; i++)
        for(int j = 0; j < res.j_m; j++)
            res.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];

    return res;
}

Matrix operator-(const Matrix &a, const Matrix &b)
{
    return -b + a;
}

Matrix operator*(const Matrix &a, const Matrix &b)
{
    Matrix res(0.0, a.i_m, b.j_m);
    if(a.i_m != b.j_m)
        return res;

    for(int i = 0; i < res.i_m; i++)
        for(int j = 0; j < res.j_m; j++)
        {
            double sum = 0;
            for(int k = 0; k< a.j_m; k++)
                sum += a.matrix[i][k] * b.matrix[k][j];

            res.matrix[i][j] = sum;
        }
    return res;
}

Matrix operator/(const Matrix &a, const Matrix &b)
{
    return (b.Det() == 0 ? Matrix(0.0, 1, 1): a * b.reverse());
}

Matrix operator+(const double &a, const Matrix &b)
{
    return Matrix(a, 1, 1) + b;
}

Matrix operator-(const double &a, const Matrix &b)
{
    return Matrix(a, 1, 1) - b;
}

Matrix operator*(const double &a, const Matrix &b)
{
    Matrix res(b);
    for(int i = 0; i < res.i_m; i++)
        for (int j = 0; j < res.j_m; j++)
            res.matrix[i][j] *= a;
    return res;
}

Matrix operator/(const double &a, const Matrix &b)
{
    return  (b.Det() == 0 ? Matrix(0.0, 1, 1): b.reverse() * a);
}


Matrix operator+(const Matrix &a, const double &b)
{
    return b + a;
}

Matrix operator-(const Matrix &a, const double &b)
{
    return -b + a;
}

Matrix operator*(const Matrix &a, const double &b)
{
    return b * a;
}

Matrix operator/(const Matrix &a, const double &b)
{
    return (b == 0? Matrix(0.0,1,1): a * (1/b));
}

Matrix operator-(const Matrix &a)
{
    Matrix res(a);
    for(int i = 0; i < a.i_m; i++)
        for(int j = 0; j < a.j_m; j++)
            res.matrix[i][j] = -a.matrix[i][j];

    return res;
}

Matrix operator+(const Matrix &a)
{
    return Matrix(a);
}

Matrix &Matrix::operator=(const Matrix &a) {
    if(this != &a)
    {
        for(int i = 0; i < i_m; i++)
            delete[] matrix[i];
        delete[] matrix;

        matrix = new double *[i_m = a.i_m];
        for (int i = 0; i< i_m; i++)
        {
            matrix[i] = new double [j_m = a.j_m];
            for (int j = 0; j < j_m; j++)
                matrix[i][j] = a.matrix[i][j];
        }
    }
    return *this;
}


Matrix &Matrix::operator+=(const Matrix &a)
{
    *this = *this + a;
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &a)
{
    *this = *this - a;
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &a)
{
    *this = *this * a;
    return *this;
}

Matrix &Matrix::operator/=(const Matrix &a)
{
    *this = *this / a;
    return *this;
}


Matrix &Matrix::operator+=(const double &b)
{
    *this = *this + b;
    return *this;
}

Matrix &Matrix::operator-=(const double &b)
{
    *this = *this - b;
    return *this;
}

Matrix &Matrix::operator*=(const double &b)
{
    *this = *this * b;
    return *this;
}

Matrix &Matrix::operator/=(const double &b)
{
    *this = *this / b;
    return *this;
}

double &Matrix::operator()(int index1, int index2)
{
    return matrix[index1][index2];
}

double Matrix::operator()(int index1, int index2) const
{
    return matrix[index1][index2];
}

double Matrix::at(int index1, int index2) const
{
    return matrix[index1][index2];
}

std::ostream &operator<<(std::ostream &out, const Matrix &a)
{
    for(int i = 0; i < a.i_m; i++)
    {
        for(int j = 0; j < a.j_m; j++)
            out << a.matrix[i][j] << "\t";

        out << '\n';
    }

    return out;
}

Matrix Matrix::trans() const
{
    Matrix res(j_m,i_m);
    for(int i = 0; i < i_m; i++)
        for(int j = 0; j < j_m; j++)
            res.matrix[j][i] = matrix[i][j];

    return res;
}

Matrix Matrix::make_minor(int i_begin, int i_end, int j_begin, int j_end) const
{
//    if(i_begin > i_end || j_begin > j_end ||
//    i_begin < 0 || j_begin < 0 || i_end > i_m - 1 || j_end > j_m - 1 ||
//    (i_end - i_begin + 1) == i_m || (j_end - j_begin + 1) == j_m) return Matrix(0.0, 1, 1);

    Matrix res(i_m - (i_end - i_begin),j_m - (j_end - j_begin));

    for (int i = 0, iminor = 0; i < i_m; i++)
    {
        if (i >= i_begin && i < i_end) continue;
        for (int j = 0, jminor = 0; j < j_m; j++)
        {
            if (j >= j_begin && j < j_end) continue;
            res.matrix[iminor][jminor] = matrix[i][j];
            jminor++;
        }
        iminor++;
    }
    return res;
}

double Matrix::Det() const
{
    if(i_m != j_m) return 0;
    if (i_m == 1) return matrix[0][0];
    if (i_m == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    for (int i = 0; i < i_m; i++)
        det += (i % 2 ? -1: 1) * matrix[0][i] * make_minor(0,1, i, i + 1).Det();

    return det;
}

Matrix Matrix::reverse() const
{
    if((i_m != j_m) || Det() == 0) return Matrix(0.0, 0, 0);

    Matrix res(i_m, j_m);
    for(int i = 0; i < i_m; i++)
        for(int j = 0; j < j_m; j++)
            res.matrix[i][j] = (pow(-1,(i+j+1)) == 1 ? -1: 1) * make_minor(i,i+1,j,j+1).Det();

    res = res.trans();

    return (1/Det())*res;
}