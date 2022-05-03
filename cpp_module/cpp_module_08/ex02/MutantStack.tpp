#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> &other)
{
	std::stack<T>::operator=(other);
}

template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return std::stack<T>::c.begin();
}

template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return std::stack<T>::c.end();
}

template <typename T>
inline typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return std::stack<T>::c.begin();
}

template <typename T>
inline typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return std::stack<T>::c.end();
}

template <typename T>
inline typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
inline typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return std::stack<T>::c.rend();
}

template <typename T>
inline typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin(void) const
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
inline typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(void) const
{
	return std::stack<T>::c.rend();
}

#endif
