#include <iostream>

class Account {
 public:
  Account() { std::cout << "constructor" << std::endl; }
  ~Account() { std::cout << "desctructor" << std::endl; }
};

int main(int argc, char const *argv[]) {
  Account *w = new Account;
  delete w;
  return 0;
}
