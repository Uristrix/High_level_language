#include <iostream>
#include "SLAU.h"
#define n 5
using namespace std;
int main()
{
    int g = 1;
	auto **arr = new double *[n];
    auto **arr2 = new double *[n];
    double arr3[n][n]
            {
                    { 2, 5, 2},
                    { 1, 4, 5},
                    { 1, 3, 3},
            };

	for(int i = 0; i < n; i++)
	{
		arr[i] = new double[n];
        arr2[i] = new double[n];
		for(int j = 0; j < n; j++)
        {
            arr2[i][j] = n * n - g;
            arr[i][j] = g++;
        }
	}

	cout<<"Matrix\n\n";
	Matrix a(arr, 3, 3);
    Matrix b(arr2, 3, 3);
    Matrix c(*arr3, 3, 3);
    const Matrix one(5.6, 1, 1);
    Matrix cop(a);
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << one << "\n";
    cout << cop << "\n";
    Matrix mv = move(cop);
    cout << cop << "\n";
    cout << mv << "\n";

    cout << "Arithmetics operations\n\n";
    cout << a+b << "\n" << a-b << "\n" << a*b << "\n" << a/b << "\n\n";
    cout << one+2 << "\n" << one-2 << "\n" << a*2 << "\n" << a/2 << "\n\n";
    cout << 2+one << "\n" << 2-one << "\n" << 2*a << "\n" << 2/a << "\n\n";

    cout << "Unary\n";
	cout << -a << "\n" << +a <<"\n\n";

    cout << "override [][] and at\n\n";
    cout << one.at(0,0) << "\n";
    a(0,0) = 4;
    cout << a << "\n\n";
    a(0,0) = 1;

    cout << "submatrix\n\n";
    cout << a.make_minor(0, 1,0,0) <<"\n\n";

    cout << "revers\n\n";
    cout << c.reverse() << "\n";

//    cout << "SLAU\n\n";
//    double arr4[n][n+1]
//    {
//            {32, 2, 1, 3, 1, 43},
//            {1, 8, 3, 1, 3, 14},
//            {1, 2, 16, 3, 1, -3},
//            {1, 2, 3, 56, 1, 169},
//            {1, 2, 1, 3, 32, -19}
//    };
//    SLAU test(*arr4, n);
//
//    cout<<"Answer: ";
//    std::vector<double> kek = test.Kramer();
//    for (auto &i : kek)
//        cout << i << "\t";
//
//    cout<<"\nAnswer: ";
//    kek = test.Gaus();
//    for (auto &i : kek)
//        cout << i << "\t";
//
//    cout<<"\nAnswer: ";
//    kek = test.Iteration();
//    for (auto &i : kek)
//        cout << i << "\t";
    return 0;
}
