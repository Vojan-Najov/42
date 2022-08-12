/******************************************************************************/

#ifndef FT_SET_HPP
#define FT_SET_HPP

#include "rb_tree.hpp"

namespace ft{

  template< typename Key, typename Compare = ft::less<Key>,
			typename Allocator = std::allocator<Key> >
	class set
	{
	private:
		typedef
		Rb_tree<Key, Key, ft::Identity<Key>, Compare, Allocator> Rep_type;

		Rep_type	rbt;

	public:
		typedef Key									key_type;
		typedef Key									value_type;
		typedef Compare								key_compare;
		typedef Compare								value_compare;
		typedef Allocator							allocator_type;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Rep_type::const_iterator	iterator;
		typedef typename Rep_type::const_iterator	const_iterator;
		typedef
		typename Rep_type::const_reverse_iterator	reverse_iterator;
		typedef
		typename Rep_type::const_reverse_iterator	const_reverse_iterator;
		typedef typename Rep_type::size_type		size_type;
		typedef typename Rep_type::difference_type	difference_type;

		// construct/assign/destroy
		explicit set(const Compare& c = Compare(),
					 const Allocator& a = Allocator())
			: rbt(c, a)
		{}

		template< typename InputIterator >
		set(InputIterator first, InputIterator last,
			const Compare& c = Compare(), const Allocator& a = Allocator())
			: rbt(c, a)
		{ rbt.insert_unique(first, last); }

		set(const set<Key,Compare,Allocator>& x) : rbt(x.rbt) {}

		~set(void) {}

		set<Key,Compare,Allocator>& operator=
		(const set<Key,Compare,Allocator>& x)
		{ 
			rbt = x.rbt;
			return *this;
		}

		// iterators
		iterator				begin(void)			{ return rbt.begin(); }
		const_iterator			begin(void) const	{ return rbt.begin(); }
		iterator				end(void)			{ return rbt.end(); }
		const_iterator			end(void) const		{ return rbt.end(); }
		reverse_iterator		rbegin(void)		{ return rbt.rbegin(); }
		const_reverse_iterator	rbegin(void) const	{ return rbt.rbegin(); }
		reverse_iterator		rend(void)			{ return rbt.rend(); }
		const_reverse_iterator	rend(void) const	{ return rbt.rend(); }

		// capacity
		bool		empty(void) const		{ return rbt.empty(); }
		size_type	size(void) const		{ return rbt.size(); }
		size_type	max_size(void) const	{ return rbt.max_size(); }

		// modifiers
		ft::pair<iterator, bool> insert(const value_type& k)
		{
			ft::pair<typename Rep_type::iterator,
					 bool> p = rbt.insert_unique(k);
			return pair<iterator, bool>(p.first, p.second);
		}

		iterator insert(iterator position, const value_type& k)
		{
			return rbt.insert_unique(position, k);
		}

		template< typename InputIterator >
		void insert(InputIterator first, InputIterator last)
		{
			rbt.insert_unique(first, last);
		}

		void erase(iterator position) { rbt.erase(position); }

		size_type erase(const key_type& k) { return rbt.erase(k); }

		void erase(iterator first, iterator last) { rbt.erase(first, last); }

		void swap(set<Key,Compare,Allocator>& x) { rbt.swap(x.rbt); }

		void clear(void) { rbt.clear(); }

		// observers
		key_compare		key_comp(void) const { return rbt.key_comp(); }

		value_compare	value_comp(void) const { return rbt.key_comp(); }

		// set operations

		iterator find(const key_type& k) const { return rbt.find(k); }

		size_type count(const key_type& k) const
		{ 
			return rbt.find(k) == rbt.end() ? 0 : 1;
		}

		iterator lower_bound(const key_type& k) const
		{
			return rbt.lower_bound(k);
		}

		iterator upper_bound(const key_type& k) const
		{
			return rbt.upper_bound(k);
		}

		ft::pair<iterator, iterator> equal_range(const key_type& k) const
		{
			return rbt.equal_range(k);
		}

		template< typename K, typename C, typename Al >
		friend bool operator==(const set<K,C,Al>& lhs, const set<K,C,Al>& rhs);
		template< typename K, typename C, typename Al >
		friend bool operator<(const set<K,C,Al>& lhs, const set<K,C,Al>& rhs);

	};

  template< typename Key, typename Compare, typename Allocator >
	inline bool operator==(const set<Key,Compare,Allocator>& lhs,
						   const set<Key,Compare,Allocator>& rhs)
	{
		return lhs.rbt == rhs.rbt;
	}

  template< typename Key, typename Compare, typename Allocator >
	inline bool operator<(const set<Key,Compare,Allocator>& lhs,
						   const set<Key,Compare,Allocator>& rhs)
	{
		return lhs.rbt < rhs.rbt;
	}

  template< typename Key, typename Compare, typename Allocator >
	inline bool operator!=(const set<Key,Compare,Allocator>& lhs,
						   const set<Key,Compare,Allocator>& rhs)
	{
		return !(lhs == rhs);
	}

  template< typename Key, typename Compare, typename Allocator >
	inline bool operator>(const set<Key,Compare,Allocator>& lhs,
						   const set<Key,Compare,Allocator>& rhs)
	{
		return rhs < lhs;
	}


  template< typename Key, typename Compare, typename Allocator >
	inline bool operator<=(const set<Key,Compare,Allocator>& lhs,
						   const set<Key,Compare,Allocator>& rhs)
	{
		return !(rhs < lhs);
	}


  template< typename Key, typename Compare, typename Allocator >
	inline bool operator>=(const set<Key,Compare,Allocator>& lhs,
						   const set<Key,Compare,Allocator>& rhs)
	{
		return !(lhs < rhs);
	}

	// swap specialization
  template< typename Key, typename Compare, typename Allocator >
	inline void swap(set<Key,Compare,Allocator>& lhs,
					 set<Key,Compare,Allocator>& rhs)
	{
		lhs.swap(rhs);
	}
}

/*
STD::SWAP specialization
*/
namespace std
{
  template< typename Key, typename Compare, typename Allocator >
	inline void swap(ft::set<Key,Compare,Allocator>& lhs,
					 ft::set<Key,Compare,Allocator>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
