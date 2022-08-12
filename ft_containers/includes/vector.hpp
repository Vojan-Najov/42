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
			start = allocate(n);
			finish = start;
			end_of_storage = start + n;	
		}
		~Vector_base(void)
		{
			deallocate(start, end_of_storage - start);
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
			if (n > max_size())
				throw std::length_error(
						"cannot create vector larger than max_size()");
			return allocator.allocate(n);
		}
		void deallocate(pointer p, size_type n)
		{
			if (p)
				allocator.deallocate(p, n);
		}
		void construct(pointer p, T const& value)
		{
			allocator.construct(p, value);
		}
		void destroy(pointer p)
		{
			allocator.destroy(p);
		}
		size_type max_size(void) const
		{
			return allocator.max_size();
		}
	};

  template< typename T, typename Allocator = std::allocator<T> >
	class vector : protected Vector_base<T, Allocator>
	{
	protected:
		typedef Vector_base<T, Allocator>		Base;
		typedef typename Base::allocator_type	T_allocator_type;
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename T_allocator_type::pointer			pointer;
		typedef typename T_allocator_type::const_pointer	const_pointer;
		typedef typename T_allocator_type::reference		reference;
		typedef typename T_allocator_type::const_reference	const_reference;
		typedef normal_iterator<pointer, vector>			iterator;
		typedef normal_iterator<const_pointer, vector>		const_iterator;
		typedef typename T_allocator_type::size_type		size_type;
		typedef typename T_allocator_type::difference_type	difference_type;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	protected:
		using Base::allocate;
		using Base::deallocate;
		using Base::construct;
		using Base::destroy;
		using Base::start;
		using Base::finish;
		using Base::end_of_storage;

	public:

		// construct/copy/destroy:
		explicit vector(const allocator_type& alloc = allocator_type());
		explicit vector(size_type n,
						value_type const& value = T(),
						allocator_type const& alloc = allocator_type());
		template< typename InputIterator >
		vector(InputIterator first, InputIterator last,
			   const allocator_type& alloc = allocator_type());
		vector(const vector<T, Allocator>& copy);
		~vector(void);
		vector& operator=(vector const& other);
		void assign(size_type n, value_type const& value);
		template< typename InputIterator >
		void assign(InputIterator first, InputIterator last);
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
		void		resize(size_type new_size,
						   value_type value = value_type());
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

		template< typename InputIterator >
		pointer _allocate_and_copy(size_type n, InputIterator first,
												InputIterator last);

		template< typename Integer >
		void _initialize_aux(Integer n, Integer value, true_type);

		template< typename InputIterator >
		void _initialize_aux(InputIterator first,
							 InputIterator last,
							 false_type);

		template< typename InputIterator >
		void _range_initialize(InputIterator first, InputIterator last,
							   std::input_iterator_tag);

		template< typename ForwardIterator >
		void _range_initialize(ForwardIterator first, ForwardIterator last,
							   std::forward_iterator_tag);

		void _fill_assign(size_type n, value_type const& value);


		template< typename Integral >
		void _assign_dispatch(Integral n, Integral value, ft::true_type);


		template< typename InputIterator>
		void _assign_dispatch(InputIterator first,
							  InputIterator last, ft::false_type);

		template< typename InputIterator>
		void _assign_aux(InputIterator first,
						 InputIterator last, std::input_iterator_tag);

		template< typename ForwardIterator>
		void _assign_aux(ForwardIterator first,
						 ForwardIterator last,
						 std::forward_iterator_tag);

		void _insert_aux(pointer position, value_type const& val);

		void _insert_fill(pointer position, size_type n,
						  value_type const& val);

		template< typename Integral >
		void _insert_dispatch(iterator position, Integral n,
							  Integral value, true_type);

		template< typename InputIterator >
		void _insert_dispatch(iterator position, InputIterator first,
							  InputIterator last, ft::false_type);

		template< typename InputIterator >
  		void _range_insert(iterator position, InputIterator first,
						   InputIterator last, std::input_iterator_tag);
	
   		template< typename ForwardIterator >
  		void _range_insert(iterator position, ForwardIterator first,
						   ForwardIterator last, std::forward_iterator_tag);

		void _destroy(pointer first, pointer last);

	};

					// construct/copy/destroy:

	/*
	empty container constructor (default constructor)
    Constructs an empty container, with no elements.
	*/

  template< typename T, typename A >
	vector<T, A>::vector(typename vector<T, A>::allocator_type const& alloc)
		: Vector_base<T,A>(alloc) 
	{}

	/*
	fill constructor
    Constructs a container with n elements. Each element is a copy of val.
	*/

  template< typename T, typename A >
	vector<T, A>::vector(typename vector<T, A>::size_type n,
						 typename vector<T, A>::value_type const& value,
						 typename vector<T, A>::allocator_type const& alloc)
		: Vector_base<T,A>(n, alloc)
	{
		finish = _uninitialized_fill_n(start, n, value);
	}

	/*
	range constructor
    Constructs a container with as many elements as the range [first,last),
	with each element constructed from its corresponding element in that range,
	in the same order.
	*/

  template< typename T, typename A >
   template< typename InputIterator >
	vector<T, A>::vector(InputIterator first, InputIterator last,
		   	  	 		 typename vector<T, A>::allocator_type const& alloc)
			: Vector_base<T,A>(alloc)
	  {
		_initialize_aux(first, last, is_integral<InputIterator>());
	  }

	/*
	copy constructor
    Constructs a container with a copy of each of the elements in other,
	in the same order.
	*/

  template< typename T, typename A >
	vector<T, A>::vector(const vector<T, A>& copy)
			: Vector_base<T, A>(copy.finish - copy.start, copy.allocator)
	{
		finish = _uninitialized_copy(copy.start, copy.finish, start);
	}

	/*
	Vector destructor
	Destroys the container object.
	*/

  template< typename T, typename A >
	vector<T, A>::~vector(void)
	{
		_destroy(start, finish);
	}

	/*
	Assign content
	Assigns new contents to the container, replacing its current contents,
	and modifying its size accordingly.
	The container preserves its current allocator, which is used to allocate
	storage in case of reallocation.
	Any elements held in the container before the call are either assigned
	to or destroyed.
	All iterators, references and pointers related to this container before
	the call are invalidated.
	Basic guarantee: if an exception is thrown, the container is in a valid
	state.
	*/

  template< typename T, typename A >
	vector<T, A>& vector<T, A>::operator=(vector<T, A> const& other)
	{
		if (this == &other)
			return *this;
		size_type length = other.finish - other.start;
		if (length > static_cast<size_type>(end_of_storage - start))
		{
			pointer tmp = _allocate_and_copy(length, other.start,
													 other.finish);
			_destroy(start, finish);
			deallocate(start, end_of_storage - start);
			start = tmp;
			end_of_storage = start + length;	
		}
		else if (length <= static_cast<size_type>(finish - start))
		{
			pointer ptr = copy(other.start, other.finish, start);
			_destroy(ptr, finish);
		}
		else
		{
			copy(other.start, other.start + size(), start);
			_uninitialized_copy(other.start + size(), finish, finish);
		}
		finish = start + length;
		return *this;
	}

	/*
	Assign vector content
	Assigns new contents to the vector, replacing its current contents,
	and modifying its size accordingly.
	In the range version, the new contents are elements constructed from
	each of the elements in the range between first and last, in the same
	order.
	In the fill version, the new contents are n elements, each initialized
	to a copy of val.
	If a reallocation happens,the storage needed is allocated using the
	internal allocator.
	Any elements held in the container before the call are destroyed and
	replaced by newly constructed elements (no assignments of elements take
	place). This causes an automatic reallocation of the allocated storage
	space if -and only if- the new vector size surpasses the current vector
	capacity.
	*/

  template< typename T, typename A >
	void vector<T,A>::assign(typename vector<T,A>::size_type n,
							 typename vector<T,A>::value_type const& value)
	{
		_fill_assign(n, value);
	}

  template< typename T, typename A >
   template< typename InputIterator >
	void vector<T,A>::assign(InputIterator first, InputIterator last)
	{
		_assign_dispatch(first, last, ft::is_integral<InputIterator>());
	}

	/*
	Get allocator
	Returns a copy of the allocator object associated with the vector.
	Member type allocator_type is the type of the allocator used by the
	container, defined in vector as an alias of its second template parameter.
	*/

  template< typename T, typename A >
	typename vector<T,A>::allocator_type vector<T,A>::get_allocator(void) const
	{
		return allocator_type();
	}
	
