#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    std::cout << "=== MutantStack Test ===" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl; // 17
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl; // 1
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Elements: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::stack<int> s(mstack);

    std::cout << "\n=== std::list Test (Birebir Ayni Olmali) ===" << std::endl;
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << "Top: " << mlist.back() << std::endl;
    
    mlist.pop_back();
    
    std::cout << "Size: " << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator it_l = mlist.begin();
    std::list<int>::iterator ite_l = mlist.end();
    
    ++it_l;
    --it_l;
    
    std::cout << "Elements: ";
    while (it_l != ite_l) {
        std::cout << *it_l << " ";
        ++it_l;
    }
    std::cout << std::endl;

    return 0;
}