#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <random>

#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm {
 private:
  std::string const name_;
  bool signed_;
  int gradeSign_ = 145;
  int gradeExec_ 137;

 public:
  ShrubberyCreationForm(std::string const name, int const gradeSign, int const gradeExec);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(Form const &other);
  ShrubberyCreationForm &operator=(Form const &other);


};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif  //ShrubberyCreationForm_HPP
