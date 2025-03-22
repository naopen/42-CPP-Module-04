#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice created" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "Ice copied" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice Assignment Operator Called" << std::endl;
    AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice destroyed" << std::endl;
}

AMateria* Ice::clone() const {
    std::cout << "Ice cloned" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
