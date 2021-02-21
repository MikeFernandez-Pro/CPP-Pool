/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:30:27 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 17:59:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class	Form
{

	public:

		Form( void );
		Form( std::string pName, int pGradeToBeSigned, int pGradeToBeExecuted);
		Form( Form const & src );
		virtual ~Form( void ) {}
		Form &	operator=( Form const & rhs );

		std::string	getName( void ) const;
		bool		getSigned( void ) const;
		int			getGradeToBeSigned( void ) const;
		int			getGradeToBeExecuted( void ) const;
		void		beSigned(const Bureaucrat &);

	class GradeTooHighException : public std::exception
	{

		public:
			GradeTooHighException( void ) {}
			GradeTooHighException( GradeTooHighException const & src );
			virtual ~GradeTooHighException( void ) throw(){}
			GradeTooHighException &	operator=( GradeTooHighException const & rhs );
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

		public:
			GradeTooLowException( void ) {}
			GradeTooLowException( GradeTooLowException const & src );
			virtual ~GradeTooLowException( void ) throw() {}
			GradeTooLowException &	operator=( GradeTooLowException const & rhs );
			virtual const char* what() const throw();
	};

	class AlreadysignedException : public std::exception
	{

		public:
			AlreadysignedException( void ) {}
			AlreadysignedException( AlreadysignedException const & src );
			virtual ~AlreadysignedException( void ) throw() {}
			AlreadysignedException &	operator=( AlreadysignedException const & rhs );
			virtual const char* what() const throw();
	};

	private :

		const std::string	_name;
		bool				_signed;
		const	int			_gradeToBeSigned;
		const	int			_gradeToBeExecuted;

};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif