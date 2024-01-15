#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
using namespace std;

void dobrodosli();
void adminMeni();
void korisnikMeni();


class Auto
{
public:
    void postaviPodatke(string ime, string br_registracije, int cijena_po_danu, int kapacitet)
    {
        marka = ime;
        broj_registracije = br_registracije;
        this->cijena_po_danu = cijena_po_danu;
        kapacitet_sjedista = kapacitet;
    }
    
	void rezervirajAuto(string korisnicko_ime)
    {
        ifstream citaj("auta.txt");
        string linija;
        ofstream tempFile("temp.txt");
 
        bool found = false;
 
        while (getline(citaj, linija))
        {
            if (linija.find("BROJ REGISTRACIJE: " + broj_registracije) != string::npos)
            {
                found = true;
                continue; // Presko�i liniju sa rezervisanim automobilom
            }
 
            tempFile << linija << endl;
        }
 
        citaj.close();
        tempFile.close();
 
        if (!found)
        {
            cout << "Automobil nije prona�en u bazi podataka." << endl;
            return;
        }
 
        remove("auta.txt");
        rename("temp.txt", "auta.txt");
 
        // Kreiraj novu rezervaciju
        ofstream rezervacija;
        string fileName = "rezervacija_" + korisnicko_ime + ".txt";
        rezervacija.open(fileName);
 
        // Napi�i podatke o rezervaciji u novu datoteku
        rezervacija << "BROJ REGISTRACIJE: " << broj_registracije << endl
                    << "IME: " << marka << endl
                    << "CIJENA PO DANU: " << cijena_po_danu << "KM" << endl
                    << "BROJ SJEDISTA: " << kapacitet_sjedista << endl
                    << "REZERVISANO OD: " << korisnicko_ime << endl;
 
        rezervacija.close();
    }
    
    void dodajUdatoteku()
    {
        ofstream datoteka;
        datoteka.open("auta.txt", ios::app);
        datoteka << "BROJ REGISTRACIJE: " << broj_registracije << endl
        		 << "IME: " << marka << endl
                 << "CIJENA PO DANU: " << cijena_po_danu << "KM" << endl
                 << "BROJ SJEDISTA: " << kapacitet_sjedista << endl
                 << endl;
        datoteka.close();
    }

private:
    string marka;
    string broj_registracije;
    int cijena_po_danu;
    int kapacitet_sjedista;
};

bool dostupnaRegistracija(string broj_registracije)
{
    string n;
    string t = "BROJ REGISTRACIJE: " + broj_registracije;
    ifstream datoteka("auta.txt");
    while (getline(datoteka, n))
    {
        if (n == t)
        {
            return true;
        }
    }
    return false;
}

// Funkcija za provjeru valjanosti podataka za prijavu
bool registriran(string korisnicko_ime, string lozinka, int val)
{
    string un, pw;
    if (val == 1)
    {
        ifstream citaj(korisnicko_ime + "_admin.txt");
        getline(citaj, un);
        getline(citaj, pw);

        if (un == korisnicko_ime && pw == lozinka)
        {
            return true;
        }
    }
    else
    {
        ifstream citaj(korisnicko_ime + ".txt");
        getline(citaj, un);
        getline(citaj, pw);

        if (un == korisnicko_ime && pw == lozinka)
        {
            return true;
        }
    }
    return false;
}

// Funkcija za provjeru postojanja korisnika
bool datotekaPostoji(string korisnicko_ime)
{
    string un;
    ifstream citaj(korisnicko_ime + ".txt");
    getline(citaj, un);

    if (un == korisnicko_ime)
    {
        return true;
    }
    return false;
}

bool adminDatotekaPostoji(string korisnicko_ime)
{
    string un;
    ifstream citaj(korisnicko_ime + "_admin.txt");
    getline(citaj, un);

    if (un == korisnicko_ime)
    {
        return true;
    }
    return false;
}