// ITERATORS:

	/*
	Returns an iterator pointing to the first element in the vector.
	If the vector object is const-qualified, the function returns a
	const_iterator.
	*/

  template< typename T, typename A >
	typename vector<T,A>::iterator vector<T,A>::begin(void)
	{
		return iterator(start);
	}

  template< typename T, typename A >
	typename vector<T,A>::const_iterator vector<T,A>::begin(void) const
	{
		return const_iterator(start);
	}

	/*
	Returns an iterator referring to the past-the-end element in the vector
	container. The past-the-end element is the theoretical element that would
	follow the last element in the vector. It does not point to any element,
	and thus shall not be dereferenced. If the vector object is const-qualified,
	the function returns a const_iterator. Otherwise, it returns an iterator.
	*/

  template< typename T, typename A >
	typename vector<T,A>::iterator vector<T,A>::end(void)
	{
		return iterator(finish);
	}

  template< typename T, typename A >
	typename vector<T,A>::const_iterator vector<T,A>::end(void) const
	{
		return const_iterator(finish);
	}

	/*
	Returns a reverse iterator pointing to the last element in the vector
	(i.e., its reverse beginning).
	Reverse iterators iterate backwards: increasing them moves them towards
	the beginning of the container.
	If the vector object is const-qualified, the function returns a
	const_reverse_iterator. Otherwise, it returns a reverse_iterator.
	*/

  template< typename T, typename A >
	typename vector<T,A>::reverse_iterator vector<T,A>::rbegin(void)
	{
		return reverse_iterator(iterator(finish));
	}

