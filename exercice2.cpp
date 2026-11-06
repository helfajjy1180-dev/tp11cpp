#include <iostream>
#include <string>

class Paiement {
public:
    virtual double effectuerPaiement(double montant) = 0;
};

class PaimentCarte : public Paiement {
private:
    std::string numeroCarte;

public:
    PaimentCarte(std::string num) : numeroCarte(num) {}

    double effectuerPaiement(double montant) override {
        std::cout << "Paiement de " << montant << " € effectué avec la carte bancaire "
                  << numeroCarte << std::endl;
        return montant;
    }
};

class PaimentEspece : public Paiement {
public:
    double effectuerPaiement(double montant) override {
        std::cout << "Paiement de " << montant << " € effectué en espèces" << std::endl;
        return montant;
    }
};

int main() {
    PaimentCarte carte("123456789");
    PaimentEspece espece;

    Paiement* tableau[2];
    tableau[0] = &carte;
    tableau[1] = &espece;

    double montants[2] = {100, 50};

    for (int i = 0; i < 2; i++) {
        tableau[i]->effectuerPaiement(montants[i]);
    }

    return 0;
}