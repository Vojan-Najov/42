#include <iostream>
#include <fstream>
#include <cassert>
#include <iterator>
#include <list>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include "utils.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"

#ifndef STL
#define STL 0
#endif

#if STL==0
using namespace ft;

void greet(void)
{
	std::cout << "Test FT\n";
}
#else
using namespace std;

void greet(void)
{
	std::cout << "Test STD\n";
}
#endif

void test_traits(void);
void test_advance_and_distance(void);
void test_reverse_iterator(void);
#if STL==0 || __cplusplus >= 201103L
void test_is_integral(void);
void test_is_same(void);
void test_enable_if(void);
#endif
void test_equal(void);
void test_lexicograhical_compare(void);
void test_pair(void);
//vector
void test_vector(void);
void test_vector_constructor(void);
void test_vector_operator_assign(void);
void test_vector_assign(void);
void test_vector_get_allocator(void);
void test_vector_get_iterators(void);
void test_vector_resize(void);
void test_vector_reserve(void);
void test_vector_at(void);
void test_vector_push_back(void);
void test_vector_pop_back(void);
void test_vector_insert(void);
void test_vector_insert2(void);
void test_vector_insert3(void);
void test_vector_insert4(void);
void test_vector_erase(void);
void test_vector_relops_swap(void);
void test_vector_swap(void);
void test_vector_iterator_comp(void);
//stack
void test_stack(void);
//map
void test_map_constructors(void);
void test_map_assign(void);
void test_map_iterator(void);
void test_map_capacity(void);
void test_map_access(void);
void test_map_insert_value(void);
void test_map_insert_position(void);
void test_map_insert_range(void);
void test_map_erase(void);
void test_map_erase_iter(void);
void test_map_erase_range(void);
void test_map_clear(void);
void test_map_swap(void);
void test_map_find(void);
void test_map_count(void);
void test_map_lower_bound(void);
void test_map_upper_bound(void);
void test_map_equal_range(void);
void test_map_compare(void);
void test_map_relops(void);
void test_swap(void);
//set
void test_set_constructors(void);
void test_set_assign(void);
void test_set_iterators(void);
void test_set_capacity(void);
void test_set_insert(void);
void test_set_insert_position(void);
void test_set_insert_range(void);
void test_set_erase_position(void);
void test_set_erase(void);
void test_set_erase_range(void);
void test_set_swap(void);
void test_set_clear(void);
void test_set_find(void);
void test_set_lower_bound(void);
void test_set_upper_bound(void);
void test_set_equal_range(void);

int main(void)
{
	greet();
	test_traits();
	test_advance_and_distance();
	test_reverse_iterator();
#if STL==0 || __cplusplus >= 201103L
	test_enable_if();
	test_is_same();
	test_is_integral();
#endif
	test_equal();
	test_lexicograhical_compare();
	test_pair();
// vector
	test_vector_constructor();
	test_vector_operator_assign();
	test_vector_assign();
	test_vector_get_allocator();
	test_vector_get_iterators();
	test_vector_resize();
	test_vector_reserve();
	test_vector_at();
	test_vector_push_back();
	test_vector_pop_back();
	test_vector_insert();
	test_vector_insert2();
	test_vector_insert3();
	test_vector_insert4();
	test_vector_erase();
	test_vector_relops_swap();
	test_vector_iterator_comp();
	test_vector_swap();
// stack
	test_stack();
// map
	test_map_constructors();
	test_map_iterator();
	test_map_capacity();
	test_map_access();
	test_map_insert_value();
	test_map_insert_position();
	test_map_insert_range();
	test_map_lower_bound();
	test_map_upper_bound();
	test_map_erase();
	test_map_erase_iter();
	test_map_erase_range();
	test_map_clear();
	test_map_swap();
	test_map_find();
	test_map_count();
	test_map_equal_range();
	test_map_compare();
	test_map_relops();
	test_map_assign();
// set
	test_set_constructors();
	test_set_assign();
	test_set_iterators();
	test_set_capacity();
	test_set_insert();
	test_set_insert_position();
	test_set_insert_range();
	test_set_erase_position();
	test_set_erase();
	test_set_erase_range();
	test_set_swap();
	test_set_clear();
	test_set_find();
	test_set_lower_bound();
	test_set_upper_bound();
	test_set_equal_range();

	std::cout << "SUCCESS\n";

	return 0;
}

void test_traits(void)
{
	random_access_iterator_tag *ran_tag = (random_access_iterator_tag *)0;
	bidirectional_iterator_tag *bid_tag = (random_access_iterator_tag *)0;
	forward_iterator_tag *fwd_tag =	(bidirectional_iterator_tag *)0;
	input_iterator_tag *in_tag = (forward_iterator_tag *)0;
	output_iterator_tag *p_out_tag = 0;
	(void) ran_tag;
	(void) bid_tag;
	(void) fwd_tag;
	(void) in_tag;
	(void) p_out_tag;


	typedef iterator< input_iterator_tag, float, short, float *, float& > Iter;
	float fl;
	Iter::iterator_category *it_tag = (input_iterator_tag *)0;
	Iter::value_type *it_val = (float *)0;
	Iter::difference_type *it_dist = (short *)0;
	Iter::pointer it_ptr = (float *)0;
	Iter::reference it_ref = fl;
	(void) fl;
	(void) it_tag;
	(void) it_val;
	(void) it_dist;
	(void) it_ptr;
	(void) it_ref;

	typedef iterator_traits<Iter> Traits;
	Traits::iterator_category *tr_tag = (input_iterator_tag *)0;
	Traits::value_type *tr_val = (float *)0;
	Traits::difference_type *tr_dist = (short *)0;
	Traits::pointer tr_ptr = (float *)0;
	Traits::reference tr_ref = fl;
	(void) tr_tag;
	(void) tr_val;
	(void) tr_dist;
	(void) tr_ptr;
	(void) tr_ref;

	typedef char* PtrIt;
	typedef iterator_traits<PtrIt> Ptraits;
	char ch;
	Ptraits::iterator_category *ptr_tag = (random_access_iterator_tag *) 0;
	Ptraits::value_type *ptr_val = (char *) 0;
	Ptraits::difference_type *ptr_dist = (ptrdiff_t *) 0;
	Ptraits::pointer ptr_ptr = (char *) 0;
	Ptraits::reference ptr_ref = ch;
	(void) ptr_tag;
	(void) ptr_val;
	(void) ptr_dist;
	(void) ptr_ptr;
	(void) ptr_ref;

	typedef const char* CPtrIt;
	typedef iterator_traits<CPtrIt> CPtraits;
	const char cch = 'a';
	CPtraits::iterator_category *cptr_tag = (random_access_iterator_tag *) 0;
	CPtraits::value_type *cptr_val = (char *) 0;
	CPtraits::difference_type *cptr_dist = (ptrdiff_t *) 0;
	CPtraits::pointer cptr_ptr = (const char *) 0;
	CPtraits::reference cptr_ref = cch;
	(void) cptr_tag;
	(void) cptr_val;
	(void) cptr_dist;
	(void) cptr_ptr;
	(void) cptr_ref;
}

struct InIt : public iterator< input_iterator_tag, int >
{
	InIt(int *a) : a(a) {}
	InIt &operator++(void) {
		++a;
		return *this;
	}
	InIt operator++(int) {
		InIt tmp = *this;
		++a;
		return tmp;
	}
	int	operator*(void) {
		return *a;
	}
	friend bool operator!=(const InIt &it1, const InIt &it2);
private:
	int *a;
};

struct BidIt: public iterator< bidirectional_iterator_tag, int>
{
	BidIt(int *a) : a(a) {}
	BidIt &operator++(void) {
		++a;
		return *this;
	}
	BidIt operator++(int) {
		BidIt tmp = *this;
		++a;
		return tmp;
	}
	int	operator*(void) {
		return *a;
	}
	BidIt &operator--(void) {
		--a;
		return *this;
	}
	BidIt operator--(int) {
		BidIt tmp = *this;
		--a;
		return tmp;
	}

	friend bool operator!=(const BidIt &it1, const BidIt &it2);
private:
	int *a;	
};

bool operator!=(const InIt &it1, const InIt &it2)
{
	return it1.a != it2.a;
}

bool operator!=(const BidIt &it1, const BidIt &it2)
{
	return it1.a != it2.a;
}

void test_advance_and_distance(void)
{
	const char *pc = "abcdefg";
	advance(pc, 4);
	assert(*pc == 'e');
	advance(pc, -1);
	assert(*pc == 'd');
	assert(distance(pc, pc + 3) == 3);

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	InIt in_it1(arr);
	InIt in_it2(arr);
	advance(in_it1, 4);
	assert(*in_it1 == 5);
	advance(in_it2, 5);
	assert(*in_it2 == 6);
	assert(distance(in_it1, in_it2) == 1);
	
	BidIt bid_it1(arr);
	BidIt bid_it2(arr);
	advance(bid_it1, 4);
	assert(*bid_it1 == 5);
	advance(bid_it1, -2);
	assert(*bid_it1 == 3);
	advance(bid_it2, 2);
	assert(*bid_it2 == 3);
	assert(distance(bid_it1, bid_it2) == 0);
	advance(bid_it1, 4);
	assert(distance(bid_it2, bid_it1) == 4);
}

	typedef char* PtrIt;
	typedef reverse_iterator<PtrIt> RevIt;
	class MyrevIt : public RevIt
	{
	public:
		MyrevIt(RevIt::iterator_type p) : RevIt(p) {}
		RevIt::iterator_type get_current() const
		{ return (current); }
	};

	struct cmplx
	{
		double r;
		double i;
		cmplx(void) : r(0), i(0) {}
		cmplx(double r, double i) : r(r), i(i) {}
		bool operator==(const cmplx &other) {return r == other.r && i == other.i;}
	};

