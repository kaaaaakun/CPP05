#include "Bureaucrat.hpp"

#include <stdexcept>
#include <string>

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name_(name) {
  try {
    if (grade < MAX_GRADE) {
      grade_ = MAX_GRADE - 1;
      throw GradeTooHighException();
    } else if (MIN_GRADE < grade) {
      grade_ = MIN_GRADE + 1;
      throw GradeTooLowException();
    } else
      grade_ = grade;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Bureaucrat " << name_ << " created." << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat " << name_ << " destroyed." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name_(other.name_) {
  *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
  grade_ = other.grade_;
  return (*this);
}

std::string const &Bureaucrat::getName() const { return (name_); }

int Bureaucrat::getGrade() const { return (grade_); }

void Bureaucrat::incrementGrade() {
  try {
    if (grade_ - 1 < MAX_GRADE)
      throw GradeTooHighException();
    else
      grade_--;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void Bureaucrat::decrementGrade() {
  try {
    if (MIN_GRADE < grade_ + 1)
      throw GradeTooLowException();
    else
      grade_++;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low.";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return (out);
}
