#include "RobotomyRequestForm.hpp"

#include <ctime>

#include "AForm.hpp"

// Constructor destructor copy constructor operator overload
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &other) {
  if (this != &other) {
    AForm::operator=(other);
    target_ = other.target_;
  }
  return (*this);
}

// execute
void RobotomySurgery(std::string target) {
  std::cout << "ガガガ" << std::endl;
  std::srand(std::time(NULL));
  if (std::rand() % 2)
    std::cout << target << " has been lobotomized successfully " << std::endl;
  else
    std::cout << target << " has been failured to robotize!" << std::endl;
};

void RobotomyRequestForm::execute(Bureaucrat const &excutor) const {
  if (excutor.getGrade() > getGradeExec())
    throw AForm::GradeTooLowException();
  else if (getSigned() == false)
    throw AForm::FormNotSignedException();
  else
    RobotomySurgery(this->target_);
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
