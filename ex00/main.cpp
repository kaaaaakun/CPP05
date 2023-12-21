#include <sstream>

#include "Bureaucrat.hpp"

std::string itoa(int i) {
  std::stringstream ss;
  ss << i;
  return ss.str();
}

void lowTest() {
  std::cout << BLUE << "-- Low test -------" << std::endl;
  Bureaucrat Low1("Low", 151);
  std::cout << Low1 << std::endl;
  std::cout << "------------------" << std::endl;
  Bureaucrat Low2("Low2", 150);
  std::cout << Low2 << std::endl;
  Low2.decrementGrade();
  std::cout << Low2 << std::endl;
}

void heightTest() {
  std::cout << RED << "-- Height test -------" << std::endl;
  Bureaucrat Height1("Height", 0);
  std::cout << Height1 << std::endl;
  std::cout << "------------------" << std::endl;
  Bureaucrat Height2("Height2", 1);
  std::cout << Height2 << std::endl;
  Height2.incrementGrade();
  std::cout << Height2 << std::endl;
}

void gradeTest() {
  std::cout << GREEN << "-- Grade test -------" << std::endl;
  Bureaucrat Grade1("GradeMan", 150);
  for (int i = 0; i < 152; i++) {
    std::cout << itoa(i) << ": " << Grade1 << std::endl;
    Grade1.incrementGrade();
  }
}

int main(void) {
  lowTest();
  heightTest();
  gradeTest();
  return 0;
}
