#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include "AForm.hpp"

// Constructor destructor copy constructor operator overload
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &other) {
  AForm::operator=(other);
  target_ = other.target_;
  return (*this);
}

// execute
static void PlantTree(std::string target) {
  std::string filename = target + "_shrubbery";
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Cannot open file" << std::endl;
    return;
  }
  file << "TREEEEEEEEEEEE" << std::endl;
  file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &excutor) const {
  try {
    if (excutor.getGrade() > getGradeExec())
      throw AForm::GradeTooLowException();
    else if (getSigned() == false)
      throw AForm::FormNotSignedException();
    else
      PlantTree(this->target_);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

// Operator overload
std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form) {
  out << "ShrubberyCreationForm " << form.getName() << " is ";
  if (form.getSigned() == true)
    out << "signed";
  else
    out << "not signed"
        << " and requires " << form.getGradeSign() << " to sign. " << std::endl;
  return out;
}
