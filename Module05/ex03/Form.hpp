/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:39:31 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 11:52:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "Bureaucrat.hpp"

class	Form
{

	public:

		Form( void );
		Form( std::string pName, int pGradeToBeSigned, int pGradeToBeExecuted);
		Form( Form const & src );
		virtual ~Form( void ) {}
		Form &	operator=( Form const & rhs );

		std::string		getName( void ) const;
		bool			getSigned( void ) const;
		int				getGradeToBeSigned( void ) const;
		int				getGradeToBeExecuted( void ) const;
		void			beSigned(const Bureaucrat &);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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

	class AlreadySignedException : public std::exception
	{

		public:
			AlreadySignedException( void ) {}
			AlreadySignedException( AlreadySignedException const & src );
			virtual ~AlreadySignedException( void ) throw() {}
			AlreadySignedException &	operator=( AlreadySignedException const & rhs );
			virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{

		public:
			NotSignedException( void ) {}
			NotSignedException( NotSignedException const & src );
			virtual ~NotSignedException( void ) throw() {}
			NotSignedException &	operator=( NotSignedException const & rhs );
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