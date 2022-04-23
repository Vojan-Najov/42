
#ifndef DATA_HPP
# define DATA_HPP

# include <cstdio>
# include <string>

class Data
{
public:
	explicit Data(const std::string &secret);
	Data(const Data &copy);
	~Data();

	Data & operator=(const Data &assign);

	const std::string &getSecret() const;

private:
	std::string secret;

	Data();
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
