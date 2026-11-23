#include "../include/IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource() {
    // std::cout << "IMateriaSource deffault constructor called\n";
}

IMateriaSource::IMateriaSource(const IMateriaSource &src) {
    // std::cout << "IMateriaSource copy constructor called\n";
    *this = src;
}

IMateriaSource  &IMateriaSource::operator=(const IMateriaSource &src) {
    // std::cout << "IMateriaSource operator = called\n";
    (void)src;
    return *this;
}

