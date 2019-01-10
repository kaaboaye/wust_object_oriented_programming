#include <cctype>
#include <cmath>
#include <deque>
#include <fstream>
#include <iostream>

std::ifstream in_text("in_text.txt");

std::ofstream out_key("out_key.txt");
std::ofstream out_text("out_text.txt");

char parse_char(char c) { return abs(c - 'a') % ('z' - 'a'); }
#define dump(c) ((char)(c + 'a'))

char get_next_key_char() {
  if (std::cin.eof()) {
    std::cout << "key to short" << std::endl;
    exit(0xdeadc0de);
  }

  char key = parse_char(std::cin.get());

  out_key.put(key + 'a');
  return key;
}

int main(int argc, char const *argv[]) {
  while (!in_text.eof()) {
    char text = in_text.get();
    char key = get_next_key_char();

    if (text == ' ') {
      out_text.put(' ');
      std::cout << "  + " << dump(key) << " =  " << std::endl;
      continue;
    } else {
      text = tolower(text);
      text = parse_char(text);
    }

    char encrypted = parse_char(text + key);
    out_text.put(encrypted + 'a');
    std::cout << dump(text) << " + " << dump(key) << " = " << dump(encrypted)
              << std::endl;
  }

  return 0;
}
