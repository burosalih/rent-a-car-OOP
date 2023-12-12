#ifndef KORISNIK_H
#define KORISNIK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Korisnik {
private:
    std::string username;
    std::string password;
    bool isAdmin;

public:
    Korisnik();
    Korisnik(const std::string& username, const std::string& password, bool isAdmin = false);

    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setAdmin(bool isAdmin);

    std::string getUsername() const;
    std::string getPassword() const;
    bool isAdminKorisnik() const;

    static std::vector<Korisnik> ucitajKorisnike(const std::string& filename);
    static void snimiKorisnike(const std::vector<Korisnik>& users, const std::string& filename);
};

#endif
