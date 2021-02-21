/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:29:34 by user42            #+#    #+#             */
/*   Updated: 2020/10/11 18:35:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form( void ) : _name("Default"), _gradeToBeSigned(1), _gradeToBeExecuted(1)
{
	this->_signed = 0;
}


Form::Form( std::string pName, int pGradeToBeSigned, int pGradeToBeExecuted)
: _name(pName) , _gradeToBeSigned(pGradeToBeSigned), _gradeToBeExecuted(pGradeToBeExecuted)
{
	if (pGradeToBeExecuted < 1 || pGradeToBeSigned < 1)
	{
		throw Form::GradeTooHighException();
		return ;
	}
	else if (pGradeToBeExecuted > 150 || pGradeToBeSigned > 150)
	{
		throw Form::GradeTooLowException();
		return ;
	}
	this->_signed = 0;
}


Form::Form( Form const & src )
: _name(src._name),
_gradeToBeSigned(src._gradeToBeSigned),
_gradeToBeExecuted(src._gradeToBeExecuted)
{
	Form::operator=(src);
}


Form &	Form::operator=( Form const & rhs )
{
	if (this != &rhs)
    	this->_signed = rhs._signed;
    return (*this);
}


std::string	Form::getName( void ) const
{
	return (this->_name);
}


bool		Form::getSigned( void ) const
{
	return (this->_signed);
}


int			Form::getGradeToBeSigned( void ) const
{
	return (this->_gradeToBeSigned);
}


int			Form::getGradeToBeExecuted( void ) const
{
	return (this->_gradeToBeExecuted);
}


void		Form::beSigned(const Bureaucrat &  officier)
{
	if (this->_signed == 1)
		throw Form::AlreadySignedException();
	else if (officier.getGrade() <= this->getGradeToBeSigned())
		this->_signed = 1;
	else
		throw Form::GradeTooLowException();
}


Form::GradeTooHighException::GradeTooHighException( GradeTooHighException const & src )
{
	this->operator=(src);
}



Form::GradeTooHighException &	Form::GradeTooHighException::operator=( GradeTooHighException const & rhs )
{
	(void)rhs;
	return (*this);
}


const char* Form::GradeTooHighException::what() const throw()
{
	return ("Problem exists the grade of the bureaucrat is too high");
}


Form::GradeTooLowException::GradeTooLowException( GradeTooLowException const & src )
{
	this->operator=(src);
}


Form::GradeTooLowException &	Form::GradeTooLowException::operator=( GradeTooLowException const & rhs )
{
	(void)rhs;
	return (*this);
}


const char* Form::GradeTooLowException::what() const throw()
{
	return ("Problem exists the grade of the bureaucrat is too low");
}


Form::AlreadySignedException::AlreadySignedException( AlreadySignedException const & src )
{
	this->operator=(src);
}


Form::AlreadySignedException &	Form::AlreadySignedException::operator=( AlreadySignedException const & rhs )
{
	(void)rhs;
	return (*this);
}


const char* Form::AlreadySignedException::what() const throw()
{
	return ("Problem exists the form is already signed!");
}


Form::NotSignedException::NotSignedException( NotSignedException const & src )
{
	this->operator=(src);
}


Form::NotSignedException &	Form::NotSignedException::operator=( NotSignedException const & rhs )
{
	(void)rhs;
	return (*this);
}


const char* Form::NotSignedException::what() const throw()
{
	return ("Problem exists the form is not signed!");
}


std::ostream &	operator<<( std::ostream &o, Form const & rhs )
{
	if (rhs.getSigned() == 1)
		o << "Form <" << rhs.getName() << "> is signed and it needs a grade <"
		<< rhs.getGradeToBeSigned() << "> to be signed and a grade <"
		<< rhs.getGradeToBeExecuted() << "> to be exectued." << std::endl;
	else
		o << "Form <" << rhs.getName() << "> is unsigned and it needs a grade <"
		<< rhs.getGradeToBeSigned() << "> to be signed and a grade <"
		<< rhs.getGradeToBeExecuted() << "> to be exectued." << std::endl;
	return (o);
}