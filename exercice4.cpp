#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NoeudFichier {
public:
    virtual string nom() const = 0;
    virtual int taille() const = 0;

    virtual ~NoeudFichier() {}
};

class Fichier : public NoeudFichier {
private:
    string nomFichier;
    int tailleFichier;

public:
    Fichier(string n, int t) {
        nomFichier = n;
        tailleFichier = t;
    }

    string nom() const override {
        return nomFichier;
    }

    int taille() const override {
        return tailleFichier;
    }
};

class Dossier : public NoeudFichier {
private:
    string nomDossier;
    vector<NoeudFichier*> enfants;

public:
    Dossier(string n) {
        nomDossier = n;
    }

    string nom() const override {
        return nomDossier;
    }

    void ajouter(NoeudFichier* noeud) {
        enfants.push_back(noeud);
    }

    int taille() const override {
        int total = 0;

        for (NoeudFichier* enfant : enfants) {
            total += enfant->taille();
        }

        return total;
    }
};

int main() {
    Fichier f1("document.txt", 100);
    Fichier f2("image.jpg", 200);
    Fichier f3("cours.pdf", 300);

    Dossier documents("Documents");
    Dossier principal("Principal");

    documents.ajouter(&f1);
    documents.ajouter(&f2);

    principal.ajouter(&documents);
    principal.ajouter(&f3);

    cout << "Dossier : " << principal.nom() << endl;
    cout << "Taille totale : " << principal.taille() << " Ko" << endl;

    return 0;
}