void test_reverse_iterator(void)
{
	char a[] = "abc";
	(void) a;
	reverse_iterator<char *> tmp1;
	(void) tmp1;
	//reverse_iterator<char *> tmp2 = a;
	//(void) tmp2; // NO Compile -- Explicit constructor need
	reverse_iterator<char *> tmp3 = reverse_iterator<char *>(a);
	(void) tmp3;
	
	reverse_iterator<char *> tmp(a);
	(void) tmp;
	reverse_iterator< const char *> tmp4 = tmp;
	(void) tmp4;
	tmp3 = tmp;
	tmp4 = tmp;

	char *pc = (char *)"abcdefg" + 3;
	PtrIt pcit(pc);
	RevIt::iterator_type *p_iter = (PtrIt *)0;
	RevIt rit0, rit(pcit);
	(void) p_iter;
	(void) rit0;
	(void) rit;
	assert(rit.base() == pcit);
	assert(*rit == 'c');

	cmplx cmplxarr[3];
	cmplxarr[0] = cmplx(0,0);
	cmplxarr[1] = cmplx(1,1);
	cmplxarr[2] = cmplx(2,2);
	reverse_iterator<cmplx *> tmp5(cmplxarr + 3);
	assert(tmp5->r == 2);
	tmp5 = reverse_iterator<cmplx *>(cmplxarr + 2);
	assert(tmp5->r == 1 && tmp5->i == 1);
	const char ca[] = "abc";
	reverse_iterator<const char *> tmp6(ca + 3);
	assert(tmp6.operator->() == ca + 2);
	reverse_iterator<const cmplx *> tmp7(cmplxarr + 3);
	assert(tmp7->r == 2);
	
	assert(*++rit == 'b');	
	assert(*rit++ == 'b' && *rit == 'a');
	assert(*--rit == 'b');
	assert(*rit-- == 'b' && *rit == 'c');
	assert(*(rit + 2) == 'a' && *rit == 'c');
	assert(*(rit - 2) == 'e' && *rit == 'c');
	assert(*(rit += 2) == 'a');
	assert(*(rit -= 2) == 'c');
	assert(rit[2] == 'a');
	assert(rit == rit);
	assert(!(rit != rit));
	assert(!(rit < rit) && rit < rit + 1);
	assert(!(rit > rit) && rit + 1 > rit);
	assert((rit <= rit) && rit <= rit + 1);
	assert((rit >= rit) && rit + 1 >= rit);
	assert((rit + 2) - rit == 2);

	reverse_iterator<const char *> crit(rit);
	assert(crit == rit);
	assert(!(rit != rit));
	assert(crit < rit + 1);
	assert(crit > rit - 1);
	assert(!(crit < rit) && crit < rit + 1);
	assert(!(crit > rit) && crit + 1 > rit);
	assert((rit <= rit) && crit <= rit + 1);
	assert((crit >= rit) && crit + 1 >= rit);
	assert((crit + 2) - crit == 2);
}

#if STL==0 || __cplusplus >= 201103L
void test_is_integral(void)
{
	assert(is_integral<bool>::value == true);
	assert(is_integral<char>::value == true);
	assert(is_integral<wchar_t>::value == true);
	assert(is_integral<unsigned char>::value == true);
	assert(is_integral<signed char>::value == true);
	assert(is_integral<int>::value == true);
	assert(is_integral<unsigned int>::value == true);
	assert(is_integral<short>::value == true);
	assert(is_integral<unsigned short>::value == true);
	assert(is_integral<long>::value == true);
	assert(is_integral<unsigned long>::value == true);
	assert(is_integral<long long>::value == true);
	assert(is_integral<unsigned long long>::value == true);
	assert(is_integral<float>::value == false);
	assert(is_integral<double>::value == false);
	assert(is_integral<cmplx>::value == false);
	assert(is_integral<float *>::value == false);
	assert(is_integral<void *>::value == false);
	assert(is_integral<char *>::value == false);
	assert(is_integral<int &>::value == false);
	assert(is_integral<const bool>::value == true);
	assert(is_integral<const char>::value == true);
	assert(is_integral<const wchar_t>::value == true);
	assert(is_integral<const unsigned char>::value == true);
	assert(is_integral<const signed char>::value == true);
	assert(is_integral<const int>::value == true);
	assert(is_integral<const unsigned int>::value == true);
	assert(is_integral<const short>::value == true);
	assert(is_integral<const unsigned short>::value == true);
	assert(is_integral<const long>::value == true);
	assert(is_integral<const unsigned long>::value == true);
	assert(is_integral<const long long>::value == true);
	assert(is_integral<const unsigned long long>::value == true);
	assert(is_integral<const float>::value == false);
	assert(is_integral<const double>::value == false);
	assert(is_integral<const cmplx>::value == false);
}

void test_is_same(void)
{
	assert((is_same<int, int>::value) == true);
	assert((is_same<double, double>::value) == true);
	assert((is_same<int, double>::value) == false);
	assert((is_same<int, const int>::value) == false);
}

template< typename T, typename E = void>
struct vv
{
	static const bool v = false;
};

template< typename T >
struct vv<T, typename enable_if<is_integral<T>::value>::type>
{
	static const bool v = true;
};

void test_enable_if(void)
{
	assert(vv<bool>::v == true);
	assert(vv<char>::v == true);
	assert(vv<int>::v == true);
	assert(vv<float>::v == false);
	assert(vv<double>::v == false);
	assert(vv<cmplx>::v == false);
}
#endif

struct pred
{
	bool operator()(int x, int y) const { return x == y; }
};

void test_equal(void)
{
	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	assert(equal(arr1, arr1 + 9, arr2) == true);
	assert(equal(arr1, arr1, arr2) == true);
	assert(equal(arr1, arr1 + 3, arr2) == true);
	assert(equal(arr1, arr1 + 9, arr2 + 1) == false);
	assert(equal(arr1 + 1, arr1 + 9, arr2) == false);
	assert(equal(arr1, arr1 + 9, arr2, pred()) == true);
	assert(equal(arr1, arr1, arr2, pred()) == true);
	assert(equal(arr1, arr1 + 3, arr2, pred()) == true);
	assert(equal(arr1, arr1 + 9, arr2 + 1, pred()) == false);
	assert(equal(arr1 + 1, arr1 + 9, arr2, pred()) == false);
}

struct comp
{
	bool operator()(char x, char y) const { return x < y; }
};

void test_lexicograhical_compare(void)
{
	const char s1[] = "abracadapra";
	const char s2[] = "abra";
	
	assert(lexicographical_compare(s1, s1 + sizeof(s1), s2, s2 + sizeof(s2)) == false);
	assert(lexicographical_compare(s2, s2 + sizeof(s2), s1, s1 + sizeof(s1)) == true);
	assert(lexicographical_compare(s1, s1 + sizeof(s2), s2, s2 + sizeof(s2)) == false);
	assert(lexicographical_compare(s1, s1, s2, s2 ) == false);
	assert(lexicographical_compare(s1, s1, s2, s2 + 1) == true);
	assert(lexicographical_compare(s1, s1 + 1, s2, s2) == false);
	assert(lexicographical_compare(s2, s1 + 2, s1 + 3, s1 + 5) == true);

	assert(lexicographical_compare(s1, s1 + sizeof(s1), s2, s2 + sizeof(s2), comp()) == false);
	assert(lexicographical_compare(s2, s2 + sizeof(s2), s1, s1 + sizeof(s1), comp()) == true);
	assert(lexicographical_compare(s1, s1 + sizeof(s2), s2, s2 + sizeof(s2), comp()) == false);
	assert(lexicographical_compare(s1, s1, s2, s2, comp()) == false);
	assert(lexicographical_compare(s1, s1, s2, s2 + 1, comp()) == true);
	assert(lexicographical_compare(s1, s1 + 1, s2, s2, comp()) == false);
	assert(lexicographical_compare(s2, s1 + 2, s1 + 3, s1 + 5, comp()) == true);
}

/*
test class for rel_ops

class Int {
public:
	Int (int v)
		: val(v) {}
	bool operator==(Int x) const
	  {return (val == x.val); }
	bool operator< (Int x) const
	  {return (val < x.val); }
private:
	int val;
};
*/

typedef pair<int, char> Pair_ic;

void test_pair(void)
{
	pair<int, float> tmp1;
	pair<int, float> tmp2(1, 2.0);
	pair<long, double> tmp3 = tmp2;
	pair<int, float>::first_type *ptr1 = (int *) 0;
	pair<int, float>::second_type *ptr2 = (float *) 0;
	tmp1 = tmp2;
	(void) tmp1;
	(void) tmp2;
	(void) tmp3;
	(void) ptr1;
	(void) ptr2;

	pair<int, char> p1;
	pair<int, char> p2(3, 'a');

	assert (p1.first == 0) ;
	assert (p1.second == 0);
	assert (p2.first == 3);
	assert (p2.second == 'a');
	assert (p2 == make_pair((Pair_ic::first_type) 3, (Pair_ic::second_type) 'a'));
	assert (p2 < make_pair((Pair_ic::first_type) 4, (Pair_ic::second_type) 'a'));
	assert (p2 < make_pair ((Pair_ic::first_type) 3, (Pair_ic::second_type) 'b'));
	assert (p1 != p2);
	assert (p2 > p1);
	assert (p2 <= p2);
	assert (p2 >= p2);
}

