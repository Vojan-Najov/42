
#include <iostream>
#include "Data.hpp"

void test_serialization()
{
	std::cout << "\n<-- test_serialization -->\n";

	Data data("***");

	std::cout << "Address: " << &data << "\n";
	std::cout << "Secret: " << data.getSecret() << "\n";

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
		std::cout << "Secret: " << data2->getSecret() << "\n";
	}
}

void test_serialization_null()
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

int main()
{
	test_serialization();
	test_serialization_null();
	return 0;
}
