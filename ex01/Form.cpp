#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor destructor copy constructor operator overload
Form::Form(std::string const name, int const gradeSign, int const gradeExec) throw(GradeTooHighException, GradeTooLowException)
    : name_(name),
      signed_(false),
      gradeSign_(gradeSign),
      gradeExec_(gradeExec) {
  if (gradeSign < 1)
	  throw From::GradeTooHighException();
  if (150 < gradeSign)
	  throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(Form const &other)
    : name_(other.name_),
      signed_(other.signed_),
      gradeSign_(other.gradeSign_),
      gradeExec_(other.gradeExec_) {
  *this = other;
}

Form &Form::operator=(Form const &other) {
  signed_ = other.signed_;
  return (*this);
}

// Getters
std::string const &Form::getName() const { return (name_); }
bool const Form::getSigned() const { return (signed_); }
int const Form::getGradeSign() const { return (gradeSign_); }
int const Form::getGradeExec() const { return (gradeExec_); }

// Exceptions
void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (signed_ == false) {
    signed_ = true;
  }
}

// Grade Errors
const char *Form::GradeTooHighException::what() const throw() {
return "Grade must be 1 or more.";
}

const char *Form::GradeTooLowException::what() const throw() {
return "Grade must be 150 or less.";
}

// Operator overload
std::ostream &operator<<(std::ostream &out, Form const &form) {
}