void test_vector(void)
{
	std::allocator<int> alloc;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<int> v;
	(void) v;
	vector<int> v1(alloc);
	(void) v1;
	vector<int> v2(5);
	(void) v2;
	vector<int> v3(10, 100);
	(void) v3;
	vector<int> v4(6, 100, alloc);
	(void) v4;
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(int));
	(void) v5;
	vector<int> v6(arr, arr + sizeof(arr) / sizeof(int), alloc);
	(void) v6;
	vector<int> v7 = v6;
	(void) v7;

	vector<int> vv(3);
	vv = v5;
	vv = v2;
	vv = v4;
	vv = v6;
	
	(void) vv;

	(void) vv.get_allocator();

	typedef vector<int>::iterator vIt;

	vIt first = vv.begin();
	vIt last = vv.end();
	for (int i = 1; i < 10; ++i)
	{
		assert(*first == i);
		++first;
	}
	assert(first == last);

	const vector<int> vvc = vv;
	typedef vector<int>::const_iterator cvIt;

	cvIt cfirst = vvc.begin();
	cvIt clast = vvc.end();
	for (int i = 1; i < 10; ++i)
	{
		assert(*cfirst == i);
		++cfirst;
	}
	assert(cfirst == clast);

	cfirst = first;
	//first = cfirst; // it is not compile;

	typedef vector<int>::reverse_iterator vrIt;

	vrIt rfirst = vv.rbegin();
	vrIt rlast = vv.rend();
	for (int i = 9; i > 0; --i)
	{
		assert(*rfirst == i);
		++rfirst;
	}
	assert(rfirst == rlast);

	typedef vector<int>::const_reverse_iterator cvrIt;

	cvrIt crfirst = vvc.rbegin();
	cvrIt crlast = vvc.rend();
	for (int i = 9; i > 0; --i)
	{
		assert(*crfirst == i);
		++crfirst;
	}
	assert(crfirst == crlast);

	crfirst = rfirst;
	//first = cfirst; // it is not compile;

	assert(vv.size() == sizeof(arr) / sizeof(int));
	std::cout << vv.max_size() << '\n';
	std::cout << vv.capacity() << '\n';

	assert(vv.empty() == false);
	assert(v.empty() == true);
	
	const vector<int> cvv(10, 1);
	//vector<int>::iterator it = cvv.begin();

	//vv.reserve(4)

	assert(vv.size() == 9 && vv.capacity() == 9);
	vv.reserve(100);
	assert(vv.size() == 9 && vv.capacity() == 100);
	
	const vector<int> ctv(arr, arr + sizeof(arr) / sizeof(int));
	assert(ctv.front() == 1);
	assert(ctv.back() == 9);

	vector<int> tv(arr, arr + sizeof(arr) / sizeof(int));
	assert(tv.front() == 1);
	assert(tv.back() == 9);

	for(size_t i = 0; i < tv.size(); ++i)
	{
		assert(tv[i] == (int) (i + 1));
	}

	bool caught = false;
	for(size_t i = 0; i < tv.size() + 1; ++i)
	{
		int tmp = 0;
		try {
			tmp = tv.at(i);
		}
		catch (...)
		{
			caught = (i == tv.size() ? true : false);
			tmp = (int) i + 1;
		}
		assert(tmp == (int) (i + 1));
	}
	assert(caught == true);

	{
	std::vector<int> v;
	
	std::cout << "size = " << v.size() << "  capacity = " << v.capacity() << '\n';

	v.push_back(0);
	std::cout << "size = " << v.size() << "  capacity = " << v.capacity() << '\n';
	v.push_back(0);
	std::cout << "size = " << v.size() << "  capacity = " << v.capacity() << '\n';
	v.push_back(0);
	std::cout << "size = " << v.size() << "  capacity = " << v.capacity() << '\n';
	v.push_back(0);
	std::cout << "size = " << v.size() << "  capacity = " << v.capacity() << '\n';
	v.push_back(0);
	std::cout << "size = " << v.size() << "  capacity = " << v.capacity() << '\n';
	v.push_back(0);
	std::cout << "size = " << v.size() << "  capacity = " << v.capacity() << '\n';
	}

	while (!tv.empty())
	{
		tv.pop_back();
	}
	//tv.pop_back();

	{
		std::vector<int> v;
		v.insert(v.begin(), 0);
		assert(v.front() == 0);
		v.insert(v.end(), 2);
		assert(v.back() == 2);
		v.insert(v.begin() + 1, 1);
		v.insert(v.begin() + 2, 3);
		v.insert(v.begin() + 1, 4);
		assert(v[0] == 0 && v[1] == 4 && v[2] == 1 && v[3] == 3 && v[4] == 2); 
	}
	{
		std::vector<int> v;
		v.insert(v.begin(), 3, 0);
		v.insert(v.begin() + 1, 2, 1);
		v.insert(v.end(), 2, 2);
		assert(v[0] == 0 && v[1] == 1 && v[2] == 1 && v[3] == 0 && v[4] == 0
				&& v[5] == 2 && v[6] == 2);
	}



}

struct St {
	int a;
	static int cout;
	St(int a = 0) : a(a) {
		++cout;
		if (cout == 7)
			throw "except";
	}
};

int St::cout = 0;

struct Svs {
	int a;
	static int dcout;
	Svs(int a = 0) : a(a) {
	}
	~Svs(void) { ++dcout; }
};

int Svs::dcout = 0;

void test_vector_constructor(void)
{
	St st;
	vector<St>::value_type *vtptr = (St*) 0;
	(void) vtptr;
#if __cplusplus < 201103L
	vector<St, std::allocator<int> >::allocator_type *aptr =
														(std::allocator<int>*) 0;
	(void) aptr;
	vector<St>::allocator_type *aptr2 = (std::allocator<St>*) 0;
	(void) aptr2;
	vector<St>::pointer pptr = (St*) 0;
	(void) pptr;
	vector<St>::const_pointer cpptr = (const St*) 0;
	(void) cpptr;
	vector<St>::reference rf = st;
	(void) rf;
	vector<St>::const_reference crf = st;
	(void) crf;
	vector<St>::size_type *stptr = (std::allocator<St>::size_type *) 0;
	(void) stptr;
	vector<St>::difference_type *dtptr = (std::allocator<St>::difference_type *) 0;
	(void) dtptr;
#endif

	std::allocator<int> alloc;
	vector<int> v1;
	vector<int> v2(alloc);
	vector<int> v3(10);
	vector<int> v4(10, 1);
	vector<int> v5(10, 1, alloc);
	vector<int> v6 = v5;
	for (int i = 0; i < 10; ++i)
		assert(v5[i] == 1 && v6[i] == 1);
	assert(v5.size() == 10 && v5.capacity() == 10);
	assert(v6.size() == 10 && v6.capacity() == 10);
	try
	{
		vector<St> tmp(10);
	}
	catch (...) {}

	{
		vector<Svs> tmp(100, 4);
	}
	assert(Svs::dcout == 101);

	//std::allocator<int> alloc;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> vv(arr, arr + sizeof(arr) / sizeof(int), alloc);
	typedef vector<int>::iterator vIt;
	vIt first = vv.begin();
	vIt last = vv.end();
	for (int i = 1; i < 10; ++i)
	{
		assert(*first == i);
		++first;
	}
	assert(first == last);

	{
	std::vector<int> sv;
	for(int i = 0; i < 1000; ++i)
		sv.push_back(i);
	vector<int> v(sv.begin(), sv.end());
	for(int i = 0; i < 1000; ++i)
		assert(v[i] == i);
	}
	{
	std::fstream f("./test/test1.txt", std::fstream::in);
	std::istream_iterator<int> start(f);
	std::istream_iterator<int> end;
	vector<int> v(start, end);
	for (int i = 0; i < 5; ++i)
		assert(v[i] == i + 1);
	}
}


void test_vector_operator_assign(void)
{
	vector<int> v(100);
	v.reserve(200);
	for (int i = 0; i < 100; ++i)
	{
		v[i] = i;
	}
	vector<int> v1(50);
	v.reserve(120);
	for (int i = 0; i < 50; ++i)
	{
		v1[i] = 50 - i;
	}
	vector<int> v2(1000);
	for (int i = 0; i < 1000; ++i)
	{
		v2[i] = 2 * i;
	}

	vector<int> vv;

	vv = v;
	for (int i = 0; i < 100; ++i)
	{
		assert(vv[i] == i);
	}
	assert(vv.size() == 100 && vv.capacity() == 100);
	
	vv = v1;
	for (int i = 0; i < 50; ++i)
	{
		assert(vv[i] == 50 - i);
	}
	assert(vv.size() == 50 && vv.capacity() == 100);
	vv = v2;
	for (int i = 0; i < 1000; ++i)
	{
		assert(vv[i] == 2 * i);
	}
	assert(vv.size() == 1000 && vv.capacity() == 1000);
}


void test_vector_assign(void)
{
	vector<int> v(10, 5);
	v.reserve(20);

	v.assign(5, 3);
	for(int i = 0; i < 5; ++i)
	{
		assert(v[i] == 3);
	}
	assert(v.size() == 5 && v.capacity() == 20);
	v.assign(15, 4);
	for(int i = 0; i < 15; ++i)
	{
		assert(v[i] == 4);
	}
	assert(v.size() == 15 && v.capacity() == 20);
	v.assign(30, 6);
	for(int i = 0; i < 30; ++i)
	{
		assert(v[i] == 6);
	}
	assert(v.size() == 30 && v.capacity() == 30);
	v.assign(0,0);
	assert(v.size() == 0 && v.capacity() == 30);
	
	int arr[100];
	for(int i = 0; i < 100; ++i)
		arr[i] = 2 * i;
	vector<int> vv;
	vv.assign(arr, arr + 100);
	for(int i = 0; i < 100; ++i)
	{
		assert(vv[i] == 2 * i);
	}
	assert(vv.size() == 100 && vv.capacity() == 100);
	
	std::vector<int> tmp;
	for(int i = 1000; i > 0; --i)
		tmp.push_back(i);
	vv.assign(tmp.begin(), tmp.end());
	for(int i = 0; i < 1000; ++i)
	{
		assert(vv[i] == tmp[i]);
	}
	assert(vv.size() == tmp.size() && vv.capacity() != tmp.capacity());
	

	{
	vector<int> vvv;
	vvv.assign(100, 0);
	std::fstream fs("./test/test1.txt", std::fstream::in);
	std::istream_iterator<int> ii(fs);
	vvv.assign(ii, std::istream_iterator<int>());
	for(int i = 0; i < 5; ++i)
	{
		assert(vvv[i] == i + 1);
	}
	assert(vvv.size() == 5 && vvv.capacity() == 100);
	fs.close();
	}
	{
	vector<int> vt;
	vt.assign(1, 0);
	std::fstream fs("./test/test1.txt", std::fstream::in);
	std::istream_iterator<int> ii(fs);
	vt.assign(ii, std::istream_iterator<int>());
	for(int i = 0; i < 5; ++i)
	{
		assert(vt[i] == i + 1);
	}
	assert(vt.size() == 5 && vt.capacity() == 8);
	}
}


void test_vector_get_allocator(void)
{
	std::allocator<char> all;
	(void) all;

	vector<int, std::allocator<int> > v;
	std::allocator<int> tmp1 = v.get_allocator();
	(void) tmp1;
#if __cplusplus < 201103L
	vector<int, std::allocator<int> > v1(all);
	std::allocator<int> tmp2 = v1.get_allocator();
	(void) tmp2;
	vector<int, std::allocator<char> > v2(all);
	std::allocator<int> tmp3 = v2.get_allocator();
	(void) tmp3;
#endif
	int *ptr = v.get_allocator().allocate(5);
	ptr[4] = 100;
	v.get_allocator().deallocate(ptr, 5);
}

