/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:29:34 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 17:12:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


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


std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}


int			Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}


void		Bureaucrat::demote( void )
{
	if (this->_grade < 150)
		this->_grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
	
}


void		Bureaucrat::promute( void )
{
	if (this->_grade > 1)
		this->_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
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