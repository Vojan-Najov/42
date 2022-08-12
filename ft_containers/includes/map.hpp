/******************************************************************************/
#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "rb_tree.hpp"

namespace ft
{

  template< typename Key, typename T, typename Compare = ft::less<Key>,
			typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		// types:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef	ft::pair<const Key, T>					value_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		
		class value_compare
			: public ft::binary_function<value_type, value_type, bool>
		{
			friend class map<Key, T, Compare, Allocator>;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}
			public:
				bool operator()(const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

	private:
		typedef Rb_tree<key_type, value_type, ft::Select1st<value_type>,
						key_compare, allocator_type>	Rep_type;
		Rep_type rbt;		// red-black tree representing map.
	public:
		typedef typename Rep_type::iterator				iterator;
		typedef typename Rep_type::const_iterator		const_iterator;
		typedef typename Rep_type::reverse_iterator		reverse_iterator;
		typedef
		typename Rep_type::const_reverse_iterator 		const_reverse_iterator;
		typedef typename Rep_type::size_type			size_type;
		typedef typename Rep_type::difference_type		difference_type;

		// Construct/copy/destroy
		explicit map(const Compare& comp = Compare(),
					 const Allocator& a = Allocator())
			: rbt(comp, a) {}

		template< typename InputIterator >
		map(InputIterator first, InputIterator last,
			const Compare& comp = Compare(), const Allocator a = Allocator())
			: rbt(comp, a)
		{
			rbt.insert_unique(first, last);
		}

		map(const map<Key,T,Compare,Allocator>& x)
			: rbt(x.rbt) {}

		~map(void) {}

		map<Key,T,Compare,Allocator>&
		operator=(const map<Key,T,Compare,Allocator>& x)
		{
			rbt = x.rbt;
			return *this;
		}

		// iterators:
		iterator				begin(void)			{ return rbt.begin(); }
		const_iterator			begin(void) const	{ return rbt.begin(); }
		iterator				end(void)			{ return rbt.end(); }
		const_iterator			end(void) const		{ return rbt.end(); }
		reverse_iterator		rbegin(void)		{ return rbt.rbegin(); }
		const_reverse_iterator	rbegin(void) const	{ return rbt.rbegin(); }
		reverse_iterator		rend(void)			{ return rbt.rend(); }
		const_reverse_iterator	rend(void) const	{ return rbt.rend(); }

		// capacity:
		bool					empty(void) const	{ return rbt.empty(); }
		size_type				size(void) const	{ return rbt.size(); }
		size_type				max_size(void) const { return rbt.max_size(); }	

		// element access:
		T& operator[](const key_type& k)
		{
			iterator it = lower_bound(k);
			if (it == end() || key_comp()(k, (*it).first))
				it = insert(it, value_type(k, T()));
			return (*it).second;
		}

		// modifiers:
		ft::pair<iterator, bool> insert(const value_type& x)
		{ return rbt.insert_unique(x); }

		iterator insert(iterator position, const value_type& x)
		{ return rbt.insert_unique(position, x); }

		template< typename InputIterator >
		void insert(InputIterator first, InputIterator last)
		{ rbt.insert_unique(first, last); }

		void erase(iterator position) { return rbt.erase(position); }

		size_type erase(const key_type& x) { return rbt.erase(x); }

		void erase(iterator first, iterator last) { rbt.erase(first, last); }

		void clear(void) { rbt.clear(); }

		void swap(map<Key,T,Compare,Allocator>& x) { return rbt.swap(x.rbt); }

		// observers:
		key_compare key_comp(void) const { return rbt.key_comp(); }

		value_compare value_comp(void) const
		{ return value_compare(rbt.key_comp()); }

		// map operations
		iterator find(const key_type& k) { return rbt.find(k); }

		const_iterator find(const key_type& k) const { return rbt.find(k); }

		size_type count(const key_type& k) const
		{ return rbt.find(k) == rbt.end() ? 0 : 1; }

		iterator lower_bound(const key_type& k) { return rbt.lower_bound(k); }

		const_iterator lower_bound(const key_type& k) const
		{ return rbt.lower_bound(k); }

		iterator upper_bound(const key_type& k) { return rbt.upper_bound(k); }

		const_iterator upper_bound(const key_type& k) const
		{ return rbt.upper_bound(k); }
		
		pair<iterator,iterator> equal_range(const key_type& k)
		{ return rbt.equal_range(k); }

		pair<const_iterator,const_iterator> equal_range(const key_type& k) const
		{ return rbt.equal_range(k); }

		// Relation operators
		template< typename K1, typename T1, typename C1, typename A1 >
		friend bool operator==(const map<K1,T1,C1,A1>& lhs,
							   const map<K1,T1,C1,A1>& rhs);
		
		template< typename K1, typename T1, typename C1, typename A1 >
		friend bool operator<(const map<K1,T1,C1,A1>& lhs,
							   const map<K1,T1,C1,A1>& rhs);
	};

  // Relation operators
  template< typename Key, typename T, typename Compare, typename Alloc >
	inline bool operator==(const map<Key,T,Compare,Alloc>& lhs,
						   const map<Key,T,Compare,Alloc>& rhs)
	{
		return lhs.rbt == rhs.rbt;
	}

  template< typename Key, typename T, typename Compare, typename Alloc >
	inline bool operator!=(const map<Key,T,Compare,Alloc>& lhs,
						   const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

  template< typename Key, typename T, typename Compare, typename Alloc >
	inline bool operator<(const map<Key,T,Compare,Alloc>& lhs,
						  const map<Key,T,Compare,Alloc>& rhs)
	{
		return lhs.rbt < rhs.rbt;
	}

  template< typename Key, typename T, typename Compare, typename Alloc >
	inline bool operator>(const map<Key,T,Compare,Alloc>& lhs,
						  const map<Key,T,Compare,Alloc>& rhs)
	{
		return rhs < lhs;
	}

  template< typename Key, typename T, typename Compare, typename Alloc >
	inline bool operator<=(const map<Key,T,Compare,Alloc>& lhs,
						   const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

  template< typename Key, typename T, typename Compare, typename Alloc >
	inline bool operator>=(const map<Key,T,Compare,Alloc>& lhs,
						   const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

  // Swap specialization
  template< typename Key, typename T, typename Compare, typename Alloc >
	inline void swap(const map<Key,T,Compare,Alloc>& lhs,
					 const map<Key,T,Compare,Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

/*
STD::SWAP specialization
*/
namespace std
{
  template< typename Key, typename T, typename Compare, typename Alloc >
	inline void swap(const ft::map<Key,T,Compare,Alloc>& lhs,
					 const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

}

#endif
