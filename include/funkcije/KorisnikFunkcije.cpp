#include "../include/klase/Korisnik.h"
#include <iostream>

static Korisnik registerUser() {
    std::string username, password;
    std::cout << "Enter a username: ";
    std::cin >> username;
    std::cout << "Enter a password: ";
    std::cin >> password;

    return Korisnik(username, password);
}

static bool loginUser(const Korisnik& korisnik, const std::string& enteredUsername, const std::string& enteredPassword) {
    return (korisnik.getUsername() == enteredUsername && korisnik.getPassword() == enteredPassword);
}


