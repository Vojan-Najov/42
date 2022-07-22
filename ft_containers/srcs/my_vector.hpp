/******************************************************************************/
#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include "utils.hpp"

namespace ft
{
  template< typename T, typename Allocator>
	class Vector_base
	{
	public:
		typedef typename Allocator::template rebind<T>::other	allocator_type;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::size_type				size_type;
	
		Vector_base(const allocator_type& alloc)
			: allocator(alloc), start(0),
			  finish(0), end_of_storage(0) {}
		Vector_base(size_type n, const allocator_type& alloc)
			: allocator(alloc)
		{
			start = allocator.allocate(n);
			finish = start;
			end_of_storage = start + n;	
		}
		~Vector_base(void)
		{
			if (start)
				allocator.deallocate(start, end_of_storage - start);
		}
		allocator_type get_allocator(void) const
		{
			return allocator_type();
		}

	protected:
		allocator_type	allocator;
		pointer 		start;
		pointer			finish;
		pointer			end_of_storage;

		pointer allocate(size_type n)
		{
			return allocator.allocate(n);
		}
		void deallocate(pointer p, size_type n)
		{
			if (p)
				allocator.deallocate(p, n);
		}
	};

  template< typename T, typename Allocator = std::allocator<T> >
	class vector : protected Vector_base<T, Allocator>
	{
	protected:
		typedef Vector_base<T, Allocator>	Base;
	public:
		typedef T											value_type;
		typedef typename Base::allocator_type				allocator_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef normal_iterator<pointer, vector>			iterator;
		typedef normal_iterator<const_pointer, vector>		const_iterator;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	protected:
		using Base::allocate;
		using Base::deallocate;
		using Base::start;
		using Base::finish;
		using Base::end_of_storage;
		using Base::allocator;

	public:

		// construct/copy/destroy:
		explicit vector(const allocator_type& alloc = allocator_type());
		explicit vector(size_type n,
						const T& value = T(),
						const allocator_type& alloc = allocator_type());
		template< typename InputIterator >
		  vector(InputIterator first, InputIterator last,
				 const allocator_type& alloc = allocator_type());
		vector(const vector<T, Allocator>& copy);
		~vector(void);
		vector& operator=(vector const& other);
		//void assign(size_type n, value_type const& value);
		//template< typename InputIterator >
		//void assign(InputIterator first, InputIterator last);
		allocator_type get_allocator(void) const;

		// iterators:
		iterator				begin(void);
		iterator				end(void);
		const_iterator			begin(void) const;
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);
		const_reverse_iterator	rbegin(void) const;
		const_reverse_iterator	rend(void) const;

		// capacity:

		size_type 	size(void) const;
		size_type	max_size(void) const;
		void		resize(size_type new_size, value_type value = value_type());
		size_type	capacity(void) const;
		bool		empty(void) const;
		void		reserve(size_type n);

		// element_access:

		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front(void);
		const_reference	front(void) const;
		reference		back(void);
		const_reference	back(void) const;

		// modifiers:

