/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:07:07 by user42            #+#    #+#             */
/*   Updated: 2020/10/26 12:47:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
    std::cout << std::endl << "\033[1;33mBASIC TEST :\033[0;m" << std::endl << std::endl;

    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << "\033[1;33mTEST CONTAINER FULL :\033[0;m" << std::endl << std::endl;
    try {
        sp.addNumber(18);
    } catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }


	std::cout << std::endl << "\033[1;33mTEST CONTAINER NOT FULL ENOUGH:\033[0;m" << std::endl << std::endl;
    Span testNotFullEnough = Span(5);
    testNotFullEnough.addNumber(1);
    try {
        std::cout << testNotFullEnough.shortestSpan() << std::endl;
    } catch (std::exception &error) {
        std::cout << "SHORTEST - " << error.what() << std::endl;
    }
    try { 
        std::cout << testNotFullEnough.longestSpan() << std::endl;
    } catch (std::exception &error) {
        std::cout << "LONGEST - " << error.what() << std::endl;
    }

	std::cout << std::endl << "\033[1;33mTEST FILLING TOO MUCH :\033[0;m" << std::endl << std::endl;
	Span fillTooMuch(5);
    try {
        for (int i = 0; i < 10; i++) {
            fillTooMuch.addNumber(i);
            std::cout << "ADD NUMBER : " << i << std::endl;
        }
    } catch (std::exception &error) {
        std::cout << error.what() << std::endl;
    }

	std::cout << std::endl << "\033[1;33mTEST LARGE CONTAINER :\033[0;m" << std::endl << std::endl;
	Span large = Span(15000);
    try {
        for (int i = 0; i < 15000; i++)
            large.addNumber(i);
    } catch (std::exception &error) {
        std::cout << "LARGE - " << error.what() << std::endl;
    }
    try { 
        std::cout << "LONGEST : " <<  large.longestSpan() << " - SHORTEST : " << large.shortestSpan() << std::endl << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	std::cout << std::endl << "\033[1;33mTEST LIMITS :\033[0;m" << std::endl << std::endl;
	Span limits = Span(2);
    try {
            limits.addNumber(INT_MAX);
			limits.addNumber(INT_MIN);
    } catch (std::exception &error) {
        std::cout << "LIMITS - " << error.what() << std::endl;
    }
    try { 
        std::cout << "LONGEST : " <<  limits.longestSpan() << " - SHORTEST : " << limits.shortestSpan() << std::endl << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[1;33mTEST CONTAINER EMPTY :\033[0;m" << std::endl << std::endl;
	Span empty = Span(0);
    try { 
        std::cout <<  empty.longestSpan() << " - SHORTEST : " << empty.shortestSpan() << std::endl << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	}
    
	return (0);
}