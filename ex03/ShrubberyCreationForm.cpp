#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , _name("ShrubberyCreationForm")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &name) : AForm(name, 145, 137), _name(name)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &oder) : AForm(oder), _name(oder._name)
{
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &oder)
{
	if (this != &oder)
	{
		AForm::operator=(oder);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (GetSigned() == false)
		throw FormNotSignedException();
	std::ofstream file((executor.getName() + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::exception();
	file <<
	"              _{\\ _{\\{/}/}/}__\n"
	"             {/{/\\}{/{/\\}(\\}{/{/\\} _\n"
	"            {/{/\\}{/{/\\}(_)}{/{/\\}  _\n"
	"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
	"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
	"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
	"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
	"      _{\\{/{\\{/(_)}\\/}{/{/{/\\}\\})\\}{/\\}\n"
	"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
	"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
	"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
	"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
	"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
	"         {/(/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
	"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
	"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
	"             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
	"              {){/ {\\/}{\\/} \\}\\}\n"
	"              (_)  \\.-'.-/\n"
	"          __...--- |'-.-'| --...__\n"
	"   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
	" -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
	" .  '-  '    .--'  | '-.'|    .  '  . '\n"
	"          ' ..     |'-_.-|\n"
	"  .  '  .       _.-|-._ -|-._  .  '  .\n"
	"              .'   |'- .-|   '.\n"
	"  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
	"   .-' '        '-._______.-'     '  .\n"
	"        .      ~,\n"
	"    .       .   |\\   .    ' '-.\n"
	"    ___________/  \\____________\n"
	"   /  Why is it, when you want \\\n"
	"  |  something, it is so damn   |\n"
	"  |    much work to get it?     |\n"
	"   \\___________________________/\n";
}
