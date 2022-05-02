/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:49:48 by ccartman          #+#    #+#             */
/*   Updated: 2022/05/02 19:37:56 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>

static void test_add(void);

static void test_length_less_2(void);

static void test_10000(void);

static void test_subject(void);

static void test_random(void);

static void test_addRange();

int main(void)
{
	test_add();
	test_length_less_2();
	test_10000();
	test_subject();
	srand(time(NULL));
	test_random();
	test_addRange();

	return (0);
}

static void test_add(void)
{
	Span sp(100);

	for(int i = 0; i < 100; ++i)
		sp.addNumber(i);
	try
	{
		sp.addNumber(0);
		std::cout << "Add Test : KO\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Add Test : OK (" << e.what() << ")" << std::endl;
	}
}

static void test_length_less_2(void)
{
	Span sp;

	try
	{
		int tmp = sp.shortestSpan();
		std::cout << "Length_less_2 Test : KO " << tmp << " \n";
	}
	catch (std::exception &e)
	{
		std::cout << "Length_less_2 Test : OK (" << e.what() << ")" << std::endl;
	}
	try
	{
		int tmp = sp.longestSpan();
		std::cout << "Length_less_2 Test : KO " << tmp << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Length_less_2 Test : OK (" << e.what() << ")" << std::endl;
	}

	Span sp2(1);
	
	sp2.addNumber(100);
	try
	{
		int tmp = sp.shortestSpan();
		std::cout << "Length_less_2 Test : KO " << tmp << " \n";
	}
	catch (std::exception &e)
	{
		std::cout << "Length_less_2 Test : OK (" << e.what() << ")" << std::endl;
	}
	try
	{
		int tmp = sp.longestSpan();
		std::cout << "Length_less_2 Test : KO " << tmp << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Length_less_2 Test : OK (" << e.what() << ")" << std::endl;
	}
}

static void test_10000(void)
{
	Span sp(10000);

	for(int i = 10000; i > 0; --i)
		sp.addNumber(i);
	std::cout << "Test_10000 :    ";
	std::cout << "Shortest span : " << sp.shortestSpan();
	std::cout << "    Longest span : " << sp.longestSpan() << std::endl;
}

static void test_random(void)
{
	Span sp(20000);

	for(int i = 20000; i > 0; --i)
		sp.addNumber(rand());
	std::cout << "Random Test :    ";
	std::cout << "Shortest span : " << sp.shortestSpan();
	std::cout << "    Longest span : " << sp.longestSpan() << std::endl;
}

static void test_subject(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Subject Test : " << sp.shortestSpan() << "  ";
	std::cout << sp.longestSpan() << std::endl;
}

static void test_addRange()
{
	std::vector<int> tmp;
	Span sp(1000);

	for (int i = 0; i < 1000; ++i)
		tmp.push_back(2*i);
	sp.addNumber(tmp.begin(), tmp.end());
	std::cout << "Add Range Test :    ";
	std::cout << "Shortest span : " << sp.shortestSpan();
	std::cout << "    Longest span : " << sp.longestSpan() << std::endl;
	
	Span sp2(1500);

	sp2.addNumber(tmp.begin(), tmp.end());
	try
	{
		sp2.addNumber(tmp.begin(), tmp.end());
		std::cout << "Add Range Test : KO\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Add Range Test : OK (" << e.what() << ")\n";
	}
}
