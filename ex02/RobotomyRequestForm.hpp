#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const static int _signGrade = 72;
		const static int _execGrade = 45;
		bool _signed;
		const string _name;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &);
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &);
		RobotomyRequestForm(const string &name);
		~RobotomyRequestForm();
		// void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

#endif
