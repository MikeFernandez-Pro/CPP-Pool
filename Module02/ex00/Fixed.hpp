/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:35:22 by user42            #+#    #+#             */
/*   Updated: 2020/09/27 11:01:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {

public:

	Fixed( void );
	Fixed( Fixed const & src );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	Fixed &	operator=( Fixed const & rhs );


private :

	int					_Integer;
	static const int	_Bits;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif
