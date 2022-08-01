/******************************************************************************/

#ifndef FT_RB_TREE_HPP
#define FT_RB_TREE_HPP

#include "utils.hpp"

namespace ft
{

	// COLOR TYPE
	typedef bool				Rb_tree_color_type;
	const Rb_tree_color_type	rb_tree_red = false;
	const Rb_tree_color_type	rb_tree_black = true;

	// RB_TREE_NODE_BASE
	struct Rb_tree_node_base
	{
		typedef Rb_tree_node_base*			Base_ptr;
		typedef const Rb_tree_node_base*	Const_Base_ptr;

		Rb_tree_color_type	color;
		Base_ptr			parent;
		Base_ptr			left;
		Base_ptr			right;

		static Base_ptr	minimum(Base_ptr x)
		{
			while (x->left != 0)
				x = x->left;
			return x;
		}

		static Const_Base_ptr	minimum(Const_Base_ptr x)
		{
			while (x->left != 0)
				x = x->left;
			return x;
		}

		static Base_ptr maximum(Base_ptr x)
		{
			while (x->right != 0)
				x = x->right;
			return x;
		}

		static Const_Base_ptr maximum(Const_Base_ptr x)
		{
			while (x->right != 0)
				x = x->right;
			return x;
		}
	};

	// RB_TREE_NODE
  template< typename Value >
	struct Rb_tree_node : public Rb_tree_node_base
	{
		typedef Rb_tree_node<Value>*	Link_type;
		Value	value_field;
	};

	//RB_TREE_BASE_ITERATOR

	struct Rb_tree_base_iterator 
	{
	protected:
		typedef Rb_tree_node_base::Base_ptr				Base_ptr;
		typedef Rb_tree_node_base::Const_Base_ptr		Const_Base_ptr;

		Base_ptr	node;
	public:
		Rb_tree_base_iterator(void) : node(0) {}
		Rb_tree_base_iterator(Base_ptr node) : node(node) {}
		void increment(void);
		void decrement(void);
	};

	void Rb_tree_base_iterator::increment(void)
	{
		if (node->right)
		{
			node = node->right;
			while (node->left)
				node = node->left;
		}
		else
		{
			Base_ptr tmp = node->parent;
			while (node == tmp->right)
			{
				node = tmp;
				tmp = tmp->parent;
			}
			if (node->right != tmp)
				node = tmp;
		}
	}

	void Rb_tree_base_iterator::decrement(void)
	{
		if (node->color == rb_tree_red && node->parent->parent == node)
			node = node->right;
		else if (node->left)
		{
			Base_ptr tmp = node->left;
			while (tmp->right)
				tmp = tmp->right;
			node = tmp;
		}
		else
		{
			Base_ptr tmp = node->parent;
			while (node == tmp->left)
			{
				node = tmp;
				tmp = tmp->parent;
			}
			node = tmp;
		}
	}

	//RB_TREE_ITERATOR

  template< typename Value >
	struct Rb_tree_iterator : public Rb_tree_base_iterator
	{
		typedef Value							value_type;
		typedef value_type&						reference;
		typedef value_type*						pointer;
		typedef ptrdiff_t						difference_type;
		typedef std::bidirectional_iterator_tag	iterator_category;

		typedef Rb_tree_node<Value>*			Link_type;
		typedef Rb_tree_base_iterator::Base_ptr	Base_ptr;
		typedef Rb_tree_iterator<Value>			Self;

		Rb_tree_iterator(void) {}
		explicit Rb_tree_iterator(Base_ptr node)
			: Rb_tree_base_iterator(node) {}
		explicit Rb_tree_iterator(Link_type node)
			: Rb_tree_base_iterator(static_cast<Base_ptr>(node)) {}
		Rb_tree_iterator(const Rb_tree_iterator& it)
			: Rb_tree_base_iterator(it.node) {}

		reference	operator*(void) const
		{ return (static_cast<Link_type>(node))->value_field; }

		pointer		operator->(void) const
		{ return &(static_cast<Link_type>(node))->value_field; }

		Self&		operator++(void)
		{
			Rb_tree_base_iterator::increment();
			return *this;
		}

