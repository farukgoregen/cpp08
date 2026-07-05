#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

// std::stack sınıfından miras alıyoruz
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Orthodox Canonical Form
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& src) : std::stack<T>(src) {}
    MutantStack& operator=(const MutantStack& rhs) {
        if (this != &rhs) {
            std::stack<T>::operator=(rhs);
        }
        return *this;
    }
    ~MutantStack() {}

    // İsimleri kısaltmak ve okunabilir kılmak için tip tanımlaması (typedef) yapıyoruz
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // begin() fonksiyonu çağrıldığında, arka plandaki 'c' kutusunun başlangıç adresini döner
    iterator begin() { 
        return this->c.begin(); 
    }
    
    // end() fonksiyonu çağrıldığında, arka plandaki 'c' kutusunun bitiş sınır adresini döner
    iterator end() { 
        return this->c.end(); 
    }

    // Salt okunur (const) nesneler için iterator adres desteği
    const_iterator begin() const { 
        return this->c.begin(); 
    }
    
    const_iterator end() const { 
        return this->c.end(); 
    }
};

#endif