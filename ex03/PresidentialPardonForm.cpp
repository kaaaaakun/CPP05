#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"

// Constructor destructor copy constructor operator overload
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target_(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &other)
    : AForm(other), target_(other.target_) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm const &other) {
  AForm::operator=(other);
  target_ = other.target_;
  return (*this);
}

// execute
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > getGradeExec())
    throw AForm::GradeTooLowException();
  else if (getSigned() == false)
    throw AForm::FormNotSignedException();
  else
    std::cout << target_ << " has been pardoned by Zafod Beeblebrox."
              << std::endl;
}

// Operator overload
std::ostream &operator<<(std::ostream &out,
                         PresidentialPardonForm const &form) {
  out << "PresidentialPardonForm " << form.getName() << " is ";
  if (form.getSigned() == true)
    out << "signed";
  else
    out << "not signed"
        << " and requires " << form.getGradeSign() << " to sign. " << std::endl;
  return out;
}