		Self		operator++(int)
		{
			Self tmp = *this;
			Rb_tree_base_iterator::increment();
			return tmp;
		}

		Self&		operator--(void)
		{
			Rb_tree_base_iterator::decrement();
			return *this;
		}

		Self		operator--(int)
		{
			Self tmp = *this;
			Rb_tree_base_iterator::decrement();
			return tmp;
		}

		friend bool operator==(const Self& lhs, const Self& rhs)
		{ return lhs.node == rhs.node; }

		friend bool operator!=(const Self& lhs, const Self& rhs)
		{ return lhs.node != rhs.node; }
		
	};

	// RB_TREE_CONST_ITERATOR

  template< typename Value >
	struct Rb_tree_const_iterator : public Rb_tree_base_iterator
	{
		typedef Value									value_type;
		typedef const value_type&						reference;
		typedef const value_type*						pointer;
		typedef ptrdiff_t								difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;

		typedef Rb_tree_node<Value>*					Link_type;
		typedef Rb_tree_base_iterator::Base_ptr			Base_ptr;
		typedef Rb_tree_const_iterator<Value>			Self;

		Rb_tree_const_iterator(void) {}
		explicit Rb_tree_const_iterator(Base_ptr node)
			: Rb_tree_base_iterator(node) {}
		explicit Rb_tree_const_iterator(Link_type node)
			: Rb_tree_base_iterator(static_cast<Base_ptr>(node)) {}
		Rb_tree_const_iterator(const Rb_tree_const_iterator& it)
			: Rb_tree_base_iterator(it.node) {}

		reference	operator*(void) const
		{ return (static_cast<Link_type>(node))->value_field; }

		pointer		operator->(void) const
		{ return &(static_cast<Link_type>(node))->value_field; }

		Self&		operator++(void)
		{
			Rb_tree_base_iterator::increment();
			return *this;
		}

		Self		operator++(int)
		{
			Self tmp = *this;
			Rb_tree_base_iterator::increment();
			return tmp;
		}

		Self&		operator--(void)
		{
			Rb_tree_base_iterator::decrement();
			return *this;
		}

		Self		operator--(int)
		{
			Self tmp = *this;
			Rb_tree_base_iterator::decrement();
			return tmp;
		}

		friend bool operator==(const Self& lhs, const Self& rhs)
		{ return lhs.node == rhs.node; }

		friend bool operator!=(const Self& lhs, const Self& rhs)
		{ return lhs.node != rhs.node; }
		
	};

	// ROTATE_LEFT

