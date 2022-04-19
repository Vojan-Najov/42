/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:01:53 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/20 00:17:43 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form tmp("TMP", 200, 100);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tmp("TMP", 100, 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tmp("TMP", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tmp("TMP", 100, -1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Bureaucrat bob("Bob", 100);
	{
		Form a1("A1", 100, 100);
		bob.signForm(a1);	
	}
	--bob;
	{
		Form a1("A1", 100, 100);
		bob.signForm(a1);	
	}
	std::cout << std::endl;
	{
		Form a1("A1", 100, 100);
		try
		{
			a1.beSigned(bob);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	++bob;
	{
		Form a1("A1", 100, 100);
		try
		{
			a1.beSigned(bob);
			std::cout << bob << " signed " << a1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
