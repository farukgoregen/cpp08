#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <climits>

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span& src) {
    *this = src;
}

Span& Span::operator=(const Span& rhs) {
    if (this != &rhs) {
        this->maxSize = rhs.maxSize;
        this->numbers = rhs.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::out_of_range("Span is full!");
    }
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers!");
    }

    std::vector<int> tmp = numbers;
    std::sort(tmp.begin(), tmp.end());

    unsigned int minDiff = UINT_MAX;
    
    for (size_t i = 0; i < tmp.size() - 1; i++) {
        unsigned int diff = tmp[i + 1] - tmp[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers!");
    }

    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal = *std::max_element(numbers.begin(), numbers.end());

    return static_cast<unsigned int>(maxVal - minVal);
}