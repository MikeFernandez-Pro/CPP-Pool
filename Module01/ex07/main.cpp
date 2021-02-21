/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:36:39 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 18:45:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

std::string toupperStr(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return (str);
}

std::string replaceStr(std::string line, std::string s1, std::string s2)
{
    size_t i = 0;

    while ((i = line.find(s1, i)) < line.length())
	{
         line.replace(i, s1.length(), s2);
         i++;
    }
    return line;
}

int		replace(const char *filename, std::string s1, std::string s2)
{
	std::ifstream	ifs(filename);
	if (s1.empty()  || s2.empty() || ifs.fail())
		return (-1);
	std::string		cpy = toupperStr(filename).append(".replace");
	const char 		*newName;
	newName = cpy.c_str();
	std::ofstream	newFile(newName);
	std::string		line;

	if (newFile.fail())
		return (-1);
	while (std::getline(ifs, line))
    	newFile << replaceStr(line, s1, s2) << "\n";
	ifs.close();
	newFile.close();
	return (0);
}

int main(int argc, const char **argv)
{
	int ret;

	if (argc != 4)
	{
		std::cout << "\033[1;31mBad number of arguments.\033[0;m" << std::endl;
		return (-1);
	}
	if ((ret = replace(argv[1], argv[2], argv[3])) == -1)
	{
		std::cout << "\033[1;31mIncorrect initialization of variables.\033[0;m" << std::endl;
		return (-1);
	}
	std::cout << "\033[1;32mCopy created with succes!\033[0;m" << std::endl;
	return (0);
}