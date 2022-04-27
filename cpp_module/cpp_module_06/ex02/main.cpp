/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:03:54 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/27 16:39:53 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"

void test_identify_ptr(void);

void test_identify_ptr_unknown(void);

void test_identify_ref(void);

void test_identify_ref_unknown(void);

int main()
{
	srand(time(0));

	test_identify_ptr();
	test_identify_ptr_unknown();
	test_identify_ref();
	test_identify_ref_unknown();

	return 0;
}

void test_identify_ptr(void)
{
	std::cout << "\n++++ test_identify_ptr ++++\n";

	for (int i = 0; i < 10; i++)
	{
		Base *obj = generate();
		identify(obj);
		delete obj;
	}
}

void test_identify_ptr_unknown(void)
{
	std::cout << "\n++++ test_identify_ptr_unknown ++++\n";

	Base obj;
	identify(&obj);
}

void test_identify_ref(void)
{
	std::cout << "\n++++ test_identify_ref ++++\n";

	for (int i = 0; i < 10; i++)
	{
		Base *obj = generate();
		identify(*obj);
		delete obj;
	}
}

void test_identify_ref_unknown(void)
{
	std::cout << "\n+++ test_identify_ref_unknown ++++\n";

	Base obj;
	identify(obj);
}
