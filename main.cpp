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

void adminMeni()
{
    cout << "------------------------------------------ ADMIN MENI ------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t1.Prikazi auta"
         << "\n\t\t\t\t\t2.Dodaj auto"
         << "\n\t\t\t\t\t3.Izbrisi auto"
         << "\n\t\t\t\t\t4.Resetuj cijenu auta"
         << "\n\t\t\t\t\t5.Odjava"
         << "\n\t\t\t\t\tUnesite opciju:";
    int odgovor;
    cin >> odgovor;
    if (odgovor == 1)
    {
        system("cls");
        cout << "------------------------------------------ ADMIN MENI ------------------------------------------" << endl;
        prikaziAute();
        system("cls");
        adminMeni();
    }
    else if (odgovor == 2)
    {
        system("cls");
        string ime;
        cout << "------------------------------------------ ADMIN MENI ------------------------------------------" << endl;
        cout << "\n\t\t\t\t\tUnesite naziv vozila: ";
        cin >> ime;
        dodajAuto(ime);
    }
    else if (odgovor == 3)
    {
        system("cls");
        string broj;
        cout << "------------------------------------------ ADMIN MENI ------------------------------------------" << endl;
        cout << "\n\t\t\t\t\tUnesite broj registracije vozila: ";
        cin >> broj;
        obrisiAuto(broj);
        cout << "\n\t\t\t\t\tUspjesno ste obrisali vozilo.";
        system("PAUSE");
        system("cls");
        adminMeni();
    }
    else if (odgovor == 4)
    {
        system("cls");
        cout << "------------------------------------------ ADMIN MENI ------------------------------------------" << endl;
        cout << "\n\t\t\t\t\tMozete resetovati samo cijenu auta."
             << "\n\t\t\t\t\tDa bi ste promjenili druge podatke o autu molimo da napravite novo auto.\n";
        string broj;
        cout << "\n\t\t\t\t\tUnesite broj registracije vozila: ";
        cin >> broj;
        int cijena;
        cout << "\n\t\t\t\t\tUnesite novu cijenu vozila: ";
        cin >> cijena;
        resetAutomobil(broj, cijena);
    }
    else if (odgovor == 5)
    {
        system("cls");
        string odjava = "Hvala Vam na koristenju nase aplikacije i vozite oprezno!\nVracanje na glavni meni\n";
        for (int i = 0; i < odjava.length(); i++)
        {
            Sleep(20);
            cout << odjava[i];
        }
        string posljednje = "\nUcitavanje";
        for (int i = 0; i < posljednje.length(); i++)
        {
            cout << posljednje[i];
        }
        for (int i = 0; i < 4; i++)
        {
            Sleep(500);
            cout << '.';
        }
        dobrodosli();
    }
    else
    {
        system("cls");
        cout << "[GRESKA] Opcija ne postoji\n\n"
             << "Vracanje na admin meni\n";
        Sleep(1000);
        system("cls");
        adminMeni();
    }
}

int procijeniCijenu(int vrijeme)
{
    int cijena = 0;
    cijena += (vrijeme * 249);
    return cijena;
}