void test_vector_get_iterators(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> vv(arr, arr + sizeof(arr) / sizeof(int));
	typedef vector<int>::iterator vIt;

	vIt first = vv.begin();
	vIt last = vv.end();
	std::vector<int> tmp(first, last);
	for (int i = 1; i < 10; ++i)
	{
		assert(*first == i);
		assert(tmp[i - 1]  == i);
		++first;
	}
	assert(first == last);

	const vector<int> vvc = vv;
	typedef vector<int>::const_iterator cvIt;

	cvIt cfirst = vvc.begin();
	cvIt clast = vvc.end();
	std::vector<int> tmp1(cfirst, clast);
	for (int i = 1; i < 10; ++i)
	{
		assert(*cfirst == i);
		assert(tmp1[i - 1]  == i);
		++cfirst;
	}
	assert(cfirst == clast);

	cfirst = first;
//	first = cfirst; // it is not compile;

	typedef vector<int>::reverse_iterator vrIt;

	vrIt rfirst = vv.rbegin();
	vrIt rlast = vv.rend();
	std::vector<int> tmp3(rfirst, rlast);
	for (int i = 9; i > 0; --i)
	{
		assert(*rfirst == i);
		assert(tmp3[9 - i]  == i);
		++rfirst;
	}
	assert(rfirst == rlast);

	typedef vector<int>::const_reverse_iterator cvrIt;

	cvrIt crfirst = vvc.rbegin();
	cvrIt crlast = vvc.rend();
	std::vector<int> tmp4(crfirst, crlast);
	for (int i = 9; i > 0; --i)
	{
		assert(*crfirst == i);
		assert(tmp4[9 - i]  == i);
		++crfirst;
	}
	assert(crfirst == crlast);
	assert(tmp4.size() == 9);

	crfirst = rfirst;
	//first = cfirst; // it is not compile;

	{
		vIt first = vv.begin();
		vIt last = vv.end();
		vIt tmp = first;
		assert(tmp == first);
		while (tmp != last)
		{
			assert(tmp < last);
			++tmp;
		}
		assert(tmp == last);
		while (tmp != first)
		{
			assert(tmp > first);
			--tmp;
		}
		while (tmp != last)
		{
			assert(tmp <= last);
			tmp++;
		}
		assert(tmp == last);
		while (tmp != first)
		{
			assert(tmp >= first);
			tmp--;
		}
		tmp += 2;
		assert(tmp - 2 == first);
		tmp -= 5;
		assert(tmp + 3 == first);
		tmp += 1;
		assert(2 + tmp == first);
		tmp += 2;
		assert(static_cast<vector<int>::size_type>(last - first) == vv.size());
	} 

}

void test_vector_resize(void)
{
	ft::vector<double> dv1;
	std::vector<double> dv2;
	assert(dv1.max_size() == dv2.max_size());

	vector<int> v;
	assert(v.size() == 0 && v.capacity() == 0);
	v.resize(10, 1);
	assert(v.size() == 10 && v.capacity() == 10);
	v.resize(8);
	assert(v.size() == 8 && v.capacity() == 10);
	v.resize(14, 1);
	//assert(v.size() == 14 && v.capacity() == 16);
	//assert(v.size() == 14 && v.capacity() == 20);
	v.resize(1000, 10);
	assert(v.size() == 1000 && v.capacity() == 1000);
	int i = 0;
	for(; i < 14; ++i)
	{
		assert(v[i] == 1);
	}
	for(; i < 1000; ++i)
	{
		assert(v[i] == 10);
	}
	v.resize(1000, 2);
	assert(v.size() == 1000 && v.capacity() == 1000);
	for(i = 0; i < 14; ++i)
	{
		assert(v[i] == 1);
	}
	for(; i < 1000; ++i)
	{
		assert(v[i] == 10);
	}
	
}

void test_vector_reserve(void)
{
	vector<int> v;
	
	v.reserve(0);
	assert(v.size() == 0 && v.capacity() == 0);
	v.reserve(1000);
	assert(v.size() == 0 && v.capacity() == 1000);
	v.assign(1000, 1);
	assert(v.size() == 1000 && v.capacity() == 1000);
	v.reserve(2000);
	for(int i = 0; i < 1000; ++i)
		assert(v[i] == 1);
	assert(v.size() == 1000 && v.capacity() == 2000);
	v.reserve(200);
	for(int i = 0; i < 1000; ++i)
		assert(v[i] == 1);
	assert(v.size() == 1000 && v.capacity() == 2000);
}

void test_vector_at(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> tv(arr, arr + sizeof(arr) / sizeof(int));
	assert(tv.front() == 1);
	assert(tv.back() == 9);
	tv.front() = 1;
	tv.back() = 9;

	for(size_t i = 0; i < tv.size(); ++i)
	{
		assert(tv[i] == (int) (i + 1));
	}

	bool caught = false;
	for(size_t i = 0; i < tv.size() + 1; ++i)
	{
		int tmp = 0;
		try {
			tmp = tv.at(i);
		}
		catch (std::out_of_range &)
		{
			caught = (i == tv.size() ? true : false);
			tmp = (int) i + 1;
		}
		assert(tmp == (int) (i + 1));
	}
	assert(caught == true);

	vector<std::string> tmp;
	tmp.front();
	tmp.back();

	const vector<int> ctv(tv.begin(), tv.end());
	assert(ctv.front() == 1);
	assert(ctv.back() == 9);
}

void test_vector_push_back(void)
{
	std::vector<float> sv(10);
	vector<float> v(10);
	for(float i = 0; i < 1000.; i += 1)
	{
		sv.push_back(i);
		v.push_back(i);
		assert(sv.size() == v.size() && sv.capacity() == v.capacity());
		assert(sv.back() == v.back());
		assert(sv.front() == v.front());
	}
	for (vector<int>::size_type i = 0; i < sv.size(); ++i)
		assert(sv[i] == v[i]);
}


void test_vector_pop_back(void)
{
	vector<int> v;
	for(int i = 0; i < 1000; ++i)
		v.push_back(i);
	for(int i = 0; i < 1000; ++i)
		v.pop_back();
	assert(v.size() == 0);

}

void test_vector_insert(void)
{
	typedef vector<int>::iterator vIt;
	vector<int> v;
	v.reserve(10);

	vIt it = v.insert(v.begin(), 1);
	assert(v.front() == 1 && v.back() == 1);
	assert(it == v.begin());
	v.insert(v.end(), 3);
	v.insert(v.end() - 1, 2);
	assert(v[0] == 1 && v[1] == 2 && v[2] == 3);
	for(int i = 4; i < 11; ++i)
		v.insert(v.end(), i);
	for(int i = 0; i < 10; ++i)
		assert(v[i] == i + 1);
	for(int i = 0; i < 30; ++i)
		v.insert(v.begin() + 5, i);
	for(int i = 0; i < 5; ++i)
		assert(v[i] == i + 1);
	for(int i = 0; i < 30; ++i)
		assert(v[5 + i] == 30 - 1 - i);
	for(int i = 35, j = 6; j < 11; ++j, ++i)
		assert(v[i] == j);

	{
	vector<int> v;
	v.reserve(11);
	v.insert(v.begin(), 5, 5);
	assert(v.size() == 5);
	for(int i(0); i < 5; ++i)
		assert(v[i] == 5);
	v.insert(v.begin() + 1, 5, 10);
	assert(v.size() == 10);
	assert(v.front() == 5);
	for(int i(1); i <= 5; ++i)
		assert(v[i] == 10);
	for(int i(6); i < 10; ++i)
		assert(v[i] == 5);
	v.reserve(15);
	v.insert(v.end() - 2, 4, 30);
	assert(v.front() == 5);
	for(int i(1); i <= 5; ++i)
		assert(v[i] == 10);
	for(int i(6); i < 8; ++i)
		assert(v[i] == 5);
	for(int i(8); i < 12; ++i)
		assert(v[i] == 30);
	for(int i(12); i < 14; ++i)
		assert(v[i] == 5);
	assert(v.size() == 14);
	v.insert(v.begin() + 4, 1000, 1);
	assert(v.size() == 1014);
	assert(v.front() == 5);
	assert(v[1] == 10);
	assert(v[2] == 10);
	assert(v[3] == 10);
	for(int i(4); i < 1004; ++i)
		assert(v[i] == 1);
	assert(v[1004] == 10);
	assert(v[1005] == 10);
	assert(v[1006] == 5);
	assert(v[1007] == 5);
	for(int i(1008); i < 1012; ++i)
		assert(v[i] == 30);
	assert(v[1012] == 5);
	assert(v[1013] == 5);
	}

}

void test_vector_insert2(void)
{
	typedef vector<std::string>::iterator vIt;
	vector<std::string> v;
	v.reserve(10);
	vIt it = v.insert(v.begin(), "1");
	assert(it == v.begin());
	assert(v.front() == "1" && v.back() == "1");
	v.insert(v.end(), "3");
	v.insert(v.end() - 1, "2");
	assert(v[0] == "1" && v[1] == "2" && v[2] == "3");

	{
	vector<std::string> v;
	v.reserve(11);
	v.insert(v.begin(), 5, "5");
	assert(v.size() == 5);
	for(int i(0); i < 5; ++i)
		assert(v[i] == "5");
	v.insert(v.begin() + 1, 5, "10");
	assert(v.size() == 10);
	assert(v.front() == "5");
	for(int i(1); i <= 5; ++i)
		assert(v[i] == "10");
	for(int i(6); i < 10; ++i)
		assert(v[i] == "5");
	v.reserve(15);
	v.insert(v.end() - 2, 4, "30");
	assert(v.front() == "5");
	for(int i(1); i <= 5; ++i)
		assert(v[i] == "10");
	for(int i(6); i < 8; ++i)
		assert(v[i] == "5");
	for(int i(8); i < 12; ++i)
		assert(v[i] == "30");
	for(int i(12); i < 14; ++i)
		assert(v[i] == "5");
	assert(v.size() == 14);
	v.insert(v.begin() + 4, 1000, "1");
	assert(v.size() == 1014);
	assert(v.front() == "5");
	assert(v[1] == "10");
	assert(v[2] == "10");
	assert(v[3] == "10");
	for(int i(4); i < 1004; ++i)
		assert(v[i] == "1");
	assert(v[1004] == "10");
	assert(v[1005] == "10");
	assert(v[1006] == "5");
	assert(v[1007] == "5");
	for(int i(1008); i < 1012; ++i)
		assert(v[i] == "30");
	assert(v[1012] == "5");
	assert(v[1013] == "5");
	}

}

