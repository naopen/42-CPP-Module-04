#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure created" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Cure copied" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure Assignment Operator Called" << std::endl;
    AMateria::operator=(other);
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destroyed" << std::endl;
}

AMateria* Cure::clone() const {
    std::cout << "Cure cloned" << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