void rezervisiAuto()
{
    string num_plate, imeVlasnika, lokacija;
    int vrijeme;
    cout << "Izaberite vozilo iz opcije \"Prikazi vozila\" !\n";
    cout << "\nUnesite ID broj vozila koje zelite: ";
    cin >> num_plate;

    Auto temp;

    if (!dostupnaRegistracija(num_plate))
    {
        cout << "\nAuto nije dostupno\n";
        cout << "\nVracanje na korisnicki meni";
        Sleep(500);
        system("cls");
        korisnikMeni();
        system("cls");
    }
    else
    {
        cout << "\nUnesite vrijeme rentanja vozila (u satima): ";
        cin >> vrijeme;
        if (vrijeme < 3)
        {
            cout << "\n[GRESKA] Minimalno 3 sata !\n";
            cout << "\nVracanje na korisnicki meni\n";
            Sleep(500);
            system("cls");
            korisnikMeni();
        }
        else
        {
            cout << "\nUnesite svoje ime: ";
            cin >> imeVlasnika;
            cout << "\nUnesite svoju adresu: ";
            cin >> lokacija;
            temp.rezervirajAuto(imeVlasnika);
            system("cls");
            string poruka = "\nUspjesno ste rezervisali auto: ";
            string posljednjaPoruka = "\nAuto ce vam biti predano na: ";
            string iznosPoruke = "\nIznos rentanja je: ";
            for (int i = 0; i < poruka.length(); i++)
            {
                Sleep(20);
                cout << poruka[i];
            }
            cout << imeVlasnika << endl;
            for (int i = 0; i < posljednjaPoruka.length(); i++)
            {
                Sleep(20);
                cout << posljednjaPoruka[i];
            }
            cout << lokacija << endl;
            for (int i = 0; i < iznosPoruke.length(); i++)
            {
                Sleep(20);
                cout << iznosPoruke[i];
            }
            cout << procijeniCijenu(vrijeme) << "KM" << endl;
            cout << "\nMolimo da pripremite vozacku dozvolu\n"
                 << "\nPlacate gore navedeni iznos pri preuzimanju vozila\n";
            cout << "\nHvala Vam na koristenju nase aplikacije i vozite oprezno!\n";
            system("PAUSE");
            system("cls");
            korisnikMeni();
        }
    }
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
void korisnikMeni()
{
	cout << "------------------------------------------ KORISNIK MENI ------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t1.Prikazi aute"
    	<< "\n\t\t\t\t\t2.Rentaj auto"
    	<< "\n\t\t\t\t\t3.Izracunaj cijenu"
    	<< "\n\t\t\t\t\t4.Odjava"
    	<< "\n\t\t\t\t\tUnesite opciju:";
	int odgovor;
	cin >> odgovor;

	if (odgovor == 1)
	{
    	system("cls");
    	cout << "------------------------------------------ KORISNIK MENI ------------------------------------------" << endl;
    	prikaziAute();
    	system("cls");
    	korisnikMeni();
	}
	else if (odgovor == 2)
	{
    	system("cls");
    	rezervisiAuto();
	}
	else if (odgovor == 3)
	{
    	system("cls");
    	cout << "------------------------------------------ KORISNIK MENI ------------------------------------------" << endl;
    	cout << "Minimalan vremenski period rentanja auta je 3 sata!";
    	int vrijeme;
    	cout << "Unesite vrijeme rentanja vozila (u satima): ";
    	cin >> vrijeme;

    	if (vrijeme < 3)
    	{
        	cout << "\n[GRESKA] Minimalan vremenski period rentanja auta je 3 sata!\n";
        	cout << "Vracanje na korisnicki meni....\n";
        	Sleep(1000);
        	system("cls");
        	korisnikMeni();
    	}
    	else
    	{
        	cout << "Cijena navedenog vozila je: " << procijeniCijenu(vrijeme) << " KM" << endl;
        	system("PAUSE");
        	system("cls");
        	korisnikMeni();
    	}
	}
	else if (odgovor == 4)
	{
    	system("cls");
    	cout << "------------------------------------------ KORISNIK MENI ------------------------------------------" << endl;
    	string odjava = "Hvala Vam na koristenju nase aplikacije i vozite oprezno!\n \nVracanje na glavni meni!\n";
    	for (int i = 0; i < odjava.length(); i++)
    	{
        	Sleep(20);
        	cout << odjava[i];
    	}
    	string posljednje = "\n";
    	for (int i = 0; i < posljednje.length(); i++)
    	{
        	Sleep(500);
        	cout << posljednje[i];
    	}
    	for (int i = 0; i < 4; i++)
    	{
        	Sleep(500);
        	cout << '.';
    	}
    	dobrodosli();
	}
	else
	{
    	system("cls");
    	cout << "[GRESKA] Opcija ne postoji!\n\n"
        	<< "Vracanje na korisnicki meni\n";
    	Sleep(1000);
    	system("cls");
    	korisnikMeni();
	}
}


int main()
{
    ucitavanje();
    dobrodosli();

    return 1;
}