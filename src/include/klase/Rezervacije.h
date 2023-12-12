#include <string>
#include "Auto.h"
using namespace std;
#ifndef RENT_A_CAR_OOP_REZERVACIJE_H
#define RENT_A_CAR_OOP_REZERVACIJE_H

class Rezervacije{
private:
    Auto auto;
    int id_rezervacije;
    char ime_korisnika[50];
    char prezime_korisnika[50];
    char datum_pocetka[50];
    char datum_zavrsetka[50];
    char naziv_automobila[50];
public:
    void setImeKorisnika(const string& ime_korisnika[50]);
    void setPrezimeKorisnika(const string& prezime_korisnika[50]);
    void setDatumPocetka(const string& datum_pocetka[50]);
    void setDatumZavrsetka(const string& datum_zavrsetka[50]);
    void setNazivAutomobila(const string& naziv_automobila[50]);

};




#endif //RENT_A_CAR_OOP_REZERVACIJE_H
