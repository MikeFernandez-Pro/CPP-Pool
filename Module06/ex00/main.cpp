/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:24:26 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 23:46:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
/*
int		main(int argc, char **argv)
{
    if (argc != 2){
		std::cout << "Bad number of arguments." << std::endl;
		return (1);
	}
		Convert a = Convert(argv[1]);

		a.convertInChar();
		a.convertInInt();
		a.convertInFloat();
		a.convertInDouble();
    	return (0);

}*/

int			main(int argc, char **argv)
{
	std::cout << std::endl << "\033[1;33m" << "TEST 0" << "\033[0;m" << std::endl;
	char *test = strdup("0");
	Convert a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST 0.0f" << "\033[0;m" << std::endl; 
	test = strdup("0.0f");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST 0.0" << "\033[0;m" << std::endl; 
	test = strdup("0.0");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();

//-----------------------------------------------------------------------------------

	std::cout << std::endl << "\033[1;33m" << "TEST -42" << "\033[0;m" << std::endl;
	test = strdup("-42");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST -4.2f" << "\033[0;m" << std::endl; 
	test = strdup("-4.2f");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST -4.2" << "\033[0;m" << std::endl; 
	test = strdup("-4.2");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();

	//-----------------------------------------------------------------------------------

	std::cout << std::endl << "\033[1;33m" << "TEST 42" << "\033[0;m" << std::endl;
	test = strdup("42");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST 4.2f" << "\033[0;m" << std::endl; 
	test = strdup("4.2f");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST 4.2" << "\033[0;m" << std::endl; 
	test = strdup("4.2");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();

//-----------------------------------------------------------------------------------

	std::cout << std::endl << "\033[1;33m" << "TEST -inff" << "\033[0;m" << std::endl;
	test = strdup("-inff");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST +inff" << "\033[0;m" << std::endl; 
	test = strdup("+inff");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST nanf" << "\033[0;m" << std::endl; 
	test = strdup("nanf");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();

	//-----------------------------------------------------------------------------------

	std::cout << std::endl << "\033[1;33m" << "TEST -inf" << "\033[0;m" << std::endl;
	test = strdup("-inf");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST +inf" << "\033[0;m" << std::endl; 
	test = strdup("+inf");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST nan" << "\033[0;m" << std::endl; 
	test = strdup("nan");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();

	//-----------------------------------------------------------------------------------

	std::cout << std::endl << "\033[1;33m" << "TEST a" << "\033[0;m" << std::endl;
	test = strdup("a");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST z" << "\033[0;m" << std::endl; 
	test = strdup("z");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();


	std::cout << std::endl << "\033[1;33m" << "TEST \\0" << "\033[0;m" << std::endl; 
	test = strdup("\0");
	a = Convert(test);
	a.convertInChar();
	a.convertInInt();
	a.convertInFloat();
	a.convertInDouble();

	return (0);
}