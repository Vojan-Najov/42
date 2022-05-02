//
// Created by Laureen Judy on 3/9/22.
//

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "vector.h"

namespace ft{
	template<class T, class Container = ft::vector<T> >
	class stack{
	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		explicit stack( const Container& cont = Container());
		stack( const stack& other);
		~stack();
		stack& operator=( const stack& other);
		reference top();//Returns reference to the top element in the stack. This is the most recently pushed element. This element will be removed on a call to pop(). Effectively calls c.back().
		const_reference top() const;
		bool empty() const;//Checks if the underlying container has no elements, i.e. whether c.empty().
		size_type size() const;//Returns the number of elements in the underlying container, that is, c.size().
		void push( const value_type& value);//Pushes the given element value to the top of the stack.
		void pop();//Removes the top element from the stack. Effectively calls c.pop_back()
		friend bool operator==(const stack & lhs, const stack & rhs)
		{ return lhs.c == rhs.c; }
		friend bool operator!=(const stack & lhs, const stack & rhs)
		{ return lhs.c != rhs.c; }
		friend bool operator<(const stack & lhs, const stack & rhs)
		{ return lhs.c < rhs.c; }
		friend bool operator<=(const stack & lhs, const stack & rhs)
		{ return lhs.c <= rhs.c; }
		friend bool operator>(const stack & lhs, const stack & rhs)
		{ return lhs.c > rhs.c; }
		friend bool operator>=(const stack & lhs, const stack & rhs)
		{ return lhs.c >= rhs.c; }
	protected:
		Container c;
	};

	template <class T, class Container>
	stack<T, Container>::stack( const Container& cont) : c(cont) {}

	template <class T, class Container>
	stack<T, Container>::stack( const stack& other) : c(other.c) {}

	template <class T, class Container>
	stack<T, Container>::~stack() {
	}

	template <class T, class Container>
	stack<T, Container>& stack<T, Container>::operator=( const stack& other){
		this->c = other.c;
		return *this;
	}

	template <class T, class Container>
	typename stack<T, Container>::reference stack<T, Container>::top(){
		return (c.back());
	}

	template <class T, class Container>
	typename stack<T, Container>::const_reference stack<T, Container>::top() const{
		return (c.back());
	}

	template <class T, class Container>
	bool stack<T, Container>::empty() const{
		return (c.empty());
	}

	template <class T, class Container>
	typename stack<T, Container>::size_type stack<T, Container>::size() const{
		return (c.size());
	}

	template <class T, class Container>
	void stack<T, Container>::push(const typename stack<T, Container>::value_type& value){
		c.push_back(value);
	}

	template <class T, class Container>
	void stack<T, Container>::pop(){
		c.pop_back();
	}

}
#endif //STACK_H