template< typename T, typename A >
	typename vector<T,A>::const_reverse_iterator vector<T,A>::rbegin(void) const
	{
		return const_reverse_iterator(iterator(finish));
	}

	/*
	Returns a reverse iterator pointing to the theoretical element preceding
	the first element in the vector (which is considered its reverse end).
	If the vector object is const-qualified, the function returns a
	const_reverse_iterator. Otherwise, it returns a reverse_iterator.
	*/

  template< typename T, typename A >
	typename vector<T,A>::reverse_iterator vector<T,A>::rend(void)
	{
		return reverse_iterator(iterator(start));
	}

    template< typename T, typename A >
	typename vector<T,A>::const_reverse_iterator vector<T,A>::rend(void) const
	{
		return const_reverse_iterator(const_iterator(start));
	}

// CAPACITY:

	/*
	Returns the number of elements in the vector.
	This is the number of actual objects held in the vector, which is not
	necessarily equal to its storage capacity.
	*/

  template< typename T, typename A >
	typename vector<T,A>::size_type vector<T,A>::size(void) const
	{
		return static_cast<size_type>(finish - start);
	}

	/*
	Returns the maximum number of elements that the vector can hold.
	This is the maximum potential size the container can reach due to known
	system or library implementation limitations, but the container is by no
	means guaranteed to be able to reach that size: it can still fail to
	allocate storage at any point before that size is reached
	*/

  template< typename T, typename A >
	typename vector<T,A>::size_type vector<T,A>::max_size(void) const
	{
		return Base::max_size();
	}

	/*
	Resizes the container so that it contains n elements.
	If n is smaller than the current container size, the content is reduced
	to its first n elements, removing those beyond (and destroying them).
	If n is greater than the current container size, the content is expanded
	by inserting at the end as many elements as needed to reach a size of n.
	If val is specified, the new elements are initialized as copies of val,
	otherwise, they are value-initialized.
	If n is also greater than the current container capacity, an automatic
	reallocation of the allocated storage space takes place.
	*/

  template< typename T, typename A >
	void vector<T,A>::resize(typename vector<T,A>::size_type new_size,
							 typename vector<T,A>::value_type value)
	{
		const size_type size = static_cast<size_type>(finish - start);
		if (new_size < size)
			erase(iterator(start + new_size), end());
		else
			insert(end(), new_size - size, value);
	}

	/*
	Returns the size of the storage space currently allocated for the vector,
	expressed in terms of elements.
	This capacity is not necessarily equal to the vector size. It can be equal
	or greater, with the extra space allowing to accommodate for growth
	without the need to reallocate on each insertion.
	*/

  template< typename T, typename A >
	typename vector<T,A>::size_type vector<T,A>::capacity(void) const
	{
		return static_cast<size_type>(end_of_storage - start);
	}

	/*
	Returns whether the vector is empty (i.e. whether its size is 0).
	*/

  template< typename T, typename A >
	bool vector<T,A>::empty(void) const
	{
		return start == finish;
	}

	/*
	Requests that the vector capacity be at least enough to contain n elements.
	If n is greater than the current vector capacity, the function causes the
	container to reallocate its storage increasing its capacity to n
	(or greater). In all other cases, the function call does not cause a
	reallocation and the vector capacity is not affected.
	*/
	
  template< typename T, typename A >
	void vector<T,A>::reserve(typename vector<T,A>::size_type n)
	{
		if (capacity() < n)
		{
			const size_type old_size = size();
			pointer tmp = _allocate_and_copy(n, start, finish);
			_destroy(start, finish);
			deallocate(start, end_of_storage - start);
			start = tmp;
			finish = tmp + old_size;
			end_of_storage = start + n;
		}
	}

