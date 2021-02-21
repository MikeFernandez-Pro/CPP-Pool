/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:41:35 by user42            #+#    #+#             */
/*   Updated: 2020/10/22 13:41:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Awesome {
    public:
        Awesome(int n): _n(n) {}
        bool operator==(Awesome const &rhs) { return (this->_n == rhs._n); }
        bool operator=(Awesome const &rhs) { return (this->_n = rhs._n); }
        bool operator>(Awesome const &rhs) { return (this->_n > rhs._n); }
        bool operator<(Awesome const &rhs) { return (this->_n < rhs._n); }
        bool operator>=(Awesome const &rhs) { return (this->_n >= rhs._n); }
        bool operator<=(Awesome const &rhs) { return (this->_n <= rhs._n); }
    private:
        int _n;
};

template< typename T>
void		swap(T &x, T &y) {
	T swap = x;
	x = y;
	y = swap;
}

template< typename T>
T		&min(T &x, T &y) {
	return (x < y ? x : y);
}

template< typename T>
T		&max(T &x, T &y) {
	return (x > y ? x : y);
}

int main(void)
{
	int			inta = 2;
	int			intb = 1;
	float 		floata = 2.5;
	float 		floatb = 1.5;
	double 		doublea = 2.5;
	double 		doubleb = 1.5;
	char 		chara = 'a';
	char		charb = 'z';
	std::string stringa = "chaine1";
	std::string stringb = "chaine2";


	std::cout << "\033[1;33m" << "TEST DU SWAP :" << "\033[0;m" << std::endl << std::endl;
	std::cout << "\033[1;36m" << "    INT    " << "\033[0;m" << "\033[0;m" <<  std::endl;
	std::cout << "int A = " << inta << " int B = " << intb << std::endl;
	swap(inta, intb);
	std::cout << "int A = " << inta << " int B = " << intb << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    FLOAT    " << "\033[0;m" << std::endl;
	std::cout << "float A = " << floata << " float B = " << floatb << std::endl;
	swap(floata, floatb);
	std::cout << "float A = " << floata << " float B = " << floatb << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    DOUBLE    " << "\033[0;m" << std::endl;
	std::cout << "double A = " << doublea << " double B = " << doubleb << std::endl;
	swap(doublea, doubleb);
	std::cout << "double A = " << doublea << " double B = " << doubleb << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    CHAR    " << "\033[0;m" << std::endl;
	std::cout << "char A = " << chara << " char B = " << charb << std::endl;
	swap(chara, charb);
	std::cout << "char A = " << chara << " char B = " << charb << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    STRING    " << "\033[0;m" << std::endl;
	std::cout << "string A = " << stringa << " string B = " << stringb << std::endl;
	swap(stringa, stringb);
	std::cout << "string A = " << stringa << " string B = " << stringb << std::endl << std::endl;


	std::cout << "\033[1;33m" << "TEST DU MIN :" << "\033[0;m" << std::endl << std::endl;
	std::cout << "\033[1;36m" << "    INT    " << "\033[0;m" << std::endl;
	std::cout << "int A = " << inta << " int B = " << intb << std::endl;
	std::cout << "res = " << min(inta, intb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    FLOAT    " << "\033[0;m" << std::endl;
	std::cout << "float A = " << floata << " float B = " << floatb << std::endl;
	std::cout << "res = " << min(floata, floatb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    DOUBLE    " << "\033[0;m" << std::endl;
	std::cout << "double A = " << doublea << " double B = " << doubleb << std::endl;
	std::cout << "res = " << min(doublea, doubleb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    CHAR    " << "\033[0;m" << std::endl;
	std::cout << "char A = " << chara << " char B = " << charb << std::endl;
	std::cout << "res = " << min(chara, charb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    STRING    " << "\033[0;m" << std::endl;
	std::cout << "string A = " << stringa << " string B = " << stringb << std::endl;
	std::cout << "res = " << ::min(stringa, stringb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    EGALITE    " << "\033[0;m" << std::endl;
	std::cout << "int A = " << inta << " = " << &inta << " int B = " << (intb = 1) << " = " << &intb << std::endl;
	std::cout << "res = " << &min(inta, intb) << std::endl << std::endl;


	std::cout << "\033[1;33m" << "TEST MAX :" << "\033[0;m" << std::endl;
	std::cout << "\033[1;36m" << "    INT    " << "\033[0;m" << std::endl;
	std::cout << "int A = " << inta << " int B = " << (intb = 2) << std::endl;
	std::cout << "res = " << max(inta, intb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    FLOAT    " << "\033[0;m" << std::endl;
	std::cout << "float A = " << floata << " BB = " << floatb << std::endl;
	std::cout << "res = " << max(floata, floatb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    DOUBLE    " << "\033[0;m" << std::endl;
	std::cout << "double A = " << doublea << " double B = " << doubleb << std::endl;
	std::cout << "res = " << max(doublea, doubleb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    CHAR    " << "\033[0;m" << std::endl;
	std::cout << "double A = " << chara << " char B = " << charb << std::endl;
	std::cout << "res = " << max(chara, charb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    STRING    " << "\033[0;m" << std::endl;
	std::cout << "string A = " << stringa << " string B = " << stringb << std::endl;
	std::cout << "res = " << ::max(stringa, stringb) << std::endl << std::endl;

	std::cout << "\033[1;36m" << "    EGALITE    " << "\033[0;m" << std::endl;
	std::cout << "int A = " << inta << " = " << &inta << " int B = " << (intb = 1) << " = " << &intb << std::endl;
	std::cout << "res = " << &max(inta, intb) << std::endl << std::endl;
	

	std::cout << "\033[1;33m" << "TEST CLASSE :" << "\033[0;m" << std::endl << std::endl;
	Awesome aA(0);
    Awesome bA(1);

	std::cout << "aA = 0 = " << &aA << " bA = 1 = " << &bA << std::endl;
	std::cout << "MAX : " << &max(aA, bA) << std::endl;
    std::cout << "MIN : " << &min(aA, bA) << std::endl;
	std::cout << "TEST SWAP : " << std::endl;
	swap(aA, bA);
	std::cout << "MAX : " << &max(aA, bA) << std::endl;
    std::cout << "MIN : " << &min(aA, bA) << std::endl;
	
	return 0;
}
