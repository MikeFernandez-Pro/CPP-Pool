/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:59:15 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 17:19:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{	
	std::cout << "\033[1;33m" << "TEST GRADE < 1 : " << "\033[0;m" << std::endl << std::endl;
	
	try
	{
		Bureaucrat Brigitte("Brigitte", -5);
		std::cout << Brigitte << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;33m" << "TEST GRADE > 150 : " << "\033[0;m" << std::endl << std::endl;
	
	try
	{
		Bureaucrat Benoit("Benoit", 151);
		std::cout << Benoit << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;33m" << "TEST PROMUTE : " << "\033[0;m" << std::endl << std::endl;
	
	try
	{
		Bureaucrat Pierre("Pierre", 3);
		std::cout << Pierre;
		Pierre.promute();
		std::cout << Pierre;
		Pierre.promute();
		std::cout << Pierre;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl <<"\033[1;33m" << "TEST DEMOTE : " << "\033[0;m" << std::endl << std::endl;

	try
	{
		Bureaucrat Jean("Jean", 148);
		std::cout << Jean;
		Jean.demote();
		std::cout << Jean;
		Jean.demote();
		std::cout << Jean;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	std::cout << std::endl <<"\033[1;33m" << "TEST DEMOTE TOO MUCH : " << "\033[0;m" << std::endl << std::endl;

	try
	{
		Bureaucrat Jean("Jean", 148);
		std::cout << Jean;
		Jean.demote();
		std::cout << Jean;
		Jean.demote();
		std::cout << Jean;
		Jean.demote();
		std::cout << Jean;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[1;33m" << "TEST PROMUTE TOO MUCH: " << "\033[0;m" << std::endl << std::endl;
	
	try
	{
		Bureaucrat Pierre("Pierre", 3);
		std::cout << Pierre;
		Pierre.promute();
		std::cout << Pierre;
		Pierre.promute();
		std::cout << Pierre;
		Pierre.promute();
		std::cout << Pierre;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	return (0);
}

