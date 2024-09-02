#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("default shrubberyCreationForm", 145, 137), target("Nontarget")
{
    // std::cout << "ShrubberyCreationForm Default Constructor Called" << '\n';
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    // std::cout << "ShrubberyCreationForm Default Destructor Called" << '\n';
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm)
{
    *this = shrubberyCreationForm;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
    if (&shrubberyCreationForm != this)
    {
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm(target + "Form", 145, 137), target(target)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::checkExecutable(executor);
    
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream outfile(filename.c_str());

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
        std::cout << "Shrubbery created successfully in " << target << "_shrubbery" << '\n';
    } else {
        std::cout << "Failed to create the file" << '\n';
    }
}

const std::string& ShrubberyCreationForm::getTarget(void) const
{
    return (this->target);
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& shrubberyCreationForm)
{
    out << static_cast<const AForm&>(shrubberyCreationForm);
    out << "target: " << shrubberyCreationForm.getTarget() << '\n';
    return (out);
}
