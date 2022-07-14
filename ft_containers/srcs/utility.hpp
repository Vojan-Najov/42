#ifndef FT_UTILITY_HPP
#define FT_UTILITY_HPP

#include <iosfwd>

namespace ft
{

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

	/* SFINAE */

	template<bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> { typedef T type};

	/* IS_INTEGRAL */

	template <typename T, T val>
	struct integral_constant
	{
		typedef integral_constant<T, val>	type;
		typedef T							value_type;
		static const T value = val;
		
	}

}

#endif
