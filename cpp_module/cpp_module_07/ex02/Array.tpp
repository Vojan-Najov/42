#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array(void) : _n(0), _array(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
	try
	{
		_array = new T[_n];
	}
	catch (std::bad_alloc & ba)
	{
		exit(EXIT_FAILURE);
	}
}

template<typename T>
Array<T>::Array(const Array<T> & copy) : _n(copy._n)
{
	try
	{
		_array = new T[_n];
		for(unsigned int i = 0; i < _n; ++i)
			_array[i] = copy._array[i];
	}
	catch (std::bad_alloc & ba)
	{
		exit(EXIT_FAILURE);
	}
}

template<typename T>
Array<T>::~Array(void)
{
	delete [] _array;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & other)
{
	if (this == &other)
		return *this;
	delete [] _array;
	_n = other._n;
	try
	{
		_array = new T[_n];
		for(unsigned int i = 0; i < _n; ++i)
			_array[i] = other._array[i];
	}
	catch (std::bad_alloc & ba)
	{
		exit(EXIT_FAILURE);
	}

	return *this;
}

template<typename T>
T & Array<T>::operator[](int idx)
{
	if (_n == 0)
		throw std::length_error("Zero-length array");
	if (idx < 0 || static_cast<unsigned int>(idx) >= _n)
		throw std::out_of_range("Out of range");
	
	return _array[idx];
}

template<typename T>
const T & Array<T>::operator[](int idx) const
{
	if (_n == 0)
		throw std::length_error("Zero-length array");
	if (idx < 0 || static_cast<unsigned int>(idx) >= _n)
		throw std::out_of_range("Out of range");
	
	return _array[idx];
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return _n;
}

#endif
