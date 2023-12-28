#pragma once

#include "Ocjena.hpp"
#include <string>
#include <vector>

struct Student
{
    std::string broj_indeksa;
    std::string ime;
    std::string prezime;
    std::string grad;
    std::vector<OcjenaIzPredmeta> ocjene;

    void ispisi_podatke() const;
    void ispisi_ocjene() const;
    void promijeni_broj_indeksa(std::string broj_indeksa);
    void promijeni_ime(std::string ime);
    void promijeni_prezime(std::string prezime);
    void promijeni_grad(std::string grad);
    void izbrisi_ocjene() { this->ocjene.clear(); };
    void dodaj_ocjenu(OcjenaIzPredmeta ocjena) { this->ocjene.push_back(ocjena); };
    double prosjek() const;

    Student(std::string broj_indeksa, std::string ime, std::string prezime, std::string grad);
};
