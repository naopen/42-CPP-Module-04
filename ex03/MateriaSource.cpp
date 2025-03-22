#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource created" << std::endl;
    for (int i = 0; i < 4; i++) {
        _learned[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copied" << std::endl;
    // Deep copy of learned materias
    for (int i = 0; i < 4; i++) {
        if (other._learned[i]) {
            _learned[i] = other._learned[i]->clone();
        } else {
            _learned[i] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource Assignment Operator Called" << std::endl;
    if (this != &other) {
        // Delete current learned materias
        for (int i = 0; i < 4; i++) {
            if (_learned[i]) {
                delete _learned[i];
                _learned[i] = nullptr;
            }
        }

        // Deep copy from other
        for (int i = 0; i < 4; i++) {
            if (other._learned[i]) {
                _learned[i] = other._learned[i]->clone();
            } else {
                _learned[i] = nullptr;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destroyed" << std::endl;
    // Clean up learned materias
    for (int i = 0; i < 4; i++) {
        if (_learned[i]) {
            delete _learned[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        std::cout << "MateriaSource tried to learn null materia" << std::endl;
        return;
    }

    // Find first empty slot
    for (int i = 0; i < 4; i++) {
        if (!_learned[i]) {
            std::cout << "MateriaSource learned " << m->getType() << " in slot " << i << std::endl;
            _learned[i] = m;
            return;
        }
    }
    // If no space available, do nothing (but don't delete)
    std::cout << "MateriaSource memory full, can't learn more materias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    std::cout << "MateriaSource trying to create materia of type: " << type << std::endl;
    // Find materia with matching type and clone it
    for (int i = 0; i < 4; i++) {
        if (_learned[i] && _learned[i]->getType() == type) {
            std::cout << "MateriaSource found matching type, creating materia" << std::endl;
            return _learned[i]->clone();
        }
    }
    // Return nullptr if type not found
    std::cout << "MateriaSource couldn't find materia of type: " << type << std::endl;
    return nullptr;
}
