/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:29:34 by user42            #+#    #+#             */
/*   Updated: 2020/10/11 18:14:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm( void )
: Form("Default", 25, 5)
{
}


PresidentialPardonForm::PresidentialPardonForm( std::string pName)
: Form((pName) , 25, 5)
{
}


PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
{
	*this = src;
}


PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if (this != &rhs)
    	Form::operator=(rhs);
    return (*this);
}


void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() != 1)
	{
		throw PresidentialPardonForm::NotSignedException();
		return;
	}
	if (executor.getGrade() > 5)
	{
		throw PresidentialPardonForm::GradeTooLowException();
		return;
	}
	std::cout << "<" << executor.getName() << "> a été pardonné par Zafod Beeblebrox." << std::endl;
}


std::ostream &	operator<<( std::ostream &o, PresidentialPardonForm const & rhs )
{
	if (rhs.getSigned() == 1)
		o << "PresidentialPardonForm <" << rhs.getName() << "> is signed and it needs a grade <"
		<< rhs.getGradeToBeSigned() << "> to be signed and a grade <"
		<< rhs.getGradeToBeExecuted() << "> to be exectued." << std::endl;
	else
		o << "PresidentialPardonForm <" << rhs.getName() << "> is unsigned and it needs a grade <"
		<< rhs.getGradeToBeSigned() << "> to be signed and a grade <"
		<< rhs.getGradeToBeExecuted() << "> to be exectued." << std::endl;
	return (o);
}