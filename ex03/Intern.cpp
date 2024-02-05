#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructor destructor copy constructor operator overload
Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(Intern const &other) { (void)other; }
Intern &Intern::operator=(Intern const &other) {
  return (*this);
  (void)other;
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
	std::string Form[]
	int i = 0;
  for (; i < 3; i++) {
    if (name == makeFormArray[i].name) {
      std::cout << "Intern creates " << name << std::endl;
	  break ;
    }
  }

  switch (i)
  {
	  case "presidential pardon":
		  return (new PresidentialPardonForm(target));
	  case "robotomy request":
		  return (new RobotomyRequestForm(target));
	  case "shrubbery creation":
		  return (new ShrubberyCreationForm(target));
	  default :
  std::cout << "Intern cannot create " << name << std::endl;
	throw Intern::FormNotFound();
  return NULL;
  }
}

const char *Intern::FormNotFound::what() const throw() {
  return "Form is not found.";
}

std::ostream &operator<<(std::ostream &out, Intern const &form) {
  out << "Intern " << std::endl;
  return (out);
  (void)form;
}

