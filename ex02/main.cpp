#include "MutantStack.hpp"
#include <iostream>

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		cout << mstack.top() << endl;
		mstack.pop();
		cout << mstack.size() << endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			cout << *it << endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	cout << endl;
	{
		MutantStack<int, vector<int> > mstack;
		mstack.push(5);
		mstack.push(17);
		cout << mstack.top() << endl;
		mstack.pop();
		cout << mstack.size() << endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int, vector<int> >::iterator it = mstack.begin();
		MutantStack<int, vector<int> >::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			cout << *it << endl;
			++it;
		}
		std::stack<int, vector<int> > s(mstack);
	}
	return 0;
}
