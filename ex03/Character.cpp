#include "Character.hpp"

Character::Character(const std::string& name) : _name(name) {
    std::cout << "Character created: " << _name << std::endl;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = nullptr;
    }
}

Character::Character(const Character& other) : _name(other._name) {
    std::cout << "Character copied: " << _name << std::endl;
    // Deep copy of inventory
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        } else {
            _inventory[i] = nullptr;
        }
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character Assignment Operator Called: " << _name << " = " << other._name << std::endl;
    if (this != &other) {
        _name = other._name;

        // Delete current inventory before deep copying
        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) {
                delete _inventory[i];
                _inventory[i] = nullptr;
            }
        }

        // Deep copy new inventory
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            } else {
                _inventory[i] = nullptr;
            }
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destroyed: " << _name << std::endl;
    // Clean up inventory
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) {
            delete _inventory[i];
        }
    }
}

std::string const& Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        std::cout << "Character " << _name << " tried to equip null materia" << std::endl;
        return;
    }

    // Find first empty slot
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            std::cout << "Character " << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
            _inventory[i] = m;
            return;
        }
    }
    // If inventory is full, we do nothing as required
    std::cout << "Character " << _name << " has full inventory, can't equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        std::cout << "Character " << _name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
        // Don't delete, just unequip as required
        _inventory[idx] = nullptr;
    } else {
        std::cout << "Character " << _name << " failed to unequip slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        std::cout << "Character " << _name << " uses materia in slot " << idx << " on " << target.getName() << std::endl;
        _inventory[idx]->use(target);
    } else {
        std::cout << "Character " << _name << " failed to use materia in slot " << idx << std::endl;
    }
}
