#include <iostream>
#include "Tree.h"
using namespace std;
int main()
{
    Tree<int> test{8,3,10,1,6,14,4,7,13};
    cout << test << '\n';
    test.pop(228);
    test.pop(7);
    cout << test << '\n';
    test.pop(14);
    cout << test << '\n';
    test.pop(3);
    cout << test << '\n';
    test.pop(8);
    cout << test << "\n\n\n";

    Tree<int> t1 {10, 7, 12, 11, 14, 6, 9, 3, 4};
    t1 = test = test;
    cout << test << "\n" << t1 << "\n";
    Tree<int> test2 = std::move(test);
    cout << test << "\n" << test2 << "\n";
//    cout << t1;
//    cout << "\n";
//    t1.lpk();
//    cout << "\n";
//    t1.lkp();
//    cout << "\n";
//    t1.klp();
//    cout << "\n";
//    Tree<int> t2 {15, 1, 3};
//    //t1.push(t2);
//    cout << t1;
//    t2.clear();
//    cout << t2 << "\n";
//    cout << t1.find(10) << '\n';
//    cout << t1.find(5) << '\n';
//    Tree<int> t3 = t1.sub_tree(6);
//    cout << t3 << '\n';
//    Tree<int> t4 (t1);
//    cout << t4 << '\n';
//    Tree<int> t5 = move(t4);
//    cout << t4 << '\n' << t5 <<"\n\n";
//
//    t5.klp();
//    cout << "\n";
//    int n = 7;
//    t5.pop(n);
//    t5.klp();
//    cout << "\n";
//    t5.push(n);
//    cout << t5 << "\n";
//
//    Tree<int> t6;
//    cout << "enter the number of items: ";
//    cin >> t6;
//    cout << t6 << "\n";

    return 0;
}
