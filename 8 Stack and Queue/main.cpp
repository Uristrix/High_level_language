#include <iostream>
#include "queue.h"
#include <chrono>
#include <stack>
#include <queue>
#define num 10000
using namespace std;
class student
{
    string name;
    int mark{};
public:
    student() = default;
    student(string Name, int Mark):name(Name), mark(Mark){}
    friend ostream& operator<<(std::ostream& out, const student &student)
    {
        out<< "Student: "<< student.name << "; His mark: " << student.mark << ";";
        return out;
    }
};

int main() try
{

        Stack <int> test;
        test >> 5;
        test >> 4;
        cout << test << "\n";
        test << 5;
        cout << test << '\n';

        Queue <int> test2;
        test2 >> 5;
        test2 >> 4;
        cout << test2 << "\n";
        test2 << 5;
        cout << test2 << '\n';

        Stack <string> st_str;
        st_str >> "Danila" >> "Hohlov" >> "is" >> "cool" >> "man";
        cout << st_str << endl;
        st_str << "Danila" << "Hohlov" <<"is";
        cout << st_str << endl;

        Stack<double> my_st;
        stack<double> st;

        cout << "///////////////////////////////////////////////////////////////////\n";
        auto begin = chrono::steady_clock::now();

        for(int i = 0; i < num; i++)
            my_st.push(i);

        auto end = chrono::steady_clock::now();
        cout << "My stack: " << chrono::duration_cast<chrono::microseconds>(end-begin).count() << "\n";

        begin = chrono::steady_clock::now();

        for(int i = 0; i < num; i++)
            st.push(i);

        end = chrono::steady_clock::now();
        cout << "stack: " << chrono::duration_cast<chrono::microseconds>(end-begin).count() << "\n";
        cout << "///////////////////////////////////////////////////////////////////\n";
        Queue<double> my_qu;
        queue<double> qu;

        begin = chrono::steady_clock::now();

        for(int i = 0; i < num; i++)
            my_qu.push(i);

        end = chrono::steady_clock::now();
        cout << "My queue: " << chrono::duration_cast<chrono::microseconds>(end-begin).count() << "\n";

        begin = chrono::steady_clock::now();

        for(int i = 0; i < num; i++)
            qu.push(i);

        end = chrono::steady_clock::now();
        cout << "queue:" << chrono::duration_cast<chrono::microseconds>(end-begin).count() << "\n";
        Queue<int> qu1 {1, 2, 3, 4, 5};
        cout << qu1.length() << "\n";
        cout << qu1 << "\n";
        cout << qu1.pop() << '\n';
        cout << qu1 << "\n";
        cout << qu1.checkpop() << '\n';
        cout << qu1 << "\n";
        Queue<int> qu2(qu1);
        cout << qu2 << "\n";
        qu1.erase();
        cout << qu1.empty() << "\n";
        qu2 = qu2;
        cout << qu2 << "\n";
        Queue <student> qu3 { student("Hohlov", 5), student("Verhov", 2)};
        cout << qu3 << '\n';
        cout << qu2 << "\n";
        Stack<int> s = Queue_to_Stack(qu2);
        cout << s.checkpop() << '\n';

        Stack <int> Test1 ({1, 2, 3, 4, 5});
        Queue<int> Test2 = Stack_to_Queue(Test1);
        cout << Test2.checkpop() << '\n';

        cout <<"Length: " <<  Test1.length() << "\n";
        cout <<"Empty: " << Test1.empty() << "\n";
        cout <<"Checkpop: " << Test1.checkpop() << "\n";
        cout <<Test1 << "\n";
        cout <<"pop: " << Test1.pop() << "\n";
        cout <<Test1 << "\n";
        Stack<int> Test3;
        Test3 = Test1;
        cout << Test3 << '\n';
        Test3.erase();
        cout << Test3 << "\n";
        Test3 = Test1;
        cout << Test3 << "\n";

        Stack <string> Test4  ({"Hohlov", "Verhov"});
        cout <<Test4 << "\n";

        Stack <double> Test5  ({12.32, 345.345, 5.71});
        cout <<Test5 << "\n";
        student a1 ("Hohlov", 5);
        student a2 ("Verhov", 6);
        Stack <student> Test6 ({a1, a2});
        cout << Test6;


    return 0;
}
catch (logic_error &error){cerr << error.what();}
