#include <stdint.h>
#include <iostream>

class Time
{
  int64_t _unix;

public:
  Time(int64_t unix_format = 0)
  {
    _unix = unix_format;
  }

  int64_t unix() { return _unix; }
};

Time operator+(Time a, Time b)
{
  return Time(a.unix() + b.unix());
}

Time operator-(Time a, Time b)
{
  return Time(a.unix() - b.unix());
}

std::ostream &operator<<(std::ostream &out, Time a)
{
  return out << a.unix();
}

std::istream &operator>>(std::istream &in, Time &a)
{
  int64_t unix;
  in >> unix;
  new (&a) Time(unix);
  return in;
}

int main(int argc, char const *argv[])
{
  for (;;)
  {
    Time t;

    std::cout << "Enter time in unix format: ";
    std::cin >> t;

    std::cout
        << "t: " << t << std::endl
        << "t + t: " << t + t << std::endl
        << "t - t: " << t - t << std::endl;
  }
  return 0;
}
