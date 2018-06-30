//
// Created by Strahinja Janjic on 6/8/2017.
//

#ifndef TM_TRAKA_H
#define TM_TRAKA_H
#include <iostream>
#include <string>
using namespace std;
class Traka {
public: struct Elem {
        int stanje;
        Elem *sled, *preth;
        Elem(int s = 0, Elem *sl = nullptr, Elem *pr = nullptr) :stanje(s), sled(sl), preth(pr) {}
    };
private:
    Elem * prvi, *posl, *tek;
public:
    Traka(string s, int glava);
    Elem * vrati_tek() {
        return tek;
    }
    bool pomeri_tek(bool b);
    void upisi_stanje(int i) {
        tek->stanje = i;
    }
    Elem * vrati_prvi() {
        return prvi;
    }
    ~Traka();
    friend ostream & operator << (ostream &it, const Traka &t);



};
#endif //TM_TRAKA_H
