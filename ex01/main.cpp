#include "Span.hpp"
#include <iostream>

int main(void) {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 2
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;  // 14
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    try {
        Span bigSpan(11000);
        std::vector<int> testData;

        for (int i = 0; i < 10500; i++) {
            testData.push_back(i * 2);
        }
        bigSpan.addNumbers(testData.begin(), testData.end());

        std::cout << "Big Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Longest:  " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}