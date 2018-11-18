#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define SALES 4
#define PRODUCTS 5

class Product {
 private:
  int64_t val;

 public:
  Product() { this->val = 0; }

  void sell(int64_t value) { this->val += value; }

  int64_t value() { return this->val; }
};

class Salesman {
 private:
  Product products[PRODUCTS];

 public:
  Product &product(uint64_t product_id) {
    return this->products[product_id - 1];
  }
};

class Shop {
 private:
  Salesman salesmen[SALES];

 public:
  Salesman &salesman(uint64_t sales_id) { return this->salesmen[sales_id - 1]; }

  void abort(const char *reason) {
    if (*reason) {
      cerr << reason << endl;
    }

    print();
    exit(0);
  }

  void print() {
    cout << endl << "Sales" << '\t';

    for (uint64_t product_no = 1; product_no <= PRODUCTS; ++product_no) {
      cout << product_no << '\t';
    }

    cout << endl;

    for (uint64_t sales_id = 1; sales_id <= SALES; ++sales_id) {
      cout << sales_id << '\t';

      for (uint64_t product_id = 1; product_id <= PRODUCTS; ++product_id) {
        cout << (double)this->salesman(sales_id).product(product_id).value() /
                    100.0
             << '\t';
      }

      cout << endl;
    }
  }

  void read_tsv_line() {
    int64_t sales;
    int64_t product;
    int64_t value;

    cout << "Enter data: [sales] [product] [value]: ";
    cin >> sales;
    assert_in_range(sales, 1, SALES);
    cin >> product;
    assert_in_range(product, 1, PRODUCTS);
    cin >> value;

    this->salesman(sales).product(product).sell(value);
  }

  void assert_in_range(int64_t num, int64_t begin, int64_t end) {
    if (num < begin || num > end) {
      stringstream ss;
      ss << "Number " << num << " is outside of range " << begin << ".." << end
         << '!';

      abort(ss.str().c_str());
    }
  }
};

int main() {
  Shop shop;

  for (;;) {
    shop.read_tsv_line();
  }

  return 0;
}
