//
// Created by Strahinja Janjic on 6/8/2017.
//

#ifndef TM_KOMANDA_H
#define TM_KOMANDA_H
#include <string>
using namespace std;

class Komanda {
public:
    struct Elem1 {
        int tren_q;
        int tren_Stanje;
        int sled_q;
        int sled_Stanje;
        int korak;
        bool dodaj(string &c);
        Elem1 *sled, *preth;
        Elem1(Elem1 *sl = nullptr, Elem1 *pr = nullptr);
    };
private:
    bool fajlFlag;
    Elem1 *prvi, *posl;
    int br;
public:
    Komanda(string s[], int br,bool fajlFl);
    Elem1 * doh_prvi() {
        return prvi;
    }
    Elem1 * doh_posl() {
        return posl;
    }
    ~Komanda();
};
#endif //TM_KOMANDA_H
