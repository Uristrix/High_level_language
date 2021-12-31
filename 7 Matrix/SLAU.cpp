#include "SLAU.h"
#define eps 0.000001
#include <iostream>
SLAU::SLAU(int I):Matrix(I, I+1){}
SLAU::SLAU(double value, int I):Matrix(value, I, I+1){}
SLAU::SLAU(double *value, int I):Matrix(value, I, I+1){}
SLAU::SLAU(double **value, int I):Matrix(value, I, I+1){}
SLAU::SLAU(const SLAU &slau):Matrix(slau){}
SLAU::SLAU(SLAU &&slau) noexcept:Matrix(slau){}

std::vector<double> SLAU:: Kramer() const
{
    std::vector<double> res;
    res.reserve(i_m);
    if(i_m != j_m - 1)
        return res;

    Matrix copy(i_m, i_m);
    for(int i = 0; i < i_m; i++)
        for(int j = 0; j < i_m; j++)
            copy(i,j) = matrix[i][j];

    double det = copy.Det();
    if(det == 0.0)
        return res;

    for(int i = 0; i < i_m; i++)
    {
        for(int j = 0; j < i_m; j++)
            copy(j,i) = matrix[j][j_m - 1];

        res.push_back(copy.Det() / det);
        for(int j = 0; j < i_m; j++)
            copy(j,i) = matrix[j][i];
    }
    return res;
}


std::vector<double> SLAU::Gaus() const
{
    std::vector<double> res(i_m);

    if(i_m != j_m - 1)
        return res;

    Matrix copy(i_m, j_m);
    for(int i = 0; i < i_m; i++)
        for(int j = 0; j < j_m; j++)
            copy(i,j) = matrix[i][j];

    for(int i = 0; i < i_m; i++)
    {
        for(int j = i+1; j < i_m; j++)
        {
            double temp = copy(j,i) / copy(i,i);
            for(int k = i; k < i_m; k++)
                copy(j,k) -= temp * copy(i,k);

            copy(j,i_m) -= temp * copy(i,i_m);
        }
    }
    for(int i = i_m - 1; i >= 0; i--)
    {
        double d = 0.0;
        for(int j = i + 1; j < i_m; j++)
            d += copy(i,j) * res[j];

        res[i] = (copy(i, i_m) - d) / copy(i,i);
    }

    return res;
}


std::vector<double> SLAU::Iteration() const
{
    std::vector<double> res(i_m);
    if(i_m != j_m - 1)
        return res;

    while(true)
    {
        std::vector<double> Xn(i_m,0);
        for (int i = 0; i < i_m; i++)
        {
            Xn[i] = matrix[i][i_m];
            for (int j = 0; j < i_m; j++)
                if (i != j)
                    Xn[i] -= matrix[i][j] * res[j];

            Xn[i] /= matrix[i][i];
        }
        double error = 0.0;
        for (int i = 0; i < i_m; i++)
            error += std::abs (Xn[i] - res[i]);

        if (error < eps) break;

        res = Xn;
    }
    return res;
}


