/******************************************************************************/
/*
* ITERATOR_TRAITS
* REVERSE_ITERATOR
* ENABLE_IF
* IS_INTEGRAL
* EQUAL
*/
/******************************************************************************/

#ifndef FT_UTILS_HPP
#define FT_UTILS_HPP

#include <cstddef>
#include <iterator>

namespace ft
{

	/*
	Output iterators are iterators that can be used in sequential output ope-
	rations, where each element pointed by the iterator is written a value only
	once and then the iterator is incremented.
	All output iterators support -at least- the following operations:
	1) Is copy-constructible, copy-assignable and destructible
		X b(a);
		b = a;
	2) Can be dereferenced as an lvalue (if in a dereferenceable state).
	It shall only be dereferenced as the left-side of an assignment statement.
	Once dereferenced, its iterator value may no longer be dereferenceable.
		*a = t;
	3) Can be incremented.
		a++
		++a
		*a++
	*/

  struct output_iterator_tag : public std::output_iterator_tag {};

	/*
	Input iterators are iterators that can be used in sequential input opera-
	tions, where each value pointed by the iterator is read only once and then
	the iterator is incremented.
	All input iterators support -at least- the following operations:
	1) Is copy-constructible, copy-assignable and destructible
		X b(a);
		b = a;
	2) Can be compared for equivalence using the equality/inequality operators
	(meaningful if both iterators are be in domain).
		a == b
		a != b
	3) Can be dereferenced as an rvalue (if in a dereferenceable state).
		*a
		a->m
	4) Can be incremented (if in a dereferenceable state).
	The result is either also dereferenceable or a past-the-end iterator.
	The previous iterator value is not required to be dereferenceable after the
	increase.
		++a
		(void) a++
		*a++
	5) Its value type does not need to be assignable.
	*/

  struct input_iterator_tag : public std::input_iterator_tag {};

	/*
	Forward iterators are iterators that can be used to access the sequence of
	elements in a range in the direction that goes from its beginning towards
	its end.
	Performing operations on a forward iterator that is dereferenceable never
	makes its iterator value non-dereferenceable. This enables algorithms that
	use this category of iterators to use multiple copies of an iterator to
	pass more than once by the same iterator values.
	All forward iterators support -at least- the following operations:
	1) Is default-constructible, copy-constructible, copy-assignable and
	destructible.
		X a;
		X b(a);
		b = a;
	2) Can be compared for equivalence using the equality/inequality operators
	(meaningful when both iterator values iterate over the same underlying
	sequence).
		a == b
		a != b
	3) Can be dereferenced as an rvalue (if in a dereferenceable state).
		*a
		a->m
	4) For mutable iterators (non-constant iterators):
	Can be dereferenced as an lvalue (if in a dereferenceable state).
		*a = t
	5) Can be incremented (if in a dereferenceable state).
	The result is either also dereferenceable or a past-the-end iterator.
	Two iterators that compare equal, keep comparing equal when both are
	increased.
		++a
		a++
		*a++
	*/

  struct forward_iterator_tag : public input_iterator_tag,
								public std::forward_iterator_tag {};

	/*
	Bidirectional iterators are iterators that can be used to access the
	sequence of elements in a range in both directions (towards the end and
	towards the beginning).
	Bidirectional iterators have the same properties as forward iterators, with
	the only difference that they can also be decremented:
	1) Is default-constructible, copy-constructible, copy-assignable and
	destructible
		X a;
		X b(a);
		b = a;
	2) Can be compared for equivalence using the equality/inequality operators
	(meaningful when both iterator values iterate over the same underlying
	sequence).
		a == b
		a != b
	3) Can be dereferenced as an rvalue (if in a dereferenceable state).
		*a
		a->m
	4) For mutable iterators (non-constant iterators):
	Can be dereferenced as an lvalue (if in a dereferenceable state).
		*a = t;
	5) Can be incremented (if in a dereferenceable state).
	The result is either also dereferenceable or a past-the-end iterator.
	Two iterators that compare equal, keep comparing equal after being both
	increased.
		++a
		a++
		*a++
	6) Can be decremented (if a dereferenceable iterator value precedes it).
		--a
		a--
		*a--
	*/

  struct bidirectional_iterator_tag : public forward_iterator_tag,
									  public std::bidirectional_iterator_tag {};

