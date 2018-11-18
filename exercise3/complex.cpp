#include <math.h>
#include <iostream>
#include <string>

class Complex {
 public:
  typedef float num_t;

 private:
  num_t _real;
  num_t _imaginary;

 public:
  Complex(num_t real = 0, num_t imaginary = 0) {
    _real = real;
    _imaginary = imaginary;
  }

  num_t real() { return _real; }
  num_t imaginary() { return _imaginary; }

  num_t modulo() { return sqrtf(_real * _real + _imaginary * _imaginary); }
  num_t argument() { return atan2(_real, _imaginary); }
};

bool operator==(Complex a, Complex b) {
  return a.real() == b.real() && a.imaginary() == b.imaginary();
}

bool operator!=(Complex a, Complex b) {
  return a.real() != b.real() || a.imaginary() != b.imaginary();
}

Complex operator+(Complex a, Complex b) {
  return Complex(a.real() + b.real(), a.imaginary() + b.imaginary());
}

Complex operator-(Complex a, Complex b) {
  return Complex(a.real() - b.real(), a.imaginary() - b.imaginary());
}

Complex operator*(Complex a, Complex b) {
  return Complex(a.real() * b.real() - a.imaginary() * b.imaginary(),
                 a.real() * b.imaginary() + a.imaginary() * b.real());
}

Complex operator/(Complex a, Complex b) {
  Complex::num_t denominator =
      b.real() * b.real() + b.imaginary() * b.imaginary();

  return Complex(
      (a.real() * b.real() + a.imaginary() * b.imaginary()) / denominator,
      (a.imaginary() * b.real() - a.real() * b.imaginary()) / denominator);
}

std::ostream &operator<<(std::ostream &out, Complex a) {
  return out << a.real() << " + " << a.imaginary() << " i";
}

std::istream &operator>>(std::istream &in, Complex &a) {
  Complex::num_t real;
  Complex::num_t imaginary;
  std::string plus_sign;
  std::string im_sign;

  in >> real >> plus_sign >> imaginary >> im_sign;

  if (plus_sign != "+" || im_sign != "i") {
    return in;
  }

  new (&a) Complex(real, imaginary);

  return in;
}

int main(int argc, char const *argv[]) {
  for (;;) {
    std::cout << "Enter 2 complex numbers in following format /\\d+ + \\d+ i/"
              << std::endl;

    Complex a, b;
    std::cin >> a >> b;

    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl
              << "a == b: " << (a == b ? "true" : "false") << std::endl
              << "a != b: " << (a != b ? "true" : "false") << std::endl
              << "a + b: " << a + b << std::endl
              << "a - b: " << a - b << std::endl
              << "a * b: " << a * b << std::endl
              << "a / b: " << a / b << std::endl;
  }
  return 0;
}
