/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:17:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/14 10:36:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

struct Data
{
	std::string s1;
    int  		n;
	std::string s2;
};

void * serialize(void)
{
	Data *datasCpy = new Data;
	void *ptrCpy;
	char randomLetter [27] = "abcdefghijklmnopqrstuvwxyz";
	char cpys1[9];
	char cpys2[9];

	for (size_t i = 0; i < 8; i++)
		cpys1[i] = randomLetter[rand() % 26];
	cpys1[8] = '\0';
	for (size_t i = 0; i < 8; i++)
		cpys2[i] = randomLetter[rand() % 26];
	cpys2[8] = '\0';
	datasCpy->s1 = static_cast<std::string>(cpys1);
	datasCpy->s2 = static_cast<std::string>(cpys2);
	datasCpy->n = rand() % 2147483647;
	ptrCpy = static_cast<void*>(datasCpy);
	return (ptrCpy);
}

Data * deserialize(void * raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	srand(time(NULL));
	
	void *ptr = serialize();
	Data *datas = deserialize(ptr);

	std::cout << datas->s1 << std::endl;
	std::cout << datas->n << std::endl;
	std::cout << datas->s2 << std::endl;

	delete (datas);

	return (0);
}