// ELEMENT_ACCESS:

	/*
	Returns a reference to the element at position n in the vector container.
	If the vector object is const-qualified, the function returns a
	const_reference. Otherwise, it returns a reference.
	*/

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

	/*
	Returns a reference to the element at position n in the vector.
	The function automatically checks whether n is within the bounds of valid
	elements in the vector, throwing an out_of_range exception if it is not
	(i.e., if n is greater than, or equal to, its size).
	If the vector object is const-qualified, the function returns a
	const_reference. Otherwise, it returns a reference.
	*/

  template<typename T, typename A >
   typename vector<T,A>::reference
	vector<T,A>::at(typename vector<T,A>::size_type n)
	{
		if (n >= size())
			throw std::out_of_range("Index is out of range");
		return *(start + n);
	}
	
  template<typename T, typename A >
   typename vector<T,A>::const_reference
	vector<T,A>::at(typename vector<T,A>::size_type n) const
	{
		if (n >= size())
			throw std::out_of_range("Index is out of range");
		return *(start + n);
	}

	/*
	Returns a reference to the first element in the vector.
	If the vector object is const-qualified, the function returns a
	const_reference. Otherwise, it returns a reference.
	*/

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

	/*
	Returns a reference to the last element in the vector.
	If the vector object is const-qualified, the function returns a
	const_reference. Otherwise, it returns a reference.
	*/

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

