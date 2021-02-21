/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:30:27 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 20:13:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class	Bureaucrat
{

	public:

		Bureaucrat( void );
		Bureaucrat( const std::string, int );
		Bureaucrat( Bureaucrat const & src );
		virtual ~Bureaucrat( void ) {};
		Bureaucrat &	operator=( Bureaucrat const & rhs );
		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void				demote( void );
		void				promute( void );
		void				SignForm( Form *) const;
		void				executeForm( Form const & form);

	class GradeTooHighException : public std::exception
	{

		public:
			GradeTooHighException( void ) {};
			GradeTooHighException( GradeTooHighException const & src );
			virtual ~GradeTooHighException( void ) throw() {};
			GradeTooHighException &	operator=( GradeTooHighException const & rhs );
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

		public:
			GradeTooLowException( void ) {};
			GradeTooLowException( GradeTooLowException const & src );
			virtual ~GradeTooLowException( void ) throw(){};
			GradeTooLowException &	operator=( GradeTooLowException const & rhs );
			virtual const char* what() const throw();
	};

	private :

		const std::string	_name;
		int					_grade;

};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#include "Form.hpp"

#endif