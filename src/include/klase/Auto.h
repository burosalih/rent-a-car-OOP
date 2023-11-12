#ifndef AUTO_H
#define AUTO_H

#include <string>

class Auto {
public:
    Auto();

    std::string getMarka() const;
    std::string getModel() const;
    int getGodina() const;

    void setMarka(const std::string& marka);
    void setModel(const std::string& model);
    void setGodina(int godina);

private:
    std::string marka;
    std::string model;
    int godina;
};

#endif