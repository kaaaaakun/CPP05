#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150
#define ERROR -1

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class AForm;

class Bureaucrat {
 private:
  std::string const name_;
  int grade_;

 public:
  Bureaucrat(std::string const &name, int grade);
  Bureaucrat(Bureaucrat const &other);
  ~Bureaucrat();
  Bureaucrat &operator=(Bureaucrat const &other);

  std::string const &getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void signAForm(AForm &form);

  void executeForm(AForm const &form);

  class isSigned : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class isBureaucratGradeLow : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