		void 		push_back(value_type const& value);
		void 		pop_back(void);
		iterator	insert(iterator position, value_type const& value);
		void 		insert(iterator position, size_type n,
									value_type const& value);
		template< typename InputIterator>
		void		insert(iterator position, InputIterator first,
											  InputIterator last);
		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last);
		void		swap(vector& other);
		void		clear(void);

	protected:

		pointer _uninitialized_fill_n(pointer ptr, size_type n,
									  value_type const& value);
		template<typename InputIterator>
		pointer _uninitialized_copy(InputIterator first,
									InputIterator last,
									pointer ptr);

		template< typename Integer >
		void _initialize_aux(Integer n, Integer value, true_type);

		template< typename InputIterator >
		void _initialize_aux(InputIterator first,
							 InputIterator last,
							 false_type);

		template< typename InputIterator >
		void _range_initialize(InputIterator first, InputIterator last,
							   input_iterator_tag);

		template< typename ForwardIterator >
		void _range_initialize(ForwardIterator first, ForwardIterator last,
							   forward_iterator_tag);

		void _destroy(pointer first, pointer last);

		pointer _allocate_and_copy(size_type n, pointer first, pointer last);

		void _insert_aux(pointer ptr);

	};

		// construct/copy/destroy:

  template< typename T, typename A >
	vector<T, A>::vector(typename vector<T, A>::allocator_type const& alloc)
		: Vector_base<T,A>(alloc) 
	{}

  template< typename T, typename A >
	vector<T, A>::vector(typename vector<T, A>::size_type n,
						 typename vector<T, A>::value_type const& value,
						 typename vector<T, A>::allocator_type const& alloc)
		: Vector_base<T,A>(n, alloc)
	{
		finish = _uninitialized_fill_n(start, n, value);
	}

  template< typename T, typename A >
	template< typename InputIterator >
	  vector<T, A>::vector(InputIterator first, InputIterator last,
		   	  	 		   typename vector<T, A>::allocator_type const& alloc)
			: Vector_base<T,A>(alloc)
	  {
		_initialize_aux(first, last, is_integral<InputIterator>());
	  }

  template< typename T, typename A >
	vector<T, A>::vector(const vector<T, A>& copy)
			: Vector_base<T, A>(copy.finish - copy.start, copy.allocator)
	{
		finish = _uninitialized_copy(copy.start, copy.finish, start);
	}

  template< typename T, typename A >
	vector<T, A>::~vector(void)
	{
		_destroy(start, finish);
	}

  template< typename T, typename A >
	vector<T, A>& vector<T, A>::operator=(vector<T, A> const& other)
	{
		if (this == &other)
			return *this;
		size_type length = other.finish - other.start;
		if (length > static_cast<size_type>(end_of_storage - start))
		{
			pointer tmp = _allocate_and_copy(length, other.start, other.finish);
			_destroy(start, finish);
			allocator.deallocate(start, end_of_storage - start);
			start = tmp;
			end_of_storage = start + length;	
		}
		else if (length <= static_cast<size_type>(finish - start))
		{
			pointer sptr = start;
			for (pointer osptr = other.start; osptr != other.finish; ++osptr)
			{
				*sptr = *osptr;
				++sptr;
			}
			_destroy(sptr, finish);
		}
		else
		{
			pointer sptr = start;
			pointer osptr = other.start;
			while (sptr != finish)
			{
				*sptr = *osptr;
				++sptr;
				++osptr;
			}
			_uninitialized_copy(osptr, other.finish, finish);
		}
		finish = start + length;
		return *this;
	}

  template< typename T, typename A >
	typename vector<T,A>::allocator_type vector<T,A>::get_allocator(void) const
	{
		return Vector_base<T,A>::get_allocator();
	}
	
		// iterators:

  template< typename T, typename A >
	typename vector<T,A>::iterator vector<T,A>::begin(void)
	{
		return iterator(start);
	}

  template< typename T, typename A >
	typename vector<T,A>::iterator vector<T,A>::end(void)
	{
		return iterator(finish);
	}

  template< typename T, typename A >
	typename vector<T,A>::const_iterator vector<T,A>::begin(void) const
	{
		return const_iterator(start);
	}

  template< typename T, typename A >
	typename vector<T,A>::const_iterator vector<T,A>::end(void) const
	{
		return const_iterator(finish);
	}

  template< typename T, typename A >
	typename vector<T,A>::reverse_iterator vector<T,A>::rbegin(void)
	{
		return reverse_iterator(iterator(finish));
	}

  template< typename T, typename A >
	typename vector<T,A>::reverse_iterator vector<T,A>::rend(void)
	{
		return reverse_iterator(iterator(start));
	}

  template< typename T, typename A >
	typename vector<T,A>::const_reverse_iterator vector<T,A>::rbegin(void) const
	{
		return const_reverse_iterator(iterator(finish));
	}

  template< typename T, typename A >
	typename vector<T,A>::const_reverse_iterator vector<T,A>::rend(void) const
	{
		return const_reverse_iterator(const_iterator(start));
	}

	// capacity:

  template< typename T, typename A >
	typename vector<T,A>::size_type vector<T,A>::size(void) const
	{
		return static_cast<size_type>(finish - start);
	}

  template< typename T, typename A >
	typename vector<T,A>::size_type vector<T,A>::max_size(void) const
	{
		return allocator.max_size();
	}

  template< typename T, typename A >
	void vector<T,A>::resize(typename vector<T,A>::size_type new_size,
							 typename vector<T,A>::value_type value)
	{
		const size_type size = static_cast<size_type>(finish - start);
		if (new_size < size)
			erase(start + new_size, finish);
		else
			insert(finish, new_size - size, value);
	}

  template< typename T, typename A >
	typename vector<T,A>::size_type vector<T,A>::capacity(void) const
	{
		return static_cast<size_type>(end_of_storage - start);
	}

  template< typename T, typename A >
	bool vector<T,A>::empty(void) const
	{
		return start == finish;
	}
	
  template< typename T, typename A >
	void vector<T,A>::reserve(typename vector<T,A>::size_type n)
	{
		if (n > max_size())
		{
			throw std::length_error(
							"cannot create vector larger than max_size()");
		}
		if (capacity() < n)
		{
			const size_type old_size = size();
			pointer tmp = _allocate_and_copy(n, start, finish);
			_destroy(start, finish);
			allocator.deallocate(start, end_of_storage - start);
			start = tmp;
			finish = tmp + old_size;
			end_of_storage = start + n;
		}
	}

	// element_access:

  template< typename T, typename A >
	typename vector<T,A>::reference
	vector<T,A>::operator[](typename vector<T,A>::size_type n)
	{
		return *(start + n);
	}	

  template< typename T, typename A >
	typename vector<T,A>::const_reference
	vector<T,A>::operator[](typename vector<T,A>::size_type n) const
	{
		return *(start + n);
	}	

  template<typename T, typename A >
	typename vector<T,A>::reference
	vector<T,A>::at(typename vector<T,A>::size_type n)
	{
		if (n >= size())
			throw std::range_error("Index is out of range");
		return *(start + n);
	}
	
  template<typename T, typename A >
	typename vector<T,A>::const_reference
	vector<T,A>::at(typename vector<T,A>::size_type n) const
	{
		if (n >= size())
			throw std::range_error("Index is out of range");
		return *(start + n);
	}

  template< typename T, typename A >
	typename vector<T,A>::reference
	vector<T,A>::front(void)
	{
		return *start;
	}	

  template< typename T, typename A >
	typename vector<T,A>::const_reference
	vector<T,A>::front(void) const
	{
		return *start;
	}	

  template< typename T, typename A >
	typename vector<T,A>::reference
	vector<T,A>::back(void)
	{
		return *(finish - 1);
	}	

  template< typename T, typename A >
	typename vector<T,A>::const_reference
	vector<T,A>::back(void) const
	{
		return *(finish - 1);
	}

		// modifiers:

  template< typename T, typename A >
	void vector<T,A>::push_back(typename vector<T,A>::value_type const& value)
	{
		if (finish != end_of_storage)
		{
			allocator.construct(finish, value);
			++finish;
		}
		else
		{
			//_insert_aux(value);
			const size_type old_size = size();
			const size_type len = old_size != 0 ? 2 * old_size : 1;
			pointer new_start = allocator.allocate(len);
			pointer new_finish = new_start;
			try
			{
				new_finish = _uninitialized_copy(start, finish, new_start);
				allocator.construct(new_finish, value);
				++new_finish;
			}
			catch (...)
			{
				_destroy(new_start, new_finish);
				allocator.deallocate(new_start, len);
				throw;
			}
			_destroy(start, finish);
			allocator.deallocate(start, end_of_storage - start);
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + len;
		}
	}

  template< typename T, typename A >
	void vector<T,A>::pop_back(void)
	{
		--finish;
		allocator.destroy(finish);
	}

  template< typename T, typename A >
	typename vector<T,A>::iterator vector<T,A>::insert(
								typename vector<T,A>::iterator position,
								typename vector<T,A>::value_type const& value)
	{
		pointer posptr = position.base();
		size_type n = posptr - start;
		if (finish != end_of_storage && posptr == finish)
		{
			allocator.construct(finish);
			++finish;
		}
		else if (finish != end_of_storage)
		{
			allocator.construct(finish, *(finish - 1));
			++finish;
			pointer curpos = finish - 2;
			while (curpos != posptr)
			{
				T tmp = *curpos;
				*curpos = *(curpos - 1);
				--curpos;
				*curpos = tmp;
			}
			*curpos = value;
		}
		else
		{
			const size_type old_size = size();
			const size_type len = old_size != 0 ? 2 * old_size : 1;
			pointer new_start = allocator.allocate(len);
			pointer new_finish = new_start;
			try
			{
				new_finish = _uninitialized_copy(start, posptr, new_start);
				allocator.construct(new_finish, value);
				++new_finish;
				new_finish = _uninitialized_copy(posptr, finish, new_finish);
			}
			catch (...)
			{
				_destroy(new_start, new_finish);
				allocator.deallocate(new_start, len);
			}
			_destroy(start, finish);
			allocator.deallocate(start, end_of_storage - start);
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + len;
		}

		return iterator(start + n);	
	}

