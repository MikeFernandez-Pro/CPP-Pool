/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:56:32 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 20:13:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm( void )
: Form("Default", 72, 45)
{
	srand(time(NULL));
}


RobotomyRequestForm::RobotomyRequestForm( std::string pName)
: Form(pName , 72, 45)
{
	srand(time(NULL));
}


RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
{
	*this = src;
}


RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if (this != &rhs)
    	Form::operator=(rhs);
    return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() != 1)
	{
		throw RobotomyRequestForm::NotSignedException();
		return;
	}
	if (executor.getGrade() > 45)
	{
		throw RobotomyRequestForm::GradeTooLowException();
		return;
	}
	int random  = rand() % 5;	
	if (random == 1) 
	{
		std::cout << "*BZZZZZZZ BZZZZZZZ SCRCHHHHHHHHH PLOP*" << std::endl;
		std::cout << "<" << executor.getName() << "> a été lobotomisé avec succès!" << std::endl;
	}
	else
		std::cout << "C'est encore un échec. Comme très souvent d'ailleurs..." << std::endl;
}


std::ostream &	operator<<( std::ostream &o, RobotomyRequestForm const & rhs )
{
	if (rhs.getSigned() == 1)
		o << "RobotomyRequestForm <" << rhs.getName() << "> is signed and it needs a grade <"
		<< rhs.getGradeToBeSigned() << "> to be signed and a grade <"
		<< rhs.getGradeToBeExecuted() << "> to be exectued." << std::endl;
	else
		o << "RobotomyRequestForm <" << rhs.getName() << "> is unsigned and it needs a grade <"
		<< rhs.getGradeToBeSigned() << "> to be signed and a grade <"
		<< rhs.getGradeToBeExecuted() << "> to be exectued." << std::endl;
	return (o);
}