void registracijaPrijava(int odgovor)
{
    string korisnicko_ime, lozinka;
    if (odgovor == 1 || odgovor == 2)
    {
        cout << "\n\t\t\t\t\t\tUnesite korisnicko ime: ";
        cin >> korisnicko_ime;
        cout << "\n\t\t\t\t\t\tUnesite lozinku: ";
        cin >> lozinka;

        // provjera podataka za prijavu
        if (registriran(korisnicko_ime, lozinka, odgovor))
        {
            cout << "\n\t\t\t\t\t\tUspjesno ste prijavljeni!";
            Sleep(500);
            system("cls");
            if (odgovor == 1)
            {
                adminMeni();
            }
            else if (odgovor == 2)
            {
                korisnikMeni();
            }
            system("PAUSE");
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t[GRESKA] Korisnicko ime ili lozinka su netocni, pokusajte ponovo.\n";

            cout << "\n\t\t\t\t\t\tUnesite 1 za glavni izbornik." << endl
                 << "\n\t\t\t\t\t\tUnesite 2 za izlaz iz programa." << endl;
            int izbor;
            cout << "\n\t\t\t\t\t\tIZBOR: ";
            cin >> izbor;
            system("cls");

            // kraj programa
            if (izbor == 1)
            {
                dobrodosli();
            }
            else if (izbor == 2)
            {
                cout << "Hvala Vam na koristenju nase aplikacije i vozite oprezno!\n";
                Sleep(500);
                system("exit");
            }
        }
    }
        // registracija novih korisnika
    else if (odgovor == 3)
    {
        cout << "Izaberite korisnicko ime: ";
        cin >> korisnicko_ime;
        cout << "Izaberite lozinku: ";
        cin >> lozinka;

        // provjera postojanja korisnika
        if (datotekaPostoji(korisnicko_ime))
        {
            system("cls");
            cout << "Korisnièko ime vec postoji." << endl;
            Sleep(500);

            cout << "\nUnesite 1 za glavni izbornik." << endl
                 << "Unesite 2 za izlaz iz programa." << endl;
            int izbor;
            cout << "\nIZBOR: ";
            cin >> izbor;
            system("cls");

            // kraj programa
            if (izbor == 1)
            {
                dobrodosli();
            }
            else if (izbor == 2)
            {
                cout << "Hvala Vam na koristenju nase aplikacije i vozite oprezno!\n";
                Sleep(1000);
                system("exit");
            }
        }

        ofstream datoteka;
        datoteka.open(korisnicko_ime + ".txt");
        datoteka << korisnicko_ime << endl
                 << lozinka;
        datoteka.close();

        cout << "Uspjesna registracija!\n";
        cout << "\nUnesite 1 za glavni izbornik." << endl
             << "Unesite 2 za izlaz iz programa." << endl;
        int izbor;
        cout << "\nIZBOR: ";
        cin >> izbor;
        system("cls");

        // kraj programa
        if (izbor == 1)
        {
            dobrodosli();
        }
        else if (izbor == 2)
        {
            cout << "Hvala Vam na koristenju nase aplikacije i vozite oprezno!\n";
            Sleep(1000);
            system("exit");
        }
    }
    else
    {
        system("cls");
        cout << "[GREsKA] Opcija ne postoji.\n";
        Sleep(500);

        cout << "\nUnesite 1 za glavni izbornik." << endl
             << "Unesite 2 za izlaz iz programa." << endl;
        int izbor;
        cout << "\nIZBOR: ";
        cin >> izbor;
        system("cls");

        // kraj programa
        if (izbor == 1)
        {
            dobrodosli();
        }
        else if (izbor == 2)
        {
            cout << "Hvala Vam na koristenju nase aplikacije i vozite oprezno!\n";
            Sleep(1000);
            system("exit");
        }
    }
}


void ucitavanje()
{
	cout << "	____  _______   ________	___     	_________	____\n"
    	"   / __ \\/ ____/ | / /_  __/   /   |   	/ ____/   |  / __ \\\n"
   	 "  / /_/ / __/ /  |/ / / /_____/ /| |______/ /   / /| | / /_/ /\n"
    	" / _, _/ /___/ /|  / / /_____/ ___ /_____/ /___/ ___ |/ _, _/ \n"
    	"/_/ |_/_____/_/ |_/ /_/ 	/_/  |_| 	\\____/_/  |_/_/ |_|  \n\n\n\n";
	cout << "\t\t\tUcitavanje";
	for (int i = 0; i < 7; i++)
	{
    	Sleep(500);
    	cout << '.';
	}
	system("cls");
}

void dobrodosli()
{
    cout << "------------------------------------------ DOBRODOSLI U RENT-A-CAR CAPCARAP ------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t\t\tNAPOMENA";
    cout << "\n\n\t\t\t1. KADA REZERVISETE VOZILO NE MOZETE OTKAZATI REZERVACIJU";
    cout << "\n\t\t\t2. U SLUCAJU SAOBRACAJNE NESRECE NASE OSIGURANJE SNOSI TROSKOVE POPRAVKE";
    cout << "\n\t\t\t3. ZA NAJAM POTREBNO VAM JE : a) Vozacka dozvola b) Novac";
    cout << "\n\t\t\tVOZITE OPREZNO !";
    cout << "\n\n\t\t\tPritisnite ENTER za nastavak...";
    cout << "\n\n------------------------------------------ DOBRODOSLI U RENT-A-CAR CAPCARAP ------------------------------------------";
    cin.get();
    system("cls");
	cout << "------------------------------------------ DOBRODOSLI U RENT-A-CAR CAPCARAP ------------------------------------------" << endl;
    string zeljenaOpcija = "\n\t\t\t\t\t\tOdaberite opciju :";
    for (int i = 0; i < zeljenaOpcija.length(); i++)
    {
        Sleep(20);
        cout << zeljenaOpcija[i];
    }
    cout << endl;
    cout << "\n\t\t\t\t\t\t1.Admin Login" << endl
         << "\n\t\t\t\t\t\t2.Login" << endl
         << "\n\t\t\t\t\t\t3.Registracija" << endl
         << "\n\t\t\t\t\t\t4.Izlaz" << endl
         << "\n\t\t\t\t\t\tUnesite opciju:";
    int odgovor;
    cin >> odgovor;
    system("cls");
    if (odgovor == 1 || odgovor == 2 || odgovor == 3)
    {
        system("cls");
        registracijaPrijava(odgovor);
    }
    else if (odgovor == 4)
    {
        system("cls");
        cout << "\n\t\t\tHvala Vam na koristenju nase aplikacije i vozite oprezno!\n";
        Sleep(500);
        system("exit");
    }
    else
    {
        system("cls");
        cout << "\n\t\t\t[GRESKA] Opcija ne postoji.";
        Sleep(500);
        system("cls");
        dobrodosli();
    }
}

