// // Created by Strahinja Janjic on 6/8/2017. // #include "komanda.h" 
#include "masina.h"
#include "traka.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
    Traka *traka = nullptr;
    Komanda *cmd = nullptr;
    Masina *tjuring = nullptr;
    cout << "Dobro dolsi u Simulator Tjuringove Masine:" << endl;
    while (1) {
        cout << "Izaberite odgovarajucu odpciju" << endl;
        cout << "1)Unosenje trake" << endl;
        cout << "2)Unosenje kod-a" << endl;
        cout << "3)Pokrenite program" << endl;
        cout << "4)Ispisite Rezultat" << endl;
        cout << "5)Resetujte" << endl;
        cout << "6)Gasenje programa" << endl;
        int x, y, i1 = 0;
        cin >> x;
        string s_pom = "";
        string *s1_pom = new string[10];
        switch (x) {
            case 1:
                cout << "Uneiste traku" << endl;
                cin >> s_pom;
                cout << "Unesite pocetnu poziciju glave" << endl;
                cin >> y;
                traka = new Traka(s_pom, y);
                if (cmd) {
                    tjuring = new Masina(traka, cmd);
                }
                break;
            case 2:
                cout << "Unesite slovo f ako zelite da program ucitate iz fajla ili slovo k ako zelite iz konzole"
                     << endl;
                char c;
                cin >> c;
                if (c == 'k' || c == 'K') {
                    cout << "Unesite kod programa(Pri zadnjoj liniji koda da bi" <<
                         "ste oznacili kraj unosa teksta unesite red koji sadrzi samo jedan space)" << endl;
                    getline(std::cin, s_pom);
                    for (string linija; linija != " "; i1++) {
                        getline(std::cin, linija);
                        if (i1 % 10 == 9) {
                            string *pom_string = new string[i1 + 10];
                            for (int i = 0; i < i1; i++) {
                                pom_string[i] = s1_pom[i];
                            }
                            delete[] s1_pom;
                            s1_pom = pom_string;
                        }
                        s1_pom[i1] = linija;
                    }
                    cmd = new Komanda(s1_pom, i1,false);
                    if (traka) {
                        tjuring = new Masina(traka, cmd);
                    }
                    break;
                }
                if (c == 'f' || c == 'F') {
                    ifstream inFile;
                    inFile.open("test.txt");
                    if (!inFile) {
                        cout << "Unable to open file";
                        exit(1); // terminate with error
                    }
                    getline(inFile, s_pom);
                    for (string linija; !inFile.eof(); i1++) {
                        getline(inFile, linija);
                        if (i1 % 10 == 9) {
                            string *pom_string = new string[i1 + 10];
                            for (int i = 0; i < i1; i++) {
                                pom_string[i] = s1_pom[i];
                            }
                            delete[] s1_pom;
                            s1_pom = pom_string;
                        }
                        s1_pom[i1] = linija;
                    }
                    cmd = new Komanda(s1_pom, i1,true);
                    if (traka) {
                        tjuring = new Masina(traka, cmd);
                    }
                    inFile.close();
                    break;
                }

                cout << "Uneli ste nekorektnu vrednost! Pokusajete ponovo" << endl;
                break;
            case 3:
                if (cmd == nullptr || tjuring == nullptr || traka == nullptr) break;
                if (tjuring->pokreni_masinu()) {
                    cout << "Tacno" << endl;;
                } else {
                    cout << "Netacno" << endl;;
                }
                break;

            case 4:
                cout << *traka << endl;
                break;
            case 5:
                if (!tjuring) {
                    cout << "Niste uneli ili program ili traku!" << endl;
                    break;
                }
                tjuring->reset();
                delete tjuring;
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Niste uneli korektnu vrednost probajte opet!" << endl;
                break;
        }
    }
    return 0;
}
