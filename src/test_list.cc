#include <string>
#include <list>
#include <iostream>
#include "liste.h"
using namespace std;

int main() {
    Liste personnel;

    // ajouter 4 elements
    personnel.ajouter("Baleze Bruno");
    personnel.ajouter("Costaud Claude");
    personnel.ajouter("Doue Damien");
    personnel.ajouter("Vaillant Veronique");


    // ajouter un element a la quatrieme position
    Iterateur pos = personnel.debut();
    pos++; pos++; pos++;
    personnel.inserer(pos, "Sage Stephane");

    // supprimer l'element a la deuxieme position
    pos = personnel.debut();
    pos++;
    personnel.supprimer(pos);

    // afficher tous les elements
    for (pos = personnel.debut(); pos != personnel.fin(); pos++)
        cout << pos.get() << endl;

    cout << endl;
    --pos;--pos;
    cout << pos.get() << endl;
    ++pos;
    cout << pos.get() << endl;
    return 0;
}
