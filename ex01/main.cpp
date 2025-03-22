#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    // 動物配列テスト
    std::cout << "=== Animal Array Test ===" << std::endl;
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // 半分をDog、半分をCatで埋める
    for (int i = 0; i < numAnimals / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        animals[i] = new Cat();
    }

    // すべての動物の音を鳴らす
    std::cout << "\n=== Make All Animals Sound ===" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }

    // すべての動物を削除
    std::cout << "\n=== Delete All Animals ===" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }

    // 深いコピーテスト
    std::cout << "\n=== Deep Copy Test for Dog ===" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I love bones!");

    Dog* copiedDog = new Dog(*originalDog);

    // オリジナルのアイデアを変更
    originalDog->getBrain()->setIdea(0, "I prefer sleeping!");

    // 両方のアイデアを表示
    std::cout << "Original Dog's idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's idea: " << copiedDog->getBrain()->getIdea(0) << std::endl;

    delete originalDog;
    delete copiedDog;

    // Catの深いコピーテスト
    std::cout << "\n=== Deep Copy Test for Cat ===" << std::endl;
    Cat* originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "I love fish!");

    Cat* copiedCat = new Cat(*originalCat);

    // オリジナルのアイデアを変更
    originalCat->getBrain()->setIdea(0, "I prefer milk!");

    // 両方のアイデアを表示
    std::cout << "Original Cat's idea: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat's idea: " << copiedCat->getBrain()->getIdea(0) << std::endl;

    delete originalCat;
    delete copiedCat;

    // スコープテスト
    std::cout << "\n=== Scope Test ===" << std::endl;
    {
        Dog basic;
        basic.getBrain()->setIdea(0, "Basic dog idea");

        Dog tmp = basic;
        std::cout << "Original dog idea: " << basic.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied dog idea: " << tmp.getBrain()->getIdea(0) << std::endl;
    } // ここでtmpとbasicが破棄される
    std::cout << "After scope ended" << std::endl;

    return 0;
}
