/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:57:00 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 20:13:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm( void )
: Form("Default", 145, 137)
{
}


ShrubberyCreationForm::ShrubberyCreationForm( std::string pName)
: Form(pName, 145, 137)
{
}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
{
	*this = src;
}


ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if (this != &rhs)
    	Form::operator=(rhs);
    return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() != 1)
	{
		throw ShrubberyCreationForm::NotSignedException();
		return;
	}
	if (executor.getGrade() > 137)
	{
		throw ShrubberyCreationForm::GradeTooLowException();
		return;
	}
	std::string		cpy = executor.getName();
	cpy.append("_shrubbery");
	const char 		*newName = cpy.c_str();
	std::ofstream	newFile(newName);
	if (newFile.fail())
	{
		throw ShrubberyCreationForm::FailedCreation();
		return;
	}
	std::string trees[17] = {"          v          ", "         >X<         ", "          A          ",
							 "         d$b         ", "       .d\\$$b.       ", "     .d$i$$\\$$b.     ",
							 "        d$$@b        ", "       d\\$$$ib       ", "     .d$$$\\$$$b      ",
							 "   .d$$@$$$$\\$$ib.   ", "       d$$i$$b       ", "      d\\$$$$@$b      ",
							 "   .d$@$$\\$$$$$@b.   ", " .d$$$$i$$$\\$$$$$$b. ", "         ###         ",
							 "         ###         ", "         ###         "};
	for (size_t i = 0; i < 17; i++)
	{
    	for (size_t j = 0; j < 5; j++)
			newFile << trees[i];	
		newFile << std::endl;
	}
	newFile.close();
	std::cout << "The file <" << newName << "> was created with succes!" << std::endl;
}


ShrubberyCreationForm::FailedCreation::FailedCreation( FailedCreation const & src )
{
	this->operator=(src);
}


ShrubberyCreationForm::FailedCreation &	ShrubberyCreationForm::FailedCreation::operator=( FailedCreation const & rhs )
{
	(void)rhs;
	return (*this);
}


const char* ShrubberyCreationForm::FailedCreation::what() const throw()
{
	return ("Problem exists the creation of the file failed");
}


std::ostream &	operator<<( std::ostream &o, ShrubberyCreationForm const & rhs )
{
	if (rhs.getSigned() == 1)
		o << "ShrubberyCreationForm <" << rhs.getName() << "> is signed and it needs a grade <"
		<< rhs.getGradeToBeSigned() << "> to be signed and a grade <"
		<< rhs.getGradeToBeExecuted() << "> to be exectued." << std::endl;
	else
		o << "ShrubberyCreationForm <" << rhs.getName() << "> is unsigned and it needs a grade <"
		<< rhs.getGradeToBeSigned() << "> to be signed and a grade <"
		<< rhs.getGradeToBeExecuted() << "> to be exectued." << std::endl;
	return (o);
}