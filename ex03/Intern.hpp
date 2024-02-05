#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  struct FormArray {
    std::string name;
    AForm *(*form)(std::string const &target);
  };

  FormArray makeFormArray[3];

 public:
  Intern();
  ~Intern();
  Intern(Intern const &other);
  Intern &operator=(Intern const &other);

  static AForm *createPresidentialPardonForm(std::string const &target);
  static AForm *createRobotomyRequestForm(std::string const &target);
  static AForm *createShrubberyCreationForm(std::string const &target);

  AForm *makeForm(std::string const &name, std::string const &target);

  class FormNotFound  : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

#endif  // INTERN_HPP
