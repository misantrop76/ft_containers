#include "../map.hpp"
#include <string>
#include <iostream>
#include <map>
#include "../stack.hpp"
#include <list>
#include <deque>
#include <vector>
#include <stack>
#include <set>
#include "../vector.hpp"

#define PURPLE "\e[36m"
#define GREEN "\e[34m"
#define REDD "\e[32;1m"
#define RESET "\e[0m"

void contructors()
{
	std::cout << REDD << "DEFAULT CONSTRUCTOR" << std::endl;

	ft::vector<char> tab;
	tab.push_back('c');
	tab.push_back('b');
	tab.push_back('a');

	ft::vector<char>::iterator it = tab.begin();

	while (it != tab.end())
		std::cout << PURPLE << *it++ << ' ';
	std::cout << " - ft" << std::endl;

	/*------------------------------------------------------------*/
	
	std::cout << REDD << "FILL CONSTRUCTOR" << std::endl;

	ft::vector<int> fill(10, 5);

	ft::vector<int>::iterator fillIt = fill.begin();

	while (fillIt != fill.end())
		std::cout << PURPLE << *fillIt++ << ' ';
	std::cout << " - ft" << std::endl;

	/*------------------------------------------------------------*/

	std::cout << REDD << "RANGE CONSTRUCTOR" << std::endl;

	ft::vector<int> range(fill.begin(), fill.end());

	ft::vector<int>::iterator rangeIt = range.begin();

	while (rangeIt != range.end())
		std::cout << PURPLE << *rangeIt++ << ' ';
	std::cout << " - ft" << std::endl;

	/*------------------------------------------------------------*/

	std::cout << REDD << "COPY CONSTRUCTOR" << std::endl;

	ft::vector<std::string> cop(5, "yo");

	ft::vector<std::string> copy(cop);

	ft::vector<std::string>::iterator copyIt = copy.begin();

	while (copyIt != copy.end())
		std::cout << PURPLE << *copyIt++ << ' ';
	std::cout << " - ft" << std::endl;

	std::cout << REDD << "OPERATOR = " << std::endl;

	ft::vector<std::string> o1(5, "hey");

	ft::vector<std::string> o3 = o1;
	ft::vector<std::string>::iterator oit = o3.begin();

	while (oit != o3.end())
		std::cout << PURPLE << *oit++ << ' ';
	std::cout << " - ft" << std::endl;
	std::cout << std::endl;
}

void iterators()
{
	std::cout << REDD << "ITERATORS" << std::endl;

	ft::vector<char> tab;

	for (int i = 65; i < 85; i++)
		tab.push_back(i);
	ft::vector<char>::iterator it = tab.begin();
	while (it != tab.end())
		std::cout << PURPLE << *it++ << ' ';
	std::cout << " - ft" << std::endl;

	/*------------------------------------------------------------*/
	
	std::cout << REDD << "CONST ITERATORS" << std::endl;
	
	ft::vector<char>::const_iterator cit = --it;

	std::cout << PURPLE << *cit << "  - ft" << std::endl;

	/*------------------------------------------------------------*/
	std::cout << REDD << "REVERSE ITERATORS" << std::endl;
	ft::vector<char> rtab;
	
	for (int i = 65; i < 85; i++)
		rtab.push_back(i);
	ft::vector<char>::reverse_iterator rit = rtab.rbegin();
	while (rit != rtab.rend())
		std::cout << PURPLE << *rit++ << ' ';
	std::cout << " - ft" << std::endl;

	/*------------------------------------------------------------*/
	
	std::cout << REDD << "CONST REVERSE ITERATORS" << std::endl;
	
	ft::vector<char>::const_reverse_iterator rcit = --rit;

	std::cout << PURPLE << *rcit << "  - ft" << std::endl;

	std::cout << std::endl;
}

void capacity()
{
	std::cout << REDD << "CAPACITY" << std::endl;
	
	ft::vector<int> tab(5, 10);

	std::cout << PURPLE << "size : " << tab.size() << "  - ft" << std::endl;

	tab.resize(10, 10);

	for (int i = 0; i < 10; i++)
		std::cout << PURPLE << tab[i] << ' ';
	std::cout << " - ft" << std::endl;

	std::cout << PURPLE << "is empty : " << tab.empty() << "  - ft" << std::endl;

	tab.reserve(20);

	std::cout << PURPLE << "capacity : " << tab.capacity() << "  - ft" << std::endl;

	std::cout << std::endl;
}

