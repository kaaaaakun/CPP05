#include <sstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void formExec(Bureaucrat &bureaucrat, AForm &form) {
  std::cout << "-- Exec form" << std::endl;
	bureaucrat.executeForm(form);
}

void signForm(Bureaucrat &bureaucrat, AForm &form) {
  std::cout << "-- Sign form" << std::endl;
	bureaucrat.signAForm(form);
  std::cout << form << std::endl;
}

void testPresidentialPardonForm(void) {
  std::cout << "\n--------- testiPresidentialPardonForm--------" << std::endl;
  std::cout << "---- sign ok, exec ko" << std::endl;
  Bureaucrat bureaucrat("B1", 10);
  PresidentialPardonForm P1("P1-target");
  std::cout << bureaucrat << std::endl;
  std::cout << P1 << std::endl;
  signForm(bureaucrat,P1);
  formExec(bureaucrat,P1);
  
  std::cout << "---- sign ok, exec ok" << std::endl;
  Bureaucrat bureaucrat2("B2", 5);
  PresidentialPardonForm P2("P2-target");
  std::cout << bureaucrat2 << std::endl;
  std::cout << P2 << std::endl;
  signForm(bureaucrat2,P2);
  formExec(bureaucrat2,P2);
  std::cout << "----" << std::endl;
}

void testShrubberyCreationForm(void) {
  std::cout << "\n--------- testiShrubberyCreationForm--------" << std::endl;
  std::cout << "---- sign ok, exec ko" << std::endl;
  Bureaucrat bureaucrat("B1", 145);
  ShrubberyCreationForm S1("S1-target");
  std::cout << bureaucrat << std::endl;
  std::cout << S1 << std::endl;
  signForm(bureaucrat,S1);
  formExec(bureaucrat,S1);

  std::cout << "---- sign ok, exec ok" << std::endl;
  Bureaucrat bureaucrat2("B2", 137);
  ShrubberyCreationForm S2("S2-target");
  std::cout << bureaucrat2 << std::endl;
  std::cout << S2 << std::endl;
  signForm(bureaucrat2,S2);
  formExec(bureaucrat2,S2);
  std::cout << "----" << std::endl;
}

void testRobotomyRequestForm(void) {
  std::cout << "\n--------- testiRobotomyRequestForm--------" << std::endl;
  std::cout << "---- sign ok, exec ko" << std::endl;
  Bureaucrat bureaucrat("B1", 72);
  RobotomyRequestForm R1("R1-target");
  std::cout << bureaucrat << std::endl;
  std::cout << R1 << std::endl;
  signForm(bureaucrat,R1);
  formExec(bureaucrat,R1);

  std::cout << "---- sign ok, exec ok" << std::endl;
  Bureaucrat bureaucrat2("B2", 45);
  RobotomyRequestForm R2("R2-target");
  std::cout << bureaucrat2 << std::endl;
  std::cout << R2 << std::endl;
  signForm(bureaucrat2,R2);
  formExec(bureaucrat2,R2);
  std::cout << "----" << std::endl;
}

int main(void) {
	testPresidentialPardonForm();
	testRobotomyRequestForm();
	testShrubberyCreationForm();
  return 0;
}
