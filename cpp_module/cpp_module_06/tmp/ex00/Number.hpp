
#ifndef NUMBER_HPP
# define NUMBER_HPP

# include <iostream>

class Number
{
public:
	enum e_type
	{
		type_unknown = 0,
		type_char,
		type_int,
		type_float,
		type_double,
	};

	Number();
	explicit Number(char value);
	explicit Number(int value);
	explicit Number(float value);
	explicit Number(double value);
	Number(const Number &copy);
	~Number();

	Number & operator=(const Number &assign);

	void	print() const;

	static Number::e_type	guessType(const std::string &str);
	static Number			&parse(const std::string &str);

private:
	e_type	type;
	bool	has_char;
	char	value_char;
	bool	has_int;
	int		value_int;
	bool	has_float;
	float	value_float;
	bool	has_double;
	double	value_double;
};

#endif
