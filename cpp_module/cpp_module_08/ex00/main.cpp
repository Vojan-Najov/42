/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:38:51 by ccartman          #+#    #+#             */
/*   Updated: 2022/05/02 15:53:39 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

static void test_vector(void);

static void test_deque(void);

static void test_list(void);

int main(void)
{
	test_vector();
	test_deque();
	test_list();

	return 0;
}

static void test_vector(void)
{
	int a[] = {1, 10, 77, 4, -100}; 
	std::vector<int> v(a, a + sizeof(a) / sizeof(int)); 

	try
	{
		easyfind(v, 77);
		std::cout << "test_vector find : OK\n";
	}
	catch (std::exception &e)
	{
		(void) e;
		std::cout << "test_vector find : KO\n";
	}
	try
	{
		easyfind(v, -77);
		std::cout << "test_vector not found : KO\n";
	}
	catch (std::exception &e)
	{
		(void) e;
		std::cout << "test_vector not found : OK\n";
	}
}

static void test_deque(void)
{
	int a[] = {1, 10, 77, 4, -100}; 
	std::deque<int> d(a, a + sizeof(a) / sizeof(int)); 

	try
	{
		easyfind(d, -100);
		std::cout << "test_deque find : OK\n";
	}
	catch (std::exception &e)
	{
		(void) e;
		std::cout << "test_deque find : KO\n";
	}
	try
	{
		easyfind(d, -77);
		std::cout << "test_deque not found : KO\n";
	}
	catch (std::exception &e)
	{
		(void) e;
		std::cout << "test_deque not found : OK\n";
	}
}

static void test_list(void)
{
	int a[] = {1, 10, 77, 4, -100}; 
	std::list<int> l(a, a + sizeof(a) / sizeof(int)); 

	try
	{
		easyfind(l, 1);
		std::cout << "test_list find : OK\n";
	}
	catch (std::exception &e)
	{
		(void) e;
		std::cout << "test_list find : KO\n";
	}
	try
	{
		easyfind(l, -77);
		std::cout << "test_list not found : KO\n";
	}
	catch (std::exception &e)
	{
		(void) e;
		std::cout << "test_list not found : OK\n";
	}
}
