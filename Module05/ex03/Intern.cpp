/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:00:24 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 18:53:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern( Intern const & src )
{
	Intern::operator=(src);
}

Intern &	Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return ( *this );
}

Form *						Intern::makeForm(std::string name, std::string str2)
{
	std::string 	str[3] = {"PRESIDENTIAL PARDON", "ROBOTOMY REQUEST", "SHRUBBERY CREATION"};
	Form *			(Intern::*forms[3])(std::string target) = {&Intern::PresidentialPardonForm1, &Intern::RobotomyRequestForm1, &Intern::ShrubberyCreationForm1};
	std::string		str1 = name;

	for (unsigned long j = 0; j < str1.length(); ++j)
	{
		str1.at(j) = std::toupper(str1.at(j));
	}
	for (int i = 0; i < 3; i++)
	{
		if (str[i] == str1)
		{
			std::cout << "Intern creates <" << str2 << ">" << std::endl;
			return ((this->*forms[i])(str2));
		}
	}
	throw Intern::FormDoesnotExistException();
	return (NULL);
}

Form *						Intern::PresidentialPardonForm1(std::string name){
	return (new PresidentialPardonForm(name));
}

Form *						Intern::RobotomyRequestForm1(std::string name){
	return (new RobotomyRequestForm(name));
}

Form *						Intern::ShrubberyCreationForm1(std::string name){
	return (new ShrubberyCreationForm(name));
}


Intern::FormDoesnotExistException::FormDoesnotExistException( FormDoesnotExistException const & src )
{
	this->operator=(src);
}


Intern::FormDoesnotExistException &	Intern::FormDoesnotExistException::operator=( FormDoesnotExistException const & rhs )
{
	(void)rhs;
	return (*this);
}


const char* Intern::FormDoesnotExistException::what() const throw()
{
	return ("\033[1;31mError : No Form match with this name\033[0;m");
}
