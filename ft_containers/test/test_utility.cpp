#include "ft_utility.hpp"

#include <assert.h>
#include <iostream>
#include <utility>

using namespace ft;
//using namespace std;

typedef pair<int, char> Pair_ic;
Pair_ic p0;

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

	// TEST <utility> (тестирование <utility>)

int main(void)
{
	Pair_ic p1 = p0;
	Pair_ic p2(3, 'a');

	// TEST pair

	assert (p1.first == 0) ;
	assert (p1.second == 0);
	assert (p2.first == 3);
	assert (p2.second = 'a');
	assert (p2 == make_pair((Pair_ic::first_type) 3, (Pair_ic::second_type) 'a'));
	assert (p2 < make_pair((Pair_ic::first_type) 4, (Pair_ic::second_type) 'a'));
	assert (p2 < make_pair ((Pair_ic::first_type) 3, (Pair_ic::second_type) 'b'));
	assert (p1 != p2);
	assert (p2 > p1);
	assert (p2 <= p2);
	assert (p2 >= p2);

	// TEST rel_ops
	using namespace ft::rel_ops;
	//using namespace std::rel_ops;
	Int a(2), b(3);

	assert (a == a);
	assert (a < b);
	assert (a != b);
	assert (b > a);
	assert (a <= b);
	assert (b >= a);

	std::cout << "SUCCESS testing <utility>\n";

	return (0);
}