void test_vector_insert3(void)
{
	vector<int> v;
	v.reserve(9);
	std::fstream f("./test/test1.txt", std::fstream::in);
	std::istream_iterator<int> it(f);
	v.insert(v.begin(), 0);
	v.insert(v.begin(), 0);
	v.insert(v.begin() + 1, it, std::istream_iterator<int>());
	assert(v.front() == 0);
	assert(v.back() == 0);
	for(int i(1); i < 6; ++i)
		assert(v[i] == i);
	f.close();
	std::fstream f2("./test/test1.txt", std::fstream::in);
	std::istream_iterator<int> it2(f2);
	v.insert(v.end(), it2, std::istream_iterator<int>());
	assert(v.front() == 0);
	for(int i(1); i < 6; ++i)
		assert(v[i] == i);
	assert(v[6] == 0);
	for(int i(1); i < 6; ++i)
		assert(v[6 + i] == i);
}

void test_vector_insert4(void)
{
	std::vector<std::string> s;
	s.push_back("1");
	s.push_back("2");
	s.push_back("3");
	s.push_back("4");
	s.push_back("5");
	std::vector<std::string>::iterator f = s.begin();
	std::vector<std::string>::iterator l = s.end();

	
	vector<std::string> v;
	v.reserve(10);
	v.insert(v.end(), f, l);
	v.insert(v.begin() + 1, f, f + 2);
	assert(v[0] == "1");
	assert(v[1] == "1");
	assert(v[2] == "2");
	assert(v[3] == "2");
	assert(v[4] == "3");
	assert(v[5] == "4");
	assert(v[6] == "5");
	v.insert(v.end() - 2, f, l);
	assert(v[0] == "1");
	assert(v[1] == "1");
	assert(v[2] == "2");
	assert(v[3] == "2");
	assert(v[4] == "3");
	assert(v[5] == "1");
	assert(v[6] == "2");
	assert(v[7] == "3");
	assert(v[8] == "4");
	assert(v[9] == "5");
	assert(v[10] == "4");
	assert(v[11] == "5");
}

void test_vector_erase(void)
{
	vector<double> v;
	v.assign(100, 1.);

	for(int i(0); i < 50; ++i)
		v.erase(v.end() - 1);
	for(int i(0); i < 50; ++i)
		v.erase(v.begin());
	assert(v.size() == 0);
	v.push_back(1.);
	v.push_back(2.);
	v.push_back(3.);
	v.erase(v.begin());
	assert(v[0] == 2.);
	assert(v[1] == 3.);
	v.erase(v.begin(), v.end());
	assert(v.size() == 0);
	v.push_back(1.);
	v.push_back(2.);
	v.push_back(3.);
	v.push_back(4.);
	v.push_back(5.);
	vector<double>::iterator it = v.erase(v.begin() + 1, v.end() - 1);
	assert(*it == 5.);
	assert(v[0] == 1.);
	assert(v[1] == 5.);
	assert(v.size() == 2);
	v.erase(v.begin(), v.begin() + 1);
	v.erase(v.end() - 1,  v.end());
	assert(v.size() == 0);

	
}

void test_vector_relops_swap(void)
{
	vector<int> v1(10, 1);
	vector<int> v2(10, 1);

	assert(v1 == v2);
	v2[6] = 2;
	assert(v1 != v2);
	assert(v1 < v2);
	v1.swap(v2);
	assert(v1 > v2);
	assert(v1 >= v2);
	std::swap(v1, v2);
	assert(v1 <= v2);
	v2[6] = 1;
	v2.push_back(1);
	assert(v1 != v2);
	assert(v1 < v2);
}

void test_vector_swap(void)
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
		v2.push_back(9 - i);
	}

	vector<int>::iterator i11, i12, i13, i21, i22, i23;
	i11 = v1.begin();
	i12 = v1.begin() + 3;
	i13 = --v1.end();
	i21 = v2.begin();
	i22 = v2.begin() + 3;
	i23 = --v2.end();

	assert(*i11 == 0 && *i12 == 3 && *i13 == 9);	
	assert(*i21 == 9 && *i22 == 6 && *i23 == 0);	

    v1.swap(v2);
	assert(*i11 == 0 && *i12 == 3 && *i13 == 9);	
	assert(*i21 == 9 && *i22 == 6 && *i23 == 0);	
	assert(i11 == v2.begin() && i12 == v2.begin() + 3 && i13 == --v2.end());
	assert(i21 == v1.begin() && i22 == v1.begin() + 3 && i23 == --v1.end());
}

void test_vector_iterator_comp(void)
{
	vector<std::string> v;
	v.push_back("1");
	v.push_back("2");
	v.push_back("3");
	v.push_back("4");

	vector<std::string>::iterator it = v.begin();
	vector<std::string>::const_iterator cit = v.begin();
	assert( it == cit);
	++it;
	assert(it > cit);
	++cit; ++cit;
	assert(it < cit);
	++it;
	assert(*it == *cit);
}

void test_stack(void)
{
	vector<std::string> v;
	v.push_back("1");
	v.push_back("2");
	v.push_back("3");
	v.push_back("4");
	stack<std::string, vector<std::string> > s;
	const stack<std::string, vector<std::string> > ss(v);
	
	assert(s.empty() == true);
	assert(ss.empty() == false);

	s.push("1");
	s.push("2");
	s.push("3");
	s.push("4");

	
	assert(s.size() == 4);
	assert(ss.size() == 4);

	assert(s.top() == "4");
	assert(ss.top() == "4");

	assert(ss == s);
	s.pop();
	s.push("3");
	assert(s != ss);
	assert(s < ss);
	assert(ss > s);
	assert(s <= ss);
	assert(ss >= s);

    {
        std::list<std::string> l(v.begin(), v.end());
    
	    stack<std::string, std::list<std::string> > s(l);
        assert(s.top() == "4");
        s.pop();
        assert(s.top() == "3");
        s.pop();
        s.push("6");
        assert(s.top() == "6");
        assert(s.size() == 3);
    }
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};


void test_map_constructors(void)
{
	map<std::string, int> m1;
	map<char, int, bool (*)(char, char)> m2(fncomp);
	map<char, int, classcomp> m3;
	classcomp cc;
	map<char, int, classcomp> m4(cc);
	std::allocator<pair<char, int> >  al;
	map<char, int, bool (*)(char, char)> m5(fncomp, al);
	map<char, int, classcomp> m6(cc, al);

	map<std::string,int> first;

  first["one"]=10;
  first["two"]=20;
  first["three"]=30;
  first["four"]=40;
  first["five"]=50;

	map<std::string,int> second (first.begin(),first.end());
	map<std::string,int> third (second);

	map<std::string, int>::iterator fit = first.begin();
	map<std::string, int>::iterator sit = second.begin();
	map<std::string, int>::iterator tit = third.begin();
	
	while (fit != first.end())
	{
		assert(*fit == *sit && *sit == *tit);
		++fit;
		++sit;
		++tit;
	}
	assert( sit == second.end() && tit == third.end());
}

void test_map_iterator(void)
{
	map<std::string,int> m;
	std::map<std::string,int> stdm;

  	m["one"]=10;
  	stdm["one"]=10;
	m["two"]=20;
	stdm["two"]=20;
	m["three"]=30;
	stdm["three"]=30;
	m["four"]=40;
	stdm["four"]=40;
	m["five"]=50;
	stdm["five"]=50;
	m["six"]=60;
	stdm["six"]=60;
	m["seven"]=70;
	stdm["seven"]=70;
	m["eight"]=80;
	stdm["eight"]=80;
	m["nine"]=90;
	stdm["nine"]=90;

	map<std::string, int>::iterator it = m.begin();
	std::map<std::string, int>::iterator stdit = stdm.begin();

	while (stdit != stdm.end())
	{
		assert((*stdit).first == (*it).first && (*stdit).second == (*it).second);
		++stdit;
		++it;
	}
	assert(it == m.end());

	it = m.begin();
	stdit = stdm.begin();
	while (stdit != stdm.end())
	{
		assert((*stdit).first == (*it).first && (*stdit).second == (*it).second);
		stdit++;
		it++;
	}
	assert(it == m.end());
	
	it = m.end();
	stdit = stdm.end();
	while (stdit != stdm.begin())
	{
		--stdit;
		--it;
		assert((*stdit).first == (*it).first && (*stdit).second == (*it).second);
	}
	assert(it == m.begin());
	assert((*stdit).first == (*it).first && (*stdit).second == (*it).second);
	
	it = m.end();
	stdit = stdm.end();
	while (stdit != stdm.begin())
	{
		stdit--;
		it--;
		assert(stdit->first == it->first && stdit->second == it->second);
	}
	assert(it == m.begin());
	assert((*stdit).first == (*it).first && (*stdit).second == (*it).second);

	const map<std::string, int> cm(m.begin(), m.end());
	const std::map<std::string, int> cstdm(stdm.begin(), stdm.end());

	map<std::string, int>::const_iterator cit = cm.begin();
	std::map<std::string, int>::const_iterator cstdit = cstdm.begin();

	while (cstdit != cstdm.end())
	{
		assert((*cstdit).first == (*cit).first &&
				(*cstdit).second == (*cit).second);
		++cstdit;
		++cit;
	}
	assert(cit == cm.end());

	cit = cm.begin();
	cstdit = cstdm.begin();
	while (cstdit != cstdm.end())
	{
		assert(cstdit->first == cit->first &&
				cstdit->second == cit->second);
		cstdit++;
		cit++;
	}
	assert(cit == cm.end());

	cit = cm.end();
	cstdit = cstdm.end();
	while (cstdit != cstdm.begin())
	{
		cstdit--;
		cit--;
		assert(cstdit->first == cit->first &&
				cstdit->second == cit->second);
	}
	assert(cstdit->first == cit->first && cstdit->second == cit->second);
	assert(cit == cm.begin());

	cit = cm.end();
	cstdit = cstdm.end();
	while (cstdit != cstdm.begin())
	{
		--cstdit;
		--cit;
		assert(cstdit->first == cit->first &&
				cstdit->second == cit->second);
	}
	assert(cstdit->first == cit->first && cstdit->second == cit->second);
	assert(cit == cm.begin());

	map<std::string, int>::reverse_iterator rit = m.rbegin();
	std::map<std::string, int>::reverse_iterator rstdit = stdm.rbegin();
	while (rstdit != stdm.rend())
	{
		assert(rstdit->first == rit->first &&
				rstdit->second == rit->second);
		++rit;
		++rstdit;
	}
	assert(rit == m.rend());
	
	map<std::string, int>::const_reverse_iterator crit = m.rbegin();
	std::map<std::string, int>::const_reverse_iterator crstdit = stdm.rbegin();
	while (crstdit != stdm.rend())
	{
		assert(crstdit->first == crit->first &&
				crstdit->second == crit->second);
		++crit;
		++crstdit;
	}
	assert(crit == m.rend());
	
}

