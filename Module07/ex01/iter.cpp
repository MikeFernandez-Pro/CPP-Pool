/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:43:02 by user42            #+#    #+#             */
/*   Updated: 2020/10/22 13:43:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T>
void	iter(T const *tab, size_t const lenght, void (*f)(T const &)) {
	if (tab)
	{
		for (size_t i = 0; i < lenght; i++)
			f(tab[i]);
	}
}

template< typename T>
void	display(T &it) {
	std::cout << it << std::endl;
}

int main(void)
{
	int         num[] = {4, 8, 15, 15, 23, 42};
	char		tab[] = {'a', 'b', 'c', 'd'};
    std::string str[] = {"bonjour", "coucou", "aurevoir"};

    std::cout << "\033[1;33m" << "TEST INT ARRAY : " << "\033[0;m" << std::endl << std::endl;
    iter <int>(num, 6, display);
    std::cout << std::endl;

	   std::cout << "\033[1;33m" << "TEST CHAR ARRAY : " << "\033[0;m" << std::endl << std::endl;
    iter <char>(tab, 4, display);
    std::cout << std::endl;

    std::cout << "\033[1;33m" << "TEST STRING ARRAY : " << "\033[0;m" << std::endl << std::endl;
    iter(str, 3, display);
    std::cout << std::endl;
	
	return 0;
}