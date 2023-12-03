#ifndef AUTO_H
#define AUTO_H

#include <string>

class Auto {
public:
    Auto();

    std::string getMarka() const;
    std::string getModel() const;
    std::string getGorivo() const;

    double getCijena() const;

    int getGodina() const;

    void setMarka(const std::string& marka);
    void setModel(const std::string& model);
    void setGodina(int godina);
    void setGorivo(const std::string& gorivo);
    void setCijena(double cijena);

    void unosAuta();
    void ispisAuta() const;
    void izmjenaAuta();

private:
    std::string marka;
    std::string model;
    std::string gorivo;

    double cijena;
    int godina;
};

#endif