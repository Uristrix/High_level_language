#ifndef SLAU_H
#define SLAU_H
#include "matrix.h"
#include "vector"

class SLAU : public Matrix
{
public:
    SLAU(int I);
    SLAU(double value, int I);
    SLAU(double *value, int I);
    SLAU(double **value, int I);
    SLAU(const SLAU &slau);
    SLAU(SLAU &&slau) noexcept;
    [[nodiscard]] std::vector<double> Kramer() const;
    [[nodiscard]] std::vector<double> Gaus() const;
    [[nodiscard]] std::vector<double> Iteration() const;
};

#endif //SLAU_H
