#include <iostream>
#include <vector>

class Animal {
public:
    virtual void crier() const = 0;

    void info() const {
        std::cout << "Je suis un animal." << std::endl;
    }

    virtual ~Animal() {}
};

class Chien : public Animal {
public:
    void crier() const override {
        std::cout << "Wouf !" << std::endl;
    }
};

class Chat : public Animal {
public:
    void crier() const override {
        std::cout << "Miaou !" << std::endl;
    }
};

class Vache : public Animal {
public:
    void crier() const override {
        std::cout << "Meuh !" << std::endl;
    }
};

int main() {
    Chien chien;
    Chat chat;
    Vache vache;

    std::vector<Animal*> animaux;

    animaux.push_back(&chien);
    animaux.push_back(&chat);
    animaux.push_back(&vache);

    for (Animal* animal : animaux) {
        animal->info();
        animal->crier();
    }

    return 0;
}