//
// Created by Strahinja Janjic on 6/8/2017.
//

#ifndef TM_MASINA_H
#define TM_MASINA_H
#include "traka.h"
#include "komanda.h"
class Masina {
private:
    Traka *traka;
    Komanda *cmd;
public:
    Masina(Traka *t, Komanda *c);
    bool pokreni_masinu();
    void isisi_traku();
    void reset();
};
#endif //TM_MASINA_H
