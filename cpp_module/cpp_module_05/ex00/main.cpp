/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:01:53 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/23 12:39:30 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bob("Bob", 100);
	Bureaucrat bob2 = bob;
	
	std::cout << "getName return " << bob.getName() << ", getGrade return ";
	std::cout << bob.getGrade() << '\n';	
	std::cout << bob << "\n" << std::endl;
	{
		try
		{
			Bureaucrat Bureaucrat("Joe", 151);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat Bureaucrat("Joe", -1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	for(;;) {
		try {
			++bob;
			std::cout << bob << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			break;
		}
	}
	std::cout << std::endl;
	for(;;) {
	 	try {
			--bob2;
			std::cout << bob2 << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			break;
		}
	}

	return 0;
}
