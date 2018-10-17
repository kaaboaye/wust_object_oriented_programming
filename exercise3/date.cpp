#include <stdint.h>
#include <iostream>

class Date
{
public:
  typedef int32_t year_t;
  typedef int16_t mouth_t;
  typedef int16_t day_t;

private:
  year_t _year;
  mouth_t _mouth;
  day_t _day;

public:
  Date(year_t year, mouth_t mouth, day_t day)
  {
    _year = year;
    _mouth = mouth;
    _day = day;
  }

  void year(year_t year) { _year = year; }
  year_t year() { return _year; }

  void mouth(mouth_t mouth) { _mouth = mouth; }
  mouth_t mouth() { return _mouth; }

  void day(day_t day) { _day = day; }
  day_t day() { return _day; }

  bool leap_year()
  {
    return ((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0);
  }

  day_t days_in_mouth()
  {
    switch (_mouth)
    {
    case 2:
      return leap_year() ? 29 : 28;

    case 4:
    case 6:
    case 9:
    case 11:
      return 30;

    default:
      return 31;
    }
  }

  int64_t days_from_1jan()
  {
    int64_t days = -1;
    for (mouth_t mouth = 1; mouth < _mouth; ++mouth)
    {
      Date d = Date(_year, mouth, 1);
      days += d.days_in_mouth();
    }

    return days + _day;
  }

  int64_t unix()
  {
    int64_t u = 0;

    if (_year != 1970)
    {
      year_t it = _year < 1970 ? _year : 1970;
      year_t end = _year > 1970 ? _year : 1970;
      for (; it < end; ++it)
      {
        Date d = Date(it, 1, 1);
        u += d.leap_year() ? 366 : 365;
      }
    }

    u += days_from_1jan();

    return u * 24 * 60 * 60;
  }
};

int main(int argc, char const *argv[])
{
  for (;;)
  {
    Date::year_t year;
    Date::mouth_t mouth;
    Date::day_t day;

    std::cout << "Provide date: [year] [mouth] [day]: ";
    std::cin >> year >> mouth >> day;

    Date d = Date(year, mouth, day);

    std::cout << "days_in_mouth: " << d.days_in_mouth() << std::endl;
    std::cout << "days_from_1jan: " << d.days_from_1jan() << std::endl;
    std::cout << "Unix time: " << d.unix() << std::endl;
  }

  return 0;
}
