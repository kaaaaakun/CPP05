#include "Form.hpp"

#include "Bureaucrat.hpp"

// Constructor destructor copy constructor operator overload
Form::Form(std::string const name, int const gradeSign, int const gradeExec)
    : name_(name),
      signed_(false),
      gradeSign_(gradeSign),
      gradeExec_(gradeExec) {
  if (gradeSign < 1 || gradeExec < 1) throw Form::GradeTooHighException();
  if (150 < gradeSign || 150 < gradeExec) throw Form::GradeTooLowException();
  std::cout << "Form" << name_ << "created." << std::endl;
}

Form::~Form() {}

Form::Form(Form const &other)
    : name_(other.name_),
      signed_(other.signed_),
      gradeSign_(other.gradeSign_),
      gradeExec_(other.gradeExec_) {
  std::cout << "Form" << name_ << "created by copy." << std::endl;
  *this = other;
}

Form &Form::operator=(Form const &other) {
  signed_ = other.signed_;
  return (*this);
}

// Getters
std::string const &Form::getName() const { return (name_); }
bool Form::getSigned() const { return (signed_); }
int Form::getGradeSign() const { return (gradeSign_); }
int Form::getGradeExec() const { return (gradeExec_); }

// Exceptions
void Form::beSigned(Bureaucrat &bureaucrat) {
  if (signed_ == false) {
    signed_ = true;
  }
  std::cout << bureaucrat.getName() << " signed " << this->getName()
            << std::endl;
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
  out << "Form " << form.getName() << " is ";
  if (form.getSigned() == true)
    out << "signed";
  else
    out << "not signed"
        << " and requires " << form.getGradeSign() << " to sign. " << std::endl;
  return out;
}
