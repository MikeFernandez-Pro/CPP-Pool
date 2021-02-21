/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:35:22 by user42            #+#    #+#             */
/*   Updated: 2020/09/27 15:03:32 by user42           ###   ########.fr       */
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

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed &	operator=( Fixed const & rhs );


private :	

	int					_Value;
	static const int	_Bits;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif
