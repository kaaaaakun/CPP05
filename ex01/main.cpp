#include <sstream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

std::string itoa(int i) {
  std::stringstream ss;
  ss << i;
  return ss.str();
}

void testNormal() {
  std::cout << "--------- test Normal--------" << std::endl;
  Bureaucrat bureaucrat("B1", 42);
  std::cout << bureaucrat << std::endl;

  Form form("F1", 42, 42);
  std::cout << form << std::endl;

  std::cout << "Sign form" << std::endl;
  bureaucrat.signForm(form);
  std::cout << form << std::endl;

  std::cout << "Sign form again" << std::endl;
  bureaucrat.signForm(form);
  std::cout << form << std::endl;
}

void testCannotSign() {
  std::cout << "--------- test Can not sign --------" << std::endl;
  Bureaucrat bureaucrat("B1", 43);
  std::cout << bureaucrat << std::endl;

  Form form("F1", 42, 42);
  std::cout << form << std::endl;

  std::cout << "Sign form" << std::endl;
  bureaucrat.signForm(form);
  std::cout << form << std::endl;

  std::cout << "Sign form again" << std::endl;
  bureaucrat.signForm(form);
  std::cout << form << std::endl;
}

// cannot create form because the grade is too high
void testTooHighGrade() {
  std::cout << "--------- test too hight grade --------" << std::endl;
  try {
    std::cout << "form('F1', 0, 42)" << std::endl;
    Form form("F1", 0, 42);
  } catch (Form::GradeTooHighException &e) {
    std::cout << "GradeTooHighException caught" << std::endl;
  }

  try {
    std::cout << "form('F1', 42, 0)" << std::endl;
    Form form("F1", 42, 0);
  } catch (Form::GradeTooHighException &e) {
    std::cout << "GradeTooHighException caught" << std::endl;
  }
}

void testTooLowGrade() {
  std::cout << "--------- test too low grade --------" << std::endl;
  try {
    std::cout << "form('F1', 151, 42)" << std::endl;
    Form form("F1", 151, 42);
  } catch (Form::GradeTooLowException &e) {
    std::cout << "GradeTooLowException caught" << std::endl;
  }

  try {
    std::cout << "form('F1', 42, 151)" << std::endl;
    Form form("F1", 42, 151);
  } catch (Form::GradeTooLowException &e) {
    std::cout << "GradeTooLowException caught" << std::endl;
  }
}

int main(void) {
  testNormal();
  testCannotSign();
  testTooHighGrade();
  testTooLowGrade();
  return 0;
}
