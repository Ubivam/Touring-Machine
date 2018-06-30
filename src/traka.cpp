//
// Created by Strahinja Janjic on 6/8/2017.
//
#include "traka.h"
#include "Konstante.h"
Traka::Traka(string s, int glava)
{
    prvi = posl = nullptr;
    for (int i = 0; s[i] != '\0'; i++) {
        Elem * novi = new Elem();
        if (s[i] == 'b') {
            novi->stanje = B;
        }
        else if (s[i] == '0') {
            novi->stanje = NULA;
        }
        else if (s[i] == '1') {
            novi->stanje = JEDAN;
        }
        else { cout << "Doslo je do greske"; exit(1); }
        if (!prvi) {
            prvi = posl = novi;
        }
        else {
            posl->sled = novi;
            novi->preth = posl;
            posl = novi;
        }
    }
    tek = prvi;
    for (int i = 0; i < glava - 1; i++) {
        tek = tek->sled;
    }
}

bool Traka::pomeri_tek(bool b)
{

    if (b) {
        if (tek->sled == nullptr) {
            Elem * novi1 = new Elem;
            tek->sled = novi1;
            novi1->preth = tek;
        }
        tek = tek->sled;
    }
    else {
        if (tek->preth == nullptr) {
            Elem * novi2 = new Elem;
            tek->preth = novi2;
            novi2->sled = tek;
            prvi = novi2;
        }
        tek = tek->preth;
    }
    if (tek)	return true;

    return false;
}

Traka::~Traka()
{
    while (prvi) {
        Elem *pom = prvi;
        prvi = prvi->sled;
        delete pom;
    }
}

ostream & operator<<(ostream & it, const Traka &t)
{
    for (Traka::Elem *pom = t.prvi; pom != nullptr; pom = pom->sled) {
        if (pom->stanje == B) {
            it << "b";
        }
        if (pom->stanje == NULA) {
            it << "0";
        }
        if (pom->stanje == JEDAN) {
            it << "1";
        }
    }
    return it;
}

