/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:37:01 by user42            #+#    #+#             */
/*   Updated: 2020/10/14 13:21:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class Base { public : virtual ~Base() {} };

class A : public Base{};
class B : public Base{};
class C : public Base{};

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference( Base & p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}

int main()
{
	A originA;
	B originB;
	C originC;
	
	std::cout << "\033[1;33mTests identify_from_pointer : \033[0;m" << std::endl << std::endl;

	Base *ptr = &originA;
	identify_from_pointer(ptr);
	ptr = &originB;
	identify_from_pointer(ptr);
	ptr = &originC;
	identify_from_pointer(ptr);
	
	
	std::cout << std::endl << "\033[1;33mTests identify_from_reference : \033[0;m" << std::endl << std::endl;
	
	Base &refA = originA;
	identify_from_reference(refA);
	Base &refB = originB;
	identify_from_reference(refB);
	Base &refC = originC;
	identify_from_reference(refC);
	std::cout << std::endl;
	return (0);
}