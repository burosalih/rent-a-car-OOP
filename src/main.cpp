#include <iostream>
#include <vector>
#include "../include/funkcije/KorisnikFunkcije.cpp"

const std::string KORISNIK_FILE = "korisnici.txt";

void korisnikMeni(){
    std::cout << "Dobrodosao korisnik !" << std::endl;
}

void adminMeni(){
    std::cout << "Dobrodosao admin !" << std::endl;
}

int main(){
    int izbor;
    
    std::vector<Korisnik> korisnici = Korisnik::ucitajKorisnike(KORISNIK_FILE);
    bool korisnikPronadjen = false;
    std::string enteredUsername, enteredPassword;
    Korisnik loggedInKorisnik;

    do {
        std::cout << "*********RENT-A-CAR*********" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Registracija" << std::endl;
        std::cout << "3. Izlaz" << std::endl;
        std::cin >> izbor;
        switch (izbor) {
        case 1:
            std::cout << "Funkcija za login.." << std::endl;
            std::cout << "Unesite username:";
            std::cin >> enteredUsername;
            std::cout << "Unesite password:";
            std::cin >> enteredPassword;

            for(const auto& korisnik : korisnici) {
                if(loginUser(korisnik, enteredUsername,enteredPassword)){
                    loggedInKorisnik = korisnik;
                    korisnikPronadjen = true;
                    std::cout << "Uspjelo.";
                    break;
                }
            }
            break;
        case 2:
            std::cout << "Funkcija za registraciju..." << std::endl;
            break;
        case 3:
            std::cout << "Hvala na koristenju nase aplikacije !" << std::endl;
            break;
        default:
            std::cout << "[GRESKA] Neispravan unos!" << std::endl;
    }} while (izbor != 3);
    return 0;
}