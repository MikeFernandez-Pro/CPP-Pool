/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:44:45 by user42            #+#    #+#             */
/*   Updated: 2020/10/22 13:44:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<char> arrayc(7);
    Array<int> arrayi(4);
    Array<int> testarrayi(arrayi);

	std::cout << "\033[1;33m" << "TEST CREATION EMPTY ARRAY :" << "\033[0;m" << std::endl;
	Array<int> emptytab;
    std::cout << emptytab.size() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST FILL ARRAY OF CHAR WITH OPERATOR [] :" << "\033[0;m" << std::endl << std::endl;
    try {
        for (unsigned int i = 0; i < arrayc.size(); i++){
           arrayc.operator[](i) = ('a' + i);
           std::cout << arrayc.operator[](i) << std::endl;
        }
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "\033[1;33m" << "TEST FILL BAD ARRAY :" << "\033[0;m" << std::endl << std::endl;
    try {
        for (unsigned int i = 0; i < arrayi.size() + 5; i++){
            arrayi[i] = 0 + i;
            std::cout << arrayi[i] << std::endl;
        }
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	

	std::cout << std::endl << "\033[1;33m" << "TEST FILL ARRAY INT :" << "\033[0;m" << std::endl << std::endl;
    try {
        for (unsigned int i = 0; i < arrayi.size(); i++){
            arrayi[i] = 0 + i;
            std::cout << arrayi[i] << std::endl;
        }
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


	Array<const int> constarrayint(arrayi);
    Array<const char> constarraychar(arrayc);
    Array<const int> constarrayintempty(emptytab);

	std::cout << std::endl << "\033[1;33m" << "TEST COPY ARRAY INT :"<< "\033[0;m" << std::endl << std::endl;
    try {
        for (unsigned int i = 0; i < constarrayint.size(); i++)
            std::cout << constarrayint[i] << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << std::endl<< "\033[1;33m" << "TEST DES CONSTS (A DECOMMENTER POUR TEST) :" << "\033[0;m" << std::endl << std::endl;
	//constarrayint[1] = 0;
	//constarraychar[1] = 'z';
}