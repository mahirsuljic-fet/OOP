#pragma once

#include "Student.hpp"
#include <list>
#include <map>
#include <string>

class BazaStudenata
{
  private:
    std::list<Student> studenti_;

  public:
    const Student& dodaj_studenta(const std::string& brojIndeksa, const std::string& ime, const std::string& prezime, const std::string& grad);
    bool izbrisi_studenta(const std::string& brojIndeksa);
    bool postoji(const std::string& brojIndeksa) const;
    void ispis_full() const;
    void ispis() const;
    double prosjek_ukupni() const;
    std::map<std::string, double> prosjek_predmeti() const;
    std::list<Student>::const_iterator pronadji(const std::string& brojIndeksa) const;
    std::list<Student>::const_iterator pronadji(const Student& student) const;
    std::list<Student>::iterator pronadji_nc(const std::string& brojIndeksa);
    std::list<Student>::iterator pronadji_nc(const Student& student);
    std::list<Student>::const_iterator begin() const { return studenti_.begin(); }
    std::list<Student>::const_iterator end() const { return studenti_.end(); }
};
