/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:50:34 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/08 15:00:40 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void replaceStrings(std::ifstream & ifs, std::ofstream & ofs, \
						   std::string s1, std::string s2);

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Three arguments are expected" << std::endl;
		return 1;
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
	ifs.close();
	ofs.close();

	return (0);
}

static void replaceStrings(std::ifstream & ifs, std::ofstream & ofs, \
						   std::string s1, std::string s2)
{
	size_t		idx;
	size_t		pos;
	size_t		s1Len;
	std::string strIn;
	std::string strOut;

	s1Len = s1.size();
	while (std::getline(ifs, strIn))
	{
		if (s1.empty()) 
		{
			ofs << (strIn.empty() ? s2 : strIn) << '\n';
			continue ;
		}
		idx = 0;
		pos = 0;
		while ((pos = strIn.find(s1, idx)) != std::string::npos)
		{
			strOut += strIn.substr(idx, pos - idx);
			strOut += s2;
			idx = pos + s1Len;
		}
		strOut += strIn.substr(idx);
		ofs << strOut << '\n';
		strOut.clear();
	}
}
