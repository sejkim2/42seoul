#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("default shrubberyCreationForm", 145, 137), target("Nontarget")
{
    std::cout << "ShrubberyCreationForm Default Constructor Called" << '\n';
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm Default Destructor Called" << '\n';
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm)
: AForm(shrubberyCreationForm)
{
    *this = shrubberyCreationForm;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
    if (&shrubberyCreationForm != this)
    {
        AForm::operator=(shrubberyCreationForm);
        this->target = shrubberyCreationForm.getTarget();
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm(), target(target)
{
}

void ShrubberyCreationForm::executeAction(void) const
{
    std::ofstream outfile(this->getTarget() + "_shrubbery");

    const std::string tree = 
        "        /\\\n"
        "       /  \\\n"
        "      /____\\\n"
        "     /\\    /\\\n"
        "    /  \\  /  \\\n"
        "   /____\\/____\\\n"
        "       ||\n"
        "       ||\n"
        "       ||\n";
    
    
    if (outfile.is_open()) {
        outfile << tree;
        outfile.close();
        std::cout << "Shrubbery created successfully in " << target << "_shrubbery" << std::endl;
    } else {
        std::cerr << "Failed to create the file" << std::endl;
    }
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->target);
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& shrubberyCreationForm)
{
    std::cout << shrubberyCreationForm;
    return (out);
}
