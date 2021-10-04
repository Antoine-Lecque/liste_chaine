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

    /*
    // ajouter un element a la quatrieme position
    list<string>::iterator pos = personnel.begin();
    pos++; pos++; pos++;
    personnel.insert(pos, "Sage Stephane");

    // supprimer l'element a la deuxieme position
    pos = personnel.begin();
    pos++;
    personnel.erase(pos);

    // afficher tous les elements
    for (pos = personnel.begin(); pos != personnel.end(); pos++)
        cout << *pos << endl;

    return 0;*/
}
