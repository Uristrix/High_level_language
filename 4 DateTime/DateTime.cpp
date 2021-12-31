#include "DateTime.h"
#include <ctime>

//=====================================================================================================================
// Time
Time::Time(): hour(0), minute(0){}

Time::Time(int hour, int minute): Time()
{
    if (valid_time(hour, minute))
    {
        this -> hour = hour;
        this -> minute = minute;
    }
}

Time::Time(const Time &time)
{
    hour = time.hour;
    minute = time.minute;
}

Time::Time(Time &&time)
{
    hour = time.hour;
    minute = time.minute;
    time.hour = time.minute = 0;
}

bool Time::valid_time(int hour, int minute)
{
    return !(hour > 23 || hour < 0 || minute > 59 || minute < 0);
}

std::string Time::strftime(std::string format) const
{
    std:: string temp;
    int pos = format.find('h');
    if (pos >= 0)
    {
        temp = std:: to_string(hour);
        if (temp.length() < 2)
            temp = "0" + temp;

        format.replace(pos, 1, temp);
    }

    pos = format.find('m');
    if (pos >= 0)
    {
        temp = std:: to_string(minute);
        if (temp.length() < 2)
            temp = "0" + temp;

        format.replace(pos, 1, temp);
    }
    return format;
}

std::ostream &operator<<(std::ostream &out, const Time &time)
{
    return out << time.strftime();
}
//======================================================================================================================
//Date
Date::Date(): year(0), month(1), day(1) {}

Date::Date(int year, int month, int day): Date()
{
    if (valid_date(year, month, day))
    {
        this -> year = year;
        this -> month = month;
        this -> day = day;
    }
}

Date::Date(const Date &date)
{
    year = date.year;
    month = date.month;
    day = date.day;
}

Date::Date(Date &&date)
{
    year = date.year;
    month = date.month;
    day = date.day;
    date.year = 0;
    date.month = date.day = 1;
}

bool Date::leap_year(int year)
{
    if(year % 4 != 0)
        return false;
    else
        return !(year % 100 == 0 && year % 400 != 0);
}

bool Date::valid_date(int year, int month, int day)
{
    if(year < 0 || year > 9999)
        return false;
    if(month < 1 || month > 12)
        return false;
    if(day < 1)
        return false;
    if ( leap_year(year) && month == 2 && day > 29)
        return false;
    if (!leap_year(year) && month == 2 && day > 28)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return !((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31);
}

std::string Date::strftime(std::string format) const
{
    std:: string temp;
    int pos = format.find('D');
    if (pos >= 0)
    {
        temp = std:: to_string(day);
        if (temp.length() < 2)
            temp = "0" + temp;

        format.replace(pos, 1, temp);
    }

    pos = format.find('M');
    if (pos >= 0)
    {
        temp = std:: to_string(month);
        if (temp.length() < 2)
            temp = "0" + temp;

        format.replace(pos, 1, temp);
    }

    pos = format.find('Y');
    if (pos >= 0)
        format.replace(pos, 1, std:: to_string(year));
    return format;
}

std::ostream &operator<<(std::ostream &out, const Date &date)
{
    return out << date.strftime();
}
//======================================================================================================================
//DateTime

DateTime:: DateTime(): Date(), Time(){}

DateTime:: DateTime(int year, int month, int day, int hour, int minute): DateTime()
{
    if (valid(year, month, day, hour, minute))
    {
        this -> year = year;
        this -> month = month;
        this -> day = day;
        this -> hour = hour;
        this -> minute = minute;
    }
}

DateTime:: DateTime(const DateTime &dt): Date(dt.toDate()), Time(dt.toTime()){}

DateTime:: DateTime(DateTime &&dt): DateTime(dt)
{
    dt.year = dt.hour = dt.minute = 0;
    dt.month = dt.day = 1;
}
void DateTime::now()
{
    time_t dt = ::time(nullptr);
    struct tm *dt_s = localtime(&dt);

    day = dt_s -> tm_mday;
    month = dt_s -> tm_mon + 1;
    year = dt_s -> tm_year + 1900;
    hour = dt_s -> tm_hour;
    minute = dt_s -> tm_min;
}

std:: string DateTime::strftime(std:: string format) const
{
    return Time:: strftime(Date:: strftime(format));
}

DateTime DateTime::strptime(const std::string &date_string, const std::string &format)
{
    int year = 0, month = 1, day = 1, hour = 0, minute = 0, j = 0;
    std::string temp;

    for(char i : format)
    {
        switch (i)
        {
            case 'D':
            {
                while(isdigit(date_string[j]))
                {
                    temp += date_string[j];
                    j++;
                }
                day = std::stoi(temp);
                temp.erase();
                j++;
                break;
            }

            case 'M':
            {
                while(isdigit(date_string[j]))
                {
                    temp += date_string[j];
                    j++;
                }
                month = std::stoi(temp);
                temp.erase();
                j++;
                break;
            }

            case 'Y':
            {
                while(isdigit(date_string[j]))
                {
                    temp += date_string[j];
                    j++;
                }
                year = std::stoi(temp);
                temp.erase();
                j++;
                break;
            }

            case 'h':
            {
                while(isdigit(date_string[j]))
                {
                    temp += date_string[j];
                    j++;
                }
                hour = std::stoi(temp);
                temp.erase();
                j++;
                break;
            }

            case 'm':
            {
                while(isdigit(date_string[j]))
                {
                    temp += date_string[j];
                    j++;
                }
                minute = std::stoi(temp);
                temp.erase();
                j++;
                break;
            }
            default:
                break;
        }
    }
    return DateTime (year, month, day, hour, minute);
}

std::ostream& operator << (std::ostream &out, const DateTime &dt)
{
    return out << dt.strftime();
}

Date DateTime::toDate() const
{
    return Date(year, month, day);
}

Time DateTime::toTime() const
{
    return Time(hour, minute);
}

bool DateTime::valid(int year, int month, int day, int hour, int minute)
{
    return valid_date(year, month, day) && valid_time(hour, minute);
}