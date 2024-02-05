#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <random>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  std::string const name_;
  bool signed_;
  int gradeSign_;
  int gradeExec_;

 public:
  AForm(std::string const name, int const gradeSign, int const gradeExec);
  virtual ~AForm();
  AForm(AForm const &other);
  AForm &operator=(AForm const &other);

  std::string const &getName() const;
  bool getSigned() const;
  int getGradeSign() const;
  int getGradeExec() const;

  void beSigned(Bureaucrat &bureaucrat);
  void signForm();

  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif  // FORM_HPP
