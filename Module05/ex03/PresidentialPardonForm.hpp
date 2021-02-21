/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:51:56 by user42            #+#    #+#             */
/*   Updated: 2020/10/11 17:15:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "Form.hpp"

class	PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string pName);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		virtual ~PresidentialPardonForm( void ) {}
		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

		virtual void	execute(Bureaucrat const & executor) const;

};

std::ostream &	operator<<( std::ostream & o, PresidentialPardonForm const & rhs );

#endif