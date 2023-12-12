#include "include/klase/Auto.h"
#include <iostream>

Auto::Auto() : godina(0), cijena(0.0) {}

std::string Auto::getMarka() const{
    return marka;
}

std::string Auto::getModel() const{
    return model;
}

std::string Auto::getGorivo() const{
    return gorivo;
}

double Auto::getCijena() const{
    return cijena;
}
int Auto::getGodina() const{
    return godina;
}

void Auto::setMarka(const std::string& marka){
    this->marka = marka;
} 

void Auto::setModel(const std::string& model){
    this->model = model;
}

void Auto::setGorivo(const std::string& gorivo){
    this->gorivo = gorivo;
}

void Auto::setCijena(double cijena){
    this->cijena = cijena;
}

void Auto::setGodina(int godina){
    this->godina = godina;
}

void Auto::unosAuta(){
    std::cout << "Unesite marku auta: ";
    std::cin >> marka;

    std::cout << "Unesite model auta: ";
    std::cin >> model;

    std::cout << "Unesite godinu proizvodnje auta: ";
    std::cin >> godina;

    std::cout << "Unesite vrstu goriva auta: ";
    std::cin >> gorivo;

    std::cout << "Unesite cijenu rentanja auta (po danu): ";
    std::cin >> cijena;

}

void Auto::ispisAuta() const{
    std::cout << "Marka: " << marka << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Godina proizvodnje: " << godina << std::endl;
    std::cout << "Vrsta goriva: " << gorivo << std::endl;
    std::cout << "Cijena po danu: " << cijena << std::endl;
}