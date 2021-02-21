/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:29:34 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 18:16:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat( void ) : _name("Default")
{
	this->_grade = 150;
}


Bureaucrat::Bureaucrat( std::string pName, int pGrade ) : _name(pName)
{
	if (pGrade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	else if (pGrade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->_grade = pGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src): _name(src._name)
{
    Bureaucrat::operator=(src);
}


Bureaucrat      &Bureaucrat::operator=(const Bureaucrat & rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    return (*this);
}


const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}


int					Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}


void				Bureaucrat::demote( void )
{
	if (this->_grade < 150)
		this->_grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
}


void				Bureaucrat::promute( void )
{
	if (this->_grade > 1)
		this->_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
}


void				Bureaucrat::SignForm( Form *document) const
{
	if (!document)
		std::cout << "<" << this->getName() << "> can't sign the form because there is no form" << std::endl;
	else if (this->getGrade() > document->getGradeToBeSigned())
	{
		std::cout << "<" << this->getName() << "> can't sign the form because he doesn't have the grade required" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (document->getSigned() == 1)
	{
		std::cout << "<" << this->getName() << "> can't sign the form because it's already signed" << std::endl;
		throw Form::AlreadySignedException();
	}
	else
	{
		document->beSigned(*this);
		std::cout << "<" << this->getName() << "> signs <"
		<< document->getName() << ">" << std::endl;
	}
}

void				Bureaucrat::executeForm( Form const & document)
{
	if (document.getSigned() == 0)
		throw Form::NotSignedException();
	else if (this->getGrade() > document.getGradeToBeExecuted())
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << "<" << this->getName() << "> executs <"
		<< document.getName() << ">" << std::endl;
		document.execute(*this);
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException( GradeTooHighException const & src )
{
	this->operator=(src);
}


Bureaucrat::GradeTooHighException &	Bureaucrat::GradeTooHighException::operator=( GradeTooHighException const & rhs )
{
	(void)rhs;
	return (*this);
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Problem exists grade is too high");
}



Bureaucrat::GradeTooLowException::GradeTooLowException( GradeTooLowException const & src )
{
	this->operator=(src);
}


Bureaucrat::GradeTooLowException &	Bureaucrat::GradeTooLowException::operator=( GradeTooLowException const & rhs )
{
	(void)rhs;
	return (*this);
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Problem exists grade is too low");
}


std::ostream &	operator<<( std::ostream &o, Bureaucrat const & rhs )
{
	o << "<" << rhs.getName() << ">, bureaucrat grade <" << rhs.getGrade() << ">." << std::endl;
	return (o);
}