	/*
	Random-access iterators are iterators that can be used to access elements
	at an arbitrary offset position relative to the element they point to,
	offering the same functionality as pointers.
	All random access iterators support -at least- the following operations:
	1) Is default-constructible, copy-constructible, copy-assignable and
	destructible.
		X a;
		X b(a);
		b = a;
	2) Can be compared for equivalence using the equality/inequality operators
	(meaningful when both iterator values iterate over the same underlying
	sequence).
		a == b
		a != b
	3) Can be dereferenced as an rvalue (if in a dereferenceable state).
		*a
		a->m
	4) For mutable iterators (non-constant iterators):
	Can be dereferenced as an lvalue (if in a dereferenceable state).
		*a = t
	5) Can be incremented (if in a dereferenceable state).
	The result is either also dereferenceable or a past-the-end iterator.
	Two iterators that compare equal, keep comparing equal after being both
	increased.
		++a
		a++
		*a++
	6) Can be decremented (if a dereferenceable iterator value precedes it).
		--a
		a--
		*a--
	7) Supports the arithmetic operators + and - between an iterator and an
	integer value, or subtracting an iterator from another.
		a + n
		n + a
		a - n
		a - b
	8) Can be compared with inequality relational operators (<, >, <= and >=).
		a < b
		a > b
		a <= b
		a >= b
	9) Supports compound assignment operations += and -=
		a += n
		a -= n
	10) Supports the offset dereference operator ([])
		a[n]
	*/

  struct random_access_iterator_tag : public bidirectional_iterator_tag,
									  public std::random_access_iterator_tag {};

	/*
	This is a base class template that can be used to derive iterator classes
	from it. It is not an iterator class and does not provide any of the
	functionality an iterator is expected to have.
	*/

  template< typename Category, typename T, typename Distance = ptrdiff_t,
			typename Pointer = T*, typename Reference = T& >
    struct iterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	/*
	Traits class defining properties of iterators.
	*/

  template< typename Iterator >
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

