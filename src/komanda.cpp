//
// Created by Strahinja Janjic on 6/8/2017.
//
#include <iostream>
#include "komanda.h"
#include "Konstante.h"
using namespace std;
bool Komanda::Elem1::dodaj(string &c)
{
    string poms1 = "";
    int pomi1 = 0;
    if (c[0] != 'f' || c[1] != '(' || c[2] != 'q')
        return false;
    pomi1 = 3;
    for (int i = pomi1; i < pomi1 + 4; i++) {
        if (isdigit(c[i])) {
            pomi1++;
            poms1 += c[i];
        }
        else { break; }
    }
    tren_q = stoi(poms1);
    poms1 = "";
    if (c[pomi1++] != ',') return false;
    switch (c[pomi1++])
    {
        case 'b': tren_Stanje = B; break;
        case '0': tren_Stanje = NULA; break;
        case '1': tren_Stanje = JEDAN; break;
        default: return false;
            break;
    }
    if (c[pomi1++] != ')') return false;
    if (c[pomi1++] != '=') return false;
    if (c[pomi1++] != '(') return false;
    if (c[pomi1++] != 'q') return false;
    switch (c[pomi1++])
    {
        case '+': sled_q = PLUS; break;
        case '-': sled_q = MINUS; break;
        default:
            pomi1--;
            for (int i = pomi1; i < pomi1 + 4; i++) {
                if (isdigit(c[i])) {
                    pomi1++;
                    poms1 += c[i];
                }
                else { break; }
            }if (sled_q != PLUS || sled_q != MINUS) {
        sled_q = stoi(poms1);
        poms1 = "";
    }
            break;
    }
    if (c[pomi1++] != ',') return false;
    switch (c[pomi1++])
    {
        case 'b': sled_Stanje = B; break;
        case '0': sled_Stanje = NULA; break;
        case '1': sled_Stanje = JEDAN; break;
        default: return false;
            break;
    }
    if (c[pomi1++] != ',') return false;
    if (c[pomi1++] == '+') {
        korak = 1;
    }
    else if (c[pomi1 - 1] == '-') {
        korak = -1;
    }
    else return false;


    if (c[pomi1++] != '1') return false;
    if (c[pomi1++] != ')') return false;

    return true;

}

Komanda::Elem1::Elem1(Elem1 * sl, Elem1 * pr)
{
    tren_q = 0;
    tren_Stanje = 0;
    tren_q = 0;
    sled_Stanje = 0;
    korak = 0;
    sled = sl;
    preth = pr;
}

Komanda::Komanda(string s[], int br,bool fajlFl)
{
    fajlFlag=fajlFl;
    prvi = posl = nullptr;
    this->br = br;
    for (int i = 0; fajlFlag?i<br:s[i] != " "; i++) {
        Elem1 *novi = new Elem1();
        if (!novi->dodaj(s[i])) {
            cout << "Doslo je do greske!" << endl; exit(1);
        }
        if (!prvi) {
            prvi = posl = novi;
        }
        else {
            posl->sled = novi;
            posl = novi;
        }
    }
}

Komanda::~Komanda()
{
    while (prvi) {
        Elem1 *pom = prvi;
        prvi = prvi->sled;
        delete pom;
    }
}
