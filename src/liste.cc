#include "liste.h"

using namespace std;

class Element {
public:
   // constructeur
   Element(const string& s);

private:
   string valeur;

   // pointeurs vers les voisins
   Element* precedent;
   Element* suivant;

friend class Liste;
friend class Iterateur;
};


Element::Element(const string& s) {
   valeur = s;
   precedent = suivant = NULL;
}


Iterateur::Iterateur() {
   position = dernier = NULL;
}


string& Iterateur::get() const {
   return position->valeur;
}


void Iterateur::suivant() {
   position = position->suivant;
}


void Iterateur::precedent() {
   if (position == NULL) // fin de la liste
      position = dernier;
   else
      position = position->precedent;
}


bool Iterateur::egal(const Iterateur& b) const {
   return position == b.position;
}


Liste::Liste() {
   premier = dernier = NULL;
}

// ajouter s a la fin de la liste
void Liste::ajouter(const std::string& s){
    Element *elt = new Element(s);
    elt->suivant = nullptr;
    elt->precedent = this->dernier;

    if (this->premier == nullptr) {
        this->premier = this->dernier = elt;
    } else
        this->dernier->suivant = elt;

    this->dernier = elt;
}

// ajouter s avant la position pos
void Liste::inserer(Iterateur& pos, const std::string& s){

}

// supprimer l'element a la position pos
void Liste::supprimer(Iterateur& pos){

}
   
Iterateur Liste::debut() const {
   Iterateur it;
   it.position = premier;
   it.dernier = dernier;
   return it;
}


Iterateur Liste::fin() const {
   Iterateur it;
   it.position = NULL;
   it.dernier = dernier;
   return it;
}
