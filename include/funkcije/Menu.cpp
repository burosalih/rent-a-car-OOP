#include "Menu.h"
#include <string>
#include <iostream>


void admin_menu(){
    int z;
    std::cout << "1. Unesite vozilo: " << std::endl;
    std::cout << "2. Pregled vozila: " << std::endl;
    std::cout << "3. Rezervisana vozila: " << std::endl;
    std::cout << "4. Pregled korisnika: " << std::endl;
    std::cout << "5. Logout" << std::endl;
    std::cout << "\nIzaberite neku opciju: ";
    std::cin >> z;


}



void korisnik_menu(int id){
    int x;
    std::cout << "1. Pregled vozila: " << std::endl;
    std::cout << "2. Popusti: " << std::endl;
    std::cout << "3. Rezervisite vozilo: " << std::endl;
    std::cout << "4. Rezervisano vozilo: " << std::endl;
    std::cout << "5. Odjava!" << std::endl;
    std::cout << "Izaberite neku opciju: ";
    std::cin >> x;

}