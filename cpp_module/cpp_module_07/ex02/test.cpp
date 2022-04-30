/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:30:02 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/30 15:00:36 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Array.hpp"

static void test_copy(void);

static void test_assign(void);

static void test_operator_idx(void);

static int test_intra(void);

int main(void)
{
	std::cout << "_______My test______\n";
	test_copy();
	test_assign();
	test_operator_idx();
	std::cout << "\n_______Intra test______\n";
	test_intra();

	return 0;
}

static void test_copy(void)
{
	Array<int> a(10);

	for (int i = 0; i < 10; ++i)
		a[i] = i;
	{
		Array<int> b = a;
		for (int i = 0; i < 10; ++i)
			if (a[i] != b[i])
				std::cout << "test_copy : KO\n";
	}
	std::cout << "test_copy : OK\n";
}

static void test_assign(void)
{
	Array<int> a(10);

	for (int i = 0; i < 10; ++i)
		a[i] = i;
	{
		Array<int> b;
		b = a;
		for (int i = 0; i < 10; ++i)
			if (a[i] != b[i])
				std::cout << "test_assign : KO\n";
	}
	std::cout << "test_assign : OK\n";
}

static void test_operator_idx(void)
{
	char c = 'a';
	Array<std::string> a(10);

	for (int i = 0 ; i < 10; ++i, ++c)
	{
		a[i] = c;
	}
	try
	{
		a[100]  = "abc";
	}
	catch (std::exception &e)
	{
		if (!strcmp(e.what(),"Out of range"))
			std::cout << "test_operator[] : OK\n";
		else
			std::cout << "test_operator[] : OK\n";
	}
	try
	{
		a[-1]  = "abc";
	}
	catch (std::exception &e)
	{
		if (!strcmp(e.what(),"Out of range"))
			std::cout << "test_operator[] : OK\n";
		else
			std::cout << "test_operator[] : OK\n";
	}
	try
	{
		a[10]  = "abc";
	}
	catch (std::exception &e)
	{
		if (!strcmp(e.what(),"Out of range"))
			std::cout << "test_operator[] : OK\n";
		else
			std::cout << "test_operator[] : OK\n";
	}
	{
		Array<int> a;
		try 
		{
			a[1] = 0;
		}
		catch (std::exception &e)
		{
			if (!strcmp(e.what(), "Zero-length array"))
			std::cout << "test_operator[] : OK\n";
		else
			std::cout << "test_operator[] : OK\n";
		}
	}
}

/*       INTRA MAIN */


#define MAX_VAL 750
static int test_intra(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
