#include <iostream>
#include <string>
#include <unordered_map>

#include "../lib/numbers/arabian.h"
#include "../lib/numbers/roman.h"

#include "../lib/shapes/cuboid.h"
#include "../lib/shapes/rectangle.h"

#include "cli.h"

namespace Cli
{
enum commands_t
{
  commands_roman,
  commands_arabian,
  commands_cuboid,
  commands_rectangle,
  commands_help,
  commands_exit,
  commands_undefined,
};

static const std::unordered_map<std::string, commands_t> commands_strings = {
    {"roman", commands_roman},
    {"arabian", commands_arabian},
    {"cuboid", commands_cuboid},
    {"rectangle", commands_rectangle},
    {"exit", commands_exit},
    {"help", commands_help},
};

static commands_t commands_cast(std::string str)
{
  auto it = commands_strings.find(str);
  return it != commands_strings.end() ? it->second : commands_undefined;
}

static void print(Numbers::Roman num)
{
  std::cout << "Numbers::Roman " << num.to_string() << std::endl;
}

static void print(Numbers::Arabian num)
{
  std::cout << "Numbers::Arabian " << num.to_string() << std::endl;
}

static void print(const Shapes::Cuboid &s)
{
  std::cout << "Shapes::Cuboid" << std::endl
            << "volume: " << s.volume() << std::endl
            << "diagonal: " << s.diagonal() << std::endl;
}

static void print(const Shapes::Rectangle &s)
{
  std::cout << "Shapes::Rectangle" << std::endl
            << "area: " << (s.area() || 0) << std::endl
            << "diagonal: " << s.diagonal() << std::endl;
}

static void help()
{
  std::cout
      << "roman" << std::endl
      << "arabian" << std::endl
      << "cuboid" << std::endl
      << "rectangle" << std::endl
      << "help" << std::endl;
}

static commands_t read_cmd()
{

  std::string s_cmd;
  std::cout << "> ";
  std::cin >> s_cmd;
  return commands_cast(s_cmd);
}

void main()
{
  help();

  for (;;)
  {
    switch (read_cmd())
    {
    case commands_arabian:
    {
      std::cout << "Provide num: ";
      int64_t num;
      std::cin >> num;

      auto ar = Numbers::Arabian(num);
      print(ar);
      break;
    }

    case commands_roman:
    {
      std::cout << "Provide num: ";
      int64_t num;
      std::cin >> num;

      auto ro = Numbers::Roman(num);
      print(ro);
      break;
    }

    case commands_rectangle:
    {
      std::cout << "Provide a and b: ";
      double a, b;
      std::cin >> a >> b;

      auto re = Shapes::Rectangle(a, b);
      print(re);
      break;
    }

    case commands_cuboid:
    {
      std::cout << "Provide a, b and h: ";
      double a, b, h;
      std::cin >> a >> b >> h;

      auto cu = Shapes::Cuboid(a, b, h);
      print(cu);
      break;
    }

    case commands_help:
      help();
      break;

    case commands_exit:
      return;

    case commands_undefined:
      std::cout << "Bad command ~~grr~~" << std::endl;
      break;
    }
  }
}
} // namespace Cli