void prikaziAute()
{
    int zastava = 0;
    ifstream datoteka("auta.txt");
    if (!datoteka || datoteka.peek() == EOF)
    {
        cout << "Nema dostupnih vozila.\n";
        zastava = 1;
        system("PAUSE");
    }
    datoteka.close();

    if (zastava == 1)
    {
        return;
    }
    ifstream citaj("auta.txt");
    string linija;
    while (getline(citaj, linija))
    {
        cout << linija << endl;
    }

    cout << "\nKRAJ\n";
    system("PAUSE");
}

void dodajAuto(string marka)
{
    string broj_registracije;
    int cijena_po_danu, kapacitet;
    cout << "\n\t\t\t\t\tUnesite broj registracije: ";
    cin >> broj_registracije;
    cout << "\n\t\t\t\t\tUnesite cijenu rentanja vozila (po satu): ";
    cin >> cijena_po_danu;
    cout << "\n\t\t\t\t\tUnesite broj sjedista vozila: ";
    cin >> kapacitet;

    Auto temp;
    temp.postaviPodatke(marka, broj_registracije, cijena_po_danu, kapacitet);
    temp.dodajUdatoteku();

    string s = "\n\t\t\t\t\tUspjesno ste dodali vozilo!\n";
    for (int i = 0; i < s.length(); i++)
    {
        Sleep(10);
        cout << s[i];
    }
    system("cls");
    adminMeni();
}

void prepisi()
{
    string linija;
    ofstream datoteka1("auta.txt");

    ifstream datoteka_temp1("auta_temp.txt");
    while (getline(datoteka_temp1, linija))
    {
        datoteka1 << linija << endl;
    }
    datoteka_temp1.close();
    datoteka1.close();
}

void obrisiAuto(string broj_registracije)
{
    if (!dostupnaRegistracija(broj_registracije))
    {
        cout << "\n[GRESKA]Nepostojeci broj registracije!\n";
        system("PAUSE");
        system("cls");
        adminMeni();
    }
    else
    {
        ifstream dat("auta.txt");
        ofstream fajlt("auta_temp.txt");

        string linija;
        string numTemp = "BROJ REGISTRACIJE: " + broj_registracije;

        bool found = false;
        while (getline(dat, linija))
        {
            if (linija.find(numTemp) != string::npos)
            {
                found = true;
                // Skip all lines for the current entry
                while (getline(dat, linija) && !linija.empty())
                {
                }
            }
            else
            {
                fajlt << linija << endl;
            }
        }

        dat.close();
        fajlt.close();

        if (!found)
        {
            cout << "\n[GRESKA]Nepostojeci broj registracije!\n";
            system("PAUSE");
            system("cls");
            adminMeni();
            return;
        }

        remove("auta.txt");
        rename("auta_temp.txt", "auta.txt");

        system("cls");
        cout << "\n\t\t\t\t\tUspjesno ste obrisali vozilo.";
        system("PAUSE");
        system("cls");
        adminMeni();
    }
}

void resetAutomobil(string num_plate, int nova_cijena)
{
    if (!dostupnaRegistracija(num_plate))
    {
        cout << "\n[GRESKA]Nepostojeci broj registracije!\n";
        system("PAUSE");
        system("cls");
        adminMeni();
    }
    else
    {
        string t = "Unesite broj registracije: " + num_plate;
        string linija3;
        int brojac = 1;

        ifstream dat("auta.txt");
        while (getline(dat, linija3))
        {
            if (linija3 == t)
            {
                break;
            }
            brojac++;
        }
        dat.close();

        brojac += 1;

        if (brojac <= 0)
        {
            brojac = 1;
        }

        string linija;
        ofstream fajlt("auta_temp.txt");
        ifstream fajl1("auta.txt");
        while (brojac > 1)
        {
            getline(fajl1, linija);
            fajlt << linija << endl;
            brojac--;
        }
        getline(fajl1, linija);
        fajlt << "Cijena po satu: " << nova_cijena << "KM" << endl;
        while (getline(fajl1, linija))
        {
            fajlt << linija << endl;
        }
        fajl1.close();
        fajlt.close();

        prepisi();
        system("cls");
        cout << "\nCijena uspjesno podesena!";
        system("PAUSE");
        system("cls");
        adminMeni();
    }
}

int main()
{
    ucitavanje();
    dobrodosli();

    return 1;
}