void	access()
{
	std::cout << REDD << "ELEMENT ACCESS" << std::endl;
	ft::vector<char> tab;
	for (int i = 65; i < 85; i++)
		tab.push_back(i);

	std::cout << PURPLE << "tab[3] : " << tab[3] << "  - ft" << std::endl;

	std::cout << PURPLE << "tab at 3 : " << tab.at(3) << "  - ft" << std::endl;

	std::cout << PURPLE << "front : " << tab.front() << "  - ft" << std::endl;

	std::cout << PURPLE << "back : " << tab.back() << "  - ft" << std::endl;

	std::cout << std::endl;
}

void printTab(ft::vector<int> &tab)
{
	std::cout << PURPLE << "tab : ";
	for (size_t i = 0; i < tab.size(); i++)
		std::cout << PURPLE << tab[i] << ' ';
	std::cout << " - ft" << std::endl;
}

void	modifiers()
{
	std::cout << REDD << "MODIFIERS" << std::endl;

	ft::vector<int> tab(3, 2);
	printTab(tab);
	
	std::cout << PURPLE << "push_back(5) : ";
	tab.push_back(5);
	printTab(tab);

	std::cout << PURPLE << "pop_back : ";
	tab.pop_back();
	printTab(tab);

	std::cout << PURPLE << "assign two 3 : ";
	tab.assign(2, 3);
	printTab(tab);

	std::cout << PURPLE << "insert 1 : ";
	tab.insert(tab.begin(), 1);
	printTab(tab);

	std::cout << PURPLE << "erase 1 : ";
	tab.erase(tab.begin());
	printTab(tab);

	std::cout << PURPLE << "clear : ";
	tab.clear();
	printTab(tab);

	ft::vector<int> a(3, 10);
	ft::vector<int> b(5, 7);
	
	std::cout << PURPLE << "a : ";
	printTab(a);
	std::cout  << "b : ";
	printTab(b);
	std::cout << RESET << "swap" << std::endl;
	a.swap(b);
	std::cout << PURPLE << "a : ";
	printTab(a);
	std::cout << "b : ";
	printTab(b);

	std::cout << std::endl;
}

