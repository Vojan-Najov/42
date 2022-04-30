/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:38:51 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/30 21:09:59 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <array>

static void test_array(void);

int main(void)
{
	test_array();

	return 0;
}

static void test_array(void)
{
	std::array<int, 5> a = {1, 10, 77, 4, -100}; 
	try
	{
		easyfind(a, 77);
		std::cout << "test_array find : OK\n";
	}
	catch (std::exception &e)
	{
		(void) e;
		std::cout << "test_array find : KO\n";
	}
	try
	{
		easyfind(a, -77);
		std::cout << "test_array not found : KO\n";
	}
	catch (std::exception &e)
	{
		(void) e;
		std::cout << "test_array find : OK\n";
	}
}