  template< typename T >
	struct iterator_traits< T* >
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};

  template< typename T >
	struct iterator_traits< const T* > {
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef const T*					pointer;
		typedef const T&					reference;
	};

	/*
	Distance.
	Returns the number of hops from first to last. 
	*/

  template< typename Iterator > inline
	typename iterator_traits<Iterator>::difference_type
	_distance(Iterator first, Iterator last, input_iterator_tag)
	{
		typename iterator_traits<Iterator>::difference_type n = 0;
		while (first != last)
		{
			++first;
			++n;
		}
		return n;
	}

  template< typename Iterator > inline
	typename iterator_traits<Iterator>::difference_type
	_distance(Iterator first, Iterator last, random_access_iterator_tag)
	{
		return last - first;
	}

  template< typename Iterator > inline
	typename iterator_traits<Iterator>::difference_type
	distance(Iterator first, Iterator last)
	{
		return _distance(first, last,
					typename iterator_traits<Iterator>::iterator_category());
	}

	/*
	Advance.
	Increments given iterator it by n elements.
	*/

  template< typename Iterator > inline 
	void _advance(Iterator& it,
				  typename iterator_traits<Iterator>::difference_type n,
				  input_iterator_tag)
	{
		while (n > 0)
		{
			--n;
			++it;
		}
	}

  template< typename Iterator > inline
	void _advance(Iterator& it,
				  typename iterator_traits<Iterator>::difference_type n,
				  bidirectional_iterator_tag)
	{
		while (n > 0)
		{
			--n;
			++it;
		}
		while (n < 0)
		{
			++n;
			--it;
		}
	}

  template< typename Iterator > inline
	void _advance(Iterator& it,
				  typename iterator_traits<Iterator>::differnce_type n,
				  random_access_iterator_tag)
	{
		it += n;
	}

  template< typename Iterator, typename Dist > inline
	void advance(Iterator& it, Dist n)
	{
		_advance(it, typename iterator_traits<Iterator>::difference_type(n),
				 typename iterator_traits<Iterator>::iterator_category());
	}

	/*
	reverse_iterator is an iterator adaptor that reverses the direction of a
	given iterator, which must be at least a BidirectionalIterator.
	In other words, when provided with a bidirectional iterator,
	reverse_iterator produces a new iterator that moves from the end to the
	beginning of the sequence defined by the underlying bidirectional iterator.
	For a reverse iterator r constructed from an iterator i, the relationship
	&*r == &*(i-1) is always true (as long as r is dereferenceable); thus a
	reverse iterator constructed from a one-past-the-end iterator dereferences
	to the last element in a sequence.  
	*/

  template< typename Iter >
	class reverse_iterator
		: public iterator< typename iterator_traits<Iter>::iterator_category,
						   typename iterator_traits<Iter>::value_type,
						   typename iterator_traits<Iter>::difference_type,
						   typename iterator_traits<Iter>::pointer,
						   typename iterator_traits<Iter>::reference >
	{
		template< typename U >
		friend class reverse_iterator;

	protected:
		Iter current;

	public:
		typedef Iter
			iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category
			iterator_category;
		typedef typename iterator_traits<Iter>::value_type
			value_type;
		typedef typename iterator_traits<Iter>::difference_type
			difference_type;
		typedef typename iterator_traits<Iter>::pointer
			pointer;
		typedef typename iterator_traits<Iter>::reference
			reference;

		reverse_iterator(void);
		explicit reverse_iterator(iterator_type it);
		reverse_iterator(reverse_iterator const& copy);
		template <typename U>
		reverse_iterator(reverse_iterator<U> const& revIt);
		reverse_iterator& operator=(reverse_iterator const& other);
		template <typename U>
		reverse_iterator& operator=(reverse_iterator<U> const& other);
		iterator_type base(void) const;
		reference operator*(void) const;
		pointer operator->(void) const;
		reverse_iterator& operator++(void);
		reverse_iterator operator++(int);
		reverse_iterator& operator--(void);
		reverse_iterator operator--(int);
		reverse_iterator operator+(difference_type n) const;
		reverse_iterator operator-(difference_type n) const;
		reverse_iterator& operator+=(difference_type n);
		reverse_iterator& operator-=(difference_type n);
		reference operator[](difference_type n) const;

		template< typename It >
		friend bool operator==(reverse_iterator<It> const& lhs,
							   reverse_iterator<It> const& rhs);
		template< typename It >
		friend bool operator<(reverse_iterator<It> const& lhs,
							   reverse_iterator<It> const& rhs);

	private:
		template <typename Tp>
		static Tp* _s_to_pointer(Tp* ptr);

		template <typename Tp>
		static pointer _s_to_pointer(Tp it);
	};

  template< typename Iter >
	reverse_iterator<Iter>::reverse_iterator(void)
		: current() {}

  template< typename Iter >
	reverse_iterator<Iter>::reverse_iterator(
		typename reverse_iterator<Iter>::iterator_type it)
		: current(it) {}

  template< typename Iter >
	reverse_iterator<Iter>::reverse_iterator(reverse_iterator<Iter> const& copy)
		: current(copy.current) {}

  template< typename Iter >
  template< typename U >
	reverse_iterator<Iter>::reverse_iterator(reverse_iterator<U> const& revIt)
		: current(revIt.current) {}

  template< typename Iter >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator=(
		reverse_iterator<Iter> const& other)
	{
		current = other.current;
		return *this;
	}

  template< typename Iter >
  template< typename U >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator=(
		reverse_iterator<U> const& other)
	{
		current = other.current;
		return *this;
	}

  template< typename Iter >
	typename reverse_iterator<Iter>::iterator_type
	reverse_iterator<Iter>::base(void) const
	{
		return current;
	}

  template< typename Iter >
	typename reverse_iterator<Iter>::reference
	reverse_iterator<Iter>::operator*(void) const
	{
		Iter tmp = current;
		return *--tmp;
	}

  template< typename Iter >
	typename reverse_iterator<Iter>::pointer
	reverse_iterator<Iter>::operator->(void) const
	{
		Iter tmp = current;
		--tmp;
		return _s_to_pointer(tmp);
	}

  template< typename Iter >
  template< typename Tp >
	Tp* reverse_iterator<Iter>::_s_to_pointer(Tp *ptr)
	{
		return ptr;
	}

  template< typename Iter >
  template< typename Tp >
	typename reverse_iterator<Iter>::pointer
	reverse_iterator<Iter>::_s_to_pointer(Tp it)
	{
		return it.operator->();
	}

  template< typename Iter >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator++(void)
	{
		--current;
		return *this;
	}	

  template< typename Iter >
	reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int)
	{
		reverse_iterator<Iter> tmp = *this;
		--current;
		return tmp;
	}

  template< typename Iter >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator--(void)
	{
		++current;
		return *this;
	}	

  template< typename Iter >
	reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int)
	{
		reverse_iterator<Iter> tmp = *this;
		++current;
		return tmp;
	}

  template< typename Iter >
	reverse_iterator<Iter>
	reverse_iterator<Iter>::operator+
	(typename reverse_iterator<Iter>::difference_type n) const
	{
		return reverse_iterator<Iter>(current - n);
	}

  template< typename Iter >
	reverse_iterator<Iter>
	reverse_iterator<Iter>::operator-
	(typename reverse_iterator<Iter>::difference_type n) const
	{
		return reverse_iterator<Iter>(current + n);
	}

  template< typename Iter >
	reverse_iterator<Iter>& 
	reverse_iterator<Iter>::operator+=
	(typename reverse_iterator<Iter>::difference_type n)
	{
		current -= n;
		return *this;
	}

  template< typename Iter >
	reverse_iterator<Iter>& 
	reverse_iterator<Iter>::operator-=
	(typename reverse_iterator<Iter>::difference_type n)
	{
		current += n;
		return *this;
	}

  template< typename Iter >
	typename reverse_iterator<Iter>::reference
	reverse_iterator<Iter>::operator[]
	(typename reverse_iterator<Iter>::difference_type n) const
	{
		return *(current - n - 1);
	}

	template< typename Iter > inline
	bool operator==(reverse_iterator<Iter> const& lhs,
					reverse_iterator<Iter> const& rhs)
	{
		return lhs.current == rhs.current;
	}


	template< typename Iter > inline
	bool operator!=(reverse_iterator<Iter> const& lhs,
					reverse_iterator<Iter> const& rhs)
	{
		return !(lhs == rhs);
	}

	template< typename Iter > inline
	bool operator<(reverse_iterator<Iter> const& lhs,
				   reverse_iterator<Iter> const& rhs)
	{
		return rhs.current < lhs.current;
	}

	template< typename Iter > inline
	bool operator>(reverse_iterator<Iter> const& lhs,
				   reverse_iterator<Iter> const& rhs)
	{
		return rhs < lhs;
	}

	template< typename Iter > inline
	bool operator<=(reverse_iterator<Iter> const& lhs,
					reverse_iterator<Iter> const& rhs)
	{
		return !(rhs < lhs);
	}

	template< typename Iter > inline
	bool operator>=(reverse_iterator<Iter> const& lhs,
					reverse_iterator<Iter> const& rhs)
	{
		return !(lhs < rhs);
	}

  template< typename IterL, typename IterR > inline
	bool operator==(reverse_iterator<IterL> const& lhs,
					reverse_iterator<IterR> const& rhs)
	{
		return lhs.base() == rhs.base();
	}

  template< typename IterL, typename IterR > inline
	bool operator!=(reverse_iterator<IterL> const& lhs,
					reverse_iterator<IterR> const& rhs)
	{
		return lhs.base() != rhs.base();
	}

  template< typename IterL, typename IterR > inline
	bool operator<(reverse_iterator<IterL> const& lhs,
				   reverse_iterator<IterR> const& rhs)
	{
		return lhs.base() > rhs.base();
	}

  template< typename IterL, typename IterR > inline
	bool operator>(reverse_iterator<IterL> const& lhs,
				   reverse_iterator<IterR> const& rhs)
	{
		return lhs.base() < rhs.base();
	}

  template< typename IterL, typename IterR > inline
	bool operator<=(reverse_iterator<IterL> const& lhs,
					reverse_iterator<IterR> const& rhs)
	{
		return lhs.base() >= rhs.base();
	}

  template< typename IterL, typename IterR > inline
	bool operator>=(reverse_iterator<IterL> const& lhs,
					reverse_iterator<IterR> const& rhs)
	{
		return lhs.base() <= rhs.base();
	}

  template< typename Iter > inline
	reverse_iterator<Iter>
	operator+(typename reverse_iterator<Iter>::defference_type n,
			  reverse_iterator<Iter> const& rev_it)
	{
		return reverse_iterator<Iter>(rev_it.base() - n);
	}

  template <typename Iter> inline
	typename reverse_iterator<Iter>::difference_type
	operator-(reverse_iterator<Iter> const& lhs,
			  reverse_iterator<Iter> const& rhs)
	{
		return rhs.base() - lhs.base();
	}

	/*
	enable_if
	This is useful to hide signatures on compile time when a particular
	condition is not met, since in this case, the member enable_if::type will
	not be defined and attempting to compile using it should fail.
	*/

  template< bool B, class T = void >
	struct enable_if {};

  template< class T >
	struct enable_if<true, T> { typedef T type; };

	/*
	Is_integral
	integral_constant. This template is designed to provide compile-time
	constants as types.
	true_type. Instantiation of integral_constant to represent the bool value
	true.
	false_type. Instantitation of integral_constant to represent the bool value
	false.
	remove_cv. Obtains the type T without any top-level const or volatile
	qualification.
	is_integral. Trait class that identifies whether T is an integral type.
	*/

  template< typename T, T val >
	struct integral_constant
	{
		typedef integral_constant<T, val>	type;
		typedef T							value_type;
		static const T value = val;
		operator value_type() const { return value; }
		value_type operator()(void) const {return value; }
	};

  typedef integral_constant<bool, true>		true_type;
  typedef integral_constant<bool, false>	false_type;

  template< typename T >
	struct remove_cv { typedef T type; };

  template< typename T >
	struct remove_cv<const T> { typedef T type; };

  template< typename T >
	struct remove_cv<volatile T> { typedef T type; };

  template< typename T >
	struct remove_cv<const volatile T> { typedef T type; };

  template< typename >
	struct _is_integral_helper : public false_type {};

  template<>
	struct _is_integral_helper<bool> : public true_type {};

  template<>
	struct _is_integral_helper<wchar_t> : public true_type {};

  template<>
	struct _is_integral_helper<char> : public true_type {};

  template<>
	struct _is_integral_helper<unsigned char> : public true_type {};

  template<>
	struct _is_integral_helper<signed char> : public true_type {};

  template<>
	struct _is_integral_helper<short int> : public true_type {};

  template<>
	struct _is_integral_helper<unsigned short int> : public true_type {};

  template<>
	struct _is_integral_helper<int> : public true_type {};

  template<>
	struct _is_integral_helper<unsigned int> : public true_type {};

  template<>
	struct _is_integral_helper<long int> : public true_type {};

  template<>
	struct _is_integral_helper<unsigned long int> : public true_type {};

  template<>
	struct _is_integral_helper<long long int> : public true_type {};

  template<>
	struct _is_integral_helper<unsigned long long int> : public true_type {};

  template< typename T >
	struct is_integral
		: public _is_integral_helper<typename remove_cv<T>::type>::type
	{};

	/*
	EQUAL
	Compares the elements in the range [first1,last1) with those in the range
	beginning at first2, and returns true if all of the elements in both ranges
	match.
	*/

  template< typename InputIterator1, typename InputIterator2 > inline
	bool equal(InputIterator1 first1,
			   InputIterator1 last1,
			   InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

  template< typename InputIterator1,
			typename InputIterator2, 
			typename BinaryPredicate > inline
	bool equal(InputIterator1 first1, InputIterator1 last1,
			   InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	/*
	Lexicographical_compare
	Returns true if the range [first1,last1) compares lexicographically less
	than the range [first2,last2).
	Compare -- comparison function object which returns true if the first
	argument is less than the second. 
	*/

  template< typename InputIterator1, typename InputIterator2 > inline
	bool lexicographical_compare(InputIterator1 first1, InputIterator2 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return first2 != last2;
	}

  template< typename InputIterator1,
			typename InputIterator2,
			typename Compare > inline
	bool lexicographical_compare(InputIterator1 first1, InputIterator2 last1,
								 InputIterator2 first2, InputIterator2 last2,
								 Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return first2 != last2;
	}

  namespace rel_ops
  {
	template <typename T>
	  inline bool
	  operator!=(const T& x, const T& y)
	  { return !(x == y); }

	template <typename T>
	  inline bool
	  operator>(const T& x, const T& y)
	  { return y < x; }

	template <typename T>
	  inline bool
	  operator<=(const T& x, const T& y)
	  { return !(y < x); }

	template <typename T>
	  inline bool
	  operator>=(const T& x, const T& y)
	  { return !(x < y); }
 }


  template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1	first;
		T2	second;
	
		pair(void) 
			: first(), second() {}
		pair(const T1& x, const T2& y)
			: first(x), second(y) {}
		template <typename U1, typename U2>
		pair(const pair<U1, U2>& pr)
			: first(pr.first), second(pr.second) {}
		pair& operator=(const pair& pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

  template <typename T1, typename T2>
	inline bool
	operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return x.first == y.first && x.second == y.second; }

  template <typename T1, typename T2>
	inline bool
	operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return x.first < y.first || (!(y.first < x.first) && x.second < y.second); }

  template <typename T1, typename T2>
	inline bool
	operator!=(const pair<T1, T2>&x, const pair<T1, T2>& y)
	{ return !(x == y); }

  template <typename T1, typename T2>
	inline bool
	operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return y < x; }

  template <typename T1, typename T2>
	inline bool
	operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return !(y < x); }

  template <typename T1, typename T2>
	inline bool
	operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return !(x < y); }

  template <typename T1, typename T2>
	inline pair<T1, T2>
	make_pair(const T1& x, const T2& y)
	{ return pair<T1, T2>(x, y); }

}

#endif
