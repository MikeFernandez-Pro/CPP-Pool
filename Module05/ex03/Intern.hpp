/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:03:38 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 17:05:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

class	Intern
{

	public:

		Intern( void ) {}
		Intern( Intern const & src );
		virtual ~Intern( void ) {}
		Intern &	operator=( Intern const & rhs );
		Form *					makeForm(std::string, std::string);

		class FormDoesnotExistException : public std::exception
		{	

			public:
				FormDoesnotExistException( void ) {};
				FormDoesnotExistException( FormDoesnotExistException const & src );
				virtual ~FormDoesnotExistException( void ) throw() {};
				FormDoesnotExistException &	operator=( FormDoesnotExistException const & rhs );
				virtual const char* what() const throw();
		};

	private :

		Form *PresidentialPardonForm1(std::string);
        Form *RobotomyRequestForm1(std::string);
        Form *ShrubberyCreationForm1(std::string);

};

#endif