#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <random>

class Form {
	private:
		std::string const	name_;
		bool				signed_;
		int const			gradeSign_;
		int const			gradeExec_;
	public:
		Form(std::string const name, int const gradeSign, int const gradeExec);
		~Form();
		Form(Form const &other);
		Form &operator=(Form const &other);

		void beSigned(Bureaucrat const &bureaucrat);
		void signForm();
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif // FORM_HPP
