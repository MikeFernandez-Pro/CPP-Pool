/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:46:40 by user42            #+#    #+#             */
/*   Updated: 2020/10/26 10:29:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
void chekFind(T &container, int nbr)
{
    if (easyfind(container, nbr))
    {
        std::cout << "\033[1;32m" << "The value : " << nbr << " have been finded in the container" << "\033[0;m" << std::endl;
        return ;
    }
    std::cout << "\033[1;31m" << "This container doesn't contain the value : " << nbr << "\033[0;m" << std::endl;
}

int main()
{
	std::cout << "\033[1;33m" << "TEST LIST CONTAINER : \033[0;m" << "\033[0;m" << std::endl << std::endl;

    std::list<int> lst;
    for (int i = 0; i < 20; i++)
        lst.push_back(i);
	chekFind(lst, 3);
	chekFind(lst, 10);
    chekFind(lst, 25);


	std::cout << std::endl << "\033[1;33m" << "TEST DEQUE CONTAINER : \033[0;m" << "\033[0;m" << std::endl << std::endl;

	std::deque<int> deque;
	 for (int i = 0; i < 20; i++)
        deque.push_back(i * 2);
	chekFind(deque, 4);
	chekFind(deque, 16);
    chekFind(deque, 5);
	
    std::cout << std::endl <<"\033[1;33mTEST VECTOR CONTAINER : \033[0;m" << std::endl << std::endl;

    std::vector<int> vector;
    for (int i = 0; i < 20; i++)
        vector.push_back(i * 3);
	chekFind(vector, 6);
	chekFind(vector, 15);
    chekFind(vector, 7);

};