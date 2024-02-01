#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructor destructor copy constructor operator overload
Intern::Intern() {
  makeFormArray[0].name = "presidential pardon";
  makeFormArray[0].form = &Intern::createPresidentialPardonForm;
  makeFormArray[1].name = "robotomy request";
  makeFormArray[1].form = &Intern::createRobotomyRequestForm;
  makeFormArray[2].name = "shrubbery creation";
  makeFormArray[2].form = &Intern::createShrubberyCreationForm;
}

Intern::~Intern() {}
Intern::Intern(Intern const &other) { (void)other; }
Intern &Intern::operator=(Intern const &other) {
  return (*this);
  (void)other;
}

std::ostream &operator<<(std::ostream &out, Intern const &form) {
  out << "Intern " << std::endl;
  return (out);
  (void)form;
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
  for (int i = 0; i < 3; i++) {
    if (name == makeFormArray[i].name) {
      std::cout << "Intern creates " << name << std::endl;
      return (makeFormArray[i].form(target));
    }
  }
  std::cout << "Intern cannot create " << name << std::endl;
  return NULL;
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) {
  return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) {
  return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string const &target) {
  return (new ShrubberyCreationForm(target));
}
