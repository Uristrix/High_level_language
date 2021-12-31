#include <iostream>
#include "Polynomial.h"
int main()
{
    float arr[]{-3, -22, 23, -10, 2};
    Polynomial pol0;
    Polynomial pol1(arr, 5);
    Polynomial pol2{1, 0, 0, 0, 0, 1};
    Polynomial pol3({1, 0, 0, 1});

    std:: cout << pol0 << '\n';
    std:: cout << pol1 << '\n';
    std:: cout << pol2 << '\n';
    std:: cout << pol3 << "\n\n";

    Polynomial cop = std::move(pol1);

    std:: cout << pol1 << '\n';
    std:: cout << cop << "\n\n";

    std:: cout << pol3 + pol2 << '\n';
    std:: cout << pol3 - pol2 << '\n';
    std:: cout << pol3 * pol2 << '\n';
    std:: cout << pol3 / pol2 << '\n';
    std:: cout << pol3 % pol2 << "\n\n";
    std:: cout << pol2 / pol3 << '\n';
    std:: cout << pol2 % pol3 << '\n';

    std:: cout << -pol3<< '\n';
    std:: cout << +pol3<< "\n\n";


    std:: cout << Polynomial{3} % pol3 << "\n\n";

    std:: cout << pol2 << '\n';
    pol2[0] = 1;
    std:: cout << pol2 << '\n';
    std:: cout << pol2.at(0) << '\n';
    std:: cout << pol2.answer(2) << "\n\n";

    std:: cout << (cop == pol3) << '\n';
    //std:: cout << (pol2 > pol3) << '\n';
//    Polynomial in;
//    std:: cin >> in;
//    std:: cout << in << '\n';

    return 0;
}
