/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:30:27 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 17:12:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>
#include <string.h>

class	Bureaucrat
{

	public:

		Bureaucrat( std::string, int );
		Bureaucrat( Bureaucrat const & src );
		virtual ~Bureaucrat( void ) {}
		Bureaucrat &	operator=( Bureaucrat const & rhs );
		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		demote( void );
		void		promute( void );

	class GradeTooHighException : public std::exception
	{

		public:
			GradeTooHighException( void ) {}
			GradeTooHighException( GradeTooHighException const & src );
			virtual ~GradeTooHighException( void ) throw() {}
			GradeTooHighException &	operator=( GradeTooHighException const & rhs );
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

		public:
			GradeTooLowException( void ) {}
			GradeTooLowException( GradeTooLowException const & src );
			virtual ~GradeTooLowException( void ) throw(){}
			GradeTooLowException &	operator=( GradeTooLowException const & rhs );
			virtual const char* what() const throw();
	};

	private :

		const std::string	_name;
		int					_grade;

		Bureaucrat( void ) {}

};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif