#include <iostream>
#include <sstream>
#include <string>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

#define SALES 4
#define PRODUCTS 5

void assert_in_range(int64_t num, int64_t begin, int64_t end);
float &get_sales_product(float *data, int64_t sales, int64_t product);
void read_tsv_line(float *data);
void abort(float *data, const char *reason);
void print(float *data);

int main()
{
  float *data = new float[SALES * PRODUCTS];
  memset(data, 0, sizeof(float) * SALES * PRODUCTS);

  while (true)
  {
    read_tsv_line(data);
  }

  free(data);
  return 0;
}

void assert_in_range(float *data, int64_t num, int64_t begin, int64_t end)
{
  if (num < begin || num > end)
  {
    stringstream ss;
    ss << "Number " << num << " is outside of range " << begin << ".."
       << "end!";

    abort(data, ss.str().c_str());
  }
}

void abort(float *data, const char *reason)
{
  if (*reason)
  {
    cerr << reason << endl;
  }

  print(data);
  exit(0);
}

float &get_sales_product(float *data, int64_t sales, int64_t product)
{
  return data[((sales - 1) * PRODUCTS) + (product - 1)];
}

void read_tsv_line(float *data)
{
  int64_t sales;
  int64_t product;
  float value;

  cout << "Enter data: [sales] [product] [value]: ";
  cin >> sales;
  assert_in_range(data, sales, 1, SALES);
  cin >> product;
  assert_in_range(data, product, 1, PRODUCTS);
  cin >> value;

  get_sales_product(data, sales, product) += value;
}

void print(float *data)
{
  cout << endl
       << "Sales" << '\t';

  for (uint64_t product_no = 1; product_no <= PRODUCTS; ++product_no)
  {
    cout << product_no << '\t';
  }

  cout << endl;

  for (uint64_t sales = 1; sales <= SALES; ++sales)
  {
    cout << sales << '\t';

    for (uint64_t product = 1; product <= PRODUCTS; ++product)
    {
      cout << get_sales_product(data, sales, product) << '\t';
    }

    cout << endl;
  }
}
