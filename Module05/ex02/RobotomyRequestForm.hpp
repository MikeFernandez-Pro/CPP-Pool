/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:51:56 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 20:13:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class	RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string pName);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm( void ) {}
		RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );

		virtual void	execute(Bureaucrat const & executor) const;

};

std::ostream &	operator<<( std::ostream & o, RobotomyRequestForm const & rhs );

#endif