void test_map_capacity(void)
{
	typedef map<char, int>::size_type sz_t;
	map<char, int> m;

	assert(m.empty() == true);
	assert(m.size() == 0);
	m['a'] = 1;
	assert(m.empty() == false);
	assert(m.size() == 1);
	for (char c = 'a', i = 1; c <= 'z'; c += 1, i += 1)
	{
		m[c] = i;
		assert(m.empty() == false);
		assert(m.size() == sz_t(i));
	}

	assert(m.max_size() > m.size());
}

void test_map_access(void)
{
	map<char, int> m;
	for (char c = 'a', i = 1; c <= 'z'; c += 1, i += 1)
	{
		m[c] = i;
	}
	assert(m['a'] == 1 && m['z'] == 26 && m['c'] == 3);
	m['c'] = 6;
	assert(m['c'] == 6);
}

void test_map_insert_value(void)
{

	typedef map<std::string, int>::iterator mit;
	map<std::string, int> m;
	pair<mit, bool> p;
	pair<std::string, int> v;
	
	assert(m.size() == 0);
	v = make_pair("1", 1);
	m.insert(v);
	assert(m.size() == 1);
	v = make_pair("2", 2);
	p = m.insert(v);
	assert(p.first->first == "2" && p.second == true);
	v = make_pair("0", 0);
	p = m.insert(v);
	assert(p.first->second == 0 && p.second == true);
	v = make_pair("0", 10);
	p = m.insert(v);
	assert(p.first->second == 0 && p.second == false);
	v = make_pair("2", 10);
	p = m.insert(v);
	assert(p.first->first == "2" && p.second == false);

	mit tmp = p.first;

	v = make_pair("6", 6);
	p = m.insert(v);
	assert(p.first->first == "6" && p.second == true);
	v = make_pair("4", 4);
	p = m.insert(v);
	assert(p.first->first == "4" && p.second == true);
	v = make_pair("5", 5);
	p = m.insert(v);
	assert(p.first->first == "5" && p.second == true);
	v = make_pair("3", 3);
	p = m.insert(v);
	assert(p.first->first == "3" && p.second == true);

	assert(tmp->first == "2" && tmp->second == 2);
	
	v = make_pair("!", 5);
	p = m.insert(v);
	assert(p.first->first == "!" && p.second == true);
	v = make_pair("$", 3);
	p = m.insert(v);
	assert(p.first->first == "$" && p.second == true);

	assert(tmp->first == "2" && tmp->second == 2);
}

void test_map_insert_position(void)
{
	typedef map<std::string, int>::iterator mit;
	map<std::string, int> m;
	pair<std::string, int> v;
	mit it;
	mit p;

	v = make_pair("0", 0);
	it = m.insert(m.begin(), v);
	assert(it->first == "0" && it->second == 0);

	v = make_pair("1", 1);
	it = m.insert(m.begin(), v);
	assert(it->first == "1" && it->second == 1);
	assert(m.begin()->first == "0" && m.begin()->second == 0);

	v = make_pair("!", 1);
	it = m.insert(m.begin(), v);
	assert(it->first == "!" && it->second == 1);
	assert(m.begin()->first == "!" && m.begin()->second == 1);
	
	p = it;

	v = make_pair("8", 8);
	it = m.insert(m.end(), v);
	assert(it->first == "8" && it->second == 8);
	assert((--m.end())->first == "8" && (--m.end())->second == 8);

	v = make_pair("7", 7);
	it = m.insert(m.end(), v);
	assert(it->first == "7" && it->second == 7);
	assert((--m.end())->first == "8" && (--m.end())->second == 8);

	assert(p->first == "!" && p->second == 1);
	p = it;

	v = make_pair("8", 8);
	it = m.insert(m.end(), v);
	assert(it->first == "8" && it->second == 8);


	v = make_pair("6", 6);
	mit tmp = m.end();
	--tmp; --tmp; --tmp;
	it = m.insert(tmp, v);
	assert(it->first == "6" && it->second == 6);
	
	v = make_pair("6", 6);
	tmp = m.begin();
	++tmp;
	it = m.insert(tmp, v);
	assert(it->first == "6" && it->second == 6);
	
	assert(p->first == "7" && p->second == 7);
	
}

void test_map_insert_range(void)
{
	pair<int, int> arr[1000];

	for (int i = 0; i < 1000; ++i)
		arr[i] = make_pair(i, 2 * i);

	map<int, int> m;

	m.insert(arr + 100, arr + 400);
	m.insert(arr + 600, arr + 1000);
	m.insert(arr, arr + 100);
	m.insert(arr + 400, arr + 600);

	pair<int, int> *start = arr;
	pair<int, int> *finish = arr + 1000;
	map<int, int>::iterator it = m.begin();

	for(; start != finish; ++it, ++start)
	{
		assert(it->second == start->second);
	}
	assert(it == m.end());

}

void test_map_lower_bound(void)
{
	pair<int, char> arr[5];
	pair<int, char>* start = arr;;
	pair<int, char>* finish = start + 5;

	arr[0] = make_pair(1, 'a');
	arr[1] = make_pair(3, 'b');
	arr[2] = make_pair(6, 'c');
	arr[3] = make_pair(7, 'd');
	arr[4] = make_pair(10, 'e');

	map<int, char> m(start, finish);
	
	assert(m.lower_bound(-121)->second == 'a');
	assert(m.lower_bound(1)->second == 'a');
	assert(m.lower_bound(2)->second == 'b');
	assert(m.lower_bound(3)->second == 'b');
	assert(m.lower_bound(4)->second == 'c');
	assert(m.lower_bound(5)->second == 'c');
	assert(m.lower_bound(6)->second == 'c');
	assert(m.lower_bound(7)->second == 'd');
	assert(m.lower_bound(8)->second == 'e');
	assert(m.lower_bound(9)->second == 'e');
	assert(m.lower_bound(10)->second == 'e');
	assert(m.lower_bound(11) == m.end());

	{
	const map<int, char> m(start, finish);
	
	assert(m.lower_bound(-121)->second == 'a');
	assert(m.lower_bound(1)->second == 'a');
	assert(m.lower_bound(2)->second == 'b');
	assert(m.lower_bound(3)->second == 'b');
	assert(m.lower_bound(4)->second == 'c');
	assert(m.lower_bound(5)->second == 'c');
	assert(m.lower_bound(6)->second == 'c');
	assert(m.lower_bound(7)->second == 'd');
	assert(m.lower_bound(8)->second == 'e');
	assert(m.lower_bound(9)->second == 'e');
	assert(m.lower_bound(10)->second == 'e');
	assert(m.lower_bound(11) == m.end());
	assert(m.lower_bound(110001) == m.end());
	}

	{
	//empty
	map<int, char> m;
	assert(m.lower_bound(11) == m.end());
	
	}
}

void test_map_upper_bound(void)
{
	pair<int, char> arr[5];
	pair<int, char>* start = arr;;
	pair<int, char>* finish = start + 5;

	arr[0] = make_pair(1, 'a');
	arr[1] = make_pair(3, 'b');
	arr[2] = make_pair(6, 'c');
	arr[3] = make_pair(7, 'd');
	arr[4] = make_pair(10, 'e');

	map<int, char> m(start, finish);
	
	assert(m.upper_bound(-121)->second == 'a');
	assert(m.upper_bound(1)->second == 'b');
	assert(m.upper_bound(2)->second == 'b');
	assert(m.upper_bound(3)->second == 'c');
	assert(m.upper_bound(4)->second == 'c');
	assert(m.upper_bound(5)->second == 'c');
	assert(m.upper_bound(6)->second == 'd');
	assert(m.upper_bound(7)->second == 'e');
	assert(m.upper_bound(8)->second == 'e');
	assert(m.upper_bound(9)->second == 'e');
	assert(m.upper_bound(10) == m.end());
	assert(m.upper_bound(100) == m.end());

	{
	const map<int, char> m(start, finish);
	
	assert(m.upper_bound(-121)->second == 'a');
	assert(m.upper_bound(1)->second == 'b');
	assert(m.upper_bound(2)->second == 'b');
	assert(m.upper_bound(3)->second == 'c');
	assert(m.upper_bound(4)->second == 'c');
	assert(m.upper_bound(5)->second == 'c');
	assert(m.upper_bound(6)->second == 'd');
	assert(m.upper_bound(7)->second == 'e');
	assert(m.upper_bound(8)->second == 'e');
	assert(m.upper_bound(9)->second == 'e');
	assert(m.upper_bound(10) == m.end());
	assert(m.upper_bound(100) == m.end());
	}

	{
	//empty
	map<int, char> m;
	assert(m.lower_bound(11) == m.end());
	}
}

void test_map_erase(void)
{
	map<int, int> m;
	std::map<int, int> stdm;
	//pair<int,int> v;
	map<int, int>::iterator it;
	std::map<int, int>::iterator stdit;

	for (int i = 0; i < 1000; ++i)
	{
		m.insert(make_pair(i, 10 * i));
		stdm.insert(std::make_pair(i, 10 * i));
	}
	it = m.lower_bound(600);
	stdit = stdm.lower_bound(600);
	

	for (int i = -99; i < 0 ; i += 2)
	{
		assert(m.erase(i) == 0);
		assert(stdm.erase(i) == 0);
	}
	for (int i = 333; i < 666 ; i += 2)
	{
		assert(m.erase(i) == 1);
		assert(stdm.erase(i) == 1);
	}
	for (int i = 1; i < 333 ; i += 2)
	{
		assert(m.erase(i) == 1);
		assert(stdm.erase(i) == 1);
	}
	for (int i = 666; i < 1000 ; i += 2)
	{
		assert(m.erase(i) == 1);
		assert(stdm.erase(i) == 1);
	}
	for (int i = 1000; i < 0 ; i += 2)
	{
		assert(m.erase(i) == 0);
		assert(stdm.erase(i) == 0);
	}

	assert(it->first == 600 && it->second == 6000);
	assert(stdit->first == 600 && stdit->second == 6000);
	assert(m.size() == stdm.size());
	
	stdit = stdm.begin();
	for (it = m.begin(); it != m.end(); ++it, ++stdit)
		assert(it->first == stdit->first && it->second == stdit->second);

	assert(stdit == stdm.end());
	
}

