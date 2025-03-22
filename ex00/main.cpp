#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    // 基本テスト
    std::cout << "=== Basic Test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    delete meta;
    delete j;
    delete i;

    // WrongAnimal テスト
    std::cout << "\n=== WrongAnimal Test ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // WrongAnimal sound（ポリモーフィズムが機能しない）
    wrongMeta->makeSound(); // WrongAnimal sound

    delete wrongMeta;
    delete wrongCat;

    // 追加テスト: スタック上での動作確認
    std::cout << "\n=== Stack Objects Test ===" << std::endl;
    Animal animalOnStack;
    Dog dogOnStack;
    Cat catOnStack;

    std::cout << "Animal type: " << animalOnStack.getType() << std::endl;
    std::cout << "Dog type: " << dogOnStack.getType() << std::endl;
    std::cout << "Cat type: " << catOnStack.getType() << std::endl;

    animalOnStack.makeSound();
    dogOnStack.makeSound();
    catOnStack.makeSound();

    return 0;
}