void operators()
{
	std::cout << REDD << "OPERATORS" << std::endl;

	std::cout << PURPLE << "ft - " << std::endl;
	ft::vector<int> foo (3,100);
	ft::vector<int> bar (2,200);
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void vector_test()
{
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "VECTOR TEST" << std::endl << std::endl;
	contructors();
	iterators();
	capacity();
	access();
	modifiers();
	operators();
	std::cout << "--------------------------------------------------------------------" << std::endl;
}


void map_constructors()
{
	std::cout << REDD << "DEFAULT CONSTRUCTOR" << std::endl;
	ft::map<char, int> m1;
	std::cout << RESET << "constructed" << std::endl;

	std::cout << REDD << "COPY CONSTRUCTOR" << std::endl;

	ft::map<char, int> mit;
	mit.insert(ft::make_pair('a', 1));
	mit.insert(ft::make_pair('c', 13));
	mit.insert(ft::make_pair('j', 3));

	ft::map<char, int> new_mit(mit);
	std::cout << PURPLE << new_mit['a'] << ' ' << new_mit['c'] << ' ' << new_mit['j'] << "  - ft" << std::endl;

	std::cout << REDD << "FILL CONSTRUCTOR" << std::endl;

	ft::map<char, int> f1(mit.begin(), mit.end());
	std::cout << PURPLE << f1['a'] << ' ' << f1['c'] << ' ' << f1['j'] << "  - ft" << std::endl;

	std::cout << REDD << "OPERATOR =" << std::endl;

	ft::map<char, int> o1 = f1;
	std::cout << PURPLE << o1['a'] << ' ' << o1['c'] << ' ' << o1['j'] << "  - ft" << std::endl;
	std:: cout << std::endl;
}

void map_iterator()
{
	ft::map<char, int> m1;

	for (int i = 65; i < 85; i++)
		m1.insert(ft::make_pair(i, 1));

	ft::map<char, int>::iterator it = m1.begin();
	ft::map<char, int>::const_iterator cit = ++m1.begin();
	ft::map<char, int>::reverse_iterator rit = m1.rbegin();
	ft::map<char, int>::const_reverse_iterator crit = ++m1.rbegin();


	std::cout << REDD << "ITERATORS" << std::endl;
	while (it != m1.end())
		std::cout << PURPLE << it++->first << ' ';
	std::cout << " - ft" << std::endl;


	std::cout << REDD << "CONST ITERATORS" << std::endl;
	std::cout << PURPLE << "const it : " << cit->first << "  - ft" << std::endl;

	std::cout << REDD << "REVERSE ITERATORS" << std::endl;
	while (rit != m1.rend())
		std::cout << PURPLE << rit++->first << ' ';
	std::cout << " - ft" << std::endl;


	std::cout << REDD << "CONST REVERSE ITERATORS" << std::endl;
	std::cout << PURPLE << "const rev it : " << crit->first << "  - ft" << std::endl;
	
	std::cout << std::endl;
}

void map_capacity()
{
	std::cout << REDD << "CAPACITY" << std::endl;

	ft::map<std::string, char> tab;
	
	tab.insert(ft::make_pair("hey", 'A'));
	tab.insert(ft::make_pair("kk", 'D'));
	tab.insert(ft::make_pair("lol", 'K'));


	std::cout << PURPLE << "size : " << tab.size() << "  - ft" << std::endl;

	std::cout << PURPLE << "empty : " << tab.empty() << "  - ft" << std::endl;

	std::cout << std::endl;
}

void map_access()
{
	std::cout << REDD << "ELEMENT ACCESS" << std::endl;
	
	ft::map<std::string, char> tab;
	
	tab.insert(ft::make_pair("hey", 'A'));
	tab.insert(ft::make_pair("kk", 'D'));
	tab.insert(ft::make_pair("lol", 'K'));

	std::cout << PURPLE << "tab[\"lol\"] : " << tab["lol"] << "  - ft" << std::endl;

	std::cout << std::endl;
}

void map_modifiers(int i)
{
	
	if (i == 0)
	{
		std::cout << REDD << "INSERT" << std::endl;
		std::cout << PURPLE;
		std::cout << "ft -" << std::endl;
		ft::map<char,int> mymap;

		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));
		mymap.insert (it, ft::pair<char,int>('c',400));


		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c')); //find operation used

		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}
}

