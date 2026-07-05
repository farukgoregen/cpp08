#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void) {
    std::cout << "=== Vector Test ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        std::cout << "Searching for 20..." << std::endl;
        std::vector<int>::iterator it = ::easyfind(vec, 20);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Searching for 99 (Should fail)..." << std::endl;
        ::easyfind(vec, 99);
    } 
    catch (const std::exception& e) {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== List Test ===" << std::endl;
    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(100);

    try {
        std::cout << "Searching for 42..." << std::endl;
        std::list<int>::iterator it = ::easyfind(lst, 42);
        std::cout << "Found: " << *it << std::endl;
    } 
    catch (const std::exception& e) {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}