	inline void Rb_tree_rotate_left(Rb_tree_node_base* x,
									Rb_tree_node_base*& root)
	{
		Rb_tree_node_base* y = x->right;
		x->right = y->left;
		if (y->left)
			y->left->parent = x;
		y->parent = x->parent;
		if (x == root)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	// ROTATE_RIGHT

	inline void Rb_tree_rotate_right(Rb_tree_node_base* x,
									 Rb_tree_node_base*& root)
	{
		Rb_tree_node_base* y = x->left;
		x->left = y->right;
		if (y->right)
			y->right->parent = x;
		y->parent = x->parent;
		if (root == x)
			root = y;
		else if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->right = x;
		x->parent = y;
	}

	// REBALANCE

	inline void Rb_tree_rebalance(Rb_tree_node_base* x,
								  Rb_tree_node_base*& root)
	{
		x->color = rb_tree_red;
		while (x != root && x->parent->color == rb_tree_red)
		{
			if (x->parent == x->parent->parent->left)
			{
				Rb_tree_node_base* y = x->parent->parent->right;
				if (y && y->color == rb_tree_red)
				{
					x->parent->color = rb_tree_black;
					y->color = rb_tree_black;
					x->parent->parent->color = rb_tree_red;
					x = x->parent->parent;
				}
				else
				{
					if (x == x->parent->right)
					{
						x = x->parent;
						Rb_tree_rotate_left(x, root);
					}
					x->parent->color = rb_tree_black;
					x->parent->parent->color = rb_tree_red;
					Rb_tree_rotate_right(x->parent->parent, root);
				}
			}
			else
			{
				Rb_tree_node_base* y = x->parent->parent->left;
				if (y && y->color == rb_tree_red)
				{
					x->parent->color = rb_tree_black;
					y->color = rb_tree_black;
					x->parent->parent->color = rb_tree_red;
					x = x->parent->parent;
				}
				else
				{
					if (x == x->parent->left)
					{
						x = x->parent;
						Rb_tree_rotate_right(x, root);
					}
					x->parent->color = rb_tree_black;
					x->parent->parent->color = rb_tree_red;
					Rb_tree_rotate_left(x->parent->parent, root);
				}
			}
		}
		root->color = rb_tree_black;
	}

	// REBALANCE_FOR_ERASE

	inline Rb_tree_node_base*
	Rb_tree_rebalance_for_erase(Rb_tree_node_base* z,
								Rb_tree_node_base*& root,
								Rb_tree_node_base*& leftmost,
								Rb_tree_node_base*& rightmost)
	{
		Rb_tree_node_base* y = z;
		Rb_tree_node_base* x = 0;
		Rb_tree_node_base* x_parent = 0;
		if (y->left == 0)
			x = y->right;
		else
		{
			if (y->right == 0)
				x = y->left;
			else
			{
				y = y->right;
				while (y->left)
					y = y->left;
				x = y->right;
			}
		}
		if (y != z)
		{
			z->left->parent = y;
			y->left = z->left;
			if (y != z->right)
			{
				x_parent = y->parent;
				if (x)
					x->parent = y->parent;
				y->parent->left = x;
				y->right = z->right;
				z->right->parent = y;
			}
			else
			{
				x_parent = y;
				if (root == z)
					root = y;
				else if (z->parent->left == z)
				{
					z->parent->left = y;
				}
				else
					z->parent->left = y;
				y->parent = z->parent;
				ft::swap(y->color, z->color);
				y = z;
			}
		}
		else
		{
			x_parent = y->parent;
			if (x)
				x->parent = y->parent;
			if (root == z)
				root = x;
			else
			{
				if (z->parent->left == z)
					z->parent->left = x;
				else
					z->parent->right = x;
			}	
			if (leftmost == z)
			{
				if (z->right == 0)
					leftmost = z->parent;
				else
					leftmost = Rb_tree_node_base::minimum(x);
			}
			if (rightmost == z)
			{
				if (z->left == 0)
					rightmost = z->parent;
				else
					rightmost = Rb_tree_node_base::maximum(x);
			}
		}
		if (y->color != rb_tree_red)
		{
			while (x != root && (x == 0 || x->color == rb_tree_black))
			{
				if (x == x_parent->left)
				{
					Rb_tree_node_base* w = x_parent->right;
					if (w->color == rb_tree_red)
					{
						w->color = rb_tree_black;
						x_parent->color = rb_tree_red;
						Rb_tree_rotate_left(x_parent, root);
						w = x_parent->right;
					}
					if ((w->left == 0 || w->left->color == rb_tree_black) &&
						(w->right == 0 || w->right->color == rb_tree_black))
					{
						w->color = rb_tree_red;
						x = x_parent;
						x_parent = x_parent->parent;
					}
					else
					{
						if (w->right == 0 || w->right->color == rb_tree_black)
						{
							if (w->left)
								w->left->color = rb_tree_black;
							w->color = rb_tree_red;
							Rb_tree_rotate_right(w, root);
							w = x_parent->right;
						}
						w->color = x_parent->color;
						x_parent->color = rb_tree_black;
						if (w->right)
							w->right->color = rb_tree_black;
						Rb_tree_rotate_left(x_parent, root);
						break;
					}
				}
				else
				{
					Rb_tree_node_base* w = x_parent->left;
					if (w->color == rb_tree_red)
					{
						w->color = rb_tree_black;
						x_parent->color = rb_tree_red;
						Rb_tree_rotate_right(x_parent, root);
						w = x_parent->left;
					}
					if ((w->right == 0 || w->right->color == rb_tree_black) &&
						(w->left == 0 || w->left->color == rb_tree_black))
					{
						w->color = rb_tree_red;
						x = x_parent;
						x_parent = x_parent->parent;
					}
					else
					{
						if (w->left == 0 || w->left->color == rb_tree_black)
						{
							if (w->right)
								w->right->color = rb_tree_black;
							w->color = rb_tree_red;
							Rb_tree_rotate_left(w, root);
							w = x_parent->left;
						}
						w->color = x_parent->color;
						x_parent->color = rb_tree_black;
						if (w->left)
							w->left->color = rb_tree_black;
						Rb_tree_rotate_right(x_parent, root);
						break;
					}
				}
			}
			if (x)
				x->color = rb_tree_black;
		}
		return y;
	}

	// RB_TREE_BASE

  template< typename T, typename Allocator >
	struct Rb_tree_base
	{
		typedef Allocator								value_allocator_type;
		typedef typename Allocator::template rebind<Rb_tree_node<T> >::other
														node_allocator_type;
		typedef typename node_allocator_type::size_type	size_type;

		node_allocator_type get_node_allocator() const
		{ return node_allocator_type(); }

		value_allocator_type get_value_allocator() const
		{ return value_allocator_type(); }

		size_type max_size(void) const
		{ return node_allocator.max_size(); }

		Rb_tree_base(void)
			: node_allocator(node_allocator_type()),
			  value_allocator(value_allocator_type()),
			  header(0)
		{
			header = get_node();
		}
			
		Rb_tree_base(const value_allocator_type& a)
			: node_allocator(node_allocator_type()),
			  value_allocator(a),
			  header(0)
		{
			header = get_node();
		}

		~Rb_tree_base(void)
		{
			put_node(header);
		}

	protected:
		node_allocator_type		node_allocator;
		value_allocator_type	value_allocator;
		Rb_tree_node<T>*		header;

		Rb_tree_node<T>* get_node(void)
		{
			return node_allocator.allocate(1);
		}

		void put_node(Rb_tree_node<T>* p)
		{
			node_allocator.deallocate(p, 1);
		}

		void construct_value(T *ptr, const T& val)
		{
			value_allocator.construct(ptr, val);
		}

		void destroy_value(T *ptr)
		{
			value_allocator.destroy(ptr);
		}
	};

	/*
	RB_TREE
	*/

  template< class Key, class Value, class KeyOfValue, class Compare,
			class Allocator = std::allocator<Value> >
	class Rb_tree : protected Rb_tree_base<Value, Allocator>
	{
		typedef Rb_tree_base<Value, Allocator> Base;
	protected:
		typedef Rb_tree_node_base*	Base_ptr;
		//typedef Rb_tree_node<Value>	Rb_tree_node;
		typedef Rb_tree_color_type	Color_type;
	public:
		typedef Key										key_type;
		typedef Value									value_type;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef size_t									size_type;
		typedef ptrdiff_t								difference_type;
		typedef Allocator								allocator_type;
		typedef Rb_tree_node<Value>*					Link_type;
		typedef Rb_tree_iterator<value_type>			iterator;
		typedef Rb_tree_const_iterator<value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		allocator_type get_allocator(void) const
		{ return Base::get_value_allocator(); }
	protected:
		using Base::get_node;
		using Base::put_node;
		using Base::construct_value;
		using Base::destroy_value;
		using Base::header;

		size_type	node_count;
		Compare		key_compare;

		// UTILS
	protected:
		Link_type create_node(const value_type& val);

		Link_type clone_node(Link_type node);
		
		void destroy_node(Link_type node);
		
		Link_type& root(void) const
		{ return reinterpret_cast<Link_type&>(header->parent); }

		Link_type& leftmost(void) const
		{ return reinterpret_cast<Link_type&>(header->left); }

		Link_type& rightmost(void) const
		{ return reinterpret_cast<Link_type&>(header->right); }

		static Link_type& left(Link_type x)
		{ return reinterpret_cast<Link_type&>(x->left); }

		static Link_type& right(Link_type x)
		{ return reinterpret_cast<Link_type&>(x->right); }

		static Link_type& parent(Link_type x)
		{ return static_cast<Link_type&>(x->parent); }

		static reference value(Link_type x)
		{ return x->value_field; }

		static const Key& key(Link_type x)
		{ return KeyOfValue()(value(x)); }

		static Color_type& color(Link_type x)
		{ return (Color_type&)(x->color); }
		
		static Link_type& left(Base_ptr x)
		{ return static_cast<Link_type&>(x->left); }

		static Link_type& right(Base_ptr x)
		{ return static_cast<Link_type&>(x->right); }

		static Link_type& parent(Base_ptr x)
		{ return static_cast<Link_type&>(x->parent); }

		static reference value(Base_ptr x)
		{ return (static_cast<Link_type>(x))->value_field; }

		static const Key& key(Base_ptr x)
		{ return KeyOfValue()(value(x)); }

		static Color_type& color(Base_ptr x)
		{ return (Color_type&)(x->color); }

		static Link_type minimum(Link_type x)
		{ return static_cast<Link_type>(Rb_tree_node_base::minimum(x)); }

		static Link_type maximum(Link_type x)
		{ return static_cast<Link_type>(Rb_tree_node_base::maximum(x)); }

		//COPY/ASSIGN/DESTROY:
	public:
		Rb_tree(void)
			: Base(allocator_type()), node_count(0), key_compare(Compare())
		{ _empty_initialize(); }

		Rb_tree(const Compare& comp)
			: Base(allocator_type()), node_count(0), key_compare(comp)
		{ _empty_initialize(); }

		Rb_tree(const Compare& comp, const allocator_type& a)
			: Base(a), node_count(0), key_compare(comp)
		{ _empty_initialize(); }

		Rb_tree(const Rb_tree& x);

		~Rb_tree(void) { clear(); }

		Rb_tree& operator=(const Rb_tree& x);

		// ACCESSORS:
	public:
		Compare key_comp() const { return key_compare; }

		iterator begin() { return iterator(leftmost()); }

		const_iterator begin() const { return const_iterator(leftmost()); }

		iterator end() { return iterator(header); }

		const_iterator end() const { return const_iterator(header); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
	
		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(end()); }

		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rend() const
		{ return const_reverse_iterator(begin()); }

		bool empty() const { return node_count == 0; } 

		size_type size() const { return node_count; }

		size_type max_size() const { return Base::max_size(); }

		void swap(Rb_tree& other)
		{	
			ft::swap(header, other.header);
			ft::swap(node_count, other.node_count);
			ft::swap(key_compare, other.key_compare);
		}

		// INSERT/ERASE
	public:
		ft::pair<iterator, bool> insert_unique(const value_type& x);
		iterator insert_unique(iterator position, const value_type& x);
		template< typename InputIterator >
		void insert_unique(InputIterator first, InputIterator last);

		void clear(void); 

	private:
		void 		_empty_initialize(void);
		Link_type	_copy(Link_type x, Link_type p);
		void		_erase(Link_type x);
		iterator	_insert(Base_ptr _x, Base_ptr _y, const value_type& v);

	};

	//COPY/ASSIGN

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Link_type
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::_copy
	(typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Link_type x,
	 typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Link_type p)
	{
		Link_type top = clone_node(x);
		top->parent = p;
		try
		{
			if (x->right)
				top->right = _copy(right(x), top);
			p = top;
			x = left(x);
			while (x)
			{
				Link_type y = clone_node(x);
				p->left = y;
				y->parent = p;
				if (x->right)
					y->right = _copy(right(x), y);
				p = y;
				x = left(x);
			}
		}
		catch (...)
		{
			_erase(top);
			throw;
		}
		return top;
	}

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Rb_tree
	(const Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>& copy)
		: Base(copy.get_allocator()),
		  node_count(0),
		  key_compare(copy.key_compare)
	{
		if (copy.root() == 0)
			_empty_initialize();
		else
		{
			color(header) = rb_tree_red;
			root() = _copy(copy.root(), header);
			leftmost() = minimum(root());
			rightmost() = maximum(root());
		}
		node_count = copy.node_count;
	}

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>&
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::operator=
	(const Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>& other)
	{
		if (this != &other)
		{
			clear();
			node_count = 0;
			key_compare = other.key_compare;
			if (other.root() == 0)
			{
				root() = 0;
				leftmost() = header;
				rightmost() = header;
			}
			else
			{
				root() = _copy(other.root(), header);
				leftmost() = minimium(root());
				rightmost() = maximun(root());
				node_count = other.node_count;
			}
		}
		return *this;
	}

	// INSERT

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::_insert
 (typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Base_ptr _x,
 typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Base_ptr _y,
 const typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::value_type& v)
	{
		Link_type x = static_cast<Link_type>(_x);
		Link_type y = static_cast<Link_type>(_y);
		Link_type z;

		if (y == header || x != 0 || key_compare(KeyOfValue()(v), key(y)))
		{
			z = create_node(v);
			left(y) = z;
			if (y == header)
			{
				root() = z;
				rightmost() = z;
			}
			else if (y == leftmost())
				leftmost() = z;
		}
		else
		{
			z = create_node(v);
			right(y) = z;
			if (y == rightmost())
				rightmost() = z;
		}
		parent(z) = y;
		left(z) = 0;
		right(z) = 0;
		Rb_tree_rebalance(z, header->parent);
		++node_count;
		return iterator(z);
	}

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	ft::pair<typename Rb_tree<Key, Value,
	KeyOfValue, Compare, Alloc>::iterator, bool>
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>
		::insert_unique(const Value& v)
	{
		Link_type y = header;
		Link_type x = root();
		bool comp = true;
		while (x)
		{
			y = x;
			comp = key_compare(KeyOfValue(v), key(x));
			x = comp ? left(x) : right(x);
		}
		iterator j = iterator(y);
		if (comp)
		{
			if (j == begin())
				return ft::pair<iterator, bool>(_insert(x, y, v), true);
			else
				--j;
		}
		if (key_compare(key(j.node), KeyOfValue()(v)))
			return ft::pair<iterator, bool>(_insert(x, y, v), true);
		return ft::pair<iterator, bool>(j, false);
	}

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::insert_unique
	(Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::iterator position,
	 const Value& v)
	{
		if (position.node == header->left) // begin
		{
			if (size() > 0 && key_compare(KeyOfValue()(v), key(position.node)))
				return _insert(position.node, position.node, v);
			else
				return insert_unique(v).first;
		}
		else if (position.node == header) // end
		{
			if (key_compare(key(rightmost()), KeyOfValue()(v)))
				return _insert(0, rightmost(), v);
			else
				return insert_unique(v).first;
		}
		else
		{
			iterator before = position;
			--before;
			if (key_compare(key(before.node), KeyOfValue()(v)) &&
				key_compare(KeyOfValue()(v), key(position.node)))
			{
				if (right(before.node) == 0)
					return _insert(0, before.node, v);
				else
					return _insert(position.node, position.node, v);
			}
			else
				return insert_unique(v).first;
		}
	}

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
   template< typename InputIterator>
	void Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::insert_unique
	(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			insert_equal(*first);
			++first;
		}
	}


