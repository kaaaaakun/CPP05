#include <sstream>

#include "Bureaucrat.hpp"

void coutColor(const std::string& str, const std::string& color) {
  std::cout << color << str << RESET << std::endl;
}

std::string itoa(int i) {
  std::stringstream ss;
  ss << i;
  return ss.str();
}

void lowTest() {
  coutColor("-- Low test --", BLUE);
  {
    try {
      coutColor("Bureaucrat Low1(\"Low\", 151);", BLUE);
      Bureaucrat Low1("Low", 151);
      std::cout << Low1 << std::endl;
      Low1.incrementGrade();
      std::cout << Low1 << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      coutColor("Bureaucrat Low2(\"Low2\", 150);", BLUE);
      Bureaucrat Low2("Low2", 150);
      std::cout << Low2 << std::endl;
      Low2.decrementGrade();
      std::cout << Low2 << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  coutColor("------------------", BLUE);
}

void heightTest() {
  coutColor("-- Height test --", RED);
  {
    try {
      coutColor("Bureaucrat Height1(\"Height\", 0);", RED);
      Bureaucrat Height1("Height", 0);
      std::cout << Height1 << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      coutColor("Bureaucrat Height2(\"Height2\", 1);", RED);
      Bureaucrat Height2("Height2", 1);
      std::cout << Height2 << std::endl;
      Height2.incrementGrade();
      std::cout << Height2 << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  coutColor("------------------", RED);
}

void gradeTest() {
  coutColor("-- Grade test --", GREEN);
  try {
    Bureaucrat Grade1("GradeMan", 150);
    for (int i = 0; i < 152; i++) {
      std::cout << itoa(i) << ": " << Grade1 << std::endl;
      Grade1.incrementGrade();
    }
    coutColor("------------------", GREEN);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

void constructorTest() {
  coutColor("-- Constructor test --", YELLOW);
  try {
    coutColor("Constructor : Bureaucrat Grade1(\"GradeMan\", 10);", YELLOW);
    Bureaucrat Grade1("GradeMan", 10);
    std::cout << Grade1 << std::endl;
    coutColor("Copy Constructor : Bureaucrat Grade2(Grade1);", YELLOW);
    Bureaucrat Grade2(Grade1);
    std::cout << Grade2 << std::endl;
    Bureaucrat Grade3("Grade3", 1);
    coutColor("Assignation : Grade3 = Grade1;", YELLOW);
    Grade3 = Grade1;
    std::cout << Grade3 << std::endl;
    coutColor("Increment : Grade3.incrementGrade();", YELLOW);
    Grade3.decrementGrade();
    std::cout << Grade3 << std::endl;
    std::cout << Grade1 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  coutColor("------------------", YELLOW);
}

int main(void) {
  lowTest();
  heightTest();
  gradeTest();
  constructorTest();
  return 0;
}
