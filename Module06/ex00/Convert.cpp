/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:24:20 by user42            #+#    #+#             */
/*   Updated: 2020/10/14 11:32:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {
	this->_str = NULL;
	this->_dbl = 0;
}

Convert::Convert(char *str) {
	int pt = 0;
	this->_str = str;
	this->_dbl = atof(this->_str);
	if (this->_dbl == -0)
		this->_dbl = 0;
	if (this->_dbl == 0 && strlen(str) == 1 && str[0] != '0')
		this->_dbl = str[0];
	else if (this->_dbl != INFINITY && this->_dbl != -INFINITY && !std::isnan(this->_dbl)){
		for (size_t i = 0; i < strlen(str); i++)
		{
			if (i == 0 && (str[i] == '-' || str[i] == '+'))
				i++;
			if (i != strlen(str) - 1 && isdigit(str[i]) == 0 && str[i] != '.')
				throw (Convert::NotValidException());
			if (str[i] == '.')
				pt += 1;
			if (pt > 1 || (i == strlen(str) - 1 && str[i] != '.' && str[i] != 'f' && isdigit(str[i]) == 0))
				throw (Convert::NotValidException());
		}
	}
		
}


Convert::Convert(Convert const & src) {
	Convert::operator=(src);
}


Convert &					Convert::operator=( Convert const & rhs) {
	if (this != &rhs)
	{
		this->_str = rhs._str;
		this->_dbl = rhs._dbl;
	}
	return (*this);
}


double				Convert::get_dbl(){
	return (this->_dbl);
}


Convert::operator char(){
	return (static_cast<char>(this->_dbl));
}


void					Convert::convertInChar(){
	char c;

	if (std::isnan(this->_dbl) ||  this->_dbl > static_cast<double>(CHAR_MAX) ||
	this->_dbl < static_cast<double>(CHAR_MIN) || floor(this->_dbl) != this->_dbl)
		std::cout << "char : " << "impossible" << std::endl;
	else {
		if (!std::isprint(static_cast<char>(this->_dbl)))
			std::cout << "char : " << "Non displayable" << std::endl;
		else
			std::cout << "char : '" << (c = Convert(this->_str)) << "'" << std::endl;
	}
}


void					Convert::convertInInt(){
	if (std::isnan(this->_dbl) || this->_dbl > static_cast<double>(INT_MAX) || this->_dbl < static_cast<double>(INT_MIN))
		std::cout << "int : " << "impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(this->_dbl) << std::endl;
}


void					Convert::convertInFloat(){

	if (std::isnan(this->_dbl))
		std::cout << "float : nanf" << std::endl;
	else if (this->_dbl == INFINITY)
		std::cout << "float : " << "inff" << std::endl;
	else if (this->_dbl == -INFINITY)
		std::cout << "float : " << "-inff" << std::endl;
	else if (this->_dbl > static_cast<double>(FLT_MAX) || this->_dbl < static_cast<double>(-FLT_MAX))
		std::cout << "float : " << "impossible" << std::endl;
	else if (floor(this->_dbl) != this->_dbl)
		std::cout << "float : " << this->_dbl << "f" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(this->_dbl) << ".0f" << std::endl;
}


void					Convert::convertInDouble(){
	if (std::isnan(this->_dbl))
		std::cout << "double : nan" << std::endl;
	else if (this->_dbl == INFINITY)
		std::cout << "double : " << "inf" << std::endl;
	else if (this->_dbl == -INFINITY)
		std::cout << "double : " << "-inf" << std::endl;
	else if (this->_dbl > static_cast<double>(DBL_MAX) || this->_dbl < static_cast<double>(-DBL_MAX))
		std::cout << "double : " << "impossible" << std::endl;
	else if (floor(this->_dbl) != this->_dbl)
		std::cout << "double : " << this->_dbl << std::endl;
	else
		std::cout << "double : " << this->_dbl << ".0" << std::endl;
}

Convert::NotValidException::NotValidException(void) {}

Convert::NotValidException::~NotValidException(void) throw() {}

Convert::NotValidException::NotValidException(const Convert::NotValidException &src)
{
  Convert::NotValidException::operator=(src);
}

Convert::NotValidException& Convert::NotValidException::operator=(const Convert::NotValidException& rhs)
{
	(void)rhs;
  return(*this);
}

char const        *Convert::NotValidException::what(void) const throw()
{
  return("Not valid argument");
}