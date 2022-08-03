#include <iostream>
#include <fstream>
#include <cassert>
#include <iterator>
#include <vector>
#include <stack>
#include <map>
#include "utils.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

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
void test_map_iterator(void);
void test_map_capacity(void);
void test_map_access(void);
void test_map_insert_value(void);
void test_map_insert_position(void);

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
//	test_vector();
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
	std::fstream f("test1.txt", std::fstream::in);
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
	std::fstream fs("test1.txt", std::fstream::in);
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
	std::fstream fs("test1.txt", std::fstream::in);
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

	vector<int, std::allocator<int> > v;
	std::allocator<int> tmp1 = v.get_allocator();
#if __cplusplus < 201103L
	vector<int, std::allocator<int> > v1(all);
	std::allocator<int> tmp2 = v1.get_allocator();
	vector<int, std::allocator<char> > v2(all);
	std::allocator<int> tmp3 = v2.get_allocator();
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
	assert(v.size() == 14 && v.capacity() == 16);
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
	std::fstream f("test1.txt", std::fstream::in);
	std::istream_iterator<int> it(f);
	v.insert(v.begin(), 0);
	v.insert(v.begin(), 0);
	v.insert(v.begin() + 1, it, std::istream_iterator<int>());
	assert(v.front() == 0);
	assert(v.back() == 0);
	for(int i(1); i < 6; ++i)
		assert(v[i] == i);
	f.close();
	std::fstream f2("test1.txt", std::fstream::in);
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
	swap(v1, v2);
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

	swap(v1, v2);
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
