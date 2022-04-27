/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:13:06 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/27 21:21:03 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

void test_serialization(void)
{
	std::cout << "\n<-- test_serialization -->\n";

	Data data("***");

	std::cout << "Address: " << &data << "\n";
	std::cout << "Content: " << data.getContent() << "\n";

	uintptr_t ptr = serialize(&data);
	std::cout << std::hex << "Serialized: " << ptr << "\n";

	Data *data2 = deserialize(ptr);
	if (data2 != &data)
	{
		std::cout << "[FAILED] Bad deserialized address: " << data2 << "\n";
	}
	else
	{
		std::cout << "[SUCCESS] deserialized address: " << data2 << "\n";
		std::cout << "Content: " << data2->getContent() << "\n";
	}
}

void test_serialization_null(void)
{
	std::cout << "\n<-- test_serialization -->\n";

	uintptr_t ptr = serialize(NULL);
	std::cout << std::hex << "Serialized: " << ptr << "\n";

	Data *data2 = deserialize(ptr);
	if (data2 != NULL)
	{
		std::cout << "[FAILED] Bad deserialized address: " << data2 << "\n";
	}
	else
	{
		std::cout << "[SUCCESS] deserialized address: " << data2 << "\n";
	}
}

int main(void)
{
	test_serialization();
	test_serialization_null();

	return 0;
}
