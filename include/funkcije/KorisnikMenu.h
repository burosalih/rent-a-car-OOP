#include <iostream>
#include <vector>

class Vozilo {
public:
    int ID_Auto;
    std::string Model;
    int GodinaProizvodnje;
};

class Korisnik {
public:
    int ID;
    std::string Ime;
    std::string Prezime;
    std::vector<Vozilo> rezervisanaVozila;
};

class Popust {
public:
    std::string Naziv;
    double Vrednost; // Vrednost popusta u procentima

    Popust(const std::string& naziv, double vrednost) : Naziv(naziv), Vrednost(vrednost) {}
};

class RentACar {
private:
    std::vector<Vozilo> ponudaVozila;
    std::vector<Korisnik> korisnici;
    int trenutniKorisnikID;
    std::vector<Popust> popusti;

public:
    RentACar() : trenutniKorisnikID(-1) {
        // Dodajemo popuste
        popusti.push_back(Popust("Student", 5.0));
        popusti.push_back(Popust("Vojnik", 15.0));
        popusti.push_back(Popust("Penzioner", 10.0));
        popusti.push_back(Popust("RVI", 15.0));
    }

    void prikaziPopuste() {
        // Implementacija prikaza popusta
        std::cout << "Popusti:" << std::endl;
        for (size_t i = 0; i < popusti.size(); ++i) {
            std::cout << i + 1 << ". " << popusti[i].Naziv << ": " << popusti[i].Vrednost << "%" << std::endl;
        }
    }

    void odjaviKorisnika() {
        // Implementacija odjave korisnika
        trenutniKorisnikID = -1;
        std::cout << "Uspešno ste se odjavili!" << std::endl;
    }

    void korisnikMenu(int korisnikID) {
        trenutniKorisnikID = korisnikID;

        int izbor;
        do {
            std::cout << "Korisnik Menu" << std::endl;
            std::cout << "1. Pregled vozila" << std::endl;
            std::cout << "2. Popusti" << std::endl;
            std::cout << "3. Rezervisite vozilo" << std::endl;
            std::cout << "4. Rezervisano vozilo" << std::endl;
            std::cout << "5. Odjava" << std::endl;
            std::cout << "Izaberite opciju: ";
            std::cin >> izbor;

            switch (izbor) {
                case 1:
                    // pozovi funkciju prikaziPonuduVozila();
                    break;
                case 2:
                    prikaziPopuste();
                    break;
                case 3:
                    // pozovi funkciju rezervisiVozilo(trenutniKorisnikID);
                    break;
                case 4:
                    // pozovi funkciju prikaziRezervisanaVozila(trenutniKorisnikID);
                    break;
                case 5:
                    odjaviKorisnika();
                    break;
                default:
                    std::cout << "Neispravan unos. Molimo vas da izaberete ponovo." << std::endl;
                    break;
            }
        } while (izbor != 5);
    }
};

int main() {
    RentACar rentACar;
    int korisnikID; // Ovde bi trebalo da bude logika za prijavu korisnika i dobijanje korisnikovog ID-a
    rentACar.korisnikMenu(korisnikID);

    return 0;
}

