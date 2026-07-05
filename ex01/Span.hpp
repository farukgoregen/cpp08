#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>
#include <cstddef>
#include <iterator>

class Span {
private:
    unsigned int      maxSize;
    std::vector<int>  numbers;

    Span();

public:
    Span(unsigned int n);
    Span(const Span& src);
    Span& operator=(const Span& rhs);
    ~Span();

    void addNumber(int number);

    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
        size_t distance = std::distance(begin, end);
        
        if (numbers.size() + distance > maxSize) {
            throw std::out_of_range("Capacity exceeded!");
        }
        
        numbers.insert(numbers.end(), begin, end);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};

#endif