void test_map_erase_iter(void)
{
	map<int, int> m;
	std::map<int, int> stdm;
	//pair<int,int> v;
	map<int, int>::iterator it;
	std::map<int, int>::iterator stdit;

	for (int i = 0; i < 1000; ++i)
	{
		m.insert(make_pair(i, 10 * i));
		stdm.insert(std::make_pair(i, 10 * i));
	}
	it = m.lower_bound(600);
	stdit = stdm.lower_bound(600);

	for (int i = 333; i < 666; i+=2)
	{
		m.erase(m.lower_bound(i));
		stdm.erase(stdm.lower_bound(i));
	}

	assert(it->first == 600 && it->second == 6000);
	assert(stdit->first == 600 && stdit->second == 6000);
	assert(m.size() == stdm.size());
	
	stdit = stdm.begin();
	for (it = m.begin(); it != m.end(); ++it, ++stdit)
		assert(it->first == stdit->first && it->second == stdit->second);

	assert(stdit == stdm.end());
	
}

void test_map_erase_range(void)
{
	map<int, int> m;
	std::map<int, int> stdm;
	//pair<int,int> v;
	map<int, int>::iterator it;
	std::map<int, int>::iterator stdit;

	for (int i = 0; i < 1000; ++i)
	{
		m.insert(make_pair(i, 10 * i));
		stdm.insert(std::make_pair(i, 10 * i));
	}
	it = m.lower_bound(50);
	stdit = stdm.lower_bound(50);


	m.erase(m.lower_bound(100), m.lower_bound(900));
	stdm.erase(stdm.lower_bound(100), stdm.lower_bound(900));

	assert(it->first == 50 && it->second == 500);
	assert(stdit->first == 50 && stdit->second == 500);
	assert(m.size() == stdm.size());
	
	stdit = stdm.begin();
	for (it = m.begin(); it != m.end(); ++it, ++stdit)
		assert(it->first == stdit->first && it->second == stdit->second);

	assert(stdit == stdm.end());
	
}

void test_map_clear(void)
{

	map<int, int> m;

	m.clear();
	assert(m.size() == 0 && m.begin() == m.end());
	for (int i = 0; i < 1000; ++i)
	{
		m.insert(make_pair(i, 10 * i));
	}

	m.clear();
	assert(m.size() == 0 && m.begin() == m.end());
	for (int i = 0; i < 1000; ++i)
	{
		m.insert(make_pair(i, 10 * i));
	}
	m.clear();
	assert(m.size() == 0 && m.begin() == m.end());
	m.clear();
	assert(m.size() == 0 && m.begin() == m.end());
}

void test_map_swap(void)
{
	map<std::string, int> m1;
	map<std::string, int>::iterator it1;
	map<std::string, int>::iterator it2;

	{
		map<std::string, int> m2;

		m1.insert(make_pair("1", 1));
		m1.insert(make_pair("2", 2));
		m1.insert(make_pair("3", 3));

		m1.swap(m2);

		assert(m1.size() == 0 && m1.begin() == m1.end());
		assert(m2.size() == 3 && m2.begin()->first == "1" && (--m2.end())->second == 3);

		m1.insert(make_pair("4", 4));
		m1.insert(make_pair("5", 5));

		m1.swap(m2);

		assert(m1.size() == 3 && m1.begin()->first == "1" && (--m1.end())->second == 3);
		assert(m2.size() == 2 && m2.begin()->first == "4" && (--m2.end())->second == 5);
	}

	assert(m1.size() == 3 && m1.begin()->first == "1" && (--m1.end())->second == 3);
}

void test_map_find(void)
{
	map<int, int> m;
	map<int, int>::iterator it;

	assert(m.size() == 0 && m.begin() == m.end());
	for (int i = 0; i < 1000; ++i)
	{
		m.insert(make_pair(i, 10 * i));
	}

	it = m.find(10);
	assert(it->first == 10 && it->second == 100);
	assert((++it)->first == 11 && it->second == 110);
	
	it = m.find(111);
	assert(it->first == 111 && it->second == 1110);
	assert((++it)->first == 112 && it->second == 1120);

	it = m.find(-100);
	assert(it == m.end());

	it = m.find(0);
	assert(it == m.begin());
	
	it = m.find(10000);
	assert(it == m.end());

	
	m.erase(10);
	it = m.find(10);
	assert(it == m.end());
	
	m.insert(make_pair(10, 10));
	it = m.find(10);
	assert(it->first == 10);

	m.insert(make_pair(10, 20));
	it = m.find(10);
	assert(it->first == 10 && it->second == 10);

	{
		const map<int, int> cm(m.begin(), m.end());
		map<int, int>::const_iterator it;

		it = m.find(10);
		assert(it->first == 10 && it->second == 10);
		assert((++it)->first == 11 && it->second == 110);
	
		it = m.find(111);
		assert(it->first == 111 && it->second == 1110);
		assert((++it)->first == 112 && it->second == 1120);

		it = m.find(-100);
		assert(it == m.end());

		it = m.find(0);
		assert(it == m.begin());
	
		it = m.find(10000);
		assert(it == m.end());
	}
}

void test_map_count(void)
{
	map<int, int> m;
	map<int, int>::iterator it;

	assert(m.size() == 0 && m.begin() == m.end());
	for (int i = 0; i < 1000; ++i)
	{
		m.insert(make_pair(i, 10 * i));
	}
	const map<int, int> cm(m.begin(), m.end());

	for(int i = -100; i < 0; ++i)
		assert(cm.count(i) == 0);
	for(int i = 0; i < 100; ++i)
		assert(cm.count(i) == 1);
	for(int i = 1000; i < 1100; ++i)
		assert(cm.count(i) == 0);

}

void test_map_equal_range(void)
{
	map<int, int> m;
	map<int, int>::iterator it;

	assert(m.size() == 0 && m.begin() == m.end());
	for (int i = 0; i < 1000; ++i)
	{
		m.insert(make_pair(i, 10 * i));
	}
	const map<int, int> cm(m.begin(), m.end());

	pair<map<int,int>::iterator, map<int,int>::iterator> p;
	pair<map<int,int>::const_iterator, map<int,int>::const_iterator> cp;

	for(int i = -100; i < 0; ++i)
	{
		p = m.equal_range(i);
		assert(p.first == m.begin() && p.second == m.begin());
	}
	for(int i = 0; i < 100; ++i)
	{
		p = m.equal_range(i);
		assert(p.first->first == i && p.second->first != i);
		assert(distance(p.first, p.second) == 1);
	}
	for(int i = 1000; i < 1100; ++i)
	{
		p = m.equal_range(i);
		assert(p.first == m.end() && p.second == m.end());
	}


	for(int i = -100; i < 0; ++i)
	{
		cp = cm.equal_range(i);
		assert(cp.first == cm.begin() && cp.second == cm.begin());
	}
	for(int i = 0; i < 100; ++i)
	{
		cp = cm.equal_range(i);
		assert(cp.first->first == i && cp.second->first != i);
		assert(distance(cp.first, cp.second) == 1);
	}
	for(int i = 1000; i < 1100; ++i)
	{
		cp = cm.equal_range(i);
		assert(cp.first == cm.end() && cp.second == cm.end());
	}

}

void test_map_compare(void)
{
	map<std::string, int>::key_compare kp;
	map<std::string, int> m;

	m["123"] = 1;
	m["94123"] = 3;

	const map<std::string, int> cm(m.begin(), m.end());

	kp = cm.key_comp(); 
	assert(kp(cm.begin()->first, (++(cm.begin()))->first) == true);

	map<std::string, int>::value_compare vp = cm.value_comp();
	assert(vp(*cm.begin(), *++cm.begin()));
	
}

void test_map_relops(void)
{
	map<std::string, int> m1, m2;

	m1["1"] = 1;
	m1["2"] = 2;
	m2["1"] = 1;
	m2["2"] = 2;
	
	assert(m1 == m2);
	assert(m1 <= m2);
	assert(m1 >= m2);

	m2.erase("2");
	m2["3"] = 3;

	assert(m1 != m2);
	assert(m1 < m2); 
	assert(m2 > m1); 
	assert(m1 <= m2); 
	assert(m2 >= m2); 
}

void test_swap(void)
{
	map<std::string, int> m1, m2;

	m1["1"] = 1;
	m1["2"] = 2;
	m2["3"] = 1;
	m2["4"] = 2;
	
	ft::swap(m1, m2);
	assert(m1.begin()->first == "3");
	assert(m2.begin()->first == "1");
}

void test_map_assign(void)
{
	map<std::string, int> m1;

	m1["1"] = 1;
	m1["2"] = 2;
	{
		map<std::string, int> m2;
		m2["3"] = 1;
		m2["4"] = 2;
		m1 = m2;
	}
	assert(m1.begin()->first == "3");
	assert((++m1.begin())->first == "4");
}

bool fncomp (std::string lhs, std::string rhs) {return lhs<rhs;}

void test_set_constructors(void)
{
	set<std::string> s1;

	less<std::string> comp;
	set<std::string> s2(comp);
	set<std::string, bool (*)(std::string, std::string)> s3(fncomp);

	std::allocator<std::string> al;
	set<std::string> s4(comp, al);


	std::string arr[] = {"1", "5", "4", "3", "6", "2" };
	set<std::string> s5(arr, arr + sizeof(arr) / sizeof(std::string));
	set<std::string> s6(arr, arr + sizeof(arr) / sizeof(std::string), comp);
	set<std::string> s7(arr, arr + sizeof(arr) / sizeof(std::string), comp, al);
}

