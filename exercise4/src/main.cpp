#include <iostream>
#include <stdint.h>

#include "cli/agr.h"
#include "cli/inh.h"

int main(int argc, char const *argv[])
{
  for (;;)
  {
    std::cout
        << "Choose mode: " << std::endl
        << "i: inheritance mode" << std::endl
        << "a: aggregate mode" << std::endl
        << "e: exit" << std::endl
        << "mode: ";

    char mode;
    std::cin >> mode;

    std::cout << std::endl;

    switch (mode)
    {
    case 'i':
      cli_inh();
      break;

    case 'a':
      cli_arg();
      break;

    case 'e':
      return 0;

    default:
      std::cout << "Bad mode" << std::endl;
    }
  }
}
