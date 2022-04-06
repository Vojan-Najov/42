/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:50:34 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 23:28:35 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void replaceStrings(std::ifstream & ifs, std::ofstream & ofs, std::string s1, std::string s2)
{
	std::string str;

	(void) s1;
	(void) s2;
	do
	{
		ifs >> str;
		ofs << str << '\n';
	}
	while (!str.empty());
	ifs.close();
	ofs.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Three arguments are expected" << std::endl;
		return 1;
	}
	else if (!argv[2])
	{
		std::cout << "The second argument cannot be an empty string";
		std::cout<< std::endl;
		return 2;
	}

	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return 3;
	}
	std::ofstream ofs(std::string(argv[1]) + std::string(".replace"));
	if (!ofs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		ifs.close();
		return 4;
	}
	replaceStrings(ifs, ofs, std::string(argv[2]), std::string(argv[3]));

	return (0);
}

