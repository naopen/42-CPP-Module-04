#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    // Test from the subject
    std::cout << "===== Subject Test =====" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    // Additional tests
    std::cout << "\n===== Additional Tests =====" << std::endl;

    // Test MateriaSource functionality
    std::cout << "\n----- MateriaSource Test -----" << std::endl;
    IMateriaSource* source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    // Try to learn a 5th materia (should do nothing as the source is full)
    AMateria* extraIce = new Ice();
    source->learnMateria(extraIce);
    // Since the source is full, we need to clean up ourselves
    delete extraIce;

    // Test createMateria
    AMateria* ice = source->createMateria("ice");
    AMateria* cure = source->createMateria("cure");
    AMateria* unknown = source->createMateria("unknown"); // Should return nullptr

    std::cout << "Ice type: " << ice->getType() << std::endl;
    std::cout << "Cure type: " << cure->getType() << std::endl;
    std::cout << "Unknown type: " << (unknown ? unknown->getType() : "nullptr") << std::endl;

    // Test Character functionality
    std::cout << "\n----- Character Test -----" << std::endl;
    Character* alice = new Character("Alice");
    Character* bob2 = new Character("Bob");

    alice->equip(ice);
    alice->equip(cure);

    // Test use
    alice->use(0, *bob2);
    alice->use(1, *bob2);
    alice->use(2, *bob2); // Should do nothing (empty slot)
    alice->use(-1, *bob2); // Should do nothing (invalid slot)

    // Store unequipped Materias (floor)
    AMateria* floor[10] = {nullptr};
    int floorIndex = 0;

    // Test unequip
    alice->unequip(0);
    floor[floorIndex++] = ice; // Save the address of the unequipped Materia
    alice->use(0, *bob2); // Should do nothing as the slot is empty

    // Test deep copy
    std::cout << "\n----- Deep Copy Test -----" << std::endl;
    Character* aliceCopy = new Character(*alice);
    std::cout << "Original character: " << alice->getName() << std::endl;
    std::cout << "Copied character: " << aliceCopy->getName() << std::endl;

    // Test using the copy
    std::cout << "Using materia from the copied character:" << std::endl;
    aliceCopy->use(1, *bob2); // Should use cure

    // Test assignment operator
    Character* charlie = new Character("Charlie");
    *charlie = *alice;
    std::cout << "After assignment, character name: " << charlie->getName() << std::endl;
    charlie->use(1, *bob2); // Should use cure

    // Test deep copy of MateriaSource
    std::cout << "\n----- MateriaSource Deep Copy Test -----" << std::endl;
    MateriaSource* sourceCopy = new MateriaSource(*(MateriaSource*)source);
    AMateria* iceCopy = sourceCopy->createMateria("ice");
    std::cout << "Created materia from copied source: " << iceCopy->getType() << std::endl;

    // Clean up
    delete alice;
    delete bob2;
    delete aliceCopy;
    delete charlie;
    delete source;
    delete sourceCopy;

    // Clean up floor Materias
    for (int i = 0; i < floorIndex; i++) {
        delete floor[i];
    }

    // Delete the extra Materias
    delete iceCopy;
    if (unknown) delete unknown;

    return 0;
}
