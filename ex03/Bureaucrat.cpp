#include "Bureaucrat.hpp"

#include <stdexcept>
#include <string>

// Constructor, destructor, copy constructor, assignation operator
Bureaucrat::Bureaucrat(std::string const &name, int grade) : name_(name) {
  std::cout << "Bureaucrat " << name_ << " created." << std::endl;
  if (grade < MAX_GRADE) {
    grade_ = grade;
    throw GradeTooHighException();
  } else if (MIN_GRADE < grade) {
    grade_ = grade;
    throw GradeTooLowException();
  } else
    grade_ = grade;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat " << name_ << " destroyed." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : name_(other.name_), grade_(other.grade_) {
  std::cout << "Bureaucrat " << name_ << " created by copy." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
  grade_ = other.grade_;
  return (*this);
}

// Getters
std::string const &Bureaucrat::getName() const { return (name_); }
int Bureaucrat::getGrade() const { return (grade_); }

// Grade increment and decrement
void Bureaucrat::incrementGrade() {
  if (grade_ - 1 < MAX_GRADE || grade_ < MAX_GRADE)
    throw GradeTooHighException();
  else
    grade_--;
}

void Bureaucrat::decrementGrade() {
  if (MIN_GRADE < grade_ + 1 || MIN_GRADE < grade_)
    throw GradeTooLowException();
  else
    grade_++;
}

void Bureaucrat::signAForm(AForm &form) {
  try {
    if (form.getSigned() == true) throw isSigned();
    if (form.getGradeSign() < grade_)
      throw isBureaucratGradeLow();
    else
      form.beSigned(*this);
  } catch (std::exception &e) {
    std::cout << name_ << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    if (form.getSigned() == false) throw isNotSigned();
    form.execute(*this);
    std::cout << name_ << " executes " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << name_ << " couldn't execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

// Signed Error
const char *Bureaucrat::isSigned::what() const throw() {
  return "it is already signed.";
}
const char *Bureaucrat::isNotSigned::what() const throw() {
  return "it isn't signed.";
}
const char *Bureaucrat::isBureaucratGradeLow::what() const throw() {
  return "Bureaucrat grade is too Low.";
}

// Grade Errors
const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high.";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low.";
}

// Operator << overload
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return (out);
}
