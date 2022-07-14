#include <iostream>
#include <cassert>
#include <iterator>
#include "utils.hpp"

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
void test_is_integral(void);
void test_enable_if(void);
void test_equal(void);
void test_lexicograhical_compare(void);

int main(void)
{
	test_traits();
	test_advance_and_distance();
	test_reverse_iterator();
	test_is_integral();
	test_enable_if();
	test_equal();
	test_lexicograhical_compare();

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
