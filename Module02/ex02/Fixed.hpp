/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:35:22 by user42            #+#    #+#             */
/*   Updated: 2020/09/27 22:35:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath>

class	Fixed {

public:

	Fixed( void );
	Fixed( Fixed const & src );
	Fixed( const int _Value );
	Fixed( const float _Float );
	~Fixed( void );


	Fixed				&	operator=( Fixed const & rhs );
	Fixed					operator+( Fixed const & rhs ) const;
	Fixed					operator-( Fixed const & rhs ) const;
	Fixed					operator*( Fixed const & rhs ) const;
	Fixed					operator/( Fixed const & rhs ) const;
	bool					operator>( Fixed const & rhs ) const;
	bool					operator>=( Fixed const & rhs ) const;
	bool					operator<( Fixed const & rhs ) const;
	bool					operator<=( Fixed const & rhs ) const;
	bool					operator==( Fixed const & rhs ) const;
	bool					operator!=( Fixed const & rhs )const;


	Fixed				&	operator++(void);
    Fixed  					operator++(int); 
	Fixed				&	operator--(void);
	Fixed  					operator--(int);
	static const Fixed	&	min(const Fixed &a, const Fixed &b);
	static const Fixed	&	max(const Fixed &a, const Fixed &b);
	static Fixed		&	min(Fixed &a, Fixed &b);
	static Fixed		&	max(Fixed &a, Fixed &b);


	int						getRawBits( void ) const;
	void					setRawBits( int const raw);
	float					toFloat(void) const;
	int						toInt(void) const;

private :	

	int					_Value;
	static const int	_Bits;
};


const Fixed  &min(const Fixed &a, const Fixed &b);
const Fixed  &max(const Fixed &a, const Fixed &b);

std::ostream	& operator<<( std::ostream & o, Fixed const & rhs );


#endif
