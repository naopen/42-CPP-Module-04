#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    // AAnimalクラスのインスタンス化は不可能（コンパイルエラー）
    // AAnimal* animal = new AAnimal(); // エラー

    // サブクラスのインスタンス化は可能
    std::cout << "=== Creating Animals ===" << std::endl;
    AAnimal* j = new Dog();
    AAnimal* i = new Cat();

    std::cout << "\n=== Animal Types ===" << std::endl;
    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat type: " << i->getType() << std::endl;

    std::cout << "\n=== Animal Sounds ===" << std::endl;
    j->makeSound();
    i->makeSound();

    // 動物の配列テスト
    std::cout << "\n=== Animal Array Test ===" << std::endl;
    const int numAnimals = 4;
    AAnimal* animals[numAnimals];

    // 半分をDog、半分をCatで埋める
    for (int i = 0; i < numAnimals / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        animals[i] = new Cat();
    }

    // すべての動物の音を鳴らす
    for (int i = 0; i < numAnimals; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }

    // すべての動物を削除
    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }

    delete j;
    delete i;

    // 深いコピーテスト
    std::cout << "\n=== Deep Copy Test ===" << std::endl;

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

    return 0;
}