// MODIFIERS:

	/*
	 Adds a new element at the end of the vector, after its current last
	element. The content of val is copied (or moved) to the new element.
	This effectively increases the container size by one, which causes an
	automatic reallocation of the allocated storage space if -and only if- the
	new vector size surpasses the current vector capacity.
	*/

  template< typename T, typename A >
	void vector<T,A>::push_back(typename vector<T,A>::value_type const& value)
	{
		if (finish != end_of_storage)
		{
			construct(finish, value);
			++finish;
		}
		else
		{
			const size_type old_size = size();
			const size_type len = old_size != 0 ? 2 * old_size : 1;
			pointer new_start = allocate(len);
			pointer new_finish = new_start;
			try
			{
				new_finish = _uninitialized_copy(start, finish, new_start);
				construct(new_finish, value);
				++new_finish;
			}
			catch (...)
			{
				deallocate(new_start, len);
				throw;
			}
			_destroy(start, finish);
			deallocate(start, end_of_storage - start);
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + len;
		}
	}

	/*
	Removes the last element in the vector, effectively reducing the container
	size by one.
	This destroys the removed element.
	*/

  template< typename T, typename A >
	void vector<T,A>::pop_back(void)
	{
		--finish;
		destroy(finish);
	}

	/*
	Insert elements
	The vector is extended by inserting new elements before the element at the
	specified position, effectively increasing the container size by the number
	of elements inserted.
	This causes an automatic reallocation of the allocated storage space
	if -and only if- the new vector size surpasses the current vector capacity.
	*/

  template< typename T, typename A >
	typename vector<T,A>::iterator vector<T,A>::insert(
								typename vector<T,A>::iterator position,
								typename vector<T,A>::value_type const& value)
	{
		pointer posptr = position.base();
		size_type n = posptr - start;
		if (finish != end_of_storage && posptr == finish)
		{
			construct(finish, value);
			++finish;
		}
		else
			_insert_aux(posptr, value);

		return iterator(start + n);	
	}

  template< typename T, typename A >
	void vector<T,A>::insert(typename vector<T,A>::iterator position,
							 typename vector<T,A>::size_type n,
							 typename vector<T,A>::value_type const& value)
	{
		if (n != 0)
			_insert_fill(position.base(), n, value);
	}

  template< typename T, typename A >
   template< typename InputIterator >
	void vector<T,A>::insert(typename vector<T,A>::iterator position,
							 InputIterator first, InputIterator last)
	{
		_insert_dispatch(position, first, last, is_integral<InputIterator>());
	}

	/*
	Erase elements
	Removes from the vector either a single element (position) or a range of
	elements ([first,last)). This effectively reduces the container size by
	the number of elements removed, which are destroyed.
	*/

  template< typename T, typename A >
	typename vector<T,A>::iterator
	vector<T,A>::erase(typename vector<T,A>::iterator position)
	{
		pointer posptr = position.base();
		if (posptr + 1 != finish)
			ft::copy(posptr + 1, finish, posptr);
		--finish;
		destroy(finish);
		return position;
	}

  template< typename T, typename A >
	typename vector<T,A>::iterator
	vector<T,A>::erase(typename vector<T,A>::iterator first,
					   typename vector<T,A>::iterator last)
	{
		pointer fptr = first.base();
		pointer lptr = last.base();
		pointer ptr = ft::copy(lptr, finish, fptr);
		_destroy(ptr, finish);
		finish -= (lptr - fptr);
		return first;
	}

	/*
	Exchanges the content of the container by the content of x,
	which is another vector object of the same type. Sizes may differ.
	*/

  template< typename T, typename A >
	void vector<T,A>::swap(vector<T,A>& other)
	{
		ft::swap(start, other.start);
		ft::swap(finish, other.finish);
		ft::swap(end_of_storage, other.end_of_storage);
	}

	/*
	Removes all elements from the vector (which are destroyed),
	leaving the container with a size of 0.
	*/

  template<typename T, typename A>
	void vector<T,A>::clear(void)
	{
		_destroy(start, finish);
		finish = start;
	}

