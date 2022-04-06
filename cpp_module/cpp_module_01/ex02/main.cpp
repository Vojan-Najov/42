/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:34:52 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 18:58:49 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str= "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "str address is       " << &str << '\n';
	std::cout << "stringPTR address is " << stringPTR << '\n';
	std::cout << "stringREF address is " << &stringREF << '\n';
	std::cout << "str value is       \"" << str << "\"\n";
	std::cout << "stringPTR value is \"" << *stringPTR << "\"\n";
	std::cout << "stringREF value is \"" << stringREF << '"' << std::endl;

	return (0);
}
