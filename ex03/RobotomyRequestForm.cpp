#include "RobotomyRequestForm.hpp"

#include "AForm.hpp"

// Constructor destructor copy constructor operator overload
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &other) {
  AForm::operator=(other);
  target_ = other.target_;
  return (*this);
}

// execute
void RobotomySurgery(std::string target) {
  if (std::rand() % 2)
    std::cout << target << " : It's a success!" << std::endl;
  else
    std::cout << target << " : It's a failure!" << std::endl;
};

void RobotomyRequestForm::execute(Bureaucrat const &excutor) const {
  try {
    if (excutor.getGrade() > getGradeExec())
      throw AForm::GradeTooLowException();
    else if (getSigned() == false)
      throw AForm::FormNotSignedException();
    else
      RobotomySurgery(this->target_);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

// Operator overload
std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form) {
  out << "RobotomySurgery " << form.getName() << " is ";
  if (form.getSigned() == true)
    out << "signed";
  else
    out << "not signed"
        << " and requires " << form.getGradeSign() << " to sign. " << std::endl;
  return out;
}
