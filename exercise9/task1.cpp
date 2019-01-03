#include <stdint.h>
#include <iostream>
#include <regex>
#include <string>

static const auto name_regex = std::regex("^[[:upper:]][[:lower:]]+$");

class BadFirstNameException {};
class BadLastNameException {};

class Student {
  std::string first_name;
  std::string last_name;
  uint64_t student_id;
  uint8_t year_of_study;

 public:
  Student(std::string first_name, std::string last_name, uint64_t student_id,
          uint64_t year_of_study) {
    std::cout << first_name << " " << last_name << " " << student_id << " "
              << year_of_study << std::endl;

    if (!std::regex_match(first_name, name_regex)) {
      throw new BadFirstNameException();
    }

    if (!std::regex_match(last_name, name_regex)) {
      throw new BadLastNameException();
    }

    this->first_name = first_name;
    this->last_name = last_name;
    this->student_id = student_id;
    this->year_of_study = year_of_study;
  }
};

int main(int argc, char const *argv[]) {
  Student *stud;

  stud = new Student("Wojciech", "Ponury", 0xDEADC0DE, 2);

  try {
    stud = new Student("Wojciech kocham", "Ponury", 0xDEADC0DE, 2);
  } catch (BadFirstNameException *) {
    std::cout << "BadFirstNameException" << std::endl;
  }

  try {
    stud = new Student("Wojciech", "Po1nury", 0xDEADC0DE, 2);
  } catch (BadLastNameException *) {
    std::cout << "BadLastNameException" << std::endl;
  }

  return 0;
}
