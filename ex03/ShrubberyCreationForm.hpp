#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const static int _signGrade = 145;
		const static int _execGrade = 137;
		const string _name;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
		ShrubberyCreationForm(const string &name);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
};



#endif
