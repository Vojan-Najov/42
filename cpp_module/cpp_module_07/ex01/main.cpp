#include <iostream>
#include "iter.hpp"

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }

	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

/*
int main()
{
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you cant write int[] tab.
								   // Wouldnt that make more sense?
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}
*/

template<typename T>
T increment(T &x)
{
	++x;
	return x;
}

template<typename T>
int decrement(T &x)
{
	x -= 1;
	return 1;
}

int main(void)
{
	int tab[] = {0, 1, 2, 3, 4};
	float tabf[] = {0.f, 1.f, 2.f, 3.f, 4.f};

	iter(tab, 5, increment<int>);
	for (int i = 0; i < 5; ++i)
		std::cout << tab[i] << ' ';
	std::cout << '\n';
	iter(tabf, 5, decrement<float>);
	for (int i = 0; i < 5; ++i)
		std::cout << tabf[i] << ' ';
	std::cout << '\n';

	{

	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print);
	iter( tab2, 5, print );

	}

	return 0;
}
