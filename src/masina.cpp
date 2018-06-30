//
// Created by Strahinja Janjic on 6/8/2017.
//
#include "masina.h"
#include "Konstante.h"

Masina::Masina(Traka * t, Komanda * c)
{
    traka = t;
    cmd = c;
}

bool Masina::pokreni_masinu()
{
    int Trenutno_Q = 0;
    Komanda::Elem1 *pom = cmd->doh_prvi();
    while (1) {
        pom = cmd->doh_prvi();
        while ((Trenutno_Q != pom->tren_q) || (traka->vrati_tek()->stanje != pom->tren_Stanje)) {
            if (pom->sled == nullptr) { cout << "Doslo je do greske!"; exit(1); }
            pom = pom->sled;
        }
        cout << "Stanje (q" << pom->tren_q << ") :" << *traka << endl;
        traka->vrati_tek()->stanje = pom->sled_Stanje;
        Trenutno_Q = pom->sled_q;
        if (pom->sled_q == PLUS) return true;
        if (pom->sled_q == MINUS) return false;
        bool bo = (pom->korak == 1) ? true : false;
        traka->pomeri_tek(bo);
    }

}

void Masina::isisi_traku()
{
    cout << "Traka:" << traka << endl;
}

void Masina::reset()
{
    delete cmd;
    delete traka;
}

