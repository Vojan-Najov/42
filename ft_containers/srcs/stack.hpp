/******************************************************************************/

#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "vector.hpp"

namespace ft
{
  template< typename T, typename Container = ft::vector<T> >
	class stack
	{
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		typedef Container						container_type;
	protected:
		Container c;
	public:
		explicit stack(Container const& c = Container()) : c(c) {}

		bool 				empty(void) const { return c.empty(); }
		size_type			size(void) const { return c.size(); }
		value_type&			top(void) { return c.back(); }
		value_type const&	top(void) const { return c.back(); }
		void				push(value_type const& val) { c.push_back(val); }
		void				pop(void) { c.pop_back(); }

		template< typename U, typename Cntr >
		friend bool operator==(stack<U, Cntr> const&lhs,
							   stack<U, Cntr> const& rhs);

		template< typename U, typename Cntr >
		friend bool operator<(stack<U, Cntr> const&lhs,
							   stack<U, Cntr> const& rhs);
	};

  template< typename T, typename Container > inline
	bool operator==(stack<T, Container> const& lhs,
					stack<T, Container> const& rhs)
	{
		return lhs.c == rhs.c;
	}

  template< typename T, typename Container > inline
	bool operator<(stack<T, Container> const& lhs,
					stack<T, Container> const& rhs)
	{
		return lhs.c < rhs.c;
	}

  template< typename T, typename Container > inline
	bool operator!=(stack<T, Container> const& lhs,
					stack<T, Container> const& rhs)
	{
		return !(lhs == rhs);
	}
	
  template< typename T, typename Container > inline
	bool operator>(stack<T, Container> const& lhs,
					stack<T, Container> const& rhs)
	{
		return rhs < lhs;
	}
	
  template< typename T, typename Container > inline
	bool operator<=(stack<T, Container> const& lhs,
					stack<T, Container> const& rhs)
	{
		return !(rhs < lhs);
	}
	
  template< typename T, typename Container > inline
	bool operator>=(stack<T, Container> const& lhs,
					stack<T, Container> const& rhs)
	{
		return !(lhs < rhs);
	}

}

#endif
