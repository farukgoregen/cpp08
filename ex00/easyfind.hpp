#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int toFind) {
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end()) {
        throw std::out_of_range("Value not found in container!");
    }
    return it;
}

#endif