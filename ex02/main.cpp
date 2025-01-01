#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat highRank("Alice", 1);
		Bureaucrat lowRank("Bob", 150);

		ShrubberyCreationForm shrubbery("Home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Zaphod");

		cout << shrubbery << "\n" << endl;
		cout << robotomy << "\n" << endl;
		cout << pardon << "\n" << endl;

		cout << "\n-- Formları İmzalama --" << endl;
		lowRank.signForm(shrubbery);
		highRank.signForm(shrubbery);
		highRank.signForm(robotomy);
		highRank.signForm(pardon);
		highRank.signForm(pardon);
		cout << endl;
		cout << shrubbery << "\n" << endl;
		cout << robotomy << "\n" << endl;
		cout << pardon << "\n" << endl;

		cout << "\n-- Formları Yürütme --" << endl;
		lowRank.executeForm(shrubbery);
		highRank.executeForm(shrubbery);
		highRank.executeForm(robotomy);
		highRank.executeForm(pardon);
		cout << endl;
	} catch (const std::exception &e) {
		cout << "Hata: " << e.what() << endl;
	}

	return 0;
}
