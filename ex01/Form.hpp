#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <random>

#include "Bureaucrat.hpp"

class Form {
 private:
  std::string const name_;
  bool signed_;
  int const gradeSign_;
  int const gradeExec_;

 public:
Form(std::string const name, int const gradeSign, int const gradeExec)
	throw(GradeTooHighException, GradeTooLowException);
  ~Form();
  Form(Form const &other);
  Form &operator=(Form const &other);

  std::string const &getName() const;
  bool const getSigned() const;
  int const getGradeSign() const;
  int const getGradeExec() const;

  void beSigned(Bureaucrat const &bureaucrat);
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
