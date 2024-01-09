cmake_minimum_required(VERSION 3.10)
project("rent-a-car")

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    src/main.cpp
    src/Korisnik.cpp
)

set(HEADERS
    include/klase/Korisnik.h
    include/funkcije/KorisnikFunkcije.cpp
        include/funkcije/LoginRegistracija.cpp
        include/funkcije/LoginRegistracija.cpp
        include/funkcije/LoginRegistracija.h

)

add_executable(rent_a_car ${SOURCES} ${HEADERS})
target_include_directories(rent_a_car PRIVATE include)