/*
		iterator	insert(iterator position, value_type const& value);
		void 		insert(iterator position, size_type n,
									value_type const& value);
		template< typename InputIterator>
		void		insert(iterator position, InputIterator first,
											  InputIterator last)
		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last);
		void		swap(vector& other);
		void		clear(void);
*/
		// utility: 

  template< typename T, typename A >
	typename vector<T, A>::pointer
	vector<T, A>::_uninitialized_fill_n(
								typename vector<T, A>::pointer ptr,
								typename vector<T, A>::size_type n,
								typename vector<T, A>::value_type const& value)
	{
		while (n > 0)
		{
			allocator.construct(ptr, value);
			++ptr;
			--n;
		}
		return ptr;
	}

  template< typename T, typename A >
   template< typename InputIterator >
	typename vector<T, A>::pointer
	vector<T, A>::_uninitialized_copy(InputIterator first,
									  InputIterator last,
									  typename vector<T, A>::pointer ptr)
	{
		while (first != last)
		{
			allocator.construct(ptr, *first);
			++ptr;
			++first;
		}
		return ptr;
	}

  template< typename T, typename A >
   template< typename Integer >
	void vector<T,A>::_initialize_aux(Integer n, Integer value, ft::true_type)
	{
		start = allocator.allocate(n);
		end_of_storage = start + n;
		finish = _uninitialized_fill_n(start, n, value);
	}

  template< typename T, typename A >
   template< typename InputIterator >
	void vector<T, A>::_initialize_aux(InputIterator first,
									   InputIterator last,
									   false_type)
	{
		_range_initialize(first, last,
				typename iterator_traits<InputIterator>::iterator_category());
	}

  template< typename T, typename A >
   template< typename InputIterator >
	void vector<T, A>::_range_initialize(InputIterator first,
										 InputIterator last,
							   			 input_iterator_tag)
	{
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}

  template< typename T, typename A >
   template< typename ForwardIterator >
	void vector<T, A>::_range_initialize(ForwardIterator first,
										 ForwardIterator last,
										 forward_iterator_tag)
	{
		size_type n = distance(first, last);
		start = allocator.allocate(n);
		end_of_storage = start + n;
		finish = _uninitialized_copy(first, last, start);
	}

  template< typename T, typename A >
	void vector<T,A>::_destroy(typename vector<T,A>::pointer first,
							   typename vector<T,A>::pointer last)
	{
		while (first != last)
		{
			allocator.destroy(first);
			++first;
		}
	}

  template< typename T, typename A >
	typename vector<T,A>::pointer
	vector<T,A>::_allocate_and_copy(typename vector<T,A>::size_type n,
									typename vector<T,A>::pointer first,
									typename vector<T,A>::pointer last)
	{
		pointer ptr = allocator.allocate(n);
		pointer curptr = ptr;
		while (first != last)
		{
			allocator.construct(curptr, *first);
			++first;
			++curptr;
		}
		return ptr;
	}
}

#endif
