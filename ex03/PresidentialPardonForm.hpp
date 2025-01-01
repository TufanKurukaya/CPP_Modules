#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const static int _signGrade = 25;
		const static int _execGrade = 5;
		bool _signed;
		const string _name;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &);
		const PresidentialPardonForm &operator=(const PresidentialPardonForm &);
		PresidentialPardonForm(const string &name);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};
#endif