// UTILITY: 

  template< typename T, typename A >
	typename vector<T, A>::pointer
	vector<T, A>::_uninitialized_fill_n(
								typename vector<T, A>::pointer ptr,
								typename vector<T, A>::size_type n,
								typename vector<T, A>::value_type const& value)
	{
		pointer tmp = ptr;
		while (n > 0)
		{
			try
			{
				construct(ptr, value);
				++ptr;
				--n;
			}
			catch (...)
			{
				_destroy(tmp, ptr);
				throw;
			}
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
		//pointer tmp = ptr;
		while (first != last)
		{
			try
			{
				construct(ptr, *first);
				++ptr;
				++first;
			}
			catch (...)
			{
				//_destroy(tmp, ptr);
				throw;
			}
		}
		return ptr;
	}

  template< typename T, typename A >
   template< typename InputIterator >
	typename vector<T,A>::pointer
	vector<T,A>::_allocate_and_copy(typename vector<T,A>::size_type n,
									InputIterator first,
									InputIterator last)
	{
		pointer ptr = allocate(n);
		try
		{
			_uninitialized_copy(first, last, ptr);
		}
		catch (...)
		{
			deallocate(ptr, n);
			throw;
		}
		return ptr;
	}

  template< typename T, typename A >
   template< typename Integer >
	void vector<T,A>::_initialize_aux(Integer n, Integer value, ft::true_type)
	{
		start = allocate(n);
		end_of_storage = start + n;
		finish = _uninitialized_fill_n(start,
									   static_cast<size_type>(n),
									   static_cast<value_type>(value));
	}

  template< typename T, typename A >
   template< typename InputIterator >
	void vector<T, A>::_initialize_aux(InputIterator first,
									   InputIterator last,
									   ft::false_type)
	{
		_range_initialize(first, last,
				typename iterator_traits<InputIterator>::iterator_category());
	}

  template< typename T, typename A >
   template< typename InputIterator >
	void vector<T, A>::_range_initialize(InputIterator first,
										 InputIterator last,
							   			 std::input_iterator_tag)
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
										 std::forward_iterator_tag)
	{
		size_type n = ft::distance(first, last);
		start = allocate(n);
		end_of_storage = start + n;
		finish = _uninitialized_copy(first, last, start);
	}

  template< typename T, typename A >
	void vector<T,A>::_fill_assign(typename vector<T,A>::size_type n,
								typename vector<T,A>::value_type const& value)
	{
		if (n > capacity())
		{
			vector<T,A> tmp(n, value, get_allocator());
			tmp.swap(*this);
		}
		else if (n > size())
		{
			ft::fill(start, finish, value);
			finish = _uninitialized_fill_n(finish, n - size(), value);
		}
		else
		{
			iterator ptr = ft::fill_n(begin(), n, value);
			erase(ptr, end());
		}
	}
  
  template< typename T, typename A >
   template< typename Integral >
	void vector<T,A>::_assign_dispatch(Integral n, Integral value,
												   ft::true_type)
	{
		_fill_assign(static_cast<size_type>(n),
					 static_cast<value_type>(value));
	}

  template< typename T, typename A >
   template< typename InputIterator>
	void vector<T,A>::_assign_dispatch(InputIterator first,
									   InputIterator last, ft::false_type)
	{
		_assign_aux(first, last,
				typename iterator_traits<InputIterator>::iterator_category());
	}

  template< typename T, typename A >
   template< typename InputIterator>
	void vector<T,A>::_assign_aux(InputIterator first,
								  InputIterator last,
								  std::input_iterator_tag)
	{
		iterator cur = begin();
		for (; first != last && cur != end(); ++first, ++cur)
			*cur = *first;
		if (first == last)
			erase(cur, end());
		else
			insert(end(), first, last);
	}

  template< typename T, typename A >
   template< typename ForwardIterator>
	void vector<T,A>::_assign_aux(ForwardIterator first,
								  ForwardIterator last,
								  std::forward_iterator_tag)
	{
		size_type len = ft::distance(first, last);
		if (len > capacity())
		{
			pointer tmp = _allocate_and_copy(len, first, last);
			_destroy(start, finish);
			deallocate(start, end_of_storage - start);
			start = tmp;
			finish = end_of_storage = start + len;			
		}
		else if (size() >= len)
		{
			pointer new_finish = ft::copy(first, last, start);
			_destroy(new_finish, finish);
			finish = new_finish;
		}
		else
		{
			ForwardIterator midle(first);
			ft::advance(midle, size());
			ft::copy(first, midle, start);
			finish = _uninitialized_copy(midle, last, finish);
		}
	}

  template< typename T, typename A >
	void vector<T,A>::_insert_aux(typename vector<T, A>::pointer position,
								  typename vector<T,A>::value_type const& val)
	{
		if (finish != end_of_storage)
		{
			value_type val_copy = val;
			construct(finish, *(finish - 1));
			++finish;
			ft::copy_backward(position, finish - 2, finish - 1);
			*position = val_copy;
		}
		else
		{
			const size_type old_size = size();
			const size_type len = old_size == 0 ? 1 : 2 * old_size;
			pointer new_start = allocate(len);
			pointer new_finish = new_start;
			pointer except_ptr = new_start;
			try
			{
				new_finish = _uninitialized_copy(start, position, new_start);
				except_ptr = new_finish;
				*new_finish = val;
				++new_finish;
				++except_ptr;
				new_finish = _uninitialized_copy(position, finish, new_finish);
			}
			catch (...)
			{
				_destroy(new_start, except_ptr);
				deallocate(new_start, len);
				throw;
			}
			_destroy(start, finish);
			deallocate(start, end_of_storage - start);
			start = new_start;
			finish = new_finish;
			end_of_storage = start + len;
		}
	}

