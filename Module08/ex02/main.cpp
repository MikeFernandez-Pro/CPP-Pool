/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:07:38 by user42            #+#    #+#             */
/*   Updated: 2020/10/25 22:27:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	
	std::cout << "\033[1;36m" << "*********TEST MUTANT STACK**********" << "\033[0;m" << std::endl<< std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST EMPTY 1:" << "\033[0;m" << std::endl << std::endl;
	std::cout << mstack.empty() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST PUSH :" << "\033[0;m" << std::endl << std::endl;
	mstack.push(1);
	mstack.push(2);
	std::cout << mstack.size() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST POP :" << "\033[0;m" << std::endl << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST SIZE :" << "\033[0;m" << std::endl << std::endl;
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	mstack.push(7);
	std::cout << mstack.size() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST ITERATOR BEGIN :" << "\033[0;m" << std::endl << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << *it << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST ITERATOR END :" << "\033[0;m" << std::endl << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << *ite << std::endl;
	
	std::cout << std::endl << "\033[1;33m" << "TEST INC ITERATOR :" << "\033[0;m" << std::endl << std::endl;
	++it;
	std::cout << *it << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST DEC ITERATOR :" << "\033[0;m" << std::endl << std::endl;
	--it;
	std::cout << *it << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST BOUCLE ITERATOR :" << "\033[0;m" << std::endl << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl << "\033[1;33m" << "TEST TOP :" << "\033[0;m" << std::endl << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST EMPTY 2:" << "\033[0;m" << std::endl << std::endl;
	std::cout << mstack.empty() << std::endl;



	std::cout << std::endl << std::endl << "\033[1;36m" << "**********TEST VECTOR**********" << "\033[0;m" << std::endl<< std::endl;

	std::vector<int> vector;

	std::cout << std::endl << "\033[1;33m" << "TEST EMPTY 1 :" << "\033[0;m" << std::endl << std::endl;
	std::cout << vector.empty() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST PUSH :" << "\033[0;m" << std::endl << std::endl;
	vector.push_back(1);
	vector.push_back(2);
	std::cout << vector.size() << std::endl;


	std::cout << std::endl << "\033[1;33m" << "TEST POP :" << "\033[0;m" << std::endl << std::endl;
	vector.pop_back();
	std::cout << vector.size() << std::endl;


	std::cout << std::endl << "\033[1;33m" << "TEST SIZE :" << "\033[0;m" << std::endl << std::endl;
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);
	vector.push_back(7);
	std::cout << vector.size() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST ITERATOR BEGIN :" << "\033[0;m" << std::endl << std::endl;
	std::vector<int>::iterator itv = vector.begin();
	std::cout << *itv << std::endl;


	std::cout << std::endl << "\033[1;33m" << "TEST ITERATOR END :" << "\033[0;m" << std::endl << std::endl;
	std::vector<int>::iterator itve = vector.end();
	std::cout << *itve << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST INC ITERATOR :" << "\033[0;m" << std::endl << std::endl;
	++itv;
	std::cout << *itv << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST DEC ITERATOR :" << "\033[0;m" << std::endl << std::endl;
	--itv;
	std::cout << *itv << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST BOUCLE ITERATOR :" << "\033[0;m" << std::endl << std::endl;
	while (itv != itve)
	{
		std::cout << *itv << std::endl;
		++itv;
	}

	std::cout << std::endl << "\033[1;33m" << "TEST EMPTY 2 :" << "\033[0;m" << std::endl << std::endl;
	std::cout << vector.empty() << std::endl;
	


	std::cout << std::endl << std::endl << "\033[1;36m" <<  "**********TEST DEEPCOPY**********" << std::endl;
	
	MutantStack<int> cpystack(mstack);

	std::cout << std::endl << "\033[1;33m" << "TEST ITERATORS BEGIN:" << "\033[0;m" << std::endl << std::endl;
	MutantStack<int>::iterator oit = mstack.begin();
	MutantStack<int>::iterator nit = cpystack.begin();
	std::cout << "Origin : " << *oit << " - Copy : " << *nit << std::endl;
	std::cout << "Origin : " << &oit << " - Copy : " << &nit << std::endl;


	std::cout << std::endl << "\033[1;33m" << "TEST ITERATORS END:" << "\033[0;m" << std::endl << std::endl;
	MutantStack<int>::iterator oite = mstack.end();
	MutantStack<int>::iterator nite = cpystack.end();
	std::cout << "Origin : " << *oite << " - Copy : " << *nite << std::endl;
	std::cout << "Origin : " << &oite << " - Copy : " << &nite << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST SIZE:" << "\033[0;m" << std::endl << std::endl;
	std::cout << cpystack.size() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST VALUES:" << "\033[0;m" << std::endl << std::endl;
	while (nit != nite)
	{
		std::cout << *nit << std::endl;
		++nit;
	}

	std::cout << std::endl << "\033[1;33m" << "TEST TOP :" << "\033[0;m" << std::endl << std::endl;
	std::cout << cpystack.top() << std::endl;


	std::cout << std::endl << "\033[1;33m" << "TEST EMPTY :" << "\033[0;m" << std::endl << std::endl;
	std::cout << cpystack.empty() << std::endl;


	return 0;
}