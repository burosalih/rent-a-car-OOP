#include <string>
#include <iostream>
#include <fstream>
#include "LoginRegistracija.h"
void login() {
    int id;
    std::string username, password, storedUsername, storedPassword, Ime, Prezime;
    bool found = false;
    std::cout << "Unesite svoje korisnicko ime: ";
    std::cin >> username;
    std::cout << "\nUnesite sifru: ";
    std::cin >> password;
    std::ifstream inFile;
    inFile.open("../korisnici.txt");
    while (inFile >> id >> Ime >> Prezime >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            found = true;
            break;
        }
    }
    inFile.close();

    if (found) {
        if (username == "admin" && password == "adminadmin") {
            std::cout << "\n---------------------------------------\nAdministrator ulogovan !\n---------------------------------------\n" << std::endl;
            //std::admin_menu();
        }
        else {
            std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
            std::cout << "\tDobrodosli, " << Ime << " " << Prezime << "!" << std::endl;
            std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
            //std::korisnik_menu(id);
        }
    } else {
        std::cout << "Neispravan unos." << std::endl;
    }
}

void registracija() {
    std::string username, password, Ime, Prezime;
    int id;
    int id_korisnika;


    std::ifstream inFile;
    inFile.open("../korisnici.txt");
    while(inFile >> id >> Ime >> Prezime >> username >> password) {

        id_korisnika = id;
    }
    inFile.close();


    id_korisnika++;


    std::cout << "Unesite svoje ime: ";
    std::cin >> Ime;

    std::cout << "Unesite svoje prezime: ";
    std::cin >> Prezime;

    std::cout << "Unesite vlastito korisnicko ime: ";
    std::cin >> username;

    std::cout << "Unesite sifru: ";
    std::cin >> password;


    std::ofstream outFile;
    outFile.open("../korisnici.txt", std::ios::app);
    outFile << id_korisnika << " " << Ime << " " << Prezime << " " << username << " " << password << "\n" << std::endl;
    outFile.close();

    std::cout << "Vasa registracija je uspjesna! Sada se mozete loginovati." << std::endl;
}
