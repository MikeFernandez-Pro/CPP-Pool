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

int main(void)
{
	std::cout << "\033[1;33mTest Shrubbery  invalide: \033[0;m" << std::endl << std::endl;
	try
	{
		Bureaucrat Assistant("Assistant", 140);
		std::cout << Assistant << std::endl;
		ShrubberyCreationForm ForestForm("ForestForm");
		std::cout << ForestForm << std::endl;
		Assistant.SignForm(&ForestForm);
		Assistant.executeForm(ForestForm);
	}
	catch (std::exception & e)
	{
		std::cerr << std::endl << "\033[1;31mError : " << e.what() << "\033[0;m" << std::endl;
	}


	std::cout << std::endl << "\033[1;33mTest Shrubbery  valide: \033[0;m" << std::endl << std::endl;
	try
	{
		Bureaucrat Assistant("Assistant", 134);
		std::cout << Assistant << std::endl;
		ShrubberyCreationForm ForestForm("ForestForm");
		std::cout << ForestForm << std::endl;
		Assistant.SignForm(&ForestForm);
		Assistant.executeForm(ForestForm);
	}
	catch (std::exception & e)
	{
		std::cerr << std::endl << "\033[1;31mError : " << e.what() << "\033[0;m" << std::endl;
	}


	std::cout << std::endl << "\033[1;33mTest Robotomies invalide: \033[0;m" << std::endl << std::endl;
	try
	{
		Bureaucrat Assistant("Assistant", 60);
		std::cout << Assistant << std::endl;
		RobotomyRequestForm  RobotomyForms("RobotomyForm1");
		std::cout << RobotomyForms << std::endl;
		Assistant.SignForm(&RobotomyForms);
		Assistant.executeForm(RobotomyForms);
	}
	catch (std::exception & e)
	{
		std::cerr << std::endl << "\033[1;31mError : " << e.what() << "\033[0;m" << std::endl;
	}


	std::cout << std::endl << "\033[1;33mTest Robotomies valide: \033[0;m" << std::endl << std::endl;
	try
	{
		Bureaucrat Assistant("Assistant", 30);
		std::cout << Assistant << std::endl;
		RobotomyRequestForm  RobotomyForms[5] = {	RobotomyRequestForm("RobotomyForm1"),
													RobotomyRequestForm("RobotomyForm2"),
													RobotomyRequestForm("RobotomyForm3"),
													RobotomyRequestForm("RobotomyForm4"),
													RobotomyRequestForm("RobotomyForm5")};
		for (size_t i = 0; i < 5; i++)
			std::cout << RobotomyForms[i] << std::endl;
		for (size_t i = 0; i < 5; i++)
			Assistant.SignForm(&RobotomyForms[i]);
		for (size_t i = 0; i < 5; i++)
			Assistant.executeForm(RobotomyForms[i]);
	}
	catch (std::exception & e)
	{
		std::cerr << std::endl << "\033[1;31mError : " << e.what() << "\033[0;m" << std::endl;
	}


	std::cout << std::endl << "\033[1;33mTest PresidentialPardon invalide: \033[0;m" << std::endl << std::endl;
	try
	{
		Bureaucrat Assistant("Assistant", 23);
		std::cout << Assistant << std::endl;
		PresidentialPardonForm  PresidentForms("PresidentForm1");
		std::cout << PresidentForms << std::endl;
		Assistant.SignForm(&PresidentForms);
		Assistant.executeForm(PresidentForms);
	}
	catch (std::exception & e)
	{
		std::cerr << std::endl << "\033[1;31mError : " << e.what() << "\033[0;m" << std::endl;
	}


	std::cout << std::endl << "\033[1;33mTest PresidentialPardon valide: \033[0;m" << std::endl << std::endl;
	try
	{
		Bureaucrat Assistant("Assistant", 1);
		std::cout << Assistant << std::endl;
		PresidentialPardonForm  PresidentForms("PresidentForm1");
		std::cout << PresidentForms << std::endl;
		Assistant.SignForm(&PresidentForms);
		Assistant.executeForm(PresidentForms);
	}
	catch (std::exception & e)
	{
		std::cerr << std::endl << "\033[1;31mError : " << e.what() << "\033[0;m" << std::endl;
	}

	std::cout << std::endl << "\033[1;33mTest Document non signé: \033[0;m" << std::endl << std::endl;
	try
	{
		Bureaucrat President("President", 1);
		std::cout << President << std::endl;
		PresidentialPardonForm  PresidentForms("PresidentForm1");
		std::cout << PresidentForms << std::endl;
		President.executeForm(PresidentForms);
	}
	catch (std::exception & e)
	{
		std::cerr << std::endl << "\033[1;31mError : " << e.what() << "\033[0;m" << std::endl;
	}


	return (0);
}