void map_erase(int i)
{
	if (!i)
	{
		std::cout << REDD << "ERASE" << std::endl;
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase(it);

		mymap.erase('c');

		it=mymap.find('e');
		mymap.erase(it, mymap.end() );

		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
}

void map_swap(int i)
{
	if (!i)
	{
		std::cout << REDD << "SWAP" << std::endl;
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it = bar.begin(); it !=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	
}

void map_clear()
{
	std::cout << REDD << "CLEAR" << std::endl;
	ft::map<int, int> tab;

	tab.insert(ft::make_pair(1, 5));
	tab.insert(ft::make_pair(3, 8));
	tab.insert(ft::make_pair(5, 66));
	tab.insert(ft::make_pair(13, 5));


	std::cout << PURPLE << tab.size() << "  - ft" << std::endl;
	tab.clear();
	std::cout << PURPLE << "cleared : " << tab.size() << "  - ft" << std::endl;
}

void map_operations(int i)
{
	if (!i)
	{
		std::cout << REDD << "OPERATIONS" << std::endl;
		std::cout << PURPLE << "ft -" << std::endl;
		//COUNT
		ft::map<char,int> mymap;
		char c;

		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
		}
	}
}

void map_bound(int i)
{
	//BOUNDS
	if (!i)
	{
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow = mymap.lower_bound('b');
		itup = mymap.upper_bound('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);

		for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	else if (i == 2)
	{
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
}

void map_operators(int i)
{
	if (!i)
	{
		std::cout << REDD << "OPERATIONS" << std::endl;
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<int, char> alice;
		ft::map<int, char> bob;
		ft::map<int, char> eve;

		alice.insert(ft::make_pair(1, 'a'));
		alice.insert(ft::make_pair(2, 'b'));
		alice.insert(ft::make_pair(3, 'c'));

		bob.insert(ft::make_pair(7, 'Z'));
		bob.insert(ft::make_pair(8, 'Y'));
		bob.insert(ft::make_pair(9, 'X'));
		bob.insert(ft::make_pair(10, 'W'));
 
		eve.insert(ft::make_pair(1, 'a'));
		eve.insert(ft::make_pair(2, 'b'));
		eve.insert(ft::make_pair(3, 'c'));
 
		std::cout << std::boolalpha;
 
		std::cout << "alice == bob returns " << (alice == bob) << '\n';
		std::cout << "alice != bob returns " << (alice != bob) << '\n';
		std::cout << "alice <  bob returns " << (alice < bob) << '\n';
		std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
		std::cout << "alice >  bob returns " << (alice > bob) << '\n';
		std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
		std::cout << '\n';

		std::cout << "alice == eve returns " << (alice == eve) << '\n';
		std::cout << "alice != eve returns " << (alice != eve) << '\n';
		std::cout << "alice <  eve returns " << (alice < eve) << '\n';
		std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
		std::cout << "alice >  eve returns " << (alice > eve) << '\n';
		std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	}
}

void map_test()
{
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << RESET << "\nmap TEST" << std::endl << std::endl;
	map_constructors();
	map_iterator();
	map_capacity();
	map_access();
	map_modifiers(0);
	map_erase(0);
	map_swap(0);
	map_clear();
	map_operations(0);
	map_bound(0);
	map_bound(2);
	map_operators(0);
	std::cout << "--------------------------------------------------------------------" << std::endl;
}

void operators_stack()
{
	std::set<int> j;
	std::cout << PURPLE << "ft - " << std::endl;
	ft::stack<int> foo;
	ft::stack<int> bar;

	foo.push(4);
	foo.push(87);
	foo.push(54);

	bar.push(1);
	bar.push(12);
	bar.push(5);
	bar.push(87);
	bar.push(-1);

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void stack_test()
{
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << RESET << "\nSTACK TEST" << std::endl << std::endl;

	ft::stack<std::string> s1;

	
	std::cout << PURPLE << "empty : " << s1.empty() << "  - ft" << std::endl;

	std::cout << PURPLE << "size : " << s1.size() << "  - ft" << std::endl;

	std::cout << RESET << "push \'hey\' \'lol\' \'pouic\'" << std::endl;
	s1.push("hey");
	s1.push("lol");
	s1.push("pouic");

	std::cout << PURPLE << "empty : " << s1.empty() << "  - ft" << std::endl;

	std::cout << PURPLE << "size : " << s1.size() << "  - ft" << std::endl;

	std::cout << PURPLE << "top : " << s1.top() << "  - ft" << std::endl;

	std::cout << RESET << "pop" << std::endl;

	s1.pop();

	std::cout << PURPLE << "top : " << s1.top() << "  - ft" << std::endl;

	operators_stack();

	std::cout << RESET << "-----------------" << std::endl;

	std::cout << "with std vector" << std::endl;

	ft::stack<int, std::vector<int> > vec;

	vec.push(5);
	vec.push(7);
	vec.push(8);
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << PURPLE << vec.top() << ' ';
		vec.pop();
	}
	std::cout << std::endl;

	std::cout << RESET << "-----------------" << std::endl;

	std::cout << "with std deque" << std::endl;

	ft::stack<int, std::deque<int> > dec;

	dec.push(5);
	dec.push(7);
	dec.push(8);
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << PURPLE << dec.top() << ' ';
		dec.pop();
	}
	std::cout << std::endl;

	std::cout << RESET << "-----------------" << std::endl;

	std::cout << "with std list" << std::endl;

	ft::stack<int, std::deque<int> > lec;

	lec.push(5);
	lec.push(7);
	lec.push(8);
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << PURPLE << lec.top() << ' ';
		lec.pop();
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
}

int main(void)
{
    map_test();
	operators_stack();
	stack_test();
    vector_test();
	return 0;
}