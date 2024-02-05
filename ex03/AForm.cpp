#include "AForm.hpp"

#include "Bureaucrat.hpp"

// Constructor destructor copy constructor operator overload
AForm::AForm(std::string const name, int const gradeSign, int const gradeExec)
    : name_(name),
      signed_(false),
      gradeSign_(gradeSign),
      gradeExec_(gradeExec) {
  if (gradeSign < 1 || gradeExec < 1) throw AForm::GradeTooHighException();
  if (150 < gradeSign || 150 < gradeExec) throw AForm::GradeTooLowException();
  std::cout << name_ << " created." << std::endl;
}

AForm::~AForm() {}

AForm::AForm(AForm const &other)
    : name_(other.name_),
      signed_(other.signed_),
      gradeSign_(other.gradeSign_),
      gradeExec_(other.gradeExec_) {
  std::cout << name_ << " created by copy." << std::endl;
  *this = other;
}

AForm &AForm::operator=(AForm const &other) {
  signed_ = other.signed_;
  return (*this);
}

// Getters
std::string const &AForm::getName() const { return (name_); }
bool AForm::getSigned() const { return (signed_); }
int AForm::getGradeSign() const { return (gradeSign_); }
int AForm::getGradeExec() const { return (gradeExec_); }

// Exceptions
void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (signed_ == false) {
    signed_ = true;
  }
  std::cout << bureaucrat.getName() << " signed " << this->getName()
            << std::endl;
}

// Grade Errors
const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade must be 1 or more.";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade must be 150 or less.";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed.";
}

// Operator overload
std::ostream &operator<<(std::ostream &out, AForm const &form) {
  out << form.getName() << " is ";
  if (form.getSigned() == true)
    out << "signed";
  else
    out << "not signed"
        << " and requires " << form.getGradeSign() << " to sign. " << std::endl;
  return out;
}
