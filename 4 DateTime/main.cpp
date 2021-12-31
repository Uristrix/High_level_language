#include <iostream>
#include "DateTime.h"

using namespace std;
int main()
{
    DateTime dt1; //проверяем конструктор копирования
    cout << dt1 << '\n';

    dt1.now(); // ставим текущую дату и время
    cout << dt1 << '\n';

    dt1.set_day(7); // меняем день.
    cout << dt1 << '\n';

    dt1.set_day(32); // проеверяем метод valid, день не изменится, значит всё хорошо
    cout << dt1 << '\n';

    cout << dt1.strftime() << '\n'; //переводим дату в строку и печатаем

    auto date = dt1.toDate(); //возвращаем дату
    cout << date << '\n';

    auto time = dt1.toTime(); // возвращаем время
    cout << time << '\n';

    DateTime dt2(dt1); // конструктор копирования
    cout << dt2 << '\n';

    DateTime dt3 = move(dt1); // конструктор перемещения
    cout << dt1 << '\n';
    cout << dt3 << '\n';

    DateTime dt4 = DateTime::strptime("05.09.1972 12:45", "D.M.Y h:m"); // из строки в объект DateTime
    cout << dt4 << '\n';
    
    cout<< DateTime:: valid(2020,2,29,12,15); //проверка валидности даты
    return 0;
}
