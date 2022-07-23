#include <iostream>
#include <fstream>
#include <cassert>
#include <iterator>
#include <vector>
#include "utils.hpp"
#include "vector.hpp"

#ifndef STL
#define STL 0
#endif

#if STL==0
using namespace ft;
#else
using namespace std;
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
void test_vector(void);
void test_vector_constructor(void);
void test_vector_operator_assign(void);
void test_vector_assign(void);
void test_vector_get_allocator(void);

int main(void)
{
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
	vector<int, std::allocator<int> > v1(all);
	std::allocator<int> tmp2 = v1.get_allocator();
	vector<int, std::allocator<char> > v2(all);
	std::allocator<int> tmp3 = v2.get_allocator();

	int *ptr = v.get_allocator().allocate(5);
	ptr[4] = 100;
	v.get_allocator().deallocate(ptr, 5);}
