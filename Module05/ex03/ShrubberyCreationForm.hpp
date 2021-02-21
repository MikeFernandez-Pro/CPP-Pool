/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:51:56 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 20:13:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class	ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string pName);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		virtual ~ShrubberyCreationForm( void ) {}
		ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );

		virtual void	execute(Bureaucrat const & executor) const;
	
	class FailedCreation : public std::exception
	{

		public:
			FailedCreation( void ) {}
			FailedCreation( FailedCreation const & src );
			virtual ~FailedCreation( void ) throw(){}
			FailedCreation &	operator=( FailedCreation const & rhs );
			virtual const char* what() const throw();
	};

};

std::ostream &	operator<<( std::ostream & o, ShrubberyCreationForm const & rhs );

#endif