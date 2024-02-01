#include "Bureaucrat.hpp"

#include <stdexcept>
#include <string>

// Constructor, destructor, copy constructor, assignation operator
Bureaucrat::Bureaucrat(std::string const &name, int grade) : name_(name) {
  std::cout << "Bureaucrat " << name_ << " created." << std::endl;
  try {
    if (grade < MAX_GRADE) {
      grade_ = grade;
      throw GradeTooHighException();
    } else if (MIN_GRADE < grade) {
      grade_ = grade;
      throw GradeTooLowException();
    } else
      grade_ = grade;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat " << name_ << " destroyed." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name_(other.name_) {
  std::cout << "Bureaucrat " << name_ << " created by copy." << std::endl;
  *this = other;
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
  try {
    if (grade_ - 1 < MAX_GRADE || grade_ < MAX_GRADE)
      throw GradeTooHighException();
    else
      grade_--;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void Bureaucrat::decrementGrade() {
  try {
    if (MIN_GRADE < grade_ + 1 || MIN_GRADE < grade_)
      throw GradeTooLowException();
    else
      grade_++;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void Bureaucrat::signAForm(AForm &form) {
  try {
    if (form.getSigned() == true) throw isSigned();
    if (form.getGradeSign() < grade_) throw isBureaucratGradeLow();
    form.beSigned(*this);
  } catch (std::exception &e) {
    std::cout << name_ << "  couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

// Signed Error
const char *Bureaucrat::isSigned::what() const throw() {
  return "it is already signed.";
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

void Bureaucrat::executeForm(AForm const & form) {
  try {
	if (form.getSigned() == false) throw isSigned();
	if (form.getGradeExec() < grade_) throw isBureaucratGradeLow();
	form.execute(*this);
	std::cout << name_ << " executes " << form.getName() << std::endl;
  } catch (std::exception &e) {
	std::cout << name_ << "  couldn't execute " << form.getName() << " because "
			  << e.what() << std::endl;
  }
}

// Operator << overload
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return (out);
}
