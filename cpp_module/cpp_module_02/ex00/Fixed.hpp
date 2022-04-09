#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const & f);

	Fixed & operator=(Fixed const & f);

	int getRawBits( void ) const;
	void setRawBits(int const raw);

	~Fixed( void );
		
private:
	int	value;
	static const int fraction = 8;		
};

#endif
