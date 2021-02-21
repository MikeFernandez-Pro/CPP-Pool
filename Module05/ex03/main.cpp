	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:59:15 by user42            #+#    #+#             */
/*   Updated: 2020/10/10 21:34:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"


int main(void)
{
	std::cout << "\033[1;33mTEST MAKE FORM PRESIDENTIAL PARDON: \033[0;m" << std::endl << std::endl;


	try
	{
		Intern someRandomIntern;
		Form *rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "PresidentialForm");
		Bureaucrat President("President", 1);
		President.SignForm(rrf);
		President.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;33mTEST MAKE FORM ROBOTOMY REQUEST: \033[0;m" << std::endl << std::endl;
	
	try
	{
		Intern someRandomIntern;
		Form *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "RobotomyForm");
		Bureaucrat President("President", 1);
		President.SignForm(rrf);
		President.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;33mTEST MAKE FORM SHRUBBERY CREATION \033[0;m" << std::endl << std::endl;

	try
	{
		Intern someRandomIntern;
		Form *rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "ShrubberyForm");
		Bureaucrat President("President", 1);
		President.SignForm(rrf);
		President.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

		std::cout << std::endl << "\033[1;33mTEST MAKE INVALID FORM \033[0;m" << std::endl << std::endl;

	try
	{
		Intern someRandomIntern;
		Form *rrf;
		rrf = someRandomIntern.makeForm("gezg egerzgh", "Bender");
		Bureaucrat President("President", 1);
		President.SignForm(rrf);
		President.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