void test_set_iterators(void)
{
	std::string arr[] = {"1", "5", "4", "3", "6", "2" };
	set<std::string> s(arr, arr + sizeof(arr) / sizeof(std::string));
	set<std::string>::iterator it;

	it = s.begin();
	assert(*it == "1");
	++it;
	assert(*it++ == "2");
	assert(*it == "3");
	++it; ++it; ++it; --it;
	assert(*it-- == "5");
	assert(*it-- == "4");
	assert(*(--s.end()) == "6");

	const set<std::string> cs(s.begin(), s.end());
	set<std::string>::iterator cit;
	cit = cs.begin();
	assert(*cit == "1");
	++cit;
	assert(*cit++ == "2");
	assert(*cit == "3");
	++cit; ++cit; ++cit; --cit;
	assert(*cit-- == "5");
	assert(*cit-- == "4");
	assert(*(--cs.end()) == "6");

	set<std::string>::reverse_iterator rit;
	rit = s.rbegin();
	assert(*rit == "6");
	assert(*--s.rend() == "1");

	set<std::string>::const_reverse_iterator crit;
	crit = cs.rbegin();
	assert(*crit == "6");
	assert(*--cs.rend() == "1");
}

void test_set_assign(void)
{
	int arr1[] = { 10, 2, 5, 8, 7};
	int arr2[] = { 4, 100, -15};
	set<int> s1(arr1, arr1 + sizeof(arr1) / sizeof(int));

	{
		set<int> s2(arr2, arr2 + sizeof(arr2) / sizeof(int));

		assert(s1.size() != s2.size());
		assert(s1 != s2);
		
		s1 = s2;
		assert(s1.size() == s2.size());
		assert(s1 == s2);
		assert(s1.begin() != s2.begin());
		assert(*s1.begin() == *s2.begin());
	}
	assert(*s1.begin() == -15 && *--s1.end() == 100);
}

void test_set_capacity(void)
{
	int arr[] = { 10, 2, 5, 8, 7};

	const set<int> ces;
	assert(ces.empty() == true);
	assert(ces.size() == 0);

	const set<int> cs(arr, arr + sizeof(arr) / sizeof(int));

	assert(cs.empty() == false);
	assert(cs.size() == sizeof(arr) / sizeof(int));
	
	assert(cs.max_size() > cs.size());
}

void test_set_insert(void)
{
	set<int> s;
	typedef set<int>::iterator sIt;
	sIt tmp1, tmp2, tmp3;
	pair<sIt, bool> p;
	
	for (int i = 20; i < 40; ++i)
	{
		p = s.insert(i);
		assert(p.second == true);
		assert(p.first == s.begin() || p.first == --s.end() ||
			   *p.first < *++p.first);
	}
	tmp1 = s.begin();
	assert(*tmp1 == 20);

	tmp2 = s.insert(80).first;
	for (int i = 81; i < 100; ++i)
	{
		p = s.insert(i);
		assert(p.second == true);
		assert(p.first == s.begin() || p.first == --s.end() ||
			   *p.first > *--p.first);
	}
	assert(*tmp2 == 80);

	for (int i = 0; i < 20; ++i)
	{
		p = s.insert(i);
		assert(p.second == true);
		assert(p.first == s.begin() || p.first == --s.end() ||
			   *p.first < *++p.first);
	}
	tmp3 = s.begin();
	assert(*tmp3 == 0);

	for (int i = 40; i < 80; ++i)
	{
		p = s.insert(i);
		assert(p.second == true);
		assert(p.first == s.begin() || p.first == --s.end() ||
			   *p.first > *--p.first);
	}

	for (int i = 0; i < 100; ++i)
	{
		p = s.insert(i);
		assert(p.second == false);
		assert(*p.first == i);
	}

	assert(*tmp1 == 20 && *tmp2 == 80 && *tmp3 == 0);
}

void test_set_insert_position(void)
{
	set<int> s;
	set<int>::iterator it, tmp1, tmp2;

	for (int i = 20; i < 30; ++i)
	{
		it = s.insert(s.begin(), i);
		assert(*it == i);
	}
	tmp1 = ++s.begin();
	assert(*tmp1 == 21);
	for (int i = 0; i < 10; ++i)
	{
		it = s.insert(--s.end(), i);
		assert(*it == i);
	}
	tmp2 = s.begin();
	std::advance(tmp2, 15);
	assert(*tmp2 == 25);
	for (int i = 10; i < 20; ++i)
	{
		it = s.begin();
		std::advance(it, i);
		it = s.insert(it, i);
		assert(*it == i);
	}

	assert(*tmp1 == 21);
	assert(*tmp2 == 25);

	for (int i = 0; i < 30; ++i)
	{
		it = s.begin();
		advance(it, i);
		it = s.insert(it, i);
		assert(*it == i);
	}

	assert(*tmp1 == 21);
	assert(*tmp2 == 25);
}

void test_set_insert_range(void)
{
	int arr1[] = { 19, 4, 0, 5, 17, 1};
	int arr2[] = {18, 2, 15, 16, 3, 11, 12, 7, 6, 10, 8, 13,14, 9};

	set<int> s;
	set<int>::iterator it;

	s.insert(arr1, arr1 + sizeof(arr1) / sizeof(int));
	it = s.begin();
	advance(it, 4);
	assert(*it == 17);

	s.insert(arr2, arr2 + sizeof(arr2) / sizeof(int));
	assert(*it == 17);

	it = s.begin();
	for (int i = 0; i < 20; ++it, ++i)
		assert(*s.find(i) == i);
}

void test_set_erase_position(void)
{
	std::set<int> ss;

	for(int i = 0; i < 100; ++i)
		ss.insert(i);

	set<int> s(ss.begin(), ss.end());

	set<int>::iterator it, tmp1, tmp2;
	std::set<int>::iterator sit;

	tmp1 = s.find(33);
	tmp2 = s.find(58);

	for (int i = 0; i < 100; i += 7)
	{
		it = s.find(i);
		sit = ss.find(i);
		s.erase(it);
		ss.erase(sit);
	}

	assert(*tmp1 == 33);
	assert(*tmp2 == 58);

	it = s.begin();
	sit = ss.begin();
	for (; it != s.end(); ++it, ++sit)
		assert(*it == *sit);
	assert(sit == ss.end());
}

void test_set_erase(void)
{
	set<int> s;
	std::set<int> ss;

	for (int i = 0; i < 1000; ++i)
	{
		s.insert(i);
		ss.insert(i);
	}

	set<int>::iterator it = s.begin();
	advance(it, 777);
	set<int>::const_iterator cit = s.begin();
	advance(cit, 333);

	for (int i = 0; i < 1000; i += 2)
	{
		s.erase(i);
		ss.erase(i);
	}

	assert(*it == 777);
	assert(*cit == 333);

	it = s.begin();
	std::set<int>::iterator sit = ss.begin();

	for(; sit != ss.end(); ++sit, ++it)
		assert(*it == *sit);
	assert(ss.size() == s.size());
}

void test_set_erase_range(void)
{
	set<int> s;
	std::set<int> ss;

	for (int i = 0; i < 1000; ++i)
	{
		s.insert(i);
		ss.insert(i);
	}

	set<int>::iterator start, finish, tmp;
	start = s.begin();
	std::advance(start, 444);
	finish = s.begin();
	std::advance(finish, 777);
	tmp = s.begin();
	std::advance(tmp, 123);
	assert(*tmp == 123);

	std::set<int>::iterator sstart, sfinish;
	sstart = ss.begin();
	std::advance(sstart, 444);
	sfinish = ss.begin();
	std::advance(sfinish, 777);

	s.erase(start, finish);
	ss.erase(sstart, sfinish);

	assert(*tmp == 123);

	start = s.begin();
	sstart = ss.begin();
	for(; start != s.end(); ++start, ++sstart)
		assert(*start == *sstart);
	assert(sstart == ss.end());

}

void test_set_swap(void)
{
	set<int> lhs;

	for(int i = 0; i < 100; ++i)
		lhs.insert(i);
	{
		set<int> rhs;
		for(int i = 1000; i < 1200; ++i)
			rhs.insert(i);
		
		lhs.swap(rhs);
		for(int i = 0; i < 100; ++i)
			assert(rhs.insert(i).second == false);
	}
	for(int i = 1000; i < 1200; ++i)
		assert(lhs.insert(i).second == false);

	set<int> rhs;
	lhs.swap(rhs);
	assert(lhs.size() == 0);
}

void test_set_clear(void)
{
	set<int> s;

	s.clear();
	assert(s.size() == 0 && s.empty() == true);
	assert(s.begin() == s.end());
	for(int i = 0; i < 100; ++i)
		s.insert(i);
	assert(s.size() != 0 && s.empty() == false);
	assert(s.begin() != s.end());
	s.clear();
	assert(s.size() == 0 && s.empty() == true);
	assert(s.begin() == s.end());
}

void test_set_find(void)
{
	set<int> s;

	for(int i = 0; i < 100; ++i)
		s.insert(2 * i);

	for (int i = -10; i < 0; ++i)
		assert(s.find(i) == s.end());
	for (int i = 1; i < 200; i += 2)
		assert(s.find(i) == s.end());
	for (int i = 0; i < 200; i += 2)
		assert(*s.find(i) == i);
	for (int i = 200; i < 250; i += 2)
		assert(s.find(i) == s.end());
}

void test_set_lower_bound(void)
{
	//std::cout << "test_set_lower_bound\n";
	set<int> s;

	for(int i = 0; i < 100; ++i)
		s.insert(2 * i);

	for (int i = -10; i < 0; ++i)
		assert(s.lower_bound(i) == s.begin());
	for (int i = 1; i < 199; i += 2)
		assert(*s.lower_bound(i) == i + 1);
	for (int i = 0; i < 200; i += 2)
		assert(*s.lower_bound(i) == i);
	for (int i = 199; i < 250; i += 2)
		assert(s.lower_bound(i) == s.end());
}

void test_set_upper_bound(void)
{
	//std::cout << "test_set_upper_bound\n";
	set<int> s;

	for(int i = 0; i < 100; ++i)
		s.insert(2 * i);

	for (int i = -10; i < 0; ++i)
		assert(s.upper_bound(i) == s.begin());
	for (int i = 1; i < 199; i += 2)
		assert(*s.upper_bound(i) == i + 1);
	for (int i = 0; i < 198; i += 2)
		assert(*s.upper_bound(i) == i + 2);
	for (int i = 198; i < 250; i += 2)
		assert(s.upper_bound(i) == s.end());
}

void test_set_equal_range(void)
{

  set<int> myset;

  for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

  pair<set<int>::const_iterator,set<int>::const_iterator> ret;
  ret = myset.equal_range(30);

  assert(*ret.first == 30);
  assert(*ret.second == 40);
}
