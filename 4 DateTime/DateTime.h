#ifndef DATETIME_H
#define DATETIME_H
#include <iostream>

//классы для даты и времени
class Date
{
    static bool leap_year(int year); //Проверка на високосный год

    protected:
        int year, month, day;

    public:
    //Конструкторы
    Date();
    Date(int year, int month, int day);
    Date(const Date& date);
    Date(Date&& date);

    friend std::ostream& operator << (std::ostream &out, const Date &date); // перегрузка вывода
    std:: string strftime(std:: string format = "D.M.Y") const; //получение строки из даты

    static bool valid_date(int year, int month, int day); //Проверка корректности даты
    //Геттеры
    inline int get_year() const;
    inline int get_month() const;
    inline int get_day() const;
    //Сеттеры
    inline void set_year(int year);
    inline void set_month(int month);
    inline void set_day(int day);
};

class Time
{
    protected:
        int hour, minute;

    public:
        //Конструкторы
        Time();
        Time(int hour, int minute);
        Time(const Time& time);
        Time(Time&& time);

        friend std::ostream& operator << (std::ostream &out, const Time &time); // перегрузка вывода
        std:: string strftime(std:: string format = "h:m") const; //получение строки из даты

        static bool valid_time(int hour, int minute); //Проверка корректности времени
        //Геттеры
        inline int get_hour() const;
        inline int get_minute() const;
        //Сеттеры
        inline void set_hour(int hour);
        inline void set_minute(int minute);
};

class DateTime: public Date, public Time //множественное наследование
{

public:
    //Конструкторы
    DateTime();
    DateTime(int year, int month, int day, int hour, int minute);
    DateTime(const DateTime& datetime);
    DateTime(DateTime&& datetime);

    //Возвращает структуры с датой и временем
    Date toDate() const;
    Time toTime() const;

    friend std::ostream& operator << (std::ostream &out, const DateTime &date); // перегрузка вывода

    static bool valid(int year, int month, int day, int hour, int minute); //объединение проверки даты и времени

    std:: string strftime(std:: string format = "D.M.Y h:m") const; //получение строки из даты
    static DateTime strptime(const std:: string& date_string, const std::string& format);//получение даты из строки

    void now(); //метод текущего времени
};

int Date:: get_year() const
{
    return year;
}

int Date:: get_month() const
{
    return month;
}

int Date:: get_day() const
{
    return day;
}

int Time:: get_hour() const
{
    return hour;
}

int Time:: get_minute() const
{
    return minute;
}

void Date::set_year(int year)
{
    if (valid_date(year, month, day))
        this -> year = year;
}

void Date::set_month(int month)
{
    if (valid_date(year, month, day))
        this -> month = month;
}

void Date::set_day(int day)
{
    if (valid_date(year, month, day))
        this -> day = day;
}

void Time::set_hour(int hour)
{
    if (valid_time(hour, minute))
        this -> hour = hour;
}

void Time::set_minute(int minute)
{
    if (valid_time(hour, minute))
        this -> minute = minute;
}

#endif //DATETIME_H