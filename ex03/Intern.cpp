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
	std::string Form[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = 0;
  for (; i < 3; i++) {
    if (name == Form[i]) {
      std::cout << "Intern creates " << name << std::endl;
	  break ;
    }
  }

  switch (i)
  {
	  case 0:
		  return (new PresidentialPardonForm(target));
	  case 1: 
		  return (new RobotomyRequestForm(target));
	  case 2:
		  return (new ShrubberyCreationForm(target));
	  default:
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