	// ERASE:
  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	void Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::_erase
	(typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Link_type x)
	{
		while (x)
		{
			_erase(right(x));
			Link_type tmp = left(x);
			destroy_node(x);
			x = tmp;
		}
	}

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	void Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::clear(void)
	{
		if (node_count != 0)
		{
			_erase(root());
			root() = 0;
			leftmost() = header;
			rightmost() = header;
			node_count = 0;
		}
	}

	// UTILS:

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Link_type
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::create_node
	(const typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>
												   ::value_type& val)
	{
		Link_type tmp = get_node();
		try
		{
			construct_value(&tmp->value_field, val);
		}
		catch (...)
		{
			put_node(tmp);
			throw;
		}
		return tmp;
	}
	
  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Link_type
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::clone_node
	(typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Link_type node)
	{
		Link_type tmp = create_node(node->value_field);
		tmp->color = node->color;
		tmp->left = 0;
		tmp->right = 0;
		return tmp;
	}

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	void
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::destroy_node
	(typename Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::Link_type node)
	{
		destroy_value(&node->value_field);
		put_node(node);
	}

  template< typename Key, typename Value,
			typename KeyOfValue, typename Compare, typename Alloc >
	void
	Rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::_empty_initialize(void)
	{
		color(header) = rb_tree_red;
		root() = 0;
		leftmost() = header;
		rightmost() = header;
	}

}

#endif
