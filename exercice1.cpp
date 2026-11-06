#include <iostream>
#include <string>

class Forme {
    public:
        virtual double aire() const = 0;
        
};

class Cercle : public Forme {
    private :
       double rayon;
    public:
      Cercle(double r) : rayon(r) {}
      double aire() const override
    {
        return 3.141 * rayon *rayon ;

    }
};

class Rectangle : public Forme {
    private :
       double largeur;
       double hauteur;
    public:
      Rectangle(double l, double h) : largeur(l), hauteur(h) {}
      double aire() const override
    {
        return largeur * hauteur ;
    }
};

int main() {
    double rayon, largeur, hauteur;
    std::cout << "Entrez le rayon du cercle : ";
    std::cin >> rayon;

    std::cout << "Entrez la largeur du rectangle : ";
    std::cin >> largeur;
    std::cout << "Entrez la hauteur du rectangle : ";
    std::cin >> hauteur;
    Forme* tableau[2];
    tableau[0] = new Cercle(rayon);
    tableau[1] = new Rectangle(largeur, hauteur);

    std::cout << "Aire du cercle : " << tableau[0]->aire() << std::endl;
    std::cout << "Aire du rectangle : " << tableau[1]->aire() << std::endl;

    delete tableau[0];
    delete tableau[1];

    return 0;
}