template< typename T, typename A >
	void vector<T,A>::_insert_fill(typename vector<T,A>::pointer position,
								   typename vector<T,A>::size_type n,
								   typename vector<T,A>::value_type const& val)
	{
		if (static_cast<size_type>(end_of_storage - finish) >= n)
		{
			value_type val_copy = val;
			pointer old_finish = finish;
			size_type elements_after_pos = finish - position;
			if (elements_after_pos > n)
			{
				finish = _uninitialized_copy(finish - n, finish, finish);
				ft::copy_backward(position, old_finish - n , old_finish);
				ft::fill(position, position + n, val_copy);
			}
			else
			{
				finish = _uninitialized_fill_n(finish, n - elements_after_pos,
																	val_copy);
				finish = _uninitialized_copy(position, old_finish, finish);
				ft::fill(position, old_finish, val_copy);
			}
		}
		else
		{
			size_type old_size = size();
			//size_type len = old_size + (old_size < n ? n : old_size);
			size_type len = (2 * capacity() < n + old_size ? n + old_size : 2 * capacity());
			pointer new_start = allocate(len);
			pointer new_finish = new_start;
			pointer except_ptr = new_start;
			try
			{
				new_finish = _uninitialized_copy(start, position, new_finish);
				except_ptr = new_finish;
				new_finish = _uninitialized_fill_n(new_finish, n, val);
				except_ptr = new_finish;
				new_finish = _uninitialized_copy(position, finish, new_finish);
			}
			catch (...)
			{
				_destroy(new_start, except_ptr);
				deallocate(new_start, len);
				throw;
			}
			_destroy(start, finish);
			deallocate(start, end_of_storage - start);
			start = new_start;
			finish = new_finish;
			end_of_storage = start + len;
		}
	}

  template< typename T, typename A >
   template< typename Integral >
	void vector<T,A>::_insert_dispatch(typename vector<T,A>::iterator position,
							 		   Integral n,
									   Integral value,
									   ft::true_type)
	{
		if (n != 0)
			_insert_fill(position.base(),
						 static_cast<size_type>(n),
						 static_cast<value_type>(value));
	}

  template< typename T, typename A >
   template< typename InputIterator >
	void vector<T,A>::_insert_dispatch(typename vector<T,A>::iterator position,
									   InputIterator first, InputIterator last,
									   ft::false_type)
	{
		_range_insert(position, first, last,
				typename iterator_traits<InputIterator>::iterator_category());
	}

  template< typename T, typename A >
   template< typename InputIterator >
  	void vector<T,A>::_range_insert(typename vector<T,A>::iterator position,
									InputIterator first, InputIterator last,
									std::input_iterator_tag)
	{
		if (position == end())
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		else if (first != last)
		{
			vector<T,A> tmp(first, last, allocator_type());
			insert(position, tmp.begin(), tmp.end());
		}
	}

  template< typename T, typename A >
   template< typename ForwardIterator >
  	void vector<T,A>::_range_insert(typename vector<T,A>::iterator position,
									ForwardIterator first,
									ForwardIterator last,
									std::forward_iterator_tag)
	{
		if (first == last)
			return;
		size_type n = ft::distance(first, last);
		pointer posptr = position.base();
		if (static_cast<size_type>(end_of_storage - finish) >= n)
		{
			const size_type elems_after = finish - posptr;
			pointer old_finish = finish;
			if (elems_after > n)
			{
				finish = _uninitialized_copy(finish - n, finish, finish);
				ft::copy_backward(posptr, old_finish - n, old_finish);
				ft::copy(first, last, position);
			}
			else
			{
				ForwardIterator midle = first;
				ft::advance(midle, elems_after);
				finish = _uninitialized_copy(midle, last, finish);
				finish = _uninitialized_copy(posptr, old_finish, finish);
				ft::copy(first, midle, position);
			}
		}
		else
		{
			const size_type old_size = size();
			const size_type len = old_size + (old_size > n ? old_size : n);
			pointer new_start = allocate(len);
			pointer new_finish = new_start;
			pointer except_ptr = new_start;
			try
			{
				new_finish = _uninitialized_copy(start, posptr, new_start);
				except_ptr = new_finish;
				new_finish = _uninitialized_copy(first, last, new_finish);
				except_ptr = new_finish;
				new_finish = _uninitialized_copy(posptr, finish, new_finish);
			}
			catch (...)
			{
				_destroy(new_start, except_ptr);
				deallocate(new_start, len);
				throw;
			}
			_destroy(start, finish);
			deallocate(start, end_of_storage - start);
			start = new_start;
			finish = new_finish;
			end_of_storage = start + len;
		}
	}

  template< typename T, typename A >
	void vector<T,A>::_destroy(typename vector<T,A>::pointer first,
							   typename vector<T,A>::pointer last)
	{
		while (first != last)
		{
			destroy(first);
			++first;
		}
	}

