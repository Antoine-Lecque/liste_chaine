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
   precedent = suivant = nullptr;
}


Iterateur::Iterateur() {
   position = dernier = nullptr;
}


string& Iterateur::get() const {
   return position->valeur;
}

// forme postfixe
Iterateur Iterateur::operator++(int i) {
   position = position->suivant;
   return *this;
}

//forme prefixe
Iterateur &Iterateur::operator++() {
    position = position->suivant;
    return *this;
}

// forme postfixe
Iterateur Iterateur::operator--(int i) {
   if (position == nullptr) // fin de la liste
      position = dernier;
   else
      position = position->precedent;
    return *this;
}

//forme prefixe
Iterateur &Iterateur::operator--(){
    if (position == nullptr) // fin de la liste
        position = dernier;
    else
        position = position->precedent;
    return *this;
}

bool Iterateur::operator==(const Iterateur &b) const {
    return position == b.position;
}

bool Iterateur::operator!=(const Iterateur &b) const {
    return position != b.position;
}

Liste::Liste() {
   premier = dernier = nullptr;
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
    Element *elt = new Element(s);
    elt->suivant = pos.position;

    pos--;

    if (pos.position != nullptr) {
        elt->precedent = pos.position;
        elt->precedent->suivant = elt;
        elt->suivant->precedent = elt;
    } else {
        this->premier = elt;
    }
}

// supprimer l'element a la position pos
void Liste::supprimer(Iterateur& pos){
    if (pos.position != nullptr) {
        if (pos.position->precedent == nullptr) { //début de la liste
            pos++;
            pos.position->precedent = nullptr;
            this->premier = pos.position;
        } else if (pos.position->suivant == nullptr) { //fin de la liste
            pos--;
            pos.position->suivant = nullptr;
            this->dernier = pos.position;
        } else if (pos.position->suivant == nullptr && pos.position->precedent == nullptr) //liste contenant un seul element
            this->premier = this->dernier = nullptr;
        else {
            pos.position->suivant->precedent = pos.position->precedent;
            pos.position->precedent->suivant = pos.position->suivant;
        }
    }
}
   
Iterateur Liste::debut() const {
   Iterateur it;
   it.position = premier;
   it.dernier = dernier;
   return it;
}


Iterateur Liste::fin() const {
   Iterateur it;
   it.position = nullptr;
   it.dernier = dernier;
   return it;
}
