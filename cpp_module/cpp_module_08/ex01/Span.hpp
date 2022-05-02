#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &copy);
	~Span(void);

	Span &operator=(const Span &other);

	void addNumber(int number);
	int	longestSpan(void) const;
	int shortestSpan(void) const;

private:
	unsigned int size;
	unsigned int idx;
	int *array;
};

#endif