/*
Performs the appropriate comparison operation between the vector containers
lhs and rhs.
The equality comparison (operator==) is performed by first comparing sizes, and
if they match, the elements are compared sequentially using operator==,
stopping at the first mismatch (as if using algorithm equal).

The less-than comparison (operator<) behaves as if using algorithm
lexicographical_compare, which compares the elements sequentially using
operator< in a reciprocal manner (i.e., checking both a<b and b<a) and stopping
at the first occurrence.
*/

  template< typename T, typename Allocator > inline
	bool operator==(vector<T, Allocator> const& lhs,
					vector<T, Allocator> const& rhs)
	{
		return lhs.size() == rhs.size() &&
			   ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

  template< typename T, typename Allocator > inline
	bool operator!=(vector<T, Allocator> const& lhs,
					vector<T, Allocator> const& rhs)
	{
		return !(lhs == rhs);
	}

  template< typename T, typename Allocator > inline
	bool operator<(vector<T, Allocator> const& lhs,
				   vector<T, Allocator> const& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),
										   rhs.begin(), rhs.end());
	}

  template< typename T, typename Allocator > inline
	bool operator>(vector<T, Allocator> const& lhs,
				   vector<T, Allocator> const& rhs)
	{
		return rhs < lhs;
	}

  template< typename T, typename Allocator > inline
	bool operator<=(vector<T, Allocator> const& lhs,
					vector<T, Allocator> const& rhs)
	{
		return !(rhs < lhs);
	}

  template< typename T, typename Allocator > inline
	bool operator>=(vector<T, Allocator> const& lhs,
					vector<T, Allocator> const& rhs)
	{
		return !(lhs < rhs);
	}

	/*
	Swap reloading
	*/
  template< typename T, typename Allocator > inline
	void swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
	{
		x.swap(y);
	}

}

/*
STD::SWAP specialization
*/

namespace std
{
  template< typename T, typename Allocator > inline
	void swap(ft::vector<T, Allocator>& x, ft::vector<T, Allocator>& y)
	{
		x.swap(y);
	}
}

#endif
