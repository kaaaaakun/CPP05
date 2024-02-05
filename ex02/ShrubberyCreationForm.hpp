#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "tree.h"

class ShrubberyCreationForm : public AForm {
 private:
  std::string target_;

 public:
  ShrubberyCreationForm(std::string target);
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(ShrubberyCreationForm const &other);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

  virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif
