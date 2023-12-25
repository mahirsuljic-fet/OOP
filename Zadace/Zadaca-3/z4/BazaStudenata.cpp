#include "BazaStudenata.hpp"
#include "Student.hpp"
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

void BazaStudenata::ispis() const
{
  if (studenti_.size() == 0) throw std::runtime_error("Nema unesenih studenata!");

  for (const auto& el : studenti_)
    std::cout << el.broj_indeksa << ": " << el.ime << " " << el.prezime << " - " << el.grad << std::endl;
}

void BazaStudenata::ispis_full() const
{
  if (studenti_.size() == 0) throw std::runtime_error("Nema unesenih studenata!");

  for (const auto& el : studenti_)
  {

    std::cout << el.broj_indeksa << ": " << el.ime << " " << el.prezime << " - " << el.grad;

    if (el.ocjene.size() > 0)
    {
      std::cout << "\nProsjek: " << el.prosjek() << "\nOcjene:" << std::endl;
      el.ispisi_ocjene();
    }
    else
      std::cout << "\nNema unesenih ocjena!";

    std::cout << std::endl;
  }
}

const Student& BazaStudenata::dodaj_studenta(
  const std::string& brojIndeksa,
  const std::string& ime,
  const std::string& prezime,
  const std::string& grad)
{
  if (postoji(brojIndeksa)) throw std::runtime_error("Student vec postoji!");

  studenti_.push_back(Student(brojIndeksa, ime, prezime, grad));

  return studenti_.back();
}

bool BazaStudenata::izbrisi_studenta(const std::string& brojIndeksa)
{
  auto student = pronadji(brojIndeksa);

  if (student->broj_indeksa == brojIndeksa)
  {
    studenti_.erase(student);
    return true;
  }

  return false;
}

bool BazaStudenata::postoji(const std::string& brojIndeksa) const
{
  for (const auto& el : studenti_)
    if (el.broj_indeksa == brojIndeksa)
      return true;

  return false;
}

std::list<Student>::const_iterator BazaStudenata::pronadji(const std::string& broj_indeksa) const
{
  for (auto it = this->begin(); it != this->end(); ++it)
    if (it->broj_indeksa == broj_indeksa)
      return it;

  return this->end();
}

std::list<Student>::const_iterator BazaStudenata::pronadji(const Student& student) const
{
  for (auto it = this->begin(); it != this->end(); ++it)
    if (it->broj_indeksa == student.broj_indeksa)
      return it;

  return this->end();
}

std::list<Student>::iterator BazaStudenata::pronadji_nc(const std::string& broj_indeksa)
{
  for (auto it = this->studenti_.begin(); it != this->studenti_.end(); ++it)
    if (it->broj_indeksa == broj_indeksa)
      return it;

  return this->studenti_.end();
}

std::list<Student>::iterator BazaStudenata::pronadji_nc(const Student& student)
{
  for (auto it = this->studenti_.begin(); it != this->studenti_.end(); ++it)
    if (it->broj_indeksa == student.broj_indeksa)
      return it;

  return this->studenti_.end();
}

std::map<std::string, double> BazaStudenata::prosjek_predmeti() const
{
  if (studenti_.size() == 0) throw std::runtime_error("Nema unesenih studenata!");

  std::map<std::string, double> rezultat;
  std::map<std::string, int> brojac;

  for (const auto& student : studenti_)
  {
    for (const auto& ocjena : student.ocjene)
    {
      rezultat["(" + ocjena.predmet->odsjek + ") " + ocjena.predmet->naziv] += ocjena.ocjena;
      ++brojac["(" + ocjena.predmet->odsjek + ") " + ocjena.predmet->naziv];
    }
  }

  if (rezultat.size() == 0) throw std::runtime_error("Nema unesenih ocjena!");

  for (auto&& el : rezultat)
    el.second /= brojac[el.first];

  return rezultat;
}

double BazaStudenata::prosjek_ukupni() const
{
  if (studenti_.size() == 0) throw std::runtime_error("Nema unesenih studenata!");

  double rezultat = 0;
  int n = 0;

  for (const auto& student : studenti_)
  {
    for (const auto& ocjena : student.ocjene)
    {
      rezultat += ocjena.ocjena;
      ++n;
    }
  }

  if (n == 0) throw std::runtime_error("Nema unesenih ocjena!");

  return rezultat / n;
}
