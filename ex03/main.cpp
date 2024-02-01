#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    // Create a bureaucrat
    Bureaucrat bureaucrat("John", 100);

    // Create an intern
    Intern intern;

    // Create forms using the intern
    AForm* form1 = intern.makeForm("presidential pardon", "target1");
    AForm* form2 = intern.makeForm("robotomy request", "target2");
    AForm* form3 = intern.makeForm("shrubbery creation", "target3");
    AForm* form4 = intern.makeForm("shrubbery", "target4");

	std::cout << *form1 << *form2 << *form3 << std::endl;
	std::cout << form4 << std::endl;

    // Sign forms
    bureaucrat.signAForm(*form1);
    bureaucrat.signAForm(*form2);
    bureaucrat.signAForm(*form3);

	std::cout << *form1 << *form2 << *form3 << std::endl;

    // Execute forms
    bureaucrat.executeForm(*form1);
    bureaucrat.executeForm(*form2);
    bureaucrat.executeForm(*form3);

    // Clean up
    delete form1;
    delete form2;
    delete form3;

    return 0;
}

