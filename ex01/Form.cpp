#include "Form.hpp"

Form::Form(std::string const name, int const gradeSign, int const gradeExec) : name_(name), signed_(false), gradeSign_(gradeSign), gradeExec_(gradeExec) {
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

~Form::Form() {}

std::ostream &operator<<(std::ostream &out, Form const &form) {
	out << form.getName();
	if (signed == true)
		out << " signed " << form.getGradeSign();
	else if (signed == false)
		out << "  couldn’t sign " << form.getGradeSign() << " because " << form.getGradeExec();
	return out;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
	if (sined_ == false) {
		signed_ = true;
	}
}
