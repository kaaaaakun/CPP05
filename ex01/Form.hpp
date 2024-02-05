#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <random>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  std::string const name_;
  bool signed_;
  const int gradeSign_;
  const int gradeExec_;

 public:
  Form(std::string const name, int const gradeSign, int const gradeExec);
  ~Form();
  Form(Form const &other);
  Form &operator=(Form const &other);

  std::string const &getName() const;
  bool getSigned() const;
  int getGradeSign() const;
  int getGradeExec() const;

  void beSigned(Bureaucrat &bureaucrat);
  void signForm();

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif  // FORM_HPP
