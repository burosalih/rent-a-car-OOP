#include "include/klase/Auto.h"

Auto::Auto() : godina(0) {}

std::string Auto::getMarka() const {
    return marka;
}

std::string Auto::getModel() const {
    return model;
}

int Auto::getGodina() const {
    return godina;
}

void Auto::setMarka(const std::string& marka) {
    this->marka = marka;
}

void Auto::setModel(const std::string& model) {
    this->model = model;
}

void Auto::setGodina(int godina) {
    this->godina = godina;
}