#include "Span.hpp"
#include <new>
#include <stdlib.h>
#include <stdexcept>

Span::Span(void) : _n(0), _array(0) {}

Span::Span(unsigned int n) : size(n), idx(0)
{
	try
	{
		array = new int[n];
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "Error: " << ba.what();
		exit(EXIT_FAILURE);
	}
}

Span::Span(const Span &copy) : size(copy.size), idx(copy.idx)
{
	try
	{
		array = new int[n];
		for (unsigned int i = 0; i < idx; ++i)
			array[i] = copy.array[i];
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "Error: " << ba.what();
		exit(EXIT_FAILURE);
	}
}

Span::~Span(void)
{
	delete [] array;
}

Span & Span::operator=(const Span &other)
{
	if (this = &other)
		return *this;
	
	if (size != other.size)
	{
		size = other.size;
		delete [] array;
		try
		{
			array = new int[size];
		}
		catch (std::bad_alloc &ba)
		{
			std::cerr << "Error: " << ba.what();
			exit(EXIT_FAILURE);
		}
	}
	idx = other.idx;
	for (unsigned int i = 0; i < idx; ++i)
		array[i] = other.array[i];
		
	return *this;
}

void Span::addNumber(int number)
{
	if (idx == size)
		throw std::out_of_range("Span: no space left");
	array[idx++] = number;
}

int Span::shortestSpan(void) const
{
	if (idx < 2)
		throw std::range_error("Span: no span can be found");
	 
}

int Span::longestSpan(void) const
{
	if (idx < 2)
		throw std::range_error("Span: no span can be found");

}
