#include <iostream>
#include <string>
//#include <map>
#include "map.h"
using namespace std;

int main() try {
    map<string, int> test;
    test.insert({"Alexandr", 5});
    test.insert({"Sanya   ", 4});
    test.insert({"Sanychek", 3});
    for(const auto& it: test)
        cout << it.first << '\t' << it.second << '\n';

    auto pop = test.find("Sanya   ");
    auto dead = test.erase(pop);
    cout << '\n' << dead->first << "\t" << dead->second << "\n\n";

    for(const auto& it: test)
        cout << it.first << '\t' << it.second << '\n';

    test["Afanasyev"] = 10;

    cout << "\n";
    for(const auto& it: test)
        cout << it.first << '\t' << it.second << '\n';

    test.at("Afanasyev") = 5;

    cout << test.at("Afanasyev") << "\n";
    for(const auto& it: test)
        cout << it.first << '\t' << it.second << '\n';
//
    cout << '\n' << test.value("kek", 69) << '\n';

    cout << test.toJSON() << '\n';
    return 0;
}
catch (logic_error &ex) { cerr << ex.what(); }