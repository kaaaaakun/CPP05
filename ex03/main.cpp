#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void InternMakeForm(const std::string formName, const std::string target,
                    const int grade) {
  Bureaucrat bureaucrat("B" + std::to_string(grade), grade);
  Intern intern;
  AForm* form;
  try {
    form = intern.makeForm(formName, target);
  } catch (std::exception& e) {
    std::cout << formName << " " << e.what() << std::endl;
	return ;
  }
  std::cout << *form << std::endl;
  bureaucrat.signAForm(*form);
  bureaucrat.executeForm(*form);
  delete form;
}

int main() {
  std::cout << "-----------------------" << std::endl;
  InternMakeForm("presidential pardon", "target1", 42);
  std::cout << "-----------------------" << std::endl;
  InternMakeForm("robotomy request", "target2", 42);
  std::cout << "-----------------------" << std::endl;
  InternMakeForm("shrubbery creation", "target3", 42);
  std::cout << "-----------------------" << std::endl;
  InternMakeForm("miss", "miss", 1);
  std::cout << "-----------------------" << std::endl;
  return 0;
}
