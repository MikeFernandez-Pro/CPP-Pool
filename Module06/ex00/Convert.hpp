/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:24:11 by user42            #+#    #+#             */
/*   Updated: 2020/10/14 11:30:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <limits.h>
#include <float.h>

class Convert
{
	public:
		Convert(void);
		Convert(char *);
		Convert(Convert const &);
		virtual ~Convert(void) {}
		Convert &				operator=( Convert const &);

		double				get_dbl();
		void				convertInChar();
		void				convertInInt();
		void				convertInFloat();
		void				convertInDouble();
		operator			char();

		class NotValidException : public std::exception
    	{
			public:
				NotValidException();
				NotValidException(const NotValidException &m);
				NotValidException& operator=(const NotValidException &m);
				virtual ~NotValidException(void) throw();
				char const *what(void) const throw();
    	};

	private:
		char 				*_str;
		double				_dbl;
};

#endif
