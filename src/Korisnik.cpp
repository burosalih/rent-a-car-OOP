#include "../include/klase/Korisnik.h"

Korisnik::Korisnik() : isAdmin(false) {}

Korisnik::Korisnik(const std::string& username, const std::string& password, bool isAdmin)
    : username(username), password(password), isAdmin(isAdmin) {}

void Korisnik::setUsername(const std::string& username) {
    this->username = username;
}

void Korisnik::setPassword(const std::string& password) {
    this->password = password;
}

void Korisnik::setAdmin(bool isAdmin) {
    this->isAdmin = isAdmin;
}

std::string Korisnik::getUsername() const {
    return username;
}

std::string Korisnik::getPassword() const {
    return password;
}

bool Korisnik::isAdminKorisnik() const {
    return isAdmin;
}

std::vector<Korisnik> Korisnik::ucitajKorisnike(const std::string& filename) {
    std::vector<Korisnik> users;
    std::ifstream file(filename);

    if (file.is_open()) {
        while (!file.eof()) {
            std::string username, password;
            bool isAdmin;
            file >> username >> password >> isAdmin;
            users.push_back(Korisnik(username, password, isAdmin));
        }

        file.close();
    }

    return users;
}

void Korisnik::snimiKorisnike(const std::vector<Korisnik>& users, const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.getUsername() << ' ' << user.getPassword() << ' ' << user.isAdminKorisnik() << '\n';
        }

        file.close();
    }
}
