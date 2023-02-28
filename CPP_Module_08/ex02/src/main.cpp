#include "../inc/Mutantstack.hpp"

// Stacks are a type of container adaptors with LIFO(Last In First Out) 
// type of working, where a new element is added at one end (top)
// and an element is removed from that end only.

int main()
{
    std::cout << "====================================" << std::endl;
    std::cout << "CREATING MUTANT STACK" << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    std::cout << mstack.top() << std::endl;
    mstack.push(17);
    mstack.pop();
    std::cout << mstack.top() << std::endl;
    mstack.push(737);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    mstack.push(3);
    mstack.push(5);
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "====================================" << std::endl;
    std::cout << "CREATING LIST" << std::endl;
    std::list<int> list;
    list.push_back(1);
    std::cout << list.front() << std::endl;
    list.push_back(17);
    list.pop_back();
    std::cout << list.front() << std::endl;
    list.push_back(737);
    std::cout << list.back() << std::endl;
    list.pop_back();
    list.push_back(3);
    list.push_back(5);
    std::cout << "size: " << list.size() << std::endl;
    list.push_back(0);
    std::list<int>::iterator it1 = list.begin();
    std::list<int>::iterator ite1 = list.end();
    ++it1;
    --it1;
    while (it1 != ite1)
    {
    std::cout << *it1 << std::endl;
    ++it1;
    }
    std::list<int> s1(list);
    std::cout << "====================================" << std::endl;
    return 0;
}
