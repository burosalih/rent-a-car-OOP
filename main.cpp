#include <iostream>

int main(){
    int izbor;

    do {
        std::cout << "*********RENT-A-CAR*********" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Registracija" << std::endl;
        std::cout << "3. Izlaz" << std::endl;
        std::cin >> izbor;
        switch (izbor) {
        case 1:
            std::cout << "Funkcija za login..." << std::endl;
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