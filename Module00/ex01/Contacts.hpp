/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:50:50 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 21:02:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>

class	Contacts {

public:

	Contacts( void );
	~Contacts( void ) ;

	std::string		getInfos( int i ) const;
	void			setInfos( std::string infos, int i );

private:

	std::string _infos